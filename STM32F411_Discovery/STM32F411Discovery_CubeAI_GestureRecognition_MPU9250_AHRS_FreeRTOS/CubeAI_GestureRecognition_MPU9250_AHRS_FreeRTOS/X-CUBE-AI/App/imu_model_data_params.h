/**
  ******************************************************************************
  * @file    imu_model_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Apr  9 15:08:46 2025
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef IMU_MODEL_DATA_PARAMS_H
#define IMU_MODEL_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_IMU_MODEL_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_imu_model_data_weights_params[1]))
*/

#define AI_IMU_MODEL_DATA_CONFIG               (NULL)


#define AI_IMU_MODEL_DATA_ACTIVATIONS_SIZES \
  { 360, }
#define AI_IMU_MODEL_DATA_ACTIVATIONS_SIZE     (360)
#define AI_IMU_MODEL_DATA_ACTIVATIONS_COUNT    (1)
#define AI_IMU_MODEL_DATA_ACTIVATION_1_SIZE    (360)



#define AI_IMU_MODEL_DATA_WEIGHTS_SIZES \
  { 828, }
#define AI_IMU_MODEL_DATA_WEIGHTS_SIZE         (828)
#define AI_IMU_MODEL_DATA_WEIGHTS_COUNT        (1)
#define AI_IMU_MODEL_DATA_WEIGHT_1_SIZE        (828)



#define AI_IMU_MODEL_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_imu_model_activations_table[1])

extern ai_handle g_imu_model_activations_table[1 + 2];



#define AI_IMU_MODEL_DATA_WEIGHTS_TABLE_GET() \
  (&g_imu_model_weights_table[1])

extern ai_handle g_imu_model_weights_table[1 + 2];


#endif    /* IMU_MODEL_DATA_PARAMS_H */
