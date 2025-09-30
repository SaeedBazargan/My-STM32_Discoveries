#include "SDCard_Configuration.h"

//<---- --------------- Bitmap Variables --------------- ---->
#define BMP_HEADER_SIZE 		54 // Standard BMP header size
#define LCD_WIDTH 				480
#define LCD_HEIGHT 				272
uint16_t imageBuf[LCD_WIDTH * LCD_HEIGHT]; // Static buffer to hold image data

//<---- --------------- SdCard Variables --------------- ---->
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
	fresult = f_mount(&fs, path, 0);
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

void Check_SD_Space(void)
{
	uint32_t total, free_space;

    f_getfree("", &fre_clust, &pfs);						// Check free space

    total = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5);
    printf("SD_CARD Total Size: \t%lu\n", total);

    free_space = (uint32_t)(fre_clust * pfs->csize * 0.5);
    printf("SD_CARD Free Space: \t%lu\n", free_space);
}
//<---- -------------------------------------------------------- ---->

uint16_t* Read_Bitmap(char *filename)
{
	uint8_t bmpHeader[BMP_HEADER_SIZE];
	uint8_t bmpPixelData[3]; // BMP stores 24-bit (B, G, R)

	Mount_SD(SDPath);
	// Open BMP file
	fresult = f_open(&fil, filename, FA_READ);
	if(fresult != FR_OK)
	{
		printf("Error opening BMP file! Code: %d\n", fresult);
		return NULL;
	}

	// Read the BMP header
	f_read(&fil, bmpHeader, BMP_HEADER_SIZE, &br);

	// Verify BMP signature ('BM' = 0x42 0x4D)
	if(bmpHeader[0] != 'B' || bmpHeader[1] != 'M')
	{
		printf("Error: Not a valid BMP file!\n");
		f_close(&fil);

		return NULL;
	}

    // BMP stores pixels bottom-up, so we read in reverse order
    for(uint16_t y = LCD_HEIGHT - 1; y >= 0; y--)
    {
        for(uint16_t x = 0; x < LCD_WIDTH; x++)
        {
            // Read 24-bit pixel (B, G, R)
            f_read(&fil, bmpPixelData, 3, &br);

            // Convert 24-bit RGB888 to 16-bit RGB565
            uint16_t r = (bmpPixelData[2] >> 3) & 0x1F; // Red   (5 bits)
            uint16_t g = (bmpPixelData[1] >> 2) & 0x3F; // Green (6 bits)
            uint16_t b = (bmpPixelData[0] >> 3) & 0x1F; // Blue  (5 bits)

            // Merge into RGB565 format
            imageBuf[y * LCD_WIDTH + x] = (r << 11) | (g << 5) | b;
        }
    }
    // Close the file
    f_close(&fil);

    // Return pointer to the buffer
    return imageBuf;
}
//<---- -------------------------------------------------------- ---->
