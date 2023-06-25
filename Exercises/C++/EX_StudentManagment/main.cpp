#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Quản lý sinh viên
*/

typedef enum{
    MALE,
    FEMALE
} Gender;

const char* readSex[] = {"MALE", "FEMALE"};

typedef enum{
    EXCELLENT,
    GOOD,
    AVERAGE,
    WEAK,
} Rank;

const char* readRank[] = {"EXCELLENT", "GOOD", "AVERAGE", "WEAK"};

class Students{
    private:
        int id;
        string name;
        int age;
        Gender sex;
        float math;
        float physics;
        float chemistry;
        float gpa;
        Rank rank;
    public:
        Students();
        void setStudent();
        void getStudent();
        string getName();
        uint8_t getAge();
        Gender getSex();
        uint8_t getID();
        float getGPA();
        Rank getRank();
};

Students::Students(){
    static int _id = 1;
    this->id = _id;
    _id++;
}

void Students::setStudent(){
    static int typeSex;
    cin.ignore(1000,'\n'); 
    cout << "Enter your name: ";
    getline(cin, this->name);

    cout << "Enter your age: ";
    cin >> age;

    cin.ignore(1000,'\n'); 
    cout << "(Gender: MALE = 0, FEMALE = 1)\nEnter gender: ";
    cin >> typeSex;
    if(typeSex == 0) this->sex = MALE;
    if(typeSex == 1) this->sex = FEMALE;

    cin.ignore(1000,'\n');
    cout << "Enter your math score: ";
    cin >> this->math;
    cout << "Enter your physical score: ";
    cin >> this->physics;
    cout << "Enter your chemistry score: ";
    cin >> this->chemistry;
    getRank();
    getGPA();
}

uint8_t Students::getID(){
    return this->id;
}

string Students::getName(){
    return this->name;
}

uint8_t Students::getAge(){
    return this->age;
}

Gender Students::getSex(){
    if(this->sex == 0) return MALE;
    if( this->sex == 1) return FEMALE;
    return sex;
}

float Students::getGPA(){
    return this->gpa = (math + physics + chemistry)/3.0;
}

Rank Students::getRank(){
    if(Students::getGPA() >= 8){
        this->rank = EXCELLENT;
    }
    else if(Students::getGPA() >= 6.5 ){
        this->rank = GOOD;
    }
    else if(Students::getGPA() >= 5){
        this->rank = AVERAGE;
    }
    else{
        this->rank = WEAK;
    }
    return rank;
}

void Students::getStudent(){
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
    cout << "Gender: " << readSex[this->sex] << endl;
    cout << "Math score: " << this->math << endl;
    cout << "Physics score: " << this->physics << endl;
    cout << "Chemistry score: " << this->chemistry << endl; 
    cout << "GPA: " << this->gpa << endl; 
    cout << "Rank: " << readRank[this->rank] << endl; 
}

class Menu{
    private:
        vector<Students> database;
    public:
        Menu();
        void addStudent();
        void updateStudent();
        void removeStudent();
        void searchStudent();
        void sortStudentByGPA();
        void sortStudentByName();
        void showListStudent();
};

Menu::Menu(){
    bool continueProgram = true;
    cout << "This is a student management program!\n";
    int key = 0;
    do
    {
        cout << "1. Add student\n";
        cout << "2. Update student information from ID\n";
        cout << "3. Remove student from ID\n";
        cout << "4. Search students by name\n";
        cout << "5. Sort students by GPA\n";
        cout << "6. Sort students by name\n";
        cout << "7. Show list student\n";
        cout << "Enter key: ";
        cin >> key;

        switch (key)
        {
        case 1:
            addStudent();
            break;
        case 2: 
            updateStudent();
            break;
        case 3:
            removeStudent();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            sortStudentByGPA();
            break;
        case 6:
            sortStudentByName();
            break;
        case 7:
            showListStudent();
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

void Menu::addStudent(){
    Students HS;
    HS.setStudent();
    database.push_back(HS);
}

void Menu::updateStudent(){
    static int _id;
    cout << "Enter ID of Student who you want to update: ";
    cin >> _id;
    for(int i = 0; i < database.size(); i++){
        if(database[i].getID() == _id){
            database[i].setStudent();
        }
        else{
            cout << "Error!\n";
        }
    }
}

void Menu::removeStudent(){
    static int _id;
    cout << "Enter ID of Student who you want to remove: ";
    cin >> _id;
    for(int i = 0; i < database.size(); i++){
        if(database[i].getID() == _id){
            database.erase(database.begin() + i);
            cout << "Removed student whose id is " << _id << endl;
        }
        else{
            cout << "Error!\n";
        }
    }
}

void Menu::searchStudent(){
    static string _name;
    cout << "Enter name of Student who you want search: ";
    cin.ignore(100,'\n');
    getline(cin, _name);
    for(int i = 0; i < database.size(); i++){
        if(database[i].getName() == _name){
            database[i].getStudent();
        }        
        else{
            cout << "Error!\n";
        }
    }
    _name.clear();
}

void Menu::sortStudentByGPA(){
    Students tempHS;
    for(int i = 0; i < database.size(); i++){
        for(int j = i+1; j < database.size(); j++)
        {
            if(database[i].getGPA() > database[j].getGPA()){
                    tempHS = database[i];
                    database[i] = database[j];
                    database[j] = tempHS;
            }
        }
    }
}

void Menu::sortStudentByName(){
    Students tempHS;
    for(int i = 0; i < database.size(); i++){
        for(int j = i+1; j < database.size(); j++)
        {
            if(database[i].getName() > database[j].getName()){
                    tempHS = database[i];
                    database[i] = database[j];
                    database[j] = tempHS;
            }
        }
    }
}

void Menu::showListStudent(){
    cout << "---------Show List Student---------" << endl;
    for(Students item: database){
        item.getStudent();
    }
}


int main(int argc, char const *argv[])
{
    Menu Students;
    return 0;
}