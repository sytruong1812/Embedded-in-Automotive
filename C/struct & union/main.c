#include "stdio.h"
#include "string.h"

char value[5] = {1,2,3,4,5};

union data_frame
{
    struct data
    {
        char id[1];             //1byte
        int cmd[3];           //3byte
        char check_sum[1];      //1byte
    }sdata;
    char data_store[5];

};
union data_frame frame;

int main(int argc, char const *argv[])
{
    strcpy(frame.data_store, value);
    return 0;
}
