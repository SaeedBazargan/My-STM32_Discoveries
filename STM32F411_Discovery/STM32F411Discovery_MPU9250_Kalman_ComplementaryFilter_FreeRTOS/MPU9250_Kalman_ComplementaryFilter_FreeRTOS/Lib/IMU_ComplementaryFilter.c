/*
 * IMU_ComplementaryFilter.c
 *
 *  Created on: Sep 9, 2025
 *      Author: Bazar
 */

#include "IMU_ComplementaryFilter.h"
#include <math.h>
#include <string.h>

#if FreeRTOS_En
#include "cmsis_os.h"
#endif

void Complementary_Init(ComplementaryFilter *cf)
{
	cf->alpha = 0.01f;
	cf->bx = cf->by = cf->bz = 0.0f;
	cf->phi_hat = cf->theta_hat = 0.0f;
}

// <---- ------ Get Accel Angles ------ ---->
void Complementary_Get_AccelAngles(float ax, float ay, float az, float* phi, float* theta)
{
    *phi = atan2(ay, sqrt(ax * ax + az * az));
    *theta = atan2(-ax, sqrt(ay * ay + az * az));
}

// <---- ------ Get Accel Angles ------ ---->
void Get_GyroBias(ComplementaryFilter *cf, float gx, float gy, float gz, uint16_t N)
{
	cf->bx = cf->by = cf->bz = 0.0f;

	for(uint16_t i = 0; i < N; i++)
	{
		cf->bx += gx;
		cf->by += gy;
		cf->bz += gz;
#if FreeRTOS_En
	osDelay(1);
#else
	HAL_Delay(1);
#endif
	}
	cf->bx /= N;
	cf->by /= N;
	cf->bz /= N;
}

void Complementary_Update(ComplementaryFilter *cf, float gx, float gy, float gz, float ax, float ay, float az, float dt)
{
	cf->current_tick = HAL_GetTick();
	cf->dt = (cf->current_tick - cf->last_tick) / 1000.0f;
	cf->last_tick = cf->current_tick;

    // Subtract biases
    gx -= cf->bx;
    gy -= cf->by;
    gz -= cf->bz;

    // Calculate Euler angle derivatives
    float phi_dot = gx + sinf(cf->phi_hat) * tanf(cf->theta_hat) * gy + cosf(cf->phi_hat) * tanf(cf->theta_hat) * gz;
    float theta_dot = cosf(cf->phi_hat) * gy - sinf(cf->phi_hat) * gz;

    // Get accelerometer angles
    float phi_acc, theta_acc;
    Complementary_Get_AccelAngles(ax, ay, az, &phi_acc, &theta_acc);

    // Complementary filter update
    cf->phi_hat = (1.0f - cf->alpha) * (cf->phi_hat + dt * phi_dot) + cf->alpha * phi_acc;
    cf->theta_hat = (1.0f - cf->alpha) * (cf->theta_hat + dt * theta_dot) + cf->alpha * theta_acc;
}

float Complementary_Get_Roll(ComplementaryFilter *cf)
{
    return RAD2DEG(cf->phi_hat);
}

float Complementary_Get_Pitch(ComplementaryFilter *cf)
{
    return RAD2DEG(cf->theta_hat);
}




