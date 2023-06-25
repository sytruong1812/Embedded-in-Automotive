#include "stdio.h"
#include "stdint.h"

struct data
{
    uint32_t C;     //4byte     4byte          0byte
    uint8_t A;      //1byte     4-1 = 3byte    0byte
    uint16_t B;     //2byte     3-2 = 1byte    1byte -> byte đệm
};

int main(int argc, char const *argv[])
{
    printf("Size: %d\n", sizeof(struct data));
    return 0;
}
