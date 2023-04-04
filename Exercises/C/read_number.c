#include "stdio.h"
#include "stdint.h"

/*
Nhập vào từ bàn phím tối đa 7 chữ số, ví dụ: 1200019
Đọc ra: Một triệu hai trăm mười chín
Điều kiện, ví dụ: 1000009
Đọc ra: Một triệu không trăm linh chín
Điều kiện, ví dụ: 1000090
Đọc ra: Một triệu không trăm chín mươi
*/

uint32_t inputNumber;
uint8_t digitsArray[7];
char *read[] = {" ","MUOI","TRAM","NGHIN","MUOI","TRAM","TRIEU"};
char *readNum[] = {"KHONG","MOT","HAI","BA","BON","NAM","SAU","BAY","TAM","CHIN"};


uint8_t countDigitsofNumber(const uint32_t inputNumber){
    uint8_t countDigits = 0;
    uint32_t tempNumber = inputNumber;
    while (tempNumber >= 1)
    {   
        ++countDigits;
        tempNumber = tempNumber / 10; 
    };
    return countDigits;
}

void separateDigits(const uint32_t inputNumber, uint8_t digitsArray[]){
    uint32_t tempNumber = inputNumber;
    for(int i = 0; i < countDigitsofNumber(inputNumber); i++){
        digitsArray[i] = tempNumber % 10;
        tempNumber = tempNumber / 10;
    }
}

void readNumber(const uint32_t inputNumber, uint8_t digitsArray[]){
    for(int i = countDigitsofNumber(inputNumber) - 1; i >= 0; i--){
        if(digitsArray[i] == 0){
            continue;
        }
        else{
            printf("%s %s ", readNum[digitsArray[i]], read[i]);
            if(i > 5, digitsArray[i] == 1 && digitsArray[i+1] == 0){
                printf("LINH ");
            }
        }
    }
}

int main(int argc, char const *argv[])
{   
    printf("Enter a number: ");
    scanf("%d", &inputNumber);
    separateDigits(inputNumber,digitsArray);
    readNumber(inputNumber, digitsArray);
    return 0;
}
