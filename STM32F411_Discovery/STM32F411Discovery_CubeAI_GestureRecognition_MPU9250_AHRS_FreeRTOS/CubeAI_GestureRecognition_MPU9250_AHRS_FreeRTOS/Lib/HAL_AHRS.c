#include "HAL_AHRS.h"

// <---- ------------ Calculate 1/sqrt(x) with magic number support ------------ ---->
static float oneOverSqrt(float x)
{
    return 1.0f / (float)sqrt(x);
}

static void calculateAngles(AHRS_TypeDef* AHRS)
{
	AHRS->Roll  = (float)atan2(AHRS->_q0 * AHRS->_q1 + AHRS->_q2 * AHRS->_q3, 0.5f - AHRS->_q1 * AHRS->_q1 - AHRS->_q2 * AHRS->_q2);
	AHRS->Pitch = (float)asin(-2.0f * (AHRS->_q1 * AHRS->_q3 - AHRS->_q0 * AHRS->_q2));
	AHRS->Yaw   = (float)atan2(AHRS->_q1 * AHRS->_q2 + AHRS->_q0 * AHRS->_q3, 0.5f - AHRS->_q2 * AHRS->_q2 - AHRS->_q3 * AHRS->_q3);

	// <---- ------------ Calculate degrees and remove inclination ------------ ---->
	AHRS->Roll *= AHRS_RAD2DEG(1);
	AHRS->Pitch *= AHRS_RAD2DEG(1);
	AHRS->Yaw = AHRS->Yaw * AHRS_RAD2DEG(1) - AHRS->Inclination;

	// <---- ------------ Check values because of inclination ------------ ---->
    if(AHRS->Yaw < -180)
    {
    	AHRS->Yaw = 180.0f - (-180.0f - AHRS->Yaw);
    }
    else if(AHRS->Yaw > 180)
    {
    	AHRS->Yaw = -180.0f - (180.0f - AHRS->Yaw);
    }
}
// <---- ------------ Initializes ARHS for motion calculations ------------ ---->
void AHRS_Init(AHRS_TypeDef* AHRS, float sampleRate, float beta, float inclination)
{
    AHRS->_beta = beta;
    AHRS->_sampleRate = 1 / sampleRate;
    AHRS->Inclination = inclination;

    AHRS->_q0 = 1.0f;
    AHRS->_q1 = 0.0f;
    AHRS->_q2 = 0.0f;
    AHRS->_q3 = 0.0f;
}

// <---- ------------ Updates IMU algorithm with new values and calculates roll, pitch and yaw angles ------------ ---->
void AHRS_UpdateIMU(AHRS_TypeDef* AHRS, float gx, float gy, float gz, float ax, float ay, float az)
{
    float recipNorm;
    float s0, s1, s2, s3;
    float qDot1, qDot2, qDot3, qDot4;
    float _2q0, _2q1, _2q2, _2q3, _4q0, _4q1, _4q2, _8q1, _8q2, q0q0, q1q1, q2q2, q3q3;

    // <---- ------------ Rate of change of quaternion from gyroscope ------------ ---->
    qDot1 = 0.5f * (-AHRS->_q1 * gx - AHRS->_q2 * gy - AHRS->_q3 * gz);
    qDot2 = 0.5f * (AHRS->_q0 * gx + AHRS->_q2 * gz - AHRS->_q3 * gy);
    qDot3 = 0.5f * (AHRS->_q0 * gy - AHRS->_q1 * gz + AHRS->_q3 * gx);
    qDot4 = 0.5f * (AHRS->_q0 * gz + AHRS->_q1 * gy - AHRS->_q2 * gx);

    // <---- ------------ Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation) ------------ ---->
    if(!(ax == 0.0f && ay == 0.0f && az == 0.0f))
    {
    	// <---- ------------ Normalise accelerometer measurement ------------ ---->
        recipNorm = oneOverSqrt(ax * ax + ay * ay + az * az);
        ax *= recipNorm;
        ay *= recipNorm;
        az *= recipNorm;

        // <---- ------------ Auxiliary variables to avoid repeated arithmetic ------------ ---->
        _2q0 = 2.0f * AHRS->_q0;
        _2q1 = 2.0f * AHRS->_q1;
        _2q2 = 2.0f * AHRS->_q2;
        _2q3 = 2.0f * AHRS->_q3;
        _4q0 = 4.0f * AHRS->_q0;
        _4q1 = 4.0f * AHRS->_q1;
        _4q2 = 4.0f * AHRS->_q2;
        _8q1 = 8.0f * AHRS->_q1;
        _8q2 = 8.0f * AHRS->_q2;
        q0q0 = AHRS->_q0 * AHRS->_q0;
        q1q1 = AHRS->_q1 * AHRS->_q1;
        q2q2 = AHRS->_q2 * AHRS->_q2;
        q3q3 = AHRS->_q3 * AHRS->_q3;

        // <---- ------------ Gradient decent algorithm corrective step ------------ ---->
        s0 = _4q0 * q2q2 + _2q2 * ax + _4q0 * q1q1 - _2q1 * ay;
        s1 = _4q1 * q3q3 - _2q3 * ax + 4.0f * q0q0 * AHRS->_q1 - _2q0 * ay - _4q1 + _8q1 * q1q1 + _8q1 * q2q2 + _4q1 * az;
        s2 = 4.0f * q0q0 * AHRS->_q2 + _2q0 * ax + _4q2 * q3q3 - _2q3 * ay - _4q2 + _8q2 * q1q1 + _8q2 * q2q2 + _4q2 * az;
        s3 = 4.0f * q1q1 * AHRS->_q3 - _2q1 * ax + 4.0f * q2q2 * AHRS->_q3 - _2q2 * ay;

        // <---- ------------ Normalise step magnitude ------------ ---->
        recipNorm = oneOverSqrt(s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3);
        s0 *= recipNorm;
        s1 *= recipNorm;
        s2 *= recipNorm;
        s3 *= recipNorm;

        // <---- ------------ Apply feedback step ------------ ---->
        qDot1 -= AHRS->_beta * s0;
        qDot2 -= AHRS->_beta * s1;
        qDot3 -= AHRS->_beta * s2;
        qDot4 -= AHRS->_beta * s3;
    }

    // <---- ------------ Integrate rate of change of quaternion to yield quaternion ------------ ---->
    AHRS->_q0 += qDot1 * AHRS->_sampleRate;
    AHRS->_q1 += qDot2 * AHRS->_sampleRate;
    AHRS->_q2 += qDot3 * AHRS->_sampleRate;
    AHRS->_q3 += qDot4 * AHRS->_sampleRate;

    // <---- ------------ Normalise quaternion ------------ ---->
    recipNorm = oneOverSqrt(AHRS->_q0 * AHRS->_q0 + AHRS->_q1 * AHRS->_q1 + AHRS->_q2 * AHRS->_q2 + AHRS->_q3 * AHRS->_q3);
    AHRS->_q0 *= recipNorm;
    AHRS->_q1 *= recipNorm;
    AHRS->_q2 *= recipNorm;
    AHRS->_q3 *= recipNorm;

    // <---- ------------ Calculate new angles ------------ ---->
    calculateAngles(AHRS);
}

