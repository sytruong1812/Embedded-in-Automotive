#include "stdio.h"
#include "stdint.h"

/*
    Nhập ngày-tháng-năm bất kỳ tính được ngày đó là ngày thứ mấy

    Công thức tính năm Nhuận: lấy số năm đem chia cho 4, nếu kết quả chia hết cho 4 
    thì năm nó là năm nhuận. Với những năm tròn thế kỷ có 2 số 00 ở cuối thì lấy số 
    năm chia cho 400, nếu kết quả chia hết cho 400 thì năm đó là năm nhuận.

    Số ngày trong 1 tháng.

    Ngày làm mốc: 1-1-1 -> thứ mấy trong tuần

    Ngày hiện tại: 25-3-2023 -> bao nhiêu ngày

    Từ ngày mốc đến ngày hiện tại có bao nhiêu ngày

    Từ số ngày đó chia lấy dư cho 7  

    Phần dư cộng với thứ của 1-1-2000 -> thứ 25-3-2023
*/

#define LEAP_YEAR(year) (year % 4 == 0) && (year % 100 !=0) || (year % 400 == 0)        // Declare a macro to calculate leap years

uint32_t sumDay;        // Declare a variable to store the total number of days

uint16_t numberOfDayInYear(uint16_t Year){          // The function checks for a leap year and returns the total number of days in that year
    if(LEAP_YEAR(Year)) return 366;
    return 365;
}

uint16_t numberOfDayInTheMonth(uint8_t Month, uint16_t Year){           // Function to check the number of days in a month and returns the total number of days in that month
    switch (Month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (LEAP_YEAR(Year)) return 29;                     // Check leap year and return the number of days in the corresponding month
        return 28;
        break;
    default:
        return 31;
        break;
    }
}

void dayOfWeek(uint8_t Day, uint8_t Month, uint16_t Year){          // Function calculates day of the week
    for (int i = 1; i < Year; i++)                  // The loop counts the total number of days from year 1 to year you want to find
    {
        sumDay += numberOfDayInYear(i);    
    }
    for (int i = 1; i < Month; i++){                 // The loop counts the total number of days from January to the month you want to find
        sumDay += numberOfDayInTheMonth(i, Year);
    }
    sumDay += Day;                  // Finally the total number of days = numberOfDayInYear + numberOfDayInTheMonth  + the day you want to find
    switch (sumDay % 7)             // Check and print the day of the week corresponding to the day/month/year you want to find, sumDay divides the remainder by 7
    {                                
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday,");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    default:
        printf("Invalid");
        break;
    }
}

int main(int argc, char const *argv[])
{
    dayOfWeek(27, 3, 2023);
    return 0;
}
