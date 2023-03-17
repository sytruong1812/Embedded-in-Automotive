#include "stdio.h"

int main(int argc, char const *argv[])
{
    int a = 10;
    int *ptr = &a;
    int **p_ptr = &ptr;

    printf("Dia chi cua a: %p\n", &a);          //Giá trị của biến a = 10, địa chỉ của biến a = 0000ffff
    printf("Gia tri cua ptr: %p\n", ptr);       //Giá trị của con trỏ ptr lưu địa chỉ của biến a = 0000ffff
    printf("Gia tri cua p_ptr: %p\n", p_ptr);   //Giá trị của con trỏ p_ptr lưu địa chỉ của con trỏ ptr

    return 0;
}
