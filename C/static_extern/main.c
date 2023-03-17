#include <stdio.h>

// Build 2 file 1 lúc: 
// gcc main.c test.c -o main
// ./main

void DEM(){
    //int x = 0;      //Nếu khai báo vậy hàm được gọi 3 lần xuất ra 0,0,0 => Biến x không được lưu trữ địa chỉ
    static int x = 0;       //Nếu khai báo vậy hàm được gọi 3 lần xuất ra 0,1,2 => Biến static lưu trữ địa chỉ của biến x,
                            //và biến static tồn tại hết vòng đời của chương trình
    printf("Dem: %d\n", x);
    x++;
}

extern void Count();    // extern dùng để gọi hàm count() trong file test qua

//extern int MAX();       //Mình không thể extern hàm MAX() bên file test được, vì đã dùng static để định nghĩ hàm đó

int main(int argc, char const *argv[])
{
    DEM();
    DEM();
    DEM();

    Count();

    //MAX(3,2);

    return 0;
}
