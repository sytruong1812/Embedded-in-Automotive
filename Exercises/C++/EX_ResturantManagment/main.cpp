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
    cout << "Enter food or drink id: ";
    cin >> this->id;
}
void FoodAndDrink::setName(){
    cout << "Enter food or drink name: ";
    cin.ignore(1000,'\n');
    getline(cin, this->name);
}
void FoodAndDrink::setCost(){
    cout << "Enter food or drink cost: ";
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
    uint8_t stt;
    bool status;
} Desk;

class ManagmentMode: public FoodAndDrink{
    private:
        vector<FoodAndDrink> database_fad;
        vector<Desk> desk_info;
    public:
        ManagmentMode();
        void addFAD();
        void editFAD();
        void deleteFAD();
        void listFAD();
        void setNumberOfDesk();
};

ManagmentMode::ManagmentMode(){
    bool continueProgram = true;
    cout << "This is management mode!\n";
    int key = 0;
    do
    {
        cout << "1. Add food or drink\n";
        cout << "2. Edit food or drink from name\n";
        cout << "3. Delete food or drink from name\n";
        cout << "4. List food and drink\n";
        cout << "5. Set number of desk\n";
        cout << "Enter key: ";
        cin >> key;

        switch (key)
        {
        case 1:
            addFAD();
            break;
        case 2: 
            editFAD();
            break;
        case 3:
            deleteFAD();
            break;
        case 4:
            listFAD();
            break;
        case 5:
            setNumberOfDesk();
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    if (continueProgram) {
        cout << "Enter 1 to continue or 0 to exit: ";
        cin >> continueProgram;
    }
    } while (continueProgram);
}

void ManagmentMode::addFAD(){
    FoodAndDrink item;
    item.setName();
    item.setCost();
    database_fad.push_back(item);
}

void ManagmentMode::editFAD(){
    static string name_edit;
    cout << "Enter food name want edit: ";
    cin.ignore(1000,'\n');
    getline(cin, name_edit);
    for(int i = 0; i < database_fad.size(); i++){
        if(database_fad[i].getName() == name_edit){
            database_fad[i].setName();
            database_fad[i].setCost();
        }
        else{
            cout << "Error!\n";
        }
    }
}

void ManagmentMode::deleteFAD(){
    static string name_delete;
    cout << "Enter food name want delete: ";
    cin.ignore(1000,'\n');
    getline(cin, name_delete);
    for(int i = 0; i < database_fad.size(); i++){
        if(database_fad[i].getName() == name_delete){
            database_fad.erase(database_fad.begin() + i);
            cout << "Removed student whose name is " << name_delete << endl;
        }
        else{
            cout << "Error!\n";
        }
    }
}

void ManagmentMode::listFAD(){
    cout << "----------List Food and Drink----------" << endl;
    for(FoodAndDrink _item: database_fad){
        _item.getName();
    }
}

void ManagmentMode::setNumberOfDesk(){

}


class EmployeeMode{
    private:
        uint8_t desk;
        uint8_t stt;
        vector<ManagmentMode> database_mm;
    public:
        EmployeeMode();
        void enterTheDesk();
};


int main(int argc, char const *argv[])
{
    ManagmentMode a;
    return 0;
}
