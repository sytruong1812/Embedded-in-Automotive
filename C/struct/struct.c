#include <stdio.h>

/*  struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau.
    Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại 
    vì còn phụ thuộc vào bộ nhớ đệm (struct padding)*/

struct Brithday
{
    int Day;
    int Month;
    int Year;
};

typedef struct
{
    int Ngay;
    int Thang;
    int Nam;
}SinhNhat;


int main(int argc, char const *argv[])
{
    struct Brithday My = {18,12,2001};
    printf("Ngay: %d, Thang: %d, Nam: %d\n", My.Day, My.Month, My.Year);

    SinhNhat Me = {18,12,2001};
    printf("Ngay: %d, Thang: %d, Nam: %d\n", Me.Ngay, Me.Thang, Me.Nam);
    return 0;
}
