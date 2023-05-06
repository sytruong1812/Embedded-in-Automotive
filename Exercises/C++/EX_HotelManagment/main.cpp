#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
File: main.c
Author: Sy Truong
Date: 1/5/2023
Description: Quản lý khách sạn
*/

#define HOUR 24
#define CURRENT_HOUR 12

typedef struct{
    int STT;
    bool status;
    int hour;
} Room;

class Service{
    private:
        Room room;
    public:
        Service();
        void setService();
        void rentByTheHour();
        void rentOvernight();
        int getHour();
};

Service::Service(){
    static int _stt = 0;
    room.STT = _stt;
    _stt++;
}

void Service::setService(){
    int option;
    cout << "-------------Table Service-------------" << endl;
    cout << "Enter 1: Room rental by the hour | " << "2: Rent overnight. ";
    cin >> option;
    if(option == 1){
        rentByTheHour();
        option = 0;
    }
    else if(option == 2){
        rentOvernight();
        option = 0;
    }
    else{
        cout << "Enter false!" << endl;
        option = 0;
    }
}


void Service::rentByTheHour(){
    cout << "Enter the number of hour you want: ";
    cin >> this->room.hour;
}

void Service::rentOvernight(){
    this->room.hour = 12;
}

int Service::getHour(){
    return this->room.hour;
}
/*-------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------*/
class ManagmentMode: public Service{
    protected:
        vector<FoodAndDrink> database_FoodAndDrink;
        vector<Room> database_Room;
    public:
        void Managment();
        void addFAD();
        void editFAD();
        void deleteFAD();
        void listFAD();
        void setRoom();
        void deleteRoom();
        void showRoom();
};

void ManagmentMode::Managment(){
    bool continueProgram = true;
    bool addMore = true;
    cout << "This is management mode!\n";
    int key = 0;
    do
    {
        cout << "1. Add food or drink" << endl;
        cout << "2. Edit food or drink from name" << endl;
        cout << "3. Delete food or drink from name" << endl;
        cout << "4. List food and drink" << endl;
        cout << "5. Set room" << endl;
        cout << "6. Delete room" << endl;
        cout << "7. show room" << endl;
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
            setRoom();
            break;
        case 6:
            deleteRoom();
            break;
        case 7:
            showRoom();
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

void ManagmentMode::setRoom(){
    int scant;
    cout << "Enter number of room want set: ";
    cin >> scant;
    Room tempRoom;
    for(int i = 1; i < scant; i++){
        tempRoom.STT = i;
        tempRoom.status = false;
        tempRoom.hour = 0;
        database_Room.push_back(tempRoom);
    }
}

void ManagmentMode::deleteRoom(){
    this->showRoom();
    int _stt;
    cout << "Enter the stt room you want to delete: ";
    cin >> _stt;
    for(int i = 0; i < database_Room.size(); i++){
        if(database_Room[i].STT == _stt){
            database_Room.erase(database_Room.begin() + i);
            cout << "Removed room whose id is " << _stt << endl;
        }
        if(database_Room[i].STT != _stt){
            continue;
        }
        else{
            cout << "Error!\n";
        }
    }
    _stt = 0;
}

void ManagmentMode::showRoom(){
    cout << "The room you seted" << endl;
    for(Room item: database_Room){
        cout << "STT -- Status -- Hour" << endl;
        cout << item.STT << "      ";
        if(item.status == false){
            cout << "occupied" << "   ";
        } 
        else {
            cout << "available" << "  ";
        }
        cout << item.hour << endl; 
    }
}

/*-------------------------------------------------------------------------------------*/
class Employee{
    private:

    public:
};

/*-------------------------------------------------------------------------------------*/
int main(int argc, char const *argv[])
{
    ManagmentMode a;
    a.Managment();
    return 0;
}
