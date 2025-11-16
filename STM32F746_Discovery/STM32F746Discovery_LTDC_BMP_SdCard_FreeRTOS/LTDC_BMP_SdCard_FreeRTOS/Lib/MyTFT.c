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
void TFT_DrawBitmap(uint16_t x, uint16_t y, const uint16_t *pBitmap)
{
	uint16_t xpos, ypos;
	uint16_t width = 480;
	uint16_t height = 272;

	for (ypos = 0; ypos < height; ypos++)
	{
		for (xpos = 0; xpos < width; xpos++)
		{
			// Calculate the framebuffer address
			*(__IO uint16_t*)(hltdc.LayerCfg[0].FBStartAdress + (2 * ((y + ypos) * hltdc.LayerCfg[0].ImageWidth + (x + xpos)))) = pBitmap[ypos * width + xpos];
		}
	}
}
// <---- --------------------------------------- ---->
