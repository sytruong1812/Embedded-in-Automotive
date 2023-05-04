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
        int id;
        string name;
        int cost;
    public:
        FoodAndDrink();
        void setFoodAndDrink();
        int getID();
        string getName();
        int getCost();
        void getFoodAndDrink();
};

FoodAndDrink::FoodAndDrink(){
    static int _id = 1;
    this->id = _id;
    _id++;
}

void FoodAndDrink::setFoodAndDrink(){
    cout << "Enter food or drink id: ";
    cin >> this->id;

    cin.ignore(100,'\n');
    cout << "Enter food or drink name: ";
    getline(cin, this->name);

    cout << "Enter food or drink cost: ";
    cin >> this->cost;
}

int FoodAndDrink::getID(){
    return this->id;
}
string FoodAndDrink::getName(){
    return this->name;
}
int FoodAndDrink::getCost(){
    return this->cost;
}

void FoodAndDrink::getFoodAndDrink(){
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "Cost: " << this->cost << endl;
}

typedef struct
{
    uint8_t stt;
    bool status;
} Desk;

class ManagmentMode{
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
    bool addMore = true;
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
            while (addMore) {
                addFAD();
                cout << "Enter 1 to add more - 0 to break: ";
                cin >> addMore;
                cin.ignore(100, '\n'); // Dùng để xóa bỏ dấu enter thừa sau khi nhập giá trị cho next
            }
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
            cout << "Please press 1 to continue the program or press 0 to end the program: ";
            cin >> continueProgram;
        }
    } while (continueProgram);
}

void ManagmentMode::addFAD(){
    FoodAndDrink item;
    item.setFoodAndDrink();
    database_fad.push_back(item);
}

void ManagmentMode::editFAD(){
    static int _id;
    cout << "Enter food id you want to edit: ";
    cin >> _id;
    for(int i = 0; i < database_fad.size(); i++){
        if(database_fad[i].getID() == _id){
            database_fad[i].setFoodAndDrink();
        }
        else{
            cout << "Error!\n";
        }
    }
}

void ManagmentMode::deleteFAD(){
    static string _name;
    cin.ignore(1000,'\n');
    cout << "Enter food name you want to delete: ";
    getline(cin, _name);
    for(int i = 0; i < database_fad.size(); i++){
        if(database_fad[i].getName() == _name){
            database_fad.erase(database_fad.begin() + i);
            cout << "Removed student whose name is " << _name << endl;
        }
        else{
            cout << "Error!\n";
        }
    }
    _name.clear();
}

void ManagmentMode::listFAD(){
    cout << "----------List Food and Drink----------" << endl;
    for(FoodAndDrink _item: database_fad){
        _item.getFoodAndDrink();
    }
}

void ManagmentMode::setNumberOfDesk(){
    int scant;
    cout << "Enter number of desk: ";
    cin >> scant;
    for(int i = 0; i < scant; i++){
        Desk desk;
        desk.stt = i;
        desk.status = false;
        desk_info.push_back(desk);
    }
}

class EmployeeMode: public ManagmentMode{
    private:
        uint8_t book_desk;
        uint8_t stt;
        vector<ManagmentMode> database_mm;
    public:
        EmployeeMode();
        void enterTheDesk();
};

EmployeeMode::EmployeeMode(){

}

void EmployeeMode::enterTheDesk(){

}

int main(int argc, char const *argv[])
{
    ManagmentMode a;
    return 0;
}
