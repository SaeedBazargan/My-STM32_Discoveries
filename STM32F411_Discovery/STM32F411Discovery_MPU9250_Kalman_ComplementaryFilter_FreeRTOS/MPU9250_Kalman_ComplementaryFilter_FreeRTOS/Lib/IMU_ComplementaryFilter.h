/*
 * IMU_ComplementaryFilter.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Bazar
 */

#ifndef IMU_COMPLEMENTARYFILTER_H_
#define IMU_COMPLEMENTARYFILTER_H_

#include <stdint.h>

#define FreeRTOS_En								0x01
#define Debug									0x01
#define RAD2DEG(x)			 					((x) * 57.2957795f)
typedef struct
{
    float bx, by, bz;        // Gyro biases
    float phi_hat;           // Estimated roll angle (rad)
    float theta_hat;         // Estimated pitch angle (rad)
    float alpha;             // Complementary filter coefficient

    uint32_t last_tick;
    uint32_t current_tick;
    float dt;
}ComplementaryFilter;

float IMU_Filter_GetRoll(ComplementaryFilter *cf);
float IMU_Filter_GetPitch(ComplementaryFilter *cf);

void Complementary_Init(ComplementaryFilter *cf);
void Complementary_Get_AccelAngles(float ax, float ay, float az, float* phi, float* theta);
void Get_GyroBias(ComplementaryFilter *cf, float gx, float gy, float gz, uint16_t N);
void Complementary_Update(ComplementaryFilter *cf, float gx, float gy, float gz, float ax, float ay, float az, float dt);
float Complementary_Get_Roll(ComplementaryFilter *cf);
float Complementary_Get_Pitch(ComplementaryFilter *cf);

#endif /* IMU_COMPLEMENTARYFILTER_H_ */
