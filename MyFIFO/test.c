#include "MyFIFO.h"

int main()
{
    FIFO_Buffer fifo;
    uint16_t highWatermark = 8;
    uint16_t lowWatermark = 2;
    bool overwrite_enable = true;
    bool useBuffer = true; // Use buffer mode

    FIFO_Init(&fifo, highWatermark, lowWatermark, overwrite_enable, useBuffer);

    // Example 1: Add a buffer of data
    uint8_t input_buffer[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t input_size = sizeof(input_buffer) / sizeof(input_buffer[0]);

    if(FIFO_Push(&fifo, input_buffer, input_size))
    {
        printf("Pushed buffer of size: %zu\n", input_size);
    }
    else
    {
        printf("Failed to push buffer (FIFO overflow)\n");
    }

    // Pop all elements from the FIFO
    uint8_t value;
    printf("\nPopping elements from FIFO (buffer mode):\n");

    while(!FIFO_IsEmpty(&fifo))
    {
        if (FIFO_Pop(&fifo, &value))
        {
            printf("Popped: %d\n", value);
        }
    }

    FIFO_DebugPrint(&fifo);

    // Example 2: Switch to single byte mode and push bytes
    useBuffer = false;
    FIFO_Init(&fifo, highWatermark, lowWatermark, overwrite_enable, useBuffer);

    printf("\nPushing single bytes to FIFO:\n");
    for(size_t i = 1; i <= 5; i++)
    {
        uint8_t data = (uint8_t)i;
        if(FIFO_Push(&fifo, &data, 1))
        {
            printf("Pushed: %d\n", data);
        }
        else
        {
            printf("Failed to push: %d (FIFO is full)\n", data);
        }
    }

    printf("\nPopping elements from FIFO (single byte mode):\n");
    while(!FIFO_IsEmpty(&fifo))
    {
        if(FIFO_Pop(&fifo, &value))
        {
            printf("Popped: %d\n", value);
        }
    }

    FIFO_DebugPrint(&fifo);

    return 0;
}
