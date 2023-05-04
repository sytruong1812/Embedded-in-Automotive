#include <stdio.h>
#include <string>
#include <cstring>
#include <stdint.h>
#include <iostream>
#include <vector>
using namespace std;

class DrinksAndFoods{
    protected:
        int id;
        string name;
        int price;
    public:
        DrinksAndFoods();
        void setDrinksAndFoods();
        void setID(int id);
        int getID();
        string getName();
        int getPrice();
        void setName();
        void setName(string name);
        void setPrice();
        void setPrice(int price);
        void setID();
};
DrinksAndFoods::DrinksAndFoods(){
    this->id = 0;
    this->name = " ";
    this->price = 0; 
}
void DrinksAndFoods::setDrinksAndFoods(){
    static int coutID = 2;
    this->id = (int)coutID;
    coutID++;
    cout<<"Enter name of Drink or Food:\n";
    cin>>this->name;
    cout<<"Enter price:"<<endl;
    cin>>this->price;
}
void DrinksAndFoods::setID(int id){
    this->id = id;
}
int DrinksAndFoods::getID(){
    return this->id;
}
string DrinksAndFoods::getName(){
    return this->name;
}
int DrinksAndFoods::getPrice(){
    return this->price;
}
void DrinksAndFoods::setName(){
    cout<<"Enter name of Drink or Food:\n";
    cin>>this->name;
}
void DrinksAndFoods::setName(string name){
    this->name = name;
}
void DrinksAndFoods::setPrice(){
    cout<<"Enter price:"<<endl;
    cin>>this->price;
}
void DrinksAndFoods::setPrice(int price){
    this->price = price;
}
void DrinksAndFoods::setID(){
    int id;
    cin>>id;
    this->id = id;
}

class Manager{
    private:
        vector<DrinksAndFoods> databaseDAF;
        uint8_t totalTables;
    public:
        void setTotalTables();
        void addDrinksAndFoods();
        void updateDrinksAndFoods();
        void deleteDrinksAndFoods();
        void getMenu();
        friend class ListOrder;
        friend class TableManagement;
};
void Manager::addDrinksAndFoods(){
    DrinksAndFoods temp;
    temp.setDrinksAndFoods();
    this->databaseDAF.push_back(temp);
}
void Manager::updateDrinksAndFoods(){
    cout<<"enter ID of Drink or Food you want to update:\n";
    int tempID;
    cin>> tempID;
    cout<<"what do you want to update? 1. Name   2.Price\n";
    int tempOption;
    cin>>tempOption;
    for(int i = 0; i < databaseDAF.size();i++){
        if(this->databaseDAF[i].getID() == tempID){
            if(tempOption == 1){
                databaseDAF[i].setName();
            }else if(tempOption == 2){
                databaseDAF[i].setPrice();
            }
        }
    }
}
void Manager::deleteDrinksAndFoods(){
    cout<<"enter ID of Drink or Food you want to delete:";
    int tempID;
    cin>> tempID;
    for(int i = 0; i < databaseDAF.size();i++){
        if((int)databaseDAF[i].getID() == tempID){
            databaseDAF.erase(databaseDAF.begin() + i);
        }
    }
}
void Manager::getMenu(){
    cout<<"**This is the restaurant's menu**\n"<<"STT: \tName: \tID: \tPrice: \n";
    for(int i = 0; i < databaseDAF.size();i++){
        cout<<"STT: "<<i+1<<"  Name: "<<databaseDAF[i].getName().c_str()<<" "<<"ID: ";
        printf("%d",databaseDAF[i].getID());
        cout<<" "<<"Price: "<<databaseDAF[i].getPrice()<<endl;
    }
}
void Manager::setTotalTables(){
    cout<<"enter total number of tables:"<<endl;
    cin>>this->totalTables;
}

class Order:public DrinksAndFoods{
    private:
    int quantityofThatItem;
    public:
    void setquantityofThatItem(int quantity){
        this->quantityofThatItem = quantity;
    }
    int getquantityofThatItem(){
        return this->quantityofThatItem;
    }
};


