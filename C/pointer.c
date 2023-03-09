#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{   
    // Con trỏ với Biến (Variables)
    int a = 2;
    int *ptr = &a;

    printf("Dia chi cua bien: %p\n", ptr);
    printf("Gia chi cua bien: %d\n", *ptr);

    // Con trỏ với Mảng (Array)
    uint8_t arr[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    uint8_t *p = arr;

    printf("Dia chi cua mang: %p\n", p);
    printf("Dia chi cua mang: %p\n", p + 1);
    printf("Dia chi cua mang: %p\n", p + 2);

    printf("Gia tri cua mang: %d\n", *p);
    printf("Gia tri cua mang: %d\n", *(p + 1));
    printf("Gia tri cua mang: %d\n", *(p + 2));


    return 0;
}
