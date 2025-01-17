#include "SDCard_Configuration.h"
#include "stm32f7xx_hal.h"

//<---- --------------- Variables --------------- ---->
FATFS fs;  				// file system
FIL fil; 				// File
FILINFO fno;			// File Info
FRESULT fresult;  		// Result
UINT br, bw;  			// File read/write count

//<---- --------------- Capacity Variables --------------- ---->
FATFS *pfs;
DWORD fre_clust;
uint32_t total, free_space;

//<---- --------------- Functions --------------- ---->
void Mount_SD(const TCHAR* path)
{
	fresult = f_mount(&fs, path, 1);
	printf("Fresult in Mounting => %d \n", fresult);

	if(fresult == FR_OK)
		printf("SD_CARD mounted successfully...\n");
	else
	{
		printf("Error! in mounting SD_CARD...\n");
		Error_Handler();
	}
}

//<---- -------------------------------------------------------- ---->
void Unmount_SD(const TCHAR* path)
{
	fresult = f_mount(NULL, path, 1);
	printf("Fresult in Unmounting => %d \n", fresult);

	if(fresult == FR_OK)
		printf("SD_CARD unmounted successfully...\n");
	else
	{
		printf("Error! in unmounting SD_CARD...\n");
		Error_Handler();
	}
}
//<---- -------------------------------------------------------- ---->

FRESULT Format_SD(void)
{
    DIR dir;
    char *path = malloc(20 * sizeof(char));
    sprintf(path, "%s", "/");

    fresult = f_opendir(&dir, path);							// Open the directory
    printf("Fresult in Opening Directory => %d \n", fresult);

    if(fresult == FR_OK)
    {
        for(;;)
        {
            fresult = f_readdir(&dir, &fno);                   	// Read a directory item
            if(fresult != FR_OK || fno.fname[0] == 0)
            	break;  										// Break on error or end of dir

            if(fno.fattrib & AM_DIR)     						// It is a directory
            {
            	if(!(strcmp("SYSTEM~1", fno.fname)))
            		continue;

            	fresult = f_unlink(fno.fname);
            	if(fresult == FR_DENIED)
            		continue;
            }
            else
            {
               fresult = f_unlink(fno.fname);					// It is a file.
            }
        }
        f_closedir(&dir);
    }
    free(path);
    return fresult;
}
//<---- -------------------------------------------------------- ---->

FRESULT Create_File(char *name)
{
	fresult = f_stat(name, &fno);
	printf("Fresult in File Status => %d \n", fresult);

	if(fresult == FR_OK)
	{
		printf("Error! *%s* already exists!\n use Update_File Function \n", name);
	    return fresult;
	}
	else
	{
		fresult = f_open(&fil, name, (FA_CREATE_ALWAYS | FA_READ | FA_WRITE));
		if(fresult == FR_OK)
			printf("*%s* created successfully\n Now use Write_File to write data\n", name);
		else
		{
			printf("Error! No. %d in creating file *%s* \n", fresult, name);
		    return fresult;
		}

		fresult = f_close(&fil);
		if(fresult == FR_OK)
			printf("File *%s* Closed Successfully\n", name);
		else
			printf("Error! No. %d in closing file *%s* \n", fresult, name);
	}
    return fresult;
}

