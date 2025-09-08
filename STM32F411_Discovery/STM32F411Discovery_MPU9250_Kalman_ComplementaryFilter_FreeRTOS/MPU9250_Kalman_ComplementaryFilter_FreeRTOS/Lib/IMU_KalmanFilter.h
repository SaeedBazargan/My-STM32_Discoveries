/*
 * IMU_KalmanFilter.h
 *
 *  Created on: Sep 8, 2025
 *      Author: Bazar
 */

#ifndef IMU_KALMANFILTER_H_
#define IMU_KALMANFILTER_H_

#include <stdint.h>

#define FreeRTOS_En								0x01
#define Debug									0x01

typedef struct
{
    float C[2][4];
    float P[4][4];
    float Q[4][4];
    float R[2][2];
    float state_estimate[4];   // [phi, phi_bias, theta, theta_bias]

    float phi_hat;
    float theta_hat;
    float phi_offset;
    float theta_offset;
    uint8_t calibrated;

    uint32_t last_tick;
    uint32_t current_tick;
    float dt;
}KalmanFilter;

void kalman_init(KalmanFilter *kf);
void kalman_calibrate(KalmanFilter *kf, float phi_acc_samples, float theta_acc_samples, int N);
void kalman_update(KalmanFilter *kf, float GX, float GY, float GZ, float AX, float AY, float AZ, float dt);
void Get_AccelAngles(float ax, float ay, float az, float* phi, float* theta);
float kalman_get_roll(KalmanFilter *kf);
float kalman_get_pitch(KalmanFilter *kf);

#endif /* IMU_KALMANFILTER_H_ */
