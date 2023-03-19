#include <stdio.h>
#include <stdint.h>

int PORTA = 0b00000000;   

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


    // Sử dụng phép toán AND để kiểm tra bit thứ 2 của biến num
    int num = 5;
    if (num & (1 << 2)) {
        printf("Bit 2 of num is set\n");
    }

    // Sử dụng phép toán SHIFT để tính toán số lần lặp trong vòng lặp for
    for (int i = 0; i < (1 << 10); i++) {
        // Thực hiện các thao tác trên bit
    }
    return 0;
}
