#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp xe hơi với các thuộc tính màu sắc, kiểu động cơ và số km
đã đi, và các phương thức để tính toán chi phí bảo trì, kiểm tra số km
đã đi và in thông tin về xe.
*/

typedef enum{
    ELECTRIC_MOTOR,
    GASOLINE_MOTOR,
    DIESEL_MOTOR
}EngineType; 

class Car{
    private:
        string colour;
        double km;
        EngineType type;
    public:
        Car(string _colour, EngineType _type, double _km);
        double calculateCostMaintenace();
        void checkNumberOfKm();
};

Car::Car(string _colour, EngineType _type, double _km){
    Car::colour = _colour;
    Car::type = _type;
    Car::km = _km;
}

double Car::calculateCostMaintenace(){
    return 1;
}

void Car::checkNumberOfKm(){
    printf("Number of km by the car: %.3f\n", km);
}

int main(int argc, char const *argv[])
{
    Car a("Red", ELECTRIC_MOTOR, 5000);
    a.calculateCostMaintenace();
    a.checkNumberOfKm();
    return 0;
}
