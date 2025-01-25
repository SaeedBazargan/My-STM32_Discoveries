#ifndef __HAL_MyFIFO__
#define __HAL_MyFIFO__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
//<---- -------------------------------------------------------- ---->

#define FIFO_SIZE 10
//<---- -------------------------------------------------------- ---->

typedef struct
{
    uint8_t buffer[FIFO_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t count;
    uint16_t highWatermark;
    uint16_t lowWatermark;
    bool overwrite_enable;
    bool useBuffer;
}FIFO_Buffer;
//<---- -------------------------------------------------------- ---->

void FIFO_Init(FIFO_Buffer *fifo, uint16_t highWatermark, uint16_t lowWatermark, bool overwrite_enable, bool useBuffer);
bool FIFO_Push(FIFO_Buffer *fifo, uint8_t *data, size_t length);
bool FIFO_Pop(FIFO_Buffer *fifo, uint8_t *data);
bool FIFO_IsEmpty(FIFO_Buffer *fifo);
bool FIFO_IsFull(FIFO_Buffer *fifo);
void FIFO_Reset(FIFO_Buffer *fifo);
void FIFO_DebugPrint(FIFO_Buffer *fifo);

#endif /* __HAL_MyFIFO__ */