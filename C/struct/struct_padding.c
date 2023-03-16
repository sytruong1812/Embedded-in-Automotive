#include "stdio.h"
#include "stdint.h"

struct data
{
    uint32_t C;     //4byte     
    uint8_t A;      //1byte     
    uint16_t B;     //2byte     
    
};

int main(int argc, char const *argv[])
{
    printf("Size: %d\n", sizeof(struct data));
    return 0;
}
