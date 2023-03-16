#include "stdio.h"
#include "string.h"

/*strcpy là một hàm trong thư viện string.h trong C/C++. 
Nó được sử dụng để sao chép nội dung của một chuỗi ký tự đến một chuỗi ký tự khác. 
Hàm này có hai tham số là một con trỏ đến vùng nhớ của chuỗi ký tự đích và một con trỏ 
đến vùng nhớ của chuỗi ký tự nguồn. Hàm strcpy sẽ sao chép toàn bộ nội dung của chuỗi 
ký tự nguồn đến vùng nhớ của chuỗi ký tự đích, bao gồm cả ký tự kết thúc chuỗi '\0'.*/

char value[5] = {1,2,3,6,9};

union data_frame
{
    struct data
    {
        char id[1];             //1byte
        char cmd[3];           //3byte
        char check_sum[1];      //1byte
    }sdata;
    char data_store[5];

};
union data_frame frame;

int main(int argc, char const *argv[])
{
    
    strcpy(frame.sdata.id, (char *)"1");        // Transmission
    strcpy(frame.sdata.cmd, (char *)"236");
    strcpy(frame.sdata.check_sum, (char *)"9");

    // strcpy(frame.data_store, value);            // Receive
    
    for (int i = 0; i < 5; i++)                 
    {
        printf("%c ", frame.data_store[i]);
    }
    return 0;
}
