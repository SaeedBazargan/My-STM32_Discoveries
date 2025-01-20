#ifndef __HAL_SDCARD_H__
#define __HAL_SDCARD_H__

#include "fatfs.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

//<---- --------------- Functions --------------- ---->
void Mount_SD(const TCHAR* path);
void Unmount_SD(const TCHAR* path);
FRESULT Format_SD(void);
FRESULT Create_File(char *name);
FRESULT Update_File(char *name, char *data);
FRESULT Write_File(char *name, char *data);
FRESULT Read_File(char *name);
FRESULT Remove_File(char *name);
FRESULT Create_Dir(char *name);
void Check_SD_Space(void);
#endif /* __HAL_SDCARD_H__ */
