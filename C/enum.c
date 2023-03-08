#include <stdio.h>

/*Mục đích tạo ra các macro, các kiểu, các biến gợi nhớ.
Trong lập trình hướng đối tượng cần code phải hiểu rõ tường minh*/

enum Month {
    Thang1,             // Mặc định Thang1=0
    Thang2,             // Thang2 = Thang1 + 1
    Thang3,
    Thang4 = 12,        // Thang sau bằng Thang trước + 1
    Thang5,             // Thang5 = 13
    Thang6,
    Thanh7,
    Thang8,
    Thang9,
    Thang10,
    Thang11,
    Thang12
};

typedef enum {
    Thu2,
    Thu3,
    Thu4 = 1,
    Thu5,
    Thu6,
    Thu7,
    CN
} TUAN;

int main(int argc, char const *argv[])
{
    enum Month nametest = Thang5;
    printf("Enum Month = %d\n", nametest);

    TUAN nametest1 = Thu5;
    printf("Enum TUAN = %d\n", nametest1);

    return 0;
}
