#include "stdio.h"

void double_pointer(int **p_ptr){
    printf("Gia tri cua p_ptr: %p\n", p_ptr);       //Giá trị của con trỏ p_ptr lưu địa chỉ của con trỏ ptr
    printf("Gia tri cua a: %d\n", **p_ptr);         //Giá trị của a khi được gọi bằng p_ptr

    **p_ptr = 15;       //Gián để thay đổi giá trị của a
}


int main(int argc, char const *argv[])
{
    int a = 10;
    int *ptr = &a;
    // int **p_ptr = &ptr;

    printf("Dia chi cua a: %p\n", &a);                  //Giá trị của biến a = 10, địa chỉ của biến a = 0000ffff
    printf("Gia tri cua ptr: %p\n", ptr);               //Giá trị của con trỏ ptr lưu địa chỉ của biến a = 0000ffff
    // printf("Gia tri cua p_ptr: %p\n", p_ptr);           //Giá trị của con trỏ p_ptr lưu địa chỉ của con trỏ ptr
    // printf("Gia tri cua a: %d\n", **p_ptr);             //Giá trị của của p_ptr là địa chỉ của con trỏ ptr, ptr trỏ tới a


    double_pointer(&ptr);
    printf("Gia tri cua a sau gan: %d\n", a);           //Giá trị của a bị thay đổi sau khi gán **p_ptr = 15

    return 0;
}
