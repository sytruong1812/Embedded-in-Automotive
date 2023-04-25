#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;
/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp người với các thuộc tính tên, tuổi và địa chỉ, và các
phương thức để in thông tin của người đó và tính tuổi của người đó.
*/

class Human{
    private:
        string name;
        int8_t age;
        int8_t address;
    public:
        Human(string _name, int8_t _age, int8_t _address);
        void showIdAndCalculateAge();
};

Human::Human(string _name, int8_t _age, int8_t _address){
    Human::name = _name;
    Human::age = _age;
    Human::address = _address;
}

void Human::showIdAndCalculateAge(){
    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
