#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp tài khoản ngân hàng với các thuộc tính số tài khoản, tên tài
khoản và số dư, và các phương thức để rút, nộp tiền và kiểm tra số dư
trong tài khoản.
*/

class Bank{
    private:
        int stk;
        string name;
        double surplus;
    public:
        Bank(int _stk, string _name, double _surplus);
        int8_t withdrawMoney(double money_get);
        void checkSurplus();
};

Bank::Bank(int _stk, string _name, double _surplus){
    Bank::stk = _stk;
    Bank::name = _name;
    Bank::surplus = _surplus;
}

int8_t Bank::withdrawMoney(double money_get){
    Bank::surplus = Bank::surplus - money_get;
    printf("You just withdrew %.f from your account!\n", money_get);
    return money_get;
}

void Bank::checkSurplus(){
    printf("The balance of the account is: %.f\n", Bank::surplus);
}

int main(int argc, char const *argv[])
{
    Bank kevin(392, "Kevin", 3000);
    kevin.withdrawMoney(1000);
    kevin.checkSurplus();
    return 0;
}
