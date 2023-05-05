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
} Table;

class ManagmentMode{
    protected:
        vector<FoodAndDrink> database_FoodAndDrink;
        vector<Table> database_TableInfo;
    public:
        ManagmentMode();
        void addFAD();
        void editFAD();
        void deleteFAD();
        void listFAD();
        void setNumberOfTable();
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
                cin.ignore(100, '\n'); 
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
            setNumberOfTable();
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
    cout << "----------List Food and Drink----------" << endl;
    for(FoodAndDrink _item: database_FoodAndDrink){
        _item.getFoodAndDrink();
    }
}

void ManagmentMode::setNumberOfTable(){
    int scant;
    cout << "Enter number of table: ";
    cin >> scant;
    for(int i = 0; i < scant; i++){
        Table table;
        table.stt = i;
        table.status = false;
        database_TableInfo.push_back(table);
    }
}

class EmployeeMode: public ManagmentMode, public FoodAndDrink{
    private:
        vector<ManagmentMode> database_Managment;
    public:
        EmployeeMode(vector<FoodAndDrink> _database_FoodAndDrink, vector<Table> _table_info);
        void bookTable();
        void orderFoodDrink();
};

EmployeeMode::EmployeeMode(vector<FoodAndDrink> _database_FoodAndDrink, vector<Table> _table_info){

}

void EmployeeMode::bookTable(){
    cout << "---This is the restaurant's menu---" << endl;
    cout << "STT    Status" << endl;
    for(int i = 0; i < database_TableInfo.size(); i++){
        cout << database_TableInfo[i].stt << "    " <<
                database_TableInfo[i].status << endl;
    }
}

void EmployeeMode::orderFoodDrink(){
    cout << "---This is the restaurant's menu---" << endl;
    cout << "ID    Name    Cost" << endl;
    for(int i = 0; i < database_FoodAndDrink.size(); i++){
        cout << database_FoodAndDrink[i].getID() << "    " << 
                database_FoodAndDrink[i].getName() << "    " <<
                database_FoodAndDrink[i].getCost() << endl;
    }
}

class APP{

};



int main(int argc, char const *argv[])
{
    ManagmentMode a;
    return 0;
}
