#include <stdio.h>
#include <stdint.h>

//uint8_t bien = 255;     //1byte = 8 bit = 2^8 = 256  (0 - 255)
//uint16_t bien = 65535;     //1byte = 16 bit = 2^16 = 65536  (0 - 65535)

//int8_t bien = 127;           //1byte = 8 bit = 2^8 = 256 (-128 - 127)
int16_t bien = -32768;     //1byte = 16 bit = 2^16 = 65536  (-32768 - 32767)

//Định nghĩ 1 biết mới
//typedef int bienmoi;
//bienmoi bien = 10;

float x = -12.11;
float y = 36.1;

int main(int argc, char const *argv[])
{
    printf("Bien: %d\n", bien);
    printf("%8.4f", x + y);     // %[fw][.pp]f : Độ rộng thực tế fw = 8, độ chính xác pp = 4
    return 0;
}