class ListOrder{
    private:
    vector<Order> databaseListOrder;
    public:
    void addOrder(Manager Manager);
    void updateOrder(Manager Manager);
    void deleteOrder();
    void getBill();
    void getListOrder();
};
void ListOrder::addOrder(Manager Manager){
    Order tempOrder;
    Manager.getMenu();
    cout<<"enter ID of Drink or Food you want to order:\n";
    int tempID;
    cin>>tempID;
    tempOrder.setID(tempID);
    for(DrinksAndFoods item:Manager.databaseDAF){
        if(((int)(item.getID())) == tempOrder.getID()){
            tempOrder.setName(item.getName().c_str());
            tempOrder.setPrice(item.getPrice());
        }
    }
    cout<<"quantity of "<<tempOrder.getName().c_str()<<"is: "<<endl;
    int tempQuantity;
    cin>>tempQuantity;
    tempOrder.setquantityofThatItem(tempQuantity);
    databaseListOrder.push_back(tempOrder);
}
void ListOrder::updateOrder(Manager Manager){
    cout<<"enter ID of Drink or Food you want to update:\n";
    int tempID;
    int tempOption;
    cin>>tempID;
    cout<<"chose options: \n1.update quatity.\n2.change DAF."<<endl;
    cin>>tempOption;
    for(Order item:databaseListOrder){
        if(item.getID() == tempID){
            if(tempOption == 1){
                cout<<"enter new quatity of Drink or Food:"<<endl;
                int tempQuantity;
                cin>>tempQuantity;
                item.setquantityofThatItem(tempQuantity);
            } else if(tempOption == 2){
                cout<<"enter new ID of Drink or Food:"<<endl;
                Order tempOrder;
                tempOrder.setID();
                for(DrinksAndFoods i:Manager.databaseDAF){
                    if(i.getID() == tempOrder.getID()){
                        tempOrder.setName(i.getName().c_str());
                        tempOrder.setPrice(i.getPrice());
                    }
                }
                cout<<"quantity of "<<tempOrder.getName().c_str()<<"is: "<<endl;
                int temp;
                cin>>temp;
                tempOrder.setquantityofThatItem(temp);
                item = tempOrder;
            }
        }
    }
}
void ListOrder::deleteOrder(){
    cout<<"enter ID of Drink or Food you want to delete:\n";
    int tempID;
    cin>>tempID;
    for(int i = 0; i < databaseListOrder.size();i++){
        if(databaseListOrder[i].getID() == tempID){
            databaseListOrder.erase(databaseListOrder.begin() + i);
        }
    }
}
void ListOrder::getListOrder(){
    cout<<"Your Order is: "<<endl;
    for(Order item:databaseListOrder){
        cout<<(int)item.getID()<<"   "<<item.getName().c_str()<<"   "<<item.getPrice()<<"  "<<item.getquantityofThatItem()<<endl;
    }
}
void ListOrder::getBill(){
    int totalMoney = 0;
    for(Order item:databaseListOrder){
        totalMoney = (int)(item.getPrice())*(item.getquantityofThatItem())+totalMoney;
    }
    cout<<"Your bill is: "<<totalMoney<<endl;
    cout<<"Thanks you"<<endl;
}

class Table{
    public:
        int position;
        bool bookATable;
        ListOrder listOrder;
        Table(){
        static int countPosition = 0;
        this->bookATable = false;
        this->position = countPosition;
        countPosition++;
        }
        void getTable(){
            cout<<"your table position is "<<this->position<<endl;
            this->listOrder.getListOrder();
        }
};


class TableManagement{
    public:
        vector<Table> databaseTables;
    void orderTM(Manager Manager);
    void updateTM(Manager Manager);
    void deleteTM();
    void getTM();
    void getBillTM(int positionTable);
};
void TableManagement::orderTM(Manager Manager){
    Table tempTable;
    tempTable.bookATable = true;
    tempTable.listOrder.addOrder(Manager);
    this->databaseTables.push_back(tempTable);
    this->databaseTables.back().getTable();
}
void TableManagement::updateTM(Manager Manager){
    cout<<"chua lam xong";
}
void TableManagement::deleteTM(){
    cout<<"chua lam xong";
}
void TableManagement::getTM(){
    cout<<"chua lam xong";
}
void TableManagement::getBillTM(int positionTable){
    this->databaseTables[positionTable].listOrder.getBill();
}


class RestaurantManagement{
    public:
        Manager manager;
        TableManagement staff;
        RestaurantManagement();
};

RestaurantManagement::RestaurantManagement(){
    int loop = 1;
    do{
    cout<<"chose option:\n1.manager\n2.staff\n3.Exit\n";
    int opt = 0;
    cin>>opt;
    switch (opt)
    {
    case 1:
    {
        cout<<"--------\n1.add Menu\n2.update Menu\n3.delete dish in Menu\n4.show Menu\n5.set total number of tables.\n6.exit\n";
        int key1 = 0;
        cin>>key1;
        switch (key1)
        {
        case 1:
            {
            int loopAddMenu = 1;
            do{
            this->manager.addDrinksAndFoods();
            cout<<"1. continue add Menu\n2.exit\n";
            int tempOption = 0;
            cin>>tempOption;
            if(tempOption == 2){
                loopAddMenu = 0;
            }
            }while(loopAddMenu);
            break;
            }
        case 2:
            this->manager.updateDrinksAndFoods();
            break;
        case 3:
            this->manager.deleteDrinksAndFoods();
            break;
        case 4:
            this->manager.getMenu();
            break;
        case 5:
            this->manager.setTotalTables();
            break;
        case 6:
            break;
        default:
            break;
        }
        break;}
    case 2:
        {
        cout<<"--------\n1.Order\n2.update order\n3.get bill\n4.exit\n";
        int key2 = 0;
        cin>>key2;
        switch (key2)
        {
        case 1:
        {
            this->staff.orderTM(manager);
            int tempOption;
            do{
            cout<<"1.continue order\n2.exit order\n";
            cin>>tempOption;
            if (tempOption == 1){
                this->staff.databaseTables.back().listOrder.addOrder(manager);
                this->staff.databaseTables.back().listOrder.getListOrder();

            }else if(tempOption == 2){
                break;
            }
            }while(1);
            break;
        }
        case 2:
            this->staff.updateTM(manager);
            break;
        case 3:
            {cout<<"enter position table that you want to get bill"<<endl;
            int i=0;
            cin>>i;
            this->staff.getBillTM(i);
            break;}
        case 4:
            break;
        default:
            break;
        }
        }
        break;
    case 3:
        loop = 0;
    default:
        break;
    }
} while(loop);
}
int main(int argc, char const *argv[])
{
    RestaurantManagement Highlands;
    return 0;
}