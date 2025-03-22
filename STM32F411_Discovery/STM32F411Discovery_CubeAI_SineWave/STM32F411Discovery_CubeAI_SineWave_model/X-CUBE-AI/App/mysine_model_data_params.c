/**
  ******************************************************************************
  * @file    mysine_model_data_params.c
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

#include "mysine_model_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_mysine_model_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_mysine_model_weights_array_u64[161] = {
  0x3b134b00be21c8feU, 0x3ec8c5a2bedd0b4eU, 0x3f0c4347bf132f91U, 0xbee4ebaabe96cc65U,
  0xbdfa2fe0bf0513e1U, 0x3ed7d0293f155cbfU, 0xbeae86a7bdd9ce8cU, 0x3ebb7067be876f66U,
  0xbc6b9d1f00000000U, 0x3e4830d600000000U, 0xbf74ebd500000000U, 0x0U,
  0x0U, 0x3e1b25edbf302b48U, 0x0U, 0xbf613dac00000000U,
  0x3ea1d25fbe6b7d99U, 0x3ec2e7ad3ed3bc81U, 0x3eb2e2b9bb327100U, 0x3df3ab34bdc0dc70U,
  0xbca171c03e746232U, 0x3de497623e0bbeffU, 0xbcce0980bd96c67cU, 0x3d7be90ebeb9519eU,
  0x3ea44461beb4a390U, 0x3dbef00fbe6f2040U, 0xbda02a16beb3fe6cU, 0x3ec4a5cdbe622de4U,
  0xbe59422e3e04c6eeU, 0xbdb63a21beac51faU, 0x3e1b30babc7118c0U, 0x3ec0143a3dc11a9cU,
  0x3b9e0880bea1fad6U, 0xbe43477a3dedadfcU, 0x3e0a33cf3d0f9448U, 0xbe40a786be6607a4U,
  0xbe39f848be9d52e7U, 0xbe92c23e3e642a8bU, 0x3c3e3c80be8912d9U, 0xbead2a9fbcc627e0U,
  0x3e6b5e0d3df43894U, 0x3e057f1cbdb16558U, 0x3ef629fb3ea7540dU, 0xbe269f6e3d136690U,
  0x3e3dff1a3e219d86U, 0xbc83c4a73eab6092U, 0x3ea0a9593e4cc23eU, 0x3eb2f58cbe7f321dU,
  0x3ea65abf3ec3367fU, 0xbc9aec103d2100a0U, 0x3e95f6533e8aca6dU, 0x3e49353e3e8bd9abU,
  0x3e8569a5be48ca4aU, 0xbe89a77bbe0b61aeU, 0x3e45137abe106b54U, 0xbecf57c03e2c7e26U,
  0xbe92ca1dbdc59f94U, 0x3e805685be5de572U, 0xbdf7d7b83d463fb0U, 0x3ed051093d9eba14U,
  0x3ed441bf3ed5522fU, 0xbe9d3041be2e9c7eU, 0xbe7b13223ea5952bU, 0x3c3874e03e2743caU,
  0xbe81db743e0823b6U, 0xbe449cef3e2b46d6U, 0xbe1fb084bea858d9U, 0x3e1e9222bdc41d54U,
  0xbed3a7d03e3804aaU, 0xbe60eccfbe0dfbfaU, 0x3e6d205ebe823150U, 0x3dcf80b4beb2afd0U,
  0xbe3f66583da2a5bcU, 0xbdde50173dd1f704U, 0xbdddca723d05fce0U, 0xbe971fd8beb1dfb9U,
  0xbed4590d3e885f53U, 0x3e7925f83ee16290U, 0xbea630293ea766ffU, 0xbdd63af5bebd7b99U,
  0xbdd785b83e5b951eU, 0x3e7686803d9e9f2cU, 0xbeb7c00b3eca0401U, 0x3eaead6f3e4af136U,
  0xbec4e3383e9a7495U, 0x3ce67e80bf4c48f2U, 0xbed279ecbdd89694U, 0xbdbb77fc3e645ab6U,
  0x3ebadddbbe517fedU, 0xbed92cd83e494356U, 0x3e6784a33c99add0U, 0xbeccfb52beae2c82U,
  0x3ca25ac0be80c784U, 0x3d2290903ef37babU, 0xbea478b53ed5984dU, 0x3d6959c43e767e42U,
  0xbe883e40bdd3a7e8U, 0x3e20fe263ed6609fU, 0xbdaaa9bcbe626b29U, 0x3ec54965be0fdb2aU,
  0x3e9d383fbe15605aU, 0xbeb5543c3e79df36U, 0xbdff28903e39c7aeU, 0xbecd7c82bec51d6fU,
  0x3d70008cbdcec944U, 0x3ec28fe33db2e6acU, 0x3edce0943e63b6faU, 0x3e0b52ca3ea71b73U,
  0xbde020ac3e9b4e17U, 0xbe219f5f3e7ab449U, 0x3eb732ff3e956235U, 0xbe964ec63e5d8066U,
  0x3e9b7183bd0ab918U, 0xbdf2c0e83ec2cbe1U, 0xbda190d4bea22cc8U, 0x3e9ad36dbe967488U,
  0xbe9f11e53bcd4f00U, 0xbe8649723e152756U, 0xbe25a26abed0cc6dU, 0x3e09894abcf02530U,
  0x3df20979ba86cd00U, 0x3cb48fdebea26a31U, 0x3eca91bbbeb10244U, 0xbe5fd4b53e3dada2U,
  0x3de71964bec6d915U, 0x3df2b734be5bb7a6U, 0x3c1e16a0bcec04e0U, 0x3e9fb238beb9e665U,
  0xbe39ea98beb99f3fU, 0x3efa19b53eca25e3U, 0xbf30e745beabb42cU, 0xbe80b7633e80d13bU,
  0xbe3fb2a8bddf6fbcU, 0x3f2275e7beb542c0U, 0xbe2f50023da23cccU, 0xbf8b5b643e67a8eeU,
  0x3e90c3a7be267c08U, 0xbe6bdf7c3e4d6b72U, 0xbe715b3b3e4191ceU, 0x3ea580bdbeb4da9cU,
  0xbe17d6cabed49949U, 0xbec9e751be40924eU, 0x3bf62cc03e9c81ddU, 0x3e7f0466be8eeab4U,
  0xbba47962bc8cbca7U, 0xbeee40d6bb463c64U, 0xbb4be3e200000000U, 0x3e0ad5c200000000U,
  0xbf26b4f9bd020f62U, 0x3e0325bf00000000U, 0xbef84c8300000000U, 0x3e517cbbU,
  0xbe524f74bea4cfd7U, 0x3ee02d1cbea7f170U, 0x3f0c95613dea64a8U, 0xbe5792d73e00bfa8U,
  0x3fa323e73f35cb1cU, 0xbe671de63e8c75f8U, 0x3ef00dcbbd84b150U, 0x3e5f72303fe689b8U,
  0xbf13e24fU,
};


ai_handle g_mysine_model_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_mysine_model_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

