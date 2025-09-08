/*
 * IMU_KalmanFilter.c
 *
 *  Created on: Sep 8, 2025
 *      Author: Bazar
 */

#include "IMU_KalmanFilter.h"
#include <math.h>
#include <string.h>

#if FreeRTOS_En
#include "cmsis_os.h"
#endif

// <---- ------ Kalman Filter init ------ ---->
void kalman_init(KalmanFilter *kf)
{
    memset(kf, 0, sizeof(KalmanFilter));

    kf->C[0][0] = 1.0f;
    kf->C[0][1] = 0.0f;
    kf->C[0][2] = 0.0f;
    kf->C[0][3] = 0.0f;
    kf->C[1][0] = 0.0f;
    kf->C[1][1] = 0.0f;
    kf->C[1][2] = 1.0f;
    kf->C[1][3] = 0.0f;

    for(uint8_t i = 0; i < 4; i++)
    {
        kf->P[i][i] = 1.0f;
        kf->Q[i][i] = 1.0f;
    }

    for(uint8_t i = 0; i < 2; i++)
    	kf->R[i][i] = 1.0f;

    for(uint8_t i = 0; i < 4; i++)
    	kf->state_estimate[i] = 0.0f;

    kf->phi_hat = 0.0f;
    kf->theta_hat = 0.0f;
    kf->phi_offset = 0.0f;
    kf->theta_offset = 0.0f;
    kf->calibrated = 0;

    kf->last_tick = HAL_GetTick();
}

// <---- ------ Calibration: average offsets ------ ---->
void kalman_calibrate(KalmanFilter *kf, float phi_acc_samples, float theta_acc_samples, int N)
{
    float phi_sum = 0, theta_sum = 0;

    for(uint8_t i = 0; i < N; i++)
    {
        phi_sum   += phi_acc_samples;
        theta_sum += theta_acc_samples;
#if FreeRTOS_En
	osDelay(10);
#else
	HAL_Delay(10);
#endif
    }

    kf->phi_offset   = phi_sum / (float)N;
    kf->theta_offset = theta_sum / (float)N;
    kf->calibrated = 1;
#if Debug
    printf("Accelerometer offsets: %.2f, %.2f \n", kf->phi_offset, kf->theta_offset);
#endif
}

