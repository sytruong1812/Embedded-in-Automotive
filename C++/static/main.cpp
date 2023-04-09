#include <stdio.h>
#include "main.h"

int SinhVien::tuoi;

int main(int argc, char const *argv[])
{
    SinhVien sv1, sv2;
    sv1.tuoi = 18;
    sv2.tuoi = 20;

    printf("Dia chi cua sv1: %p\n", &sv1);
    printf("Dia chi cua sv2: %p\n", &sv2);
    printf("Dia chi cua sv1.tuoi: %p va gia tri: %d\n", &sv1.tuoi, sv1.tuoi);
    printf("Dia chi cua sv2.tuoi: %p va gia tri: %d\n", &sv2.tuoi, sv2.tuoi);
    return 0;
}
