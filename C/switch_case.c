#include <stdio.h>
#include <stdint.h>
#include <windows.h>        //Tiếng việt


int thang = 1;


int main(int argc, char const *argv[])
{
    SetConsoleOutputCP(CP_UTF8);        //Xuất tiếng việt dưới cmd
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Tháng %d có 31 day", thang);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Tháng %d có 30 day", thang);
        break;
    case 2:
        printf("Tháng %d có 28 or 29 day", thang);
        break;
    default:
        printf("Nhập sai tháng!");
        break;
    }

    return 0;
}

