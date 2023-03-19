#include "stdio.h"

void tim_nguoi(int ma){
    char* ds[] = {
        "Ma sai",               //ds[0]
        "Nguyen Thi Anh",       //ds[1]
        "Nguyen Van Toan",      //ds[2]
        "Pham Van Tri",         //ds[3]
        "Do Hung Dung",         //ds[4]
        "Le Van Vu"             //ds[5]
    };
    printf("Ma %d: %s\n", ma, (ma<1 || ma>5) ? ds[0] : ds[ma]);
                            // (condition) ? expression1 : expression2
                            // condition là một biểu thức điều kiện.
                            // expression1 được thực thi nếu condition là đúng.
                            // expression2 được thực thi nếu condition là sai.
}

int main(int argc, char const *argv[])
{
    int i;
    printf("Can tim nguoi thu: ");
    scanf("%d", &i);
    tim_nguoi(i);
    return 0;
}
