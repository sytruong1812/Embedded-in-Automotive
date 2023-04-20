#include <stdio.h>
#include <stdint.h>
#include <cmath>

class Diem{
    private:
        int8_t toaDoX;
        int8_t toaDoY;
    public:
        Diem(int8_t _toaDoX = 0, int8_t _toaDoY = 0);
        int8_t getToaDoX();
        int8_t getToaDoY();
};

Diem::Diem(int8_t _toaDoX, int8_t _toaDoY){
    Diem::toaDoX = _toaDoX;
    Diem::toaDoY = _toaDoY;
}

int8_t Diem::getToaDoX(){
    return Diem::toaDoX;
}

int8_t Diem::getToaDoY(){
    return Diem::toaDoY;
}

class PhepToanOXY{
    private:
        Diem diemA;
        Diem diemB;
        Diem diemC;
        typedef enum{
            KHOANG_CACH,
            DIEN_TICH
        }PhepToan;
        PhepToan checkPhepToan;
    public:
        PhepToanOXY(Diem _diemA, Diem _diemB);
        PhepToanOXY(Diem _diemA, Diem _diemB, Diem _diemC);
        double khoangCach2Diem();
        double dienTichTamGiac();
};

PhepToanOXY::PhepToanOXY(Diem _diemA, Diem _diemB){
    PhepToanOXY::diemA = _diemA;
    PhepToanOXY::diemB = _diemB;
    PhepToanOXY::checkPhepToan = KHOANG_CACH;
}

PhepToanOXY::PhepToanOXY(Diem _diemA, Diem _diemB, Diem _diemC){
    PhepToanOXY::diemA = _diemA;
    PhepToanOXY::diemB = _diemB;
    PhepToanOXY::diemC = _diemC;
    PhepToanOXY::checkPhepToan = DIEN_TICH;
}

double PhepToanOXY::khoangCach2Diem(){
    double x;
    double y;
    double distance;
    if(PhepToanOXY::checkPhepToan == KHOANG_CACH){
        x = diemA.getToaDoX() - diemB.getToaDoX(); 
        y = diemA.getToaDoY() - diemB.getToaDoY();
        distance = sqrt(x*x + y*y);
        return distance;
    }
    else{
        printf("Khong phai chuong trinh checkPhepToan!");
        return -1;
    }
}

double PhepToanOXY::dienTichTamGiac(){
    double disAB;
    double disBC;
    double disAC;
    double P;
    double acreage;
    if (PhepToanOXY::checkPhepToan == DIEN_TICH){
        disAB = sqrt(((diemA.getToaDoX() - diemB.getToaDoX()) * (diemA.getToaDoX() - diemB.getToaDoX())) + ((diemA.getToaDoY() - diemB.getToaDoY()) * (diemA.getToaDoY() - diemB.getToaDoY())));
        disBC = sqrt(((diemB.getToaDoX() - diemC.getToaDoX()) * (diemB.getToaDoX() - diemC.getToaDoX())) + ((diemB.getToaDoY() - diemC.getToaDoY()) * (diemB.getToaDoY() - diemC.getToaDoY())));
        disAC = sqrt(((diemA.getToaDoX() - diemC.getToaDoX()) * (diemA.getToaDoX() - diemC.getToaDoX())) + ((diemA.getToaDoY() - diemC.getToaDoY()) * (diemA.getToaDoY() - diemC.getToaDoY())));
        P = (disAB + disBC + disAC) / 2;
        acreage = sqrt(P * (P - disAB) * (P - disBC) * (P - disAC));
        return acreage; 
    }
    else{
        printf("Khong phai chuong trinh checkPhepToan!");
        return -1;
    }  
}
int main(int argc, char const *argv[])
{
    Diem diemA = {2, 1};
    Diem diemB = {6, 2};
    Diem diemC = {3, 4};
    PhepToanOXY tinh1(diemA, diemB);
    PhepToanOXY tinh2(diemA, diemB, diemC);
    printf("Khoang cach giua 2 diem A va B = %f\n", tinh1.khoangCach2Diem());
    printf("Dien tich tam giac ABC = %f\n", tinh2.dienTichTamGiac());
    return 0;
}
