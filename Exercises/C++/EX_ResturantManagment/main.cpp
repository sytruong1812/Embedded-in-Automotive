#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

/*
File: main.c
Author: Sy Truong
Date: 1/5/2023
Description: Quản lý nhà hàng
*/


class FoodAndDrink{
    private:
        uint8_t id;
        string name;
        uint16_t cost;
    public:
        FoodAndDrink();
        void setID();
        void setName();
        void setCost();
        uint8_t getID();
        string getName();
        uint16_t getCost();
};

FoodAndDrink::FoodAndDrink(){
    static int _id = 1;
    this->id = _id;
    _id++;
}
void FoodAndDrink::setID(){

}
void FoodAndDrink::setName(){
    cout << "Enter food and drink name: ";
    getline(cin, this->name);
}
void FoodAndDrink::setCost(){
    cout << "Enter food and drink cost: ";
    cin >> this->cost;
}
uint8_t FoodAndDrink::getID(){
    return this->id;
}
string FoodAndDrink::getName(){
    return this->name;
}
uint16_t FoodAndDrink::getCost(){
    return this->cost;
}

typedef struct
{
    uint8_t position;
    bool status;
} Desk;

class ManagmentMode{
    private:
        vector<FoodAndDrink> database_fad;
        vector<Desk> desk_info;
    public:
        ManagmentMode();
        void setNumberOfDesk();
        void addFood();
        void editFood();
        void deleteFood();
        void listFood();
};

ManagmentMode::ManagmentMode(){

}

void ManagmentMode::setNumberOfDesk(){

}

class EmployeeMode{
    private:
        uint8_t desk;
        uint8_t quantity;
        vector<ManagmentMode> database;
    public:
        EmployeeMode();
        void enterTheDesk();
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
