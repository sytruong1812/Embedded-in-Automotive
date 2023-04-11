#include <stdio.h>
#include <stdint.h>
#include <string.h>

class DoiTuong{
    // public:
    // private:
    protected:
        uint8_t ID;
        char TEN[20];
        uint8_t TUOI;
    public:
        void hienThi();
        // Tính đa hình
        void sum(uint8_t a, uint8_t b);
        void sum(uint8_t a, uint8_t b, uint8_t c);
        double sum(double a, double b, double c);
        // Tính trừu tượng
        virtual void bangCap() = 0;
};

void DoiTuong::hienThi(){           
    printf("ID: %d\n", DoiTuong::ID);
    printf("TEN: %s\n", DoiTuong::TEN);
    printf("TUOI: %d\n", DoiTuong::TUOI);
}

void DoiTuong::sum(uint8_t a, uint8_t b){       //Tính đa hình
    printf("Sum a + b = %d\n", a + b);
}
void DoiTuong::sum(uint8_t a, uint8_t b, uint8_t c){        //Tính đa hình
    printf("Sum a + b + c = %d\n", a + b + c);
}
double DoiTuong::sum(double a, double b, double c){     //Tính đa hình
    return a + b +c;
}
/*
Tính kế thừa:
    - Nếu class con có dạng kế thừa là public, thì class cha kiểu gì qua class con giữ nguyên 
    - Nếu class con có dạng kế thừa là private, thì nếu:
        + Class cha kiểu plulic -> Class con kiểu private
        + Class cha kiểu private -> Class con kiểu private
        + Class cha kiểu protected - > Class con kiểu private
    - Nếu class con có dạng kế thừa là protected, thì nếu:
        + Class cha kiểu plulic -> Class con kiểu protected
        + Class cha kiểu private -> Class con kiểu private
        + Class cha kiểu protected - > Class con kiểu protected 
*/
class HocSinh : public DoiTuong{        
    public:
        void hienThi();
        void setData(uint8_t _id, char* _ten, uint8_t _tuoi, uint8_t _lop);
    protected:
        uint8_t LOP;
};

void HocSinh::hienThi(){            // Định nghĩa lại phương thức của class cha (Phướng thức ghi đè)
    printf("ID: %d\n", HocSinh::ID);
    printf("TEN: %s\n", HocSinh::TEN);
    printf("TUOI: %d\n", HocSinh::TUOI);
    printf("LOP: %d\n", HocSinh::LOP);
}

void HocSinh::setData(uint8_t _id, char *_ten, uint8_t _tuoi, uint8_t _lop){
    HocSinh::ID = _id;
    strcpy(HocSinh::TEN, _ten);
    HocSinh::TUOI = _tuoi;
    HocSinh::LOP = _lop;
}

class SinhVien : public DoiTuong{
    public:
        void bangCap() override {
            printf("Dai hoc nam 3, Dai hoc nam 4");
        }
};

class GiangVien : public DoiTuong{
    public:
        void bangCap() override {
            printf("Thac si, Tien si, Giao su");
        }
};

int main(int argc, char const *argv[])
{
    // DoiTuong dt;
    // dt.ID = 101;
    // strcpy(dt.TEN, (char*)"Nguyen Van A");
    // dt.TUOI = 16;
    // dt.hienThi();
    // dt.sum(3, 6);
    // dt.sum((uint8_t)2, (uint8_t)4, (uint8_t)6);
    // printf("Sum a + b + c = %f\n", dt.sum(3.3, 3.2, 1.2));

    // HocSinh hs;
    // hs.ID = 102;
    // strcpy(hs.TEN, (char*)"Nguyen Van B");
    // hs.TUOI = 18;
    // hs.LOP = 14;
    // hs.setData(103, (char*)"Nguyen Van C", 18, 6);
    // hs.hienThi();
    return 0;
}
