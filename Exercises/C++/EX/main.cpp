#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

typedef enum{
    MALE,
    FEMALE
} Sex;

typedef enum{
    EXCELLENT,
    GOOD,
    AVERAGE,
    WEAK,
} Rank;

class Students{
    private:
        uint8_t id;
        string name;
        uint8_t age;
        Sex sex;
        float math;
        float physics;
        float chemistry;
        float medium;
        Rank rank;
    public:
        Students(string _name, uint8_t _age, Sex _sex, float _math, float _physics, float _chemistry);
        void setName(string name);
        string getName();
        void setAge(uint8_t age);
        uint8_t setAge();
        uint8_t getId();
        float getMedium();
        Rank getRank();
};

Students::Students(string _name, uint8_t _age, Sex _sex, float _math, float _physics, float _chemistry){
    static uint8_t _id = 100;
    this->id = _id;
    _id++;

}

Rank Students::getRank(){
    if(Students::getMedium() >= 8){
        return EXCELLENT;
    }
    else if(Students::getMedium() >= 6.5 ){
        return GOOD;
    }
    else if(Students::getMedium() >= 5){
        return AVERAGE;
    }
    else{
        return WEAK;
    }
}

class Menu{
    private:
        vector<Students> database;
    public:
        Menu();
        void addStudent();
        void updateStudent();
        void showList();
};

Menu::Menu(){
    printf("This is a student management program!\n");
    int key = 0;
    do
    {
        printf("1. Add Strudent\n");
        printf("2. Update Student\n");
        printf("3. Show list Student\n");
        scanf("%d", &key);
    } while (key <= 7);

    switch (key)
    {
    case 1:
        addStudent();
        break;
    case 2: 
        updateStudent();
        break;
    default:
        break;
    }
}

void Menu::addStudent(){
    string name;
    uint8_t age;

    printf();
    scanf();

    Students student(name, age);
    database.push_back(student);

}

void Menu::showList(){
    printf("ID: \tNAME: \tAGE: \tSEX: \n");
    for(Students item: database){
        printf();
    }
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
