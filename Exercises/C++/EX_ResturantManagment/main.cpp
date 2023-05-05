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
};

FoodAndDrink::FoodAndDrink(){
    int _id = 1;
    this->id = _id;
    _id++;
}

void FoodAndDrink::setFoodAndDrink(){
    cout << "Enter food or drink name: ";
    cin.ignore(100,'\n');
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

typedef struct
{
    int stt;
    bool status;
} Table;

class ManagmentMode{
    protected:
        static vector<FoodAndDrink> database_FoodAndDrink;
        static vector<Table> database_TableInfo;
    public:
        void Managment();
        void addFAD();
        void editFAD();
        void deleteFAD();
        void listFAD();
        void setNumberOfTable();
};

void ManagmentMode::Managment(){
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
        cout << "5. Set number of table\n";
        cout << "Enter key: ";
        cin >> key;

        switch (key)
        {
        case 1:
            while (addMore) {
                addFAD();
                cout << "Enter 1 to add more - 0 to break: ";
                cin >> addMore;
            }
            addMore = true;
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
            setNumberOfTable();
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
        if (continueProgram) {
            cout << "Do you want to continue in management mode?\n" << "Enter 1 to continue or 0 to end: ";
            cin >> continueProgram;
        }
    } while (continueProgram);
}

void ManagmentMode::addFAD(){
    FoodAndDrink item;
    item.setFoodAndDrink();
    database_FoodAndDrink.push_back(item);
}

void ManagmentMode::editFAD(){
    static int _id;
    cout << "Enter food id you want to edit: ";
    cin >> _id;
    for(int i = 0; i < database_FoodAndDrink.size(); i++){
        if(database_FoodAndDrink[i].getID() == _id){
            database_FoodAndDrink[i].setFoodAndDrink();
        }
    }
}

void ManagmentMode::deleteFAD(){
    static string _name;
    cin.ignore(1000,'\n');
    cout << "Enter food name you want to delete: ";
    getline(cin, _name);
    for(int i = 0; i < database_FoodAndDrink.size(); i++){
        if(database_FoodAndDrink[i].getName() == _name){
            database_FoodAndDrink.erase(database_FoodAndDrink.begin() + i);
            cout << "Removed student whose name is " << _name << endl;
        }
        else{
            cout << "Error!\n";
        }
    }
    _name.clear();
}

void ManagmentMode::listFAD(){
    cout << "ID    Name    Cost" << endl;
    for(int i = 0; i < database_FoodAndDrink.size(); i++){
        cout << database_FoodAndDrink[i].getID() << "      " << 
                database_FoodAndDrink[i].getName() << "     " <<
                database_FoodAndDrink[i].getCost() << endl;
    }
}

void ManagmentMode::setNumberOfTable(){
    int scant;
    cout << "Enter number of table: ";
    cin >> scant;
    Table table;
    for(int i = 0; i < scant; i++){
        table.stt = i;
        table.status = false;
        database_TableInfo.push_back(table);
    }
}

/*Khai báo vector toàn cục để chia sẻ dữ liệu giữa class ManagmentMode và EmployeeMode*/
vector<FoodAndDrink> ManagmentMode::database_FoodAndDrink;
vector<Table> ManagmentMode::database_TableInfo;

class EmployeeMode: public ManagmentMode, public FoodAndDrink {
    private:

    public:
        void setTable();
        void orderDishes();
        void editDishes();
        void deleteDishes();
};

void EmployeeMode::setTable(){
    cout << "---Number and status of current tables---" << endl;
    cout << "STT    Status" << endl;
    for(int i = 0; i < database_TableInfo.size(); i++){
        cout << database_TableInfo[i].stt << "    ";
        if (database_TableInfo[i].status) {
            cout << "occupied" << endl;
        } else {
            cout << "available" << endl;
        }
    }
    int choose_table;
    cout << "Please choose a table" << endl;
    cin >> choose_table;
    for(int i = 0; i < database_TableInfo.size(); i++){
        if(database_TableInfo[i].stt == choose_table){
            database_TableInfo[i].status = true;
        }
    }
}

void EmployeeMode::orderDishes(){
    cout << "---This is the restaurant's menu---" << endl;
    ManagmentMode::listFAD();
    //Order food or drink

}
void EmployeeMode::editDishes(){

}
void EmployeeMode::deleteDishes(){
    
}

int main(int argc, char const *argv[])
{
    bool loop = true;
    int option;
    ManagmentMode a;
    EmployeeMode b;
    do
    {
        cout << "----Chose option----\n1: Managment Mode\n2: Employee Mode\n3: Exit!" << endl;
        cin >> option;
    
        switch (option)
        {
        case 1:
            a.Managment();
            break;
        case 2: 
            b.setTable();
            break;
        case 3:
            loop = false;
            cout << "See you again!" << endl;
            break;
        default:
            cout << "Option false!" << endl;
            break;
        }
    } while (loop);
    
    return 0;
}
