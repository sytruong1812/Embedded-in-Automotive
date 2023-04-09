#include <stdio.h>
#include "main.h"

/*
    g++ .\b1_class.cpp -o b1_class
    .\b1_class
*/

class SinhVien{
    public:
        int lop;
        int mssv;
        int tuoi;
        void hienthi(){
            printf("Lop: %d, MSSV: %d, Tuoi: %d\n", lop, mssv, tuoi);
        }
};

void HocSinh::show(){
    // HocSinh::lop = 10;
    // HocSinh::mshs = 1900;
    // HocSinh::tuoi = 16;
    printf("Lop: %d, MSHS: %d, Tuoi: %d\n", HocSinh::lop, HocSinh::mshs, HocSinh::tuoi);
}

HocSinh::HocSinh(int _lop, int _mshs, int _tuoi){
    HocSinh::lop = _lop;
    HocSinh::mshs = _mshs;
    HocSinh::tuoi = _tuoi;
}


int main(int argc, char const *argv[])
{
    // SinhVien sv;
    // sv.lop = 10;
    // sv.mssv = 1100;
    // sv.tuoi = 20;

    SinhVien sv = {10, 2991, 20};
    sv.hienthi();
    // printf("Lop: %d, MSSV: %d, Tuoi: %d", sv.lop, sv.mssv, sv.tuoi);

    HocSinh hs, hs2(17, 1923, 18);
    // hs.lop = 10;
    // hs.mshs = 1999;
    // hs.tuoi = 16;
    hs.show();
    hs2.show();

    return 0;
}
