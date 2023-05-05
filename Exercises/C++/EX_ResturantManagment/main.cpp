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
    static int _id = 0;
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

typedef struct{
    int id;
    string name;
    int cost;
    int count; 
} Order;

/*Khai báo vector toàn cục để chia sẻ dữ liệu giữa class ManagmentMode và EmployeeMode*/
vector<FoodAndDrink> ManagmentMode::database_FoodAndDrink;
vector<Table> ManagmentMode::database_TableInfo;

class EmployeeMode: public ManagmentMode, public FoodAndDrink {
    private:
        vector<Order> database_YourOrder; 
    public:
        void Employee();
        void setTable();
        void orderDishes();
        void editDishes();
        void deleteDishes();
        void showOrder();
};
void EmployeeMode::Employee(){
    bool continueProgram = true;
    bool addMore = true;
    cout << "This is employee mode!\n";
    int key = 0;
    do
    {
        cout << "1. Set table\n";
        cout << "2. Order dishes\n";
        cout << "3. Edit dishes\n";
        cout << "4. Delete dishes\n";
        cout << "5. Show order\n";
        cout << "Enter key: ";
        cin >> key;

        switch (key)
        {
        case 1:
            while (addMore) {
                setTable();
                cout << "Enter 1 to add more - 0 to break: ";
                cin >> addMore;
            }
            addMore = true;
            break;
        case 2: 
            while (addMore) {
                orderDishes();
                cout << "Enter 1 to add more - 0 to break: ";
                cin >> addMore;
            }
            addMore = true;
            break;
        case 3:
            editDishes();
            break;
        case 4:
            deleteDishes();
            break;
        case 5:
            showOrder();
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
        if (continueProgram) {
            cout << "Do you want to continue in employee mode?\n" << "Enter 1 to continue or 0 to end: ";
            cin >> continueProgram;
        }
    } while (continueProgram);
}
void EmployeeMode::setTable(){
    cout << "---Number and status of current tables---" << endl;
    cout << "STT    Status" << endl;
    for(int i = 0; i < database_TableInfo.size(); i++){
        cout << database_TableInfo[i].stt << "    ";
        if (database_TableInfo[i].status) {
            cout << "occupied" << endl;
        } 
        else {
            cout << "available" << endl;
        }
    }
    //Set table
    int choose_table;
    cout << "Please choose a table" << endl;
    cin >> choose_table;
    for(int i = 0; i < database_TableInfo.size(); i++){
        if(database_TableInfo[i].stt == choose_table){
            if (database_TableInfo[i].status == false){
                database_TableInfo[i].status = true;  
            }
            else{
                cout << "This table is already occupied, please choose another table!" << endl;
            }
        }
    }
    choose_table = 0;
}

void EmployeeMode::orderDishes(){
    cout << "---This is the restaurant's menu---" << endl;
    ManagmentMode::listFAD();
    Order tempOrder;
    int temp_id;
    cout << "what do you want order?\n" << "Enter dish id: ";
    cin >> temp_id;
    for(int i = 0; i < database_FoodAndDrink.size(); i++){
        if(database_FoodAndDrink[i].getID() == temp_id){
            tempOrder.id = database_FoodAndDrink[i].getID();
            tempOrder.name = database_FoodAndDrink[i].getName();
            tempOrder.cost = database_FoodAndDrink[i].getCost();
        }
    }
    cout << "Number of dish: " ;
    cin >> tempOrder.count;
    database_YourOrder.push_back(tempOrder);
}
void EmployeeMode::editDishes(){
    this->showOrder();
    int _id_old;
    int _id_new;
    cout << "Enter old ID you want to edit: ";
    cin >> _id_old;
    cout << "Enter new ID to edit: ";
    cin >> _id_new;
    for(int i = 0; i < database_YourOrder.size(); i++){
        if(database_YourOrder[i].id == _id_old){
            database_YourOrder[i].id = _id_new;
        }
        if(database_YourOrder[i].id != _id_old){
            continue;
        }
        else{
            cout << "Error!\n";
        }
    }
    _id_new = 0;
    _id_old = 0;
}
void EmployeeMode::deleteDishes(){
    this->showOrder();
    static int _id;
    cout << "Enter ID of dishes you want to remove: ";
    cin >> _id;
    for(int i = 0; i < database_YourOrder.size(); i++){
        if(database_YourOrder[i].id == _id){
            database_YourOrder.erase(database_YourOrder.begin() + i);
            cout << "Removed student whose id is " << _id << endl;
        }
        if(database_YourOrder[i].id != _id){
            continue;
        }
        else{
            cout << "Error!\n";
        }
    }
    _id = 0;
}
void EmployeeMode::showOrder(){
    cout << "The dishes you ordered" << endl;
    for(Order item: database_YourOrder){
        cout << "ID -- Name -- Cost -- Cout" << endl;
        cout << item.id << "      " << 
                item.name << "     " << 
                item.cost << "     " << 
                item.count << endl; 
    }
}

int main(int argc, char const *argv[])
{
    bool loop = true;
    int option;
    ManagmentMode a;
    EmployeeMode b;
    do
    {
        cout << "----------------------Chose option---------------------\n" << endl;
        cout << "1: Managment Mode\t2: Employee Mode\t3: Exit!" << endl;
        cout << "Mode: ";
        cin >> option;
    
        switch (option)
        {
        case 1:
            a.Managment();
            break;
        case 2: 
            b.Employee();
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
