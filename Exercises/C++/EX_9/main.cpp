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

const char* engineType[] = {"ELECTRIC_MOTOR", "GASOLINE_MOTOR", "DIESEL_MOTOR"};

class Car{
    private:
        string colour;
        EngineType type;
        uint32_t km;
    public:
        Car(string _colour, EngineType _type, uint32_t _km);
        uint32_t calculateCostMaintenace();
        void showInformation();
};

Car::Car(string _colour, EngineType _type, uint32_t _km){
    Car::colour = _colour;
    Car::type = _type;
    Car::km = _km;
}

uint32_t Car::calculateCostMaintenace(){
    if(km < 5000) return (uint32_t)1000000;
    else if(km < 15000) return (uint32_t)2000000;
    else if(km < 30000) return (uint32_t)3000000;
    else if(km < 40000) return (uint32_t)3500000;
    else if(km < 100000) return (uint32_t)4000000;
    else return (uint32_t)5000000;
}

void Car::showInformation(){
    printf("Information by the car:\n");
    printf("Colour: %s \tType: %s \tKm: %d\n", colour.c_str(), engineType[type], km);
    printf("Number money by cost maintenace is: %li\n", Car::calculateCostMaintenace());
}

int main(int argc, char const *argv[])
{
    Car a("Red", ELECTRIC_MOTOR, 50000);
    a.calculateCostMaintenace();
    a.showInformation();
    return 0;
}
