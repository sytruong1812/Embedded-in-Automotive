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

#define LeapYear(year) (year % 4 == 0) && (year % 100 !=0) || (year % 400 == 0)

uint32_t sumDay;

uint16_t numberOfDayInYear(uint16_t Year){
    if(LeapYear(Year)) return 366;
    return 365;
}

uint16_t numberOfDayInTheMonth(uint8_t Month, uint16_t Year){
    switch (Month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (LeapYear(Year)) return 29;
        return 28;
        break;
    default:
        return 31;
        break;
    }
}

void dayOfWeek(uint8_t Day, uint8_t Month, uint16_t Year){
    for (int i = 1; i < Year; i++)
    {
        sumDay += numberOfDayInYear(i);
    }
    for (int i = 1; i < Month; i++)
    {
        sumDay += numberOfDayInTheMonth(i, Year);
    }
    sumDay += Day;
    switch (sumDay % 7)
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
