#include "stdio.h"

/* void *ptr là khai báo một con trỏ không kiểu, 
được sử dụng để lưu trữ địa chỉ của bất kỳ biến nào 
trong chương trình. Vì nó là một con trỏ không kiểu, 
nên nó có thể trỏ đến bất kỳ loại dữ liệu nào.*/

int a = 10;
float b = 2.5;
char c = 'a';
char d[5] = "hello";
double f = 15.0;

void *ptr = &d;

int main(int argc, char const *argv[])
{
    printf("Gia tri cua ptr: %s", ptr);
    return 0;
}
