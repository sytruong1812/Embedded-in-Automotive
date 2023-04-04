#include "stdio.h"
#include "stdint.h"
#include "string.h"

/*
Nhập vào chuỗi có nhiều kiểu dữ liệu (number, string, char, double)
Phân tách ra từng loại, nếu là kiểu number thì tính tổng các phần tử của kiểu đó
nếu là kiểu string, char thì sắp xếp theo thứ tự ABC
VD: Input: 1,2,3,"10",'A', "ABC", "Hello";
Output: 16, A ABC Hello
*/

// void *string = &Input; 
// int number[] = {0};

char input[] = {'1', '2', '3','9'};

int number[100];
char string[100];

void dataClassify(char *array){
    int sum = 0;
    for (int i = 0; array[i] != '\0'; i++)
    {
        if(array[i] > 47 && array[i] < 58){
            array[i] = number[i];
            sum += number[i] - '0';
        }
        if((array[i] > 65  && array[i] < 90) || (array[i] > 97 && array[i] < 122)){
            array[i] = string[i];
        }
        else{
            continue;
        }
    }
    printf("%d", sum); 
}

void sumNumber(){
    char x[10] = {'1','2','3',"10"};
    int sum;
    for (int i = 0; x[i] != '\0'; i++)
    {
        sum += x[i] - '0';  // chuyển ký tự thành số  
        /*
        Trong bảng mã ASCCI ký tự số '0' = 48
        Nếu x[i] = '1'
        '1' = 49
        x[i] - '0' = 49 - 48 = 1
        */
    }
    printf("%d", sum);
}

int main(int argc, char const *argv[])
{
    sumNumber();
    // dataClassify(input);
    return 0;
}
