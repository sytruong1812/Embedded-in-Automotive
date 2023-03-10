#include <stdio.h>
#include <stdint.h>

union Data_union
{
    uint8_t u8bit;      //1byte
    uint16_t u16bit;    //2byte
    uint32_t u32bit;    //4byte
};


int main(int argc, char const *argv[])
{
    union Data_union data;
    printf("Size of Union: %d\n", sizeof(data));

    data.u8bit = 8;
    printf("u8bit = %d\n", data.u8bit);

    
    return 0;
}
