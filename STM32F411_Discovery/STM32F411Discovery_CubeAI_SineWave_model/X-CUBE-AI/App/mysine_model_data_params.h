/**
  ******************************************************************************
  * @file    mysine_model_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Mar 22 21:36:50 2025
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

#ifndef MYSINE_MODEL_DATA_PARAMS_H
#define MYSINE_MODEL_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_MYSINE_MODEL_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_mysine_model_data_weights_params[1]))
*/

#define AI_MYSINE_MODEL_DATA_CONFIG               (NULL)


#define AI_MYSINE_MODEL_DATA_ACTIVATIONS_SIZES \
  { 128, }
#define AI_MYSINE_MODEL_DATA_ACTIVATIONS_SIZE     (128)
#define AI_MYSINE_MODEL_DATA_ACTIVATIONS_COUNT    (1)
#define AI_MYSINE_MODEL_DATA_ACTIVATION_1_SIZE    (128)



#define AI_MYSINE_MODEL_DATA_WEIGHTS_SIZES \
  { 1284, }
#define AI_MYSINE_MODEL_DATA_WEIGHTS_SIZE         (1284)
#define AI_MYSINE_MODEL_DATA_WEIGHTS_COUNT        (1)
#define AI_MYSINE_MODEL_DATA_WEIGHT_1_SIZE        (1284)



#define AI_MYSINE_MODEL_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_mysine_model_activations_table[1])

extern ai_handle g_mysine_model_activations_table[1 + 2];



#define AI_MYSINE_MODEL_DATA_WEIGHTS_TABLE_GET() \
  (&g_mysine_model_weights_table[1])

extern ai_handle g_mysine_model_weights_table[1 + 2];


#endif    /* MYSINE_MODEL_DATA_PARAMS_H */
