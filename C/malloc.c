#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    uint8_t *data;
    data = (uint8_t *)malloc(5*sizeof(uint8_t));

    for (int i = 0; i < 5; i++)
    {
        data[i] = i*2;
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("i = %d\n", data[i]);
    }
    return 0;
}
