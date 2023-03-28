#include "stdio.h"
#include "stdint.h"


unsigned short swap_bytes(unsigned short x) {
    unsigned short result;
    result = (x >> 8) | (x << 8);
    printf("%x", result);
    return result;
}

int main(int argc, char const *argv[])
{ 
    swap_bytes(12000);         // DEC: 1200  -> HEX: 2EE0: 0b0010 1110 1110 0000 
                              //  DEC: 57390 -> HEX: E02E: 0b1110 0000 0010 1110
    return 0;
}
