#include <stdio.h>

union data_frame
{
    struct data
    {
        char id[1];     //1byte
        char cmd[3];        //3byte
        char check_sum[1];      //1byte
    }sdata;
    char data_store[5];
};

union data_frame frame_union;


int main(int argc, char const *argv[])
{
    printf("Size: %d\n", sizeof(frame_union));
    return 0;
}