// <---- ------ Update filter ------ ---->
void kalman_update(KalmanFilter *kf, float GX, float GY, float GZ, float AX, float AY, float AZ, float dt)
{
	if(!kf->calibrated)
		return;

	kf->current_tick = HAL_GetTick();
	kf->dt = (kf->current_tick - kf->last_tick) / 1000.0f;
	kf->last_tick = kf->current_tick;

    // Accelerometer angles
    float phi_acc;
    float theta_acc;
    Get_AccelAngles(AX, AY, AZ, &phi_acc, &theta_acc);
    phi_acc -= kf->phi_offset;
    theta_acc -= kf->theta_offset;

    // Gyro integration (Euler)
    float phi_dot   = GX + sinf(kf->phi_hat) * tanf(kf->theta_hat) * GY + cosf(kf->phi_hat) * tanf(kf->theta_hat) * GZ;
    float theta_dot = cosf(kf->phi_hat) * GY - sinf(kf->phi_hat) * GZ;

    // State prediction
    float A[4][4] =
    {
        {1, -dt, 0,  0},
        {0,  1,  0,  0},
        {0,  0,  1, -dt},
        {0,  0,  0,  1}
    };
    float B[4][2] =
    {
        {dt, 0},
        {0, 0},
        {0, dt},
        {0, 0}
    };
    float gyro_input[2] = {phi_dot, theta_dot};

    // x = A*x + B*u
    float new_state[4];
    for(uint8_t i = 0; i < 4; i++)
    {
        new_state[i] = 0;
        for(uint8_t j = 0; j < 4; j++)
        	new_state[i] += A[i][j] * kf->state_estimate[j];

        for(uint8_t j = 0; j < 2; j++)
        	new_state[i] += B[i][j] * gyro_input[j];
    }
    memcpy(kf->state_estimate, new_state, sizeof(new_state));

    // <---- ------ P = A.dot(P.dot(np.transpose(A))) + Q ------ ---->
    float AP[4][4] = {0};
    for(uint8_t i = 0; i < 4; i++)
    {
        for(uint8_t j = 0; j < 4; j++)
        {
            for(uint8_t k = 0; k < 4; k++)
            {
                AP[i][j] += A[i][k] * kf->P[k][j];
            }
        }
    }

    float APA_T[4][4] = {0};
    for(uint8_t i = 0; i < 4; i++)
    {
        for(uint8_t j = 0; j < 4; j++)
        {
            for(uint8_t k = 0; k < 4; k++)
            {
                APA_T[i][j] += AP[i][k] * A[j][k]; // A * P * A^T
            }
        }
    }
    for(uint8_t i = 0; i < 4; i++)
    {
        for(uint8_t j = 0; j < 4; j++)
        {
            kf->P[i][j] = APA_T[i][j] + kf->Q[i][j];
        }
    }

    // <---- ------ Measurement update ------ ---->
    // y_tilde = measurement - C * state_estimate
    float Cx[2] = {0, 0};
    for(uint8_t i = 0; i < 2; i++)
    {
        for(uint8_t j = 0; j < 4; j++)
        {
            Cx[i] += kf->C[i][j] * kf->state_estimate[j];
        }
    }

    // measurement = [phi_acc, theta_acc]
    float measurement[2] = {phi_acc, theta_acc};
    float y_tilde[2];
    for(uint8_t i = 0; i < 2; i++)
    {
        y_tilde[i] = measurement[i] - Cx[i];
    }

    // <---- ------ S = R + C.dot(P.dot(np.transpose(C))) ------ ---->
    float CP[2][4] = {0};
    for(uint8_t i = 0; i < 2; i++)
        for(uint8_t j = 0; j < 4; j++)
            for(uint8_t k = 0; k < 4; k++)
                CP[i][j] += kf->C[i][k] * kf->P[k][j];

    float CPC_T[2][2] = {0};
    for(uint8_t i = 0; i < 2; i++)
        for(uint8_t j = 0; j < 2; j++)
            for(uint8_t k = 0; k < 4; k++)
                CPC_T[i][j] += CP[i][k] * kf->C[j][k];

    float S[2][2];
    for(uint8_t i = 0; i < 2; i++)
        for(uint8_t j = 0; j < 2; j++)
            S[i][j] = kf->R[i][j] + CPC_T[i][j];

    // <---- ------ K = P.dot(np.transpose(C).dot(np.linalg.inv(S))) ------ ---->
    float C_T[4][2];
    for(uint8_t i = 0; i < 4; i++)
        for(uint8_t j = 0; j < 2; j++)
            C_T[i][j] = kf->C[j][i];

    float PC_T[4][2] = {0};
    for(uint8_t i = 0; i < 4; i++)
        for(uint8_t j = 0; j < 2; j++)
            for(uint8_t k = 0; k < 4; k++)
                PC_T[i][j] += kf->P[i][k] * C_T[k][j];

    // Inverse of 2x2 matrix S
    float det = S[0][0]*S[1][1] - S[0][1]*S[1][0];
    float invS[2][2] = {{S[1][1]/det, -S[0][1]/det}, {-S[1][0]/det, S[0][0]/det}};
    float K[4][2] = {0};
    for(uint8_t i = 0; i < 4; i++)
        for(uint8_t j = 0; j < 2; j++)
            for(uint8_t k = 0; k < 2; k++)
                K[i][j] += PC_T[i][k] * invS[k][j];

    // <---- ------ state_estimate = state_estimate + K.dot(y_tilde) ------ ---->
    for(uint8_t i = 0; i < 4; i++)
        for(uint8_t j = 0; j < 2; j++)
            kf->state_estimate[i] += K[i][j] * y_tilde[j];


    // <---- ------ P = (np.eye(4) - K.dot(C)).dot(P) ------ ---->
    float KC[4][4] = {0};
    for(uint8_t i = 0; i < 4; i++)
        for(uint8_t j = 0; j < 4; j++)
            for(uint8_t k = 0; k < 2; k++)
                KC[i][j] += K[i][k] * kf->C[k][j];

    float I_KC[4][4];
    for(uint8_t i = 0; i < 4; i++)
        for(uint8_t j = 0; j < 4; j++)
            I_KC[i][j] = (i==j ? 1.0f : 0.0f) - KC[i][j];

    float newP[4][4] = {0};
    for(uint8_t i = 0; i < 4; i++)
        for(uint8_t j = 0; j < 4; j++)
            for(uint8_t k = 0; k < 4; k++)
                newP[i][j] += I_KC[i][k] * kf->P[k][j];

    memcpy(kf->P, newP, sizeof(newP));

    // Update estimated angles
    kf->phi_hat   = kf->state_estimate[0];
    kf->theta_hat = kf->state_estimate[2];
}
// <---- ------ Get Accel Angles ------ ---->
void Get_AccelAngles(float ax, float ay, float az, float* phi, float* theta)
{
    *phi = atan2(ay, sqrt(ax * ax + az * az));
    *theta = atan2(-ax, sqrt(ay * ay + az * az));
}

// <---- ------ Get Roll ------ ---->
float kalman_get_roll(KalmanFilter *kf)
{
    return kf->phi_hat * 180.0f / M_PI;
}

// <---- ------ Get Pitch ------ ---->
float kalman_get_pitch(KalmanFilter *kf)
{
    return kf->theta_hat * 180.0f / M_PI;
}







