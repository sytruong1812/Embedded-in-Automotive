#include <stdio.h>
#include <stdint.h>

#define CURRENT_YEAR 2023

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp ngày tháng năm với các thuộc tính ngày, tháng và năm, và
các phương thức để tính tuổi của người và kiểm tra xem một ngày nhất
định có phải là ngày nghỉ lễ hay không.
*/

class DayMonthYear{
    private:
        uint8_t day;
        uint8_t month;
        uint8_t year;
    public:
        DayMonthYear(uint8_t _day, uint8_t _month, uint8_t _year);
        uint8_t calculateAge();
        uint8_t checkHoliday();
};

DayMonthYear::DayMonthYear(uint8_t _day, uint8_t _month, uint8_t _year){
    DayMonthYear::day = _day;
    DayMonthYear::month = _month;
    DayMonthYear::year = _year;
}

uint8_t DayMonthYear::calculateAge(){
    uint8_t age = CURRENT_YEAR - year;
    printf("Your age is: %d\n", age);
    return age;
}

uint8_t DayMonthYear::checkHoliday(){

}


int main(int argc, char const *argv[])
{
    DayMonthYear a(18, 12, 2001);
    a.calculateAge();
    a.checkHoliday();
    return 0;
}

