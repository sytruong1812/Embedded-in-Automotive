#include <stdio.h>

struct ngay
{
    int ngay;
    int thang;
    char nam[10];
};

struct nhan_cong
{
    char ten[20];
    char dia_chi[20];
    double bac_luong;
    struct ngay ngay_sinh;
    struct ngay ngay_vao_co_quan; 
};

int main()
{
    struct nhan_cong a = {"Truong", "Nghe An", 3.0, {18, 12, "2001"}, {13, 6, "2023"}};

    printf("Ten: %s, Dia chi: %s, Bac luong: %lf\n", a.ten, a.dia_chi, a.bac_luong);
    printf("Ngay sinh: %d-%d-%s\n", a.ngay_sinh.ngay, a.ngay_sinh.thang, a.ngay_sinh.nam);
    printf("Ngay vao co quan: %d-%d-%s\n", a.ngay_vao_co_quan.ngay, a.ngay_vao_co_quan.thang, a.ngay_vao_co_quan.nam);

    return 0;
}
