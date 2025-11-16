#include "MyTFT.h"
#include "ltdc.h"

void TFT_FillScreen(uint32_t color)
{
	uint32_t n = hltdc.LayerCfg[0].ImageHeight * hltdc.LayerCfg[0].ImageWidth;

	for(uint32_t i = 0; i < n; i++)
	{
		*(__IO uint16_t*)(hltdc.LayerCfg[0].FBStartAdress + (i*2)) = (uint16_t)color;
	}
}
// <---- ------------------------------------- ---->
void TFT_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	if(x1 > x2)
	{
		swap(x1, x2);
	}
	if(y1 > y2)
	{
		swap(y1, y2);
	}

	for(uint32_t ypos = y1; ypos <= y2; ypos++)
	{
		for(uint32_t xpos = x1; xpos <= x2; xpos++)
		{
			*(__IO uint16_t*)(hltdc.LayerCfg[0].FBStartAdress + (2 * (ypos * hltdc.LayerCfg[0].ImageWidth + xpos))) = (uint16_t)color;
		}
	}
}
// <---- ------------------------------------- ---->
void TFT_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint32_t color)
{
	*(__IO uint16_t*)(hltdc.LayerCfg[0].FBStartAdress + (2 * (Ypos * hltdc.LayerCfg[0].ImageWidth + Xpos))) = (uint16_t)color;
}
// <---- ------------------------------------- ---->
void TFT_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	int steep = abs(y2 - y1) > abs(x2 - x1);

	if(steep)
	{
		swap(x1, y1);
		swap(x2, y2);
	}
	if(x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	int dx, dy;
	dx = x2 - x1;
	dy = abs(y2 - y1);

	int err = dx / 2;
	int ystep;

	if(y1 < y2)
	{
		ystep = 1;
	}
	else
	{
		ystep = -1;
	}

	for(; x1 <= x2; x1++)
	{
		if(steep)
		{
			TFT_DrawPixel(y1, x1, color);
		}
		else
		{
			TFT_DrawPixel(x1, y1, color);
		}

		err -= dy;
		if(err < 0)
		{
			y1 += ystep;
			err = dx;
		}
	}
}
// <---- --------------------------------------- ---->
void TFT_DrawBitmap(uint32_t Xpos, uint32_t Ypos, uint8_t *pbmp)
{
	uint32_t index = 0, ix = 0, width = 0, height = 0, bit_pixel = 0;
	uint32_t address;

	/* Get bitmap data addres offset*/
	index = *(__IO uint16_t *)(pbmp + 10);
	index |= (*(__IO uint16_t *)(pbmp + 12)) << 16;

	/* Read bitmap width */
	width = *(__IO uint16_t *)(pbmp + 18);
	width |= (*(__IO uint16_t *)(pbmp + 20)) << 16;

	/* Read bitmap height */
	height = *(__IO uint16_t *)(pbmp + 22);
	height |= (*(__IO uint16_t *)(pbmp + 24)) << 16;

	/* Read bit/pixel */
	bit_pixel = *(__IO uint16_t *)(pbmp + 28);

	/* Set the addres*/
	address = hltdc.LayerCfg[0].FBStartAdress + (((X_SIZE * Ypos) + Xpos) * 4);

	/* Bypass the bitmap header */
	pbmp += (index + (width * (height - 1) * (bit_pixel / 8)));

	if((bit_pixel / 8) == 4)
	{
		TFT_FillScreen(0xFFFF0000);
	}
	else if((bit_pixel / 8) == 2)
	{
		TFT_FillScreen(0xFF00FF00);
	}
	else
	{
		/* Convert picture to ARGB8888 pixel format */
		for(index = 0; index < height; index++)
		{
			for(ix = 0; ix < width; ix++)
			{
				*(uint32_t *)(address + (ix * 4)) = convert24to32(*(uint32_t*)(pbmp + (ix * 3)));
			}
			address += X_SIZE * 4;
			pbmp -= width * (bit_pixel / 8);
		}
	}
	bit_pixel = 0;
}
// <---- --------------------------------------- ---->
