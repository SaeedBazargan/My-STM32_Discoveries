/**
  ******************************************************************************
  * @file    imu_model.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Apr  9 15:08:46 2025
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "imu_model.h"
#include "imu_model_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_imu_model
 
#undef AI_IMU_MODEL_MODEL_SIGNATURE
#define AI_IMU_MODEL_MODEL_SIGNATURE     "0x73e07121eeb8a43a44847a91caa8461e"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Apr  9 15:08:46 2025"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_IMU_MODEL_N_BATCHES
#define AI_IMU_MODEL_N_BATCHES         (1)

static ai_ptr g_imu_model_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_imu_model_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_input0_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  gemm_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  gemm_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  nl_3_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  gemm_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  gemm_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  gemm_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  gemm_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 48, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 3, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  gemm_0_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 162, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  gemm_1_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 112, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 31, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  nl_3_scratch0_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 3, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_2_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 3,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008960895240306854f, 0.00806473009288311f, 0.008439013734459877f),
    AI_PACK_INTQ_ZP(0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_input0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02336728386580944f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008410290814936161f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_1_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03419047221541405f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_2_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11729957908391953f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0021223786752671003f, 0.005311071872711182f, 0.0031289367470890284f, 0.004221123177558184f, 0.0022277680691331625f, 0.0025212315376847982f, 0.002762004965916276f, 0.0042889853939414024f, 0.0032706221099942923f, 0.005562551319599152f, 0.002758047776296735f, 0.003895107889547944f, 0.0037788471672683954f, 0.004852371755987406f, 0.0023320976179093122f, 0.0021779057569801807f, 0.003001832403242588f, 0.002833571285009384f, 0.003937471657991409f, 0.0020274552516639233f, 0.005610899534076452f, 0.0025817272253334522f, 0.0037440499290823936f, 0.004088812507688999f, 0.0020580613054335117f, 0.002302818698808551f, 0.0011285367654636502f, 0.0027346170973032713f, 0.004246722906827927f, 0.0029278278816491365f, 0.004620809573680162f, 0.003556832205504179f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_1_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005750870332121849f, 0.005249306093901396f, 0.002758019370958209f, 0.004484017379581928f, 0.006033169571310282f, 0.0053169140592217445f, 0.004887342918664217f, 0.00605071522295475f, 0.004920177161693573f, 0.004294455982744694f, 0.005257429555058479f, 0.005779560189694166f, 0.004687379579991102f, 0.007920180447399616f, 0.004965027794241905f, 0.006138650234788656f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  nl_3_scratch0, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &nl_3_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  gemm_1_bias, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &gemm_1_bias_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_weights, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 1, 1), AI_STRIDE_INIT(4, 1, 16, 48, 48),
  1, &gemm_2_weights_array, &gemm_2_weights_array_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_bias, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &gemm_2_bias_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  gemm_0_scratch0, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 162, 1, 1), AI_STRIDE_INIT(4, 2, 2, 324, 324),
  1, &gemm_0_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_input0_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &serving_default_input0_output_array, &serving_default_input0_output_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  gemm_0_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &gemm_0_output_array, &gemm_0_output_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  gemm_1_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &gemm_1_output_array, &gemm_1_output_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  gemm_1_scratch0, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 2, 2, 224, 224),
  1, &gemm_1_scratch0_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3, 3),
  1, &gemm_2_output_array, &gemm_2_output_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  nl_3_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3, 3),
  1, &nl_3_output_array, &nl_3_output_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  gemm_0_weights, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 2, 32, 1, 1), AI_STRIDE_INIT(4, 1, 2, 64, 64),
  1, &gemm_0_weights_array, &gemm_0_weights_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_scratch0, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 31, 1, 1), AI_STRIDE_INIT(4, 2, 2, 62, 62),
  1, &gemm_2_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  gemm_0_bias, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &gemm_0_bias_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  gemm_1_weights, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 32, 16, 1, 1), AI_STRIDE_INIT(4, 1, 32, 512, 512),
  1, &gemm_1_weights_array, &gemm_1_weights_array_intq)



/**  Layer declarations section  **********************************************/



