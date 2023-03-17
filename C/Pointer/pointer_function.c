#include "stdio.h"

void tong(int a, int b){
    printf("a+b=%d\n", a+b);
}
void hieu(int a, int b){
    printf("a-b=%d\n", a-b);
}
int tich(int a, int b){
    printf("a*b=%d\n", a*b);
}
float thuong(float a, float b){
    printf("a/b=%f\n", a/b);
}

void math(void (*ptr_math)(int, int), int a, int b){
    printf("Input Parameter is Function Pointer\n");
    ptr_math(a, b);
}

int main(int argc, char const *argv[])
{
    // void (*tinhtong)(int, int);             //Khai báo con trỏ hàm tính tổng

    // tinhtong = &tong;
    // tinhtong(3, 6);

    // void (*tinhhieu)(int, int);             //Khai báo con trỏ hàm tính hiệu
    // tinhhieu  = &hieu;
    // tinhhieu(6, 3);

    // int (*tinhtich)(int, int);              //Khai báo con trỏ hàm tính tích

    // tinhtich = &tich;
    // tinhtich(3, 6);

    // float (*tinhthuong)(float, float);      //Khai báo con trỏ hàm tính thương

    // tinhthuong = &thuong;
    // tinhthuong(6, 3);

    math(tong, 3, 6);                           //Input parameter của hàm math là một con trỏ hàm *ptr_math
    math(hieu, 6, 3);
    return 0;
}
