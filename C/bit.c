#include <stdio.h>
#include <stdint.h>

int PORTA = 0b00010010;     //0-7 từ trái qua phải

void digitalWrite(uint8_t pin, uint8_t status)
{
    if (status == 1)
    {
        PORTA |= 0b010000000 >> pin;
    }
    else if (status == 0)
    {
        PORTA &= ~(0b10000000 >> pin);
    }
}

int main(int argc, char const *argv[])
{
    digitalWrite(3,0);
    return 0;
}
