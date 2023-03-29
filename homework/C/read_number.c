#include "stdio.h"
#include <stdlib.h>

/*
Nhập vào từ bàn phím tối đa 7 chữ số, ví dụ: 1200019
Đọc ra: Một triệu hai trăm mười chín
Điều kiện, ví dụ: 1000009
Đọc ra: Một triệu không trăm linh chín
Điều kiện, ví dụ: 1000090
Đọc ra: Một triệu không trăm chín mươi
*/

void readNumber(int num);

int main() {
    int num;
    printf("Nhap vao mot so nguyen duong toi da 7 chu so: ");
    scanf("%d", &num);

    if (num < 0 || num > 9999999) {
        printf("So nhap vao khong hop le.\n");
        return 0;
    }

    readNumber(num);
    return 0;
}

void readNumber(int num) {
    char *ones[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    char *tens[] = {"muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi"};
    char *hundreds[] = {"mot tram", "hai tram", "ba tram", "bon tram", "nam tram", "sau tram", "bay tram", "tam tram", "chin tram"};
    char *thousands[] = {"mot ngan", "hai ngan", "ba ngan", "bon ngan", "nam ngan", "sau ngan", "bay ngan", "tam ngan", "chin ngan"};
    char *millions[] = {"mot trieu", "hai trieu", "ba trieu", "bon trieu", "nam trieu", "sau trieu", "bay trieu", "tam trieu", "chin trieu"};

    int digit1 = num % 10;       // đơn vị
    int digit10 = (num / 10) % 10;   // chục
    int digit100 = (num / 100) % 10;   // hàng trăm
    int digit1000 = (num / 1000) % 10;   // hàng nghìn
    int digit10000 = (num / 10000) % 10;   // hàng chục nghìn
    int digit100000 = (num / 100000) % 10;   // hàng trăm nghìn
    int digit1000000 = (num / 1000000) % 10;   // hàng triệu

    if (digit1000000 != 0) {
        printf("%s trieu ", ones[digit1000000]);
    }

    if (digit100000 != 0) {
        printf("%s tram ", ones[digit100000]);
    } else {
        if (digit10000 != 0 || digit1000 != 0 || digit100 != 0 || digit10 != 0 || digit1 != 0) {
            printf("khong tram ");
        }
    }

    if (digit10000 != 0) {
        if (digit10000 == 1) {
            printf("%s ", tens[digit10]);
        } else {
            printf("%s ", ones[digit10000]);
            printf("%s ", tens[digit10]);
        }
    } else {
        if (digit1000 != 0 || digit100 != 0 || digit10 != 0 || digit1 != 0) {
            printf("nghin ");
        }
    }

    if (digit1000 != 0) {
        printf("%s ", hundreds[digit1000 - 1]);
    }

    if (digit100 != 0) {
        printf("%s ", hundreds[digit100 - 1]);
    } else {
        if (digit10 != 0 || digit1 != 0) {
            printf("khong tram ");
        }
    }

    if (digit10 != 0 && digit10 != 1) {
        printf("%s ", tens[digit10 - 1]);
    }

    if (digit10 == 1) {
        printf("muoi ");
    }

    if (digit1 != 0) {
        if (digit10 != 1) {
            printf("%s ", ones[digit1]);
        } else {
            printf("mot ");
        }
    }
    printf("dong.");
}
