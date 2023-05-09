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

class HotelRoom{
    private:
        Room room;
    public:
        HotelRoom();
        void setHotelRoom();
        void rentByTheHour();
        void rentOvernight();
        int getHour();
};

HotelRoom::HotelRoom(){
    static int _stt = 0;
    room.STT = _stt;
    _stt++;
}

void HotelRoom::setHotelRoom(){
    int option;
    cout << "Enter 1: Room rental by the hour | " << "2: Rent overnight. " << endl;
    cout << "Enter service number: ";
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


void HotelRoom::rentByTheHour(){
    cout << "Enter the number of hour you want: ";
    cin >> this->room.hour;
}

void HotelRoom::rentOvernight(){
    cout << "Overngiht is 12 hours!" << endl;
    this->room.hour = 12;
}

int HotelRoom::getHour(){
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
class ManagmentMode{
    protected:
        static vector<FoodAndDrink> database_FoodAndDrink;
        static vector<Room> database_Room;
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
    cout << "-------------------------" << endl;
    cout << "This is management mode!" << endl;
    cout << "-------------------------" << endl;
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
        int key = 0;
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
    for(int i = 0; i < scant; i++){
        tempRoom.STT = i;
        tempRoom.status = true;
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

vector<FoodAndDrink> ManagmentMode::database_FoodAndDrink;
vector<Room> ManagmentMode::database_Room; 

typedef struct{
    int room;
    int id;
    string name;
    int cost;
    int count; 
} RoomOrder;

/*-------------------------------------------------------------------------------------*/
class EmployeeMode: public HotelRoom, public ManagmentMode{
    protected:
        vector<RoomOrder> database_roomOrder;
        HotelRoom _room;
        int tempRoom;
    public:
        void Employee();
        void choseRoom();
        void choseService();
        void choseDish();
        void editDish();
        void deleteDish();
        void checkOutRoom();
        void getMoneyRoom();
};

void EmployeeMode::Employee(){
    bool continueProgram = true;
    bool again = true;
    cout << "-------------------------" << endl;
    cout << "This is employee mode!" << endl;
    cout << "-------------------------" << endl;
    do
    {
        cout << "1. Chose Room" << endl;
        cout << "2. Chose Service" << endl;
        cout << "3. Check Out Room" << endl;
        cout << "4. Get Money Room" << endl;
        cout << "Enter key: ";
        int key = 0;
        cin >> key;
        switch (key)
        {
        case 1:
            while (again) {
                choseRoom();
                cout << "Enter 1 to choose more - 0 to break: ";
                cin >> again;
            }
            again = true;
            break;
        case 2: 
            choseService();
            break;
        case 3:
            checkOutRoom();
            break;
        case 4:
            getMoneyRoom();
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

void EmployeeMode::choseRoom(){
    ManagmentMode::showRoom();
    cout  << "Enter the room you want to chose: ";
    cin >> this->tempRoom;
    for(int i = 0; i < database_Room.size(); i++){
        if(database_Room[i].STT == this->tempRoom){
            database_Room[i].status = false;
            cout << "------------------ROOM " << this->tempRoom <<"-------------------" << endl;
            _room.setHotelRoom();
            database_Room[i].hour = _room.getHour();
        }
    }
    this->tempRoom = 0;
}

void EmployeeMode::choseDish(){
    cout << "---This is the list menu---" << endl;
    ManagmentMode::listFAD();
    RoomOrder tempOrder;
    int temp_id;
    cout << "what do you want order?\n" << "Enter dish id: ";
    cin >> temp_id;
    for(int i = 0; i < database_FoodAndDrink.size(); i++){
        if(database_FoodAndDrink[i].getID() == temp_id){
            tempOrder.room = this->tempRoom;
            tempOrder.id = database_FoodAndDrink[i].getID();
            tempOrder.name = database_FoodAndDrink[i].getName();
            tempOrder.cost = database_FoodAndDrink[i].getCost();
        }
    }
    cout << "Number of dish: " ;
    cin >> tempOrder.count;
    database_roomOrder.push_back(tempOrder);
}
void EmployeeMode::editDish(){
    int _id_old;
    int _id_new;
    cout << "Enter old ID you want to edit: ";
    cin >> _id_old;
    cout << "Enter new ID to edit: ";
    cin >> _id_new;
    for(int i = 0; i < database_roomOrder.size(); i++){
        if(database_roomOrder[i].id == _id_old){
            database_roomOrder[i].id = _id_new;
        }
        if(database_roomOrder[i].id != _id_old){
            continue;
        }
        else{
            cout << "Error!\n";
        }
    }
    _id_new = 0;
    _id_old = 0;

}
void EmployeeMode::deleteDish(){
    int _id;
    cout << "Enter ID of dishes you want to remove: ";
    cin >> _id;
    for(int i = 0; i < database_roomOrder.size(); i++){
        if(database_roomOrder[i].id == _id){
            database_roomOrder.erase(database_roomOrder.begin() + i);
            cout << "Removed dishes whose id is " << _id << endl;
        }
        if(database_roomOrder[i].id != _id){
            continue;
        }
        else{
            cout << "Error!\n";
        }
    }
    _id = 0;
}

void EmployeeMode::choseService(){
    bool continueProgram = true;
    ManagmentMode::showRoom();
    cout  << "Enter the room you want order dish: ";
    cin >> this->tempRoom;
    for(int i = 0; i < database_Room.size(); i++){
        if(database_Room[i].STT == this->tempRoom){
            do
            {
                int option;
                cout << "--------Chose Service-------" << endl;
                cout << "1. Chose Dish\t2. Edit Dish\t3. Delete Dish" << endl;
                cout << "Enter option: ";
                cin >> option;
                switch (option)
                {
                case 1:
                    this->choseDish();
                    break;
                case 2:
                    this->editDish();
                    break;
                case 3:
                    this->deleteDish();
                    break;
                default:
                    cout << "Invalid option, please try again.\n";
                    break;
                }
                if (continueProgram) {
                    cout << "Do you want to continue?\n" << "Enter 1 to continue or 0 to end: ";
                    cin >> continueProgram;
                }
            } while (continueProgram);  
        }
    }
    this->tempRoom = 0;  
}

void EmployeeMode::checkOutRoom(){

}

void EmployeeMode::getMoneyRoom(){

}
/*-------------------------------------------------------------------------------------*/
int main(int argc, char const *argv[])
{
    bool loop = true;
    int option;
    ManagmentMode a;
    EmployeeMode b;
    do
    {
        cout << "-------------------------" << endl;
        cout << "\tMain Menu"<<endl;
        cout << "-------------------------" << endl;
        cout << "1. ManagerMode" << endl;
        cout << "2. EmployeeMode" << endl;
        cout << "3. Exit!" << endl;
        cout << "Enter: ";
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
