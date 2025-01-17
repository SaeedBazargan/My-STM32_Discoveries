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
//<---- -------------------------------------------------------- ---->

FRESULT Update_File(char *name, char *data)
{
	fresult = f_stat(name, &fno);
	printf("Fresult in File Status => %d \n", fresult);

	if(fresult == FR_OK)
	{
		fresult = f_open(&fil, name, (FA_OPEN_APPEND | FA_WRITE));
		if(fresult != FR_OK)
		{
			printf("Error! No. %d in opening file *%s*\n\n", fresult, name);
			return fresult;
		}

		fresult = f_write(&fil, data, strlen (data), &bw);					// Writing text
		printf("Fresult in Write File => %d \n", fresult);

		if(fresult == FR_OK)
			printf("*%s* UPDATED successfully\n", name);
		else
			printf("Error! No. %d in writing file *%s*\n\n", fresult, name);

		fresult = f_close(&fil);											// Close file
		printf("Fresult in Closing File => %d \n", fresult);

		if(fresult == FR_OK)
			printf("File *%s* CLOSED successfully\n", name);
		else
			printf("Error! No. %d in closing file *%s*\n\n", fresult, name);
	}
	else
	{
		printf("Error! *%s* does not exists\n\n", name);
	    return fresult;
	}
    return fresult;
}
//<---- -------------------------------------------------------- ---->

FRESULT Write_File(char *name, char *data)
{
	fresult = f_stat(name, &fno);
	printf("Fresult in File Status => %d \n", fresult);

	if(fresult == FR_OK)
	{
	    fresult = f_open(&fil, name, (FA_OPEN_EXISTING | FA_WRITE));
	    printf("Fresult in Opening File => %d \n", fresult);

	    if(fresult == FR_OK)
	    {
	    	fresult = f_write(&fil, data, strlen(data), &bw);
	    	printf("Fresult in Write File => %d \n", fresult);

	    	if(fresult != FR_OK)
	    		printf("Error! No. %d while writing to the FILE *%s*\n\n", fresult, name);

	    	fresult = f_close(&fil);
	    	if(fresult == FR_OK)
	    		printf("File *%s* is WRITTEN and CLOSED successfully\n", name);
	    	else
	    		printf("Error! No. %d in closing file *%s* after writing it\n\n", fresult, name);
	    }
	    else
	    {
	    	printf("Error! No. %d in opening file *%s*\n\n", fresult, name);
	        return fresult;
	    }
	    return fresult;
	}
	else
	{
		printf("Error! *%s* does not exists\n\n", name);
	    return fresult;
	}
}
//<---- -------------------------------------------------------- ---->

FRESULT Read_File(char *name)
{
	fresult = f_stat(name, &fno);
	printf("Fresult in File Status => %d \n", fresult);

	if(fresult == FR_OK)
	{
		fresult = f_open(&fil, name, FA_READ);
		printf("Fresult in Opening File => %d \n", fresult);

		if(fresult != FR_OK)
		{
			printf("Error! No. %d in opening file *%s*\n\n", fresult, name);
		    return fresult;
		}

		char *buffer = malloc(sizeof(f_size(&fil)));
		fresult = f_read(&fil, buffer, f_size(&fil), &br);
		printf("Fresult in Reading File => %d \n", fresult);

		if(fresult == FR_OK)
		{
			printf("buffer ----> %s \n", buffer);
			free(buffer);

			fresult = f_close(&fil);
			if(fresult == FR_OK)
				printf("File *%s* CLOSED successfully\n", name);
			else
				printf("Error! No. %d in closing file *%s*\n\n", fresult, name);
		}
		else
		{
		 	printf("Error! No. %d in reading file *%s*\n\n", fresult, name);
			free(buffer);
		}
	    return fresult;
	}
	else
	{
		printf("Error! *%s* does not exists\n\n", name);
	    return fresult;
	}
}
//<---- -------------------------------------------------------- ---->

FRESULT Remove_File(char *name)
{
	fresult = f_stat(name, &fno);
	printf("Fresult in File Status => %d \n", fresult);

	if(fresult == FR_OK)
	{
		fresult = f_unlink(name);
		printf("Fresult in Delete a File/Directory => %d \n", fresult);

		if(fresult == FR_OK)
			printf("*%s* has been removed successfully\n", name);
		else
			printf("Error! No. %d in removing *%s*\n\n", fresult, name);
	}
	else
	{
		printf("Error! *%s* does not exists\n\n", name);
		return fresult;
	}
	return fresult;
}
//<---- -------------------------------------------------------- ---->

FRESULT Create_Dir(char *name)
{
    fresult = f_mkdir(name);
    printf("Fresult in Create a Directory => %d \n", fresult);

    if(fresult == FR_OK)
    	printf("*%s* has been created successfully\n", name);
    else
    	printf("Error! No. %d in creating directory *%s*\n\n", fresult, name);

    return fresult;
}
//<---- -------------------------------------------------------- ---->

void Check_SD_Space (void)
{
	uint32_t total, free_space;

    f_getfree("", &fre_clust, &pfs);						// Check free space

    total = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5);
    printf("SD_CARD Total Size: \t%lu\n", total);

    free_space = (uint32_t)(fre_clust * pfs->csize * 0.5);
    printf("SD_CARD Free Space: \t%lu\n", free_space);
}