AI_STATIC_CONST ai_i32 nl_3_nl_params_data[] = { 2015191424, 23, -248 };
AI_ARRAY_OBJ_DECLARE(
    nl_3_nl_params, AI_ARRAY_FORMAT_S32,
    nl_3_nl_params_data, nl_3_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  nl_3_layer, 3,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm_integer,
  &nl_3_chain,
  NULL, &nl_3_layer, AI_STATIC, 
  .nl_params = &nl_3_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_2_weights, &gemm_2_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_2_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &gemm_2_chain,
  NULL, &nl_3_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_1_weights, &gemm_1_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_1_layer, 1,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &gemm_1_chain,
  NULL, &gemm_2_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_0_weights, &gemm_0_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_0_layer, 0,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &gemm_0_chain,
  NULL, &gemm_1_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 828, 1, 1),
    828, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 360, 1, 1),
    360, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_IMU_MODEL_IN_NUM, &serving_default_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_IMU_MODEL_OUT_NUM, &nl_3_output),
  &gemm_0_layer, 0x9e64fc93, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 828, 1, 1),
      828, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 360, 1, 1),
      360, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_IMU_MODEL_IN_NUM, &serving_default_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_IMU_MODEL_OUT_NUM, &nl_3_output),
  &gemm_0_layer, 0x9e64fc93, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool imu_model_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_imu_model_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_input0_output_array.data = AI_PTR(g_imu_model_activations_map[0] + 356);
    serving_default_input0_output_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 356);
    gemm_0_scratch0_array.data = AI_PTR(g_imu_model_activations_map[0] + 32);
    gemm_0_scratch0_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 32);
    gemm_0_output_array.data = AI_PTR(g_imu_model_activations_map[0] + 0);
    gemm_0_output_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 0);
    gemm_1_scratch0_array.data = AI_PTR(g_imu_model_activations_map[0] + 32);
    gemm_1_scratch0_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 32);
    gemm_1_output_array.data = AI_PTR(g_imu_model_activations_map[0] + 256);
    gemm_1_output_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 256);
    gemm_2_scratch0_array.data = AI_PTR(g_imu_model_activations_map[0] + 0);
    gemm_2_scratch0_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 0);
    gemm_2_output_array.data = AI_PTR(g_imu_model_activations_map[0] + 64);
    gemm_2_output_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 64);
    nl_3_scratch0_array.data = AI_PTR(g_imu_model_activations_map[0] + 0);
    nl_3_scratch0_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 0);
    nl_3_output_array.data = AI_PTR(g_imu_model_activations_map[0] + 12);
    nl_3_output_array.data_start = AI_PTR(g_imu_model_activations_map[0] + 12);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool imu_model_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_imu_model_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    gemm_0_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_0_weights_array.data = AI_PTR(g_imu_model_weights_map[0] + 0);
    gemm_0_weights_array.data_start = AI_PTR(g_imu_model_weights_map[0] + 0);
    gemm_0_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_0_bias_array.data = AI_PTR(g_imu_model_weights_map[0] + 64);
    gemm_0_bias_array.data_start = AI_PTR(g_imu_model_weights_map[0] + 64);
    gemm_1_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_1_weights_array.data = AI_PTR(g_imu_model_weights_map[0] + 192);
    gemm_1_weights_array.data_start = AI_PTR(g_imu_model_weights_map[0] + 192);
    gemm_1_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_1_bias_array.data = AI_PTR(g_imu_model_weights_map[0] + 704);
    gemm_1_bias_array.data_start = AI_PTR(g_imu_model_weights_map[0] + 704);
    gemm_2_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_2_weights_array.data = AI_PTR(g_imu_model_weights_map[0] + 768);
    gemm_2_weights_array.data_start = AI_PTR(g_imu_model_weights_map[0] + 768);
    gemm_2_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_2_bias_array.data = AI_PTR(g_imu_model_weights_map[0] + 816);
    gemm_2_bias_array.data_start = AI_PTR(g_imu_model_weights_map[0] + 816);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_imu_model_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_IMU_MODEL_MODEL_NAME,
      .model_signature   = AI_IMU_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 720,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x9e64fc93,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_imu_model_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_IMU_MODEL_MODEL_NAME,
      .model_signature   = AI_IMU_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 720,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x9e64fc93,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_imu_model_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_imu_model_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_imu_model_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_imu_model_create(network, AI_IMU_MODEL_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_imu_model_data_params_get(&params) != true) {
    err = ai_imu_model_get_error(*network);
    return err;
  }
#if defined(AI_IMU_MODEL_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_IMU_MODEL_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_imu_model_init(*network, &params) != true) {
    err = ai_imu_model_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_imu_model_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_imu_model_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_imu_model_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_imu_model_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= imu_model_configure_weights(net_ctx, params);
  ok &= imu_model_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_imu_model_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_imu_model_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_IMU_MODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

