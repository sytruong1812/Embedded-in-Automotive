#include "stdio.h"

/* Câu hỏi PV: Cho một mảng số nguyên không âm và một số nguyên k, 
hãy viết chương trình để tìm tất cả các cặp số trong mảng 
mà tổng của chúng bằng k, sử dụng bitmask để tối ưu hóa thuật toán.*/

void input(int arr[5], int k){
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                printf("(%d,%d)", arr[i], arr[j]);
            }
        } 
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6};
    input(arr, 8);
    return 0;
}
