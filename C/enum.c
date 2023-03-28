#include <stdio.h>

/* Mục đích tạo ra các macro, các kiểu, các biến gợi nhớ.
Trong lập trình hướng đối tượng cần code phải hiểu rõ tường minh*/

enum Month {
    Thang1,             // Mặc định Thang1 = 0
    Thang2,             // Thang2 = Thang1 + 1
    Thang3,
    Thang4 = 12,        // Sau khi gán giá trị, Thang sau bằng Thang trước + 1
    Thang5,             // Thang5 = 13
    Thang6,
    Thanh7,
    Thang8,
    Thang9,
    Thang10,
    Thang11,
    Thang12
};

typedef enum{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
}Week;


int main(int argc, char const *argv[])
{
    enum Month inputMonth = Thang3;
    printf("Enum Month = %d\n", inputMonth);

    Week inputWeek = Thursday;
    printf("Enum TUAN = %d\n", inputWeek);

    return 0;
}
