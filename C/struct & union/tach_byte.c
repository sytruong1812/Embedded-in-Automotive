#include "stdio.h"

/*Tách từng byte của 1 biến bằng union và struct*/

typedef struct
{
    char byte1;
    char byte2;
    char byte3;
    char byte4;
} Apart;

typedef union
{
    float data4byte;
    Apart;
} Processing;

Processing data;

int main(int argc, char const *argv[])
{
    data.data4byte = 26.04;
    printf("Processing: byte1 = %d, byte2 = %d, byte3 = %d, byte4 = %d\n", data.byte1, data.byte2, data.byte3, data.byte4);
    return 0;
}
