#include <stdio.h>
#include <stdint.h>

int PORTA = 0bxxxxxxxx;    

void digitalWrite(uint8_t pin, uint8_t status)
{
    if (status == 1)
    {
        PORTA = PORTA|1 << (7 - pin);
    }
    else if (status == 0)
    {
        PORTA &= ~ (1 << (7 - pin));
    }
}

int main(int argc, char const *argv[])
{
    digitalWrite(3,0);
    return 0;
}
