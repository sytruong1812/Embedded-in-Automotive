#include <stdio.h>

int main() {
    float data = 26.04;
    char *ptr = (char *) &data;         // ép kiểu con trỏ từ float sang char

    for (int i = 0; i < sizeof(float); i++) {
        printf("%d ", *(ptr + i));      // in ra từng byte của float data
    }

    return 0;
}