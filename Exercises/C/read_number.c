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
    uint32_t tempNumber = inputNumber;      //Biến tạm
    while (tempNumber >= 1)     //1234567
    {   
        ++countDigits;          //1
        tempNumber /= 10;       //1234567/10 = 123456
                                //123456/10 = 12345
                                //12345/10 = 1234
                                //1234/10 = 123
                                //123/10 = 12
                                //12/10 = 1
                                //1/10 = 0
    };
    return countDigits;         //countDigits = 8
}

void separateDigits(const uint32_t inputNumber, uint8_t digitsArray[]){
    uint32_t tempNumber = inputNumber;      //Biến tạm
    for(int i = 0; i < countDigitsofNumber(inputNumber); i++){          
        digitsArray[i] = tempNumber % 10;       //1234567 % 10 = 7
    //  digitsArray[] = {7,6,5,4,3,2,1}
        tempNumber = tempNumber / 10;           //1234567 / 10 = 123456
    }
}

void readNumber(const uint32_t inputNumber, uint8_t digitsArray[]){
    for(int i = countDigitsofNumber(inputNumber) - 1; i >= 0; i--){         //Duyệt ngược chuỗi
        //  i = 8 - 1 = 7
        if(digitsArray[i] == 0){            //  digitsArray[] = {7,6,5,4,3,2,1}
            if(digitsArray[i] == 0 && digitsArray[i-1] == 1 && digitsArray[i+1] == 1){       //1000101 ~ 1010001
                printf("LINH ");
            }
            continue;
        }
        else{
            printf("%s %s ", readNum[digitsArray[i]], read[i]);
                        //   readNum[7]             , read[7]
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
