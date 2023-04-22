#include <stdio.h>
#include <stdint.h>

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp phân số với các thuộc tính tử số và mẫu số và các phương
thức để tính toán các phép tính toán cơ bản như cộng, trừ, nhân và chia.
*/

class Fraction{
    private:
        double numerator;
        double denominator;
    public: 
        Fraction(double _numerator, double _denominator);
        double addition();
        double subtraction ();
        double multiply();
        double division();
};

Fraction::Fraction(double _numerator, double _denominator){
    Fraction::numerator = _numerator;
    Fraction::denominator = _denominator;
}

double Fraction::addition(){
    double result = numerator + denominator;
    printf("Ket qua tinh tong = %f\n", result);
    return result;
}

double Fraction::subtraction(){
    double result = numerator - denominator;
    printf("Ket qua tinh hieu = %f\n", result);
    return result;
}
double Fraction::multiply(){
    double result = numerator * denominator;
    printf("Ket qua tinh tich = %f\n", result);
    return result;
}
double Fraction::division(){
    double result = numerator / denominator;
    printf("Ket qua tinh thuong = %f\n", result);
    return result;
}

int main(int argc, char const *argv[])
{
    Fraction a(6, 9);
    a.addition();
    a.subtraction();
    a.multiply();
    a.division();
    return 0;
}
