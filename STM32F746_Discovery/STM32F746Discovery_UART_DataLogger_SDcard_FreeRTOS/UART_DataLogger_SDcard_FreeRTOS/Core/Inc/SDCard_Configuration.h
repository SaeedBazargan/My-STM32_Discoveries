#ifndef __HAL_SDCARD_H__
#define __HAL_SDCARD_H__

#include "fatfs.h"
#include "string.h"
#include "stdio.h"

//<---- --------------- Functions --------------- ---->
void Mount_SD(const TCHAR* path);
void Unmount_SD(const TCHAR* path);
FRESULT Format_SD(void);
FRESULT Create_File(char *name);

#endif /* __HAL_SDCARD_H__ */
