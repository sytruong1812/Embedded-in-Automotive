#include <stdio.h>
#include <stdint.h>
#include <cmath>

using namespace std;
/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp hình chữ nhật với các thuộc tính chiều dài, chiều rộng và
các phương thức để tính chu vi, diện tích, đường chéo và kiểm tra xem
nó có phải là hình vuông hay không.
*/

class Rectangle{
    private:
        int8_t length;
        int8_t width;
    public:
        Rectangle(int8_t _length, int8_t _width);
        double perimeter();
        double area();
        double diagonal();
        void check();
};

Rectangle::Rectangle(int8_t _length, int8_t _width){
    Rectangle::length = _length;
    Rectangle::width = _width;
}

double Rectangle::perimeter(){
    double p = (length + width) * 2;
    printf("Perimeter = %f\n", p);
    return p;
}

double Rectangle::area(){
    double s = length * width;
    printf("Area = %f\n", s);
    return s;
}

double Rectangle::diagonal(){
    double dia = sqrt((length * length) + (width * width));
    printf("Diagonal = %f\n", dia);
    return dia;
}

void Rectangle::check(){
    if(length == width){
        printf("Do la hinh vuong");
    }
    else{
        printf("Do la hinh chu nhat");
    }
}

int main(int argc, char const *argv[])
{
    Rectangle object(3, 5);
    object.perimeter();
    object.area();
    object.diagonal();
    object.check();
    return 0;
}


