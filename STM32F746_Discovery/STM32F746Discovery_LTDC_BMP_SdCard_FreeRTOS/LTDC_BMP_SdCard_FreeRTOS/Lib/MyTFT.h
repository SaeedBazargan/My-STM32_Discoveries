#ifndef __HAL_TFT_LIB_H__
#define __HAL_TFT_LIB_H__

#include "string.h"
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

#define swap(a, b)          {int16_t t = a; a = b; b = t;}
#define convert24to32(x)	(x | 0xFF000000)

#define X_SIZE 				480
#define Y_SIZE 				272

//<---- --------------- Functions --------------- ---->
void TFT_FillScreen(uint32_t color);
void TFT_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void TFT_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint32_t color);
void TFT_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void TFT_DrawBitmap(uint16_t x, uint16_t y, const uint16_t *pBitmap);

#endif /* __HAL_TFT_LIB_H__ */
