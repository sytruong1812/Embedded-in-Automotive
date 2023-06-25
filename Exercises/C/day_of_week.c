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

#define LEAP_YEAR(year) (year % 4 == 0) && (year % 100 !=0) || (year % 400 == 0)        // Khai báo macro để tính năm nhuận

uint32_t sumDay;        // Khai báo một biến lưu tổng số ngày

uint16_t numberOfDayInYear(uint16_t Year){          // Hàm kiểm tra năm nhuận và trả về tổng số ngày trong năm đó
    if(LEAP_YEAR(Year)) return 366;
    return 365;
}

uint16_t numberOfDayInTheMonth(uint8_t Month, uint16_t Year){           // Hàm kiểm tra số ngày trong tháng và trả về tổng số ngày trong tháng đó
    switch (Month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (LEAP_YEAR(Year)) return 29;         // Kiểm tra năm nhuận và trả về số ngày của tháng tương ứng
        return 28;
        break;
    default:
        return 31;
        break;
    }
}

void dayOfWeek(uint8_t Day, uint8_t Month, uint16_t Year){         //Hàm tính ngày trong tuần
    for (int i = 1; i < Year; i++)       // Vòng lặp đếm tổng số ngày từ năm 1 đến năm muốn tìm
    {
        sumDay += numberOfDayInYear(i);    
    }
    for (int i = 1; i < Month; i++){                 // Vòng lặp đếm tổng số ngày từ tháng 1 đến tháng muốn tìm
        sumDay += numberOfDayInTheMonth(i, Year);
    }
    sumDay += Day;                  // Cuối cùng tổng số ngày = numberOfDayInYear + numberOfDayInTheMonth + ngày bạn muốn tìm
    switch (sumDay % 7)             // Kiểm tra và in ra ngày trong tuần tương ứng với ngày/tháng/năm muốn tìm, sumDay chia dư cho 7
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
