#include "stdio.h"
#include "stdint.h"

/*
Nhập vào chuỗi có nhiều kiểu dữ liệu (number, string, char, double)
Phân tách ra từng loại, nếu là kiểu number thì tính tổng các phần tử của kiểu đó
nếu là kiểu string, char thì sắp xếp theo thứ tự ABC
VD: Input: 1,2,3,"10",'A', "ABC", "Hello";
Output: 16, A ABC Hello
*/
#define LENG(arr) (sizeof(arr) / sizeof(arr[0]))

char input[] = {'1','2','3','9'};
int number[100];
char strings[100];

char *cacl[100] = {NULL};

void inputKeys(){
    int i;
    uint8_t typeInt;
    char typeChar[100];
    char typeString[100];
    double typeDouble;
    do
    {
        int input;
        scanf("%ld", &input);
        switch (input)
        {
        case 1:
            // uint8_t typeInt;
            scanf("%d", &typeInt);
            *(int *)cacl[i] = typeInt;
            i++;
            break;
        case 2:
            // char typeChar[100];
            scanf("%c", &typeChar);
            *(char *)cacl[i] = typeChar;
            i++;
            break;
        case 3:
            // char typeString[100];
            scanf("%s", &typeString);
            *(char *)cacl[i] = typeString;
            i++;
            break;
        case 4:
            // double typeDouble;
            scanf("%f", &typeDouble);
            *(double *)cacl[i] = typeDouble;
            i++;
            break;
        default:
            break;
        }
    } while (1);
}


void dataClassify(char *array){
    int sum = 0;
    for (int i = 0; array[i] != '\0'; i++)
    {
        if(array[i] > 47 && array[i] < 58){
            array[i] = number[i];
            sum += number[i] - '0';
        }
        if((array[i] > 65  && array[i] < 90) || (array[i] > 97 && array[i] < 122)){
            array[i] = strings[i];
        }
        else{
            continue;
        }
    }
    printf("%d", sum); 
}

void sumNumber(){
    char x[10] = {'1','2','3'};
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
    // sumNumber();
    // dataClassify(input);
    inputKeys();
    return 0;
}
