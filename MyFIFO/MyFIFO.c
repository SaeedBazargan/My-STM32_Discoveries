#include "MyFIFO.h"
//<---- -------------------------------------------------------- ---->

#define ENTER_CRITICAL_SECTION() do { __disable_irq(); __NOP(); __NOP(); __NOP(); } while(0) // Disable interrupts with NOPs
#define EXIT_CRITICAL_SECTION() __enable_irq()  // Enable interrupts
//<---- -------------------------------------------------------- ---->

void FIFO_Init(FIFO_Buffer *fifo, uint16_t highWatermark, uint16_t lowWatermark, bool overwrite_enable, bool useBuffer)
{
    fifo->head = 0;
    fifo->tail = 0;
    fifo->count = 0;
    fifo->highWatermark = highWatermark;
    fifo->lowWatermark = lowWatermark;
    fifo->overwrite_enable = overwrite_enable;
    fifo->useBuffer = useBuffer;
}
//<---- -------------------------------------------------------- ---->

bool FIFO_Push(FIFO_Buffer *fifo, uint8_t *data, size_t length)
{
    ENTER_CRITICAL_SECTION();

    if(fifo->useBuffer)
    {
        // If using buffer mode, handle multiple bytes
        if(fifo->count + length > FIFO_SIZE)
        {
            if(!fifo->overwrite_enable)
            {
                EXIT_CRITICAL_SECTION();

                return false; // Not enough space and overwrite not allowed
            }

            // Overwrite logic: Move the tail to create enough space
            size_t space_available = FIFO_SIZE - fifo->count;
            size_t data_to_discard = length - space_available;
            fifo->tail = (fifo->tail + data_to_discard) % FIFO_SIZE;
            fifo->count = FIFO_SIZE; // After overwriting, FIFO is full
        }

        // Add the new elements
        for(size_t i = 0; i < length; i++)
        {
            fifo->buffer[fifo->head] = data[i];
            fifo->head = (fifo->head + 1) % FIFO_SIZE;
            fifo->count++;
        }

    }
    else
    {
        // If not using buffer, handle just one byte
        if(fifo->count == FIFO_SIZE)
        {
            if(!fifo->overwrite_enable)
            {
                EXIT_CRITICAL_SECTION();

                return false; // Cannot add, FIFO is full
            }

            fifo->tail = (fifo->tail + 1) % FIFO_SIZE; // Overwrite the oldest data
            fifo->count--;
        }

        // Add the new element (single byte)
        fifo->buffer[fifo->head] = *data;
        fifo->head = (fifo->head + 1) % FIFO_SIZE;
        fifo->count++;
    }

    // Check watermarks
    if(fifo->count >= fifo->highWatermark)
    {
        printf("High watermark reached: %u items in the FIFO.\n", fifo->count);
    }

    EXIT_CRITICAL_SECTION(); // End critical section

    return true;
}
//<---- -------------------------------------------------------- ---->

bool FIFO_Pop(FIFO_Buffer *fifo, uint8_t *data)     // Pop an element from the FIFO
{
    ENTER_CRITICAL_SECTION();

    // Check if the buffer is empty
    if(fifo->count == 0)
    {
        EXIT_CRITICAL_SECTION();

        return false; // Cannot remove, FIFO is empty
    }

    // Retrieve the element
    *data = fifo->buffer[fifo->tail];
    fifo->tail = (fifo->tail + 1) % FIFO_SIZE;
    fifo->count--;

    // Check watermarks
    if (fifo->count <= fifo->lowWatermark)
    {
        printf("Low watermark reached: %u items in the FIFO.\n", fifo->count);
    }

    EXIT_CRITICAL_SECTION();

    return true;
}
//<---- -------------------------------------------------------- ---->

bool FIFO_IsEmpty(FIFO_Buffer *fifo)    // Check if the FIFO is empty
{
    return(fifo->count == 0);
}
//<---- -------------------------------------------------------- ---->

bool FIFO_IsFull(FIFO_Buffer *fifo)     // Check if the FIFO is full
{
    return(fifo->count == FIFO_SIZE);
}
//<---- -------------------------------------------------------- ---->

void FIFO_Reset(FIFO_Buffer *fifo)      // Reset the FIFO
{
    ENTER_CRITICAL_SECTION();
    fifo->head = 0;
    fifo->tail = 0;
    fifo->count = 0;
    EXIT_CRITICAL_SECTION();
}
//<---- -------------------------------------------------------- ---->

void FIFO_DebugPrint(FIFO_Buffer *fifo)     // Debug print for FIFO state
{
    ENTER_CRITICAL_SECTION();
    printf("FIFO Debug Info:\n");
    printf("Size: %u, Count: %u, Head: %u, Tail: %u\n", FIFO_SIZE, fifo->count, fifo->head, fifo->tail);

    for(uint16_t i = 0; i < fifo->count; i++)
    {
        uint16_t index = (fifo->tail + i) % FIFO_SIZE;

        printf("Index %u: %02X\n", i, fifo->buffer[index]);
    }
    EXIT_CRITICAL_SECTION();
}
//<---- -------------------------------------------------------- ---->

