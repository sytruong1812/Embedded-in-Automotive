#include "stdio.h"
#include "string.h"

#define LENG_ARRAY(arr)  (int)(sizeof(arr)/sizeof(arr[0]))

//Đảo ngược chuỗi thành: Party Congress the or Gandhi Rahul.....

char InputArray[] = {"Make no mistake. All your attempts to create a chilling effect a throttling effect a strangulating effect on open fearless speech relating to public influence will not stop either Rahul Gandhi or the Congress Party"};
char OutputArray[LENG_ARRAY(InputArray)];
int len = LENG_ARRAY(InputArray);



void ReverseString(const char InArray[], char OutArray[]){
    int count = 0;
    int j = 0;
    for (int i = len; i >= 0; i--)        
    {
        if(i == len || i == len-1) continue;      //Gặp ký tự \0 thì bỏ qua

        count++;        //Đếm số lượng ký tự duyệt qua

        if(InArray[i] == ' ')       //Gặp khoảng trắng thì sao chép từ đó sáng mảng OutArray
        {
            for (int k = i; k < i + count; k++)
            {
                OutArray[j] = InArray[k+1];
                j++;
            }
            OutArray[j-1] = ' ';        //Thêm khoảng trắng giữa 2 từ sau khi đảo
            count = 0;
        }
        if(i == 0)      //Xử lý từ ở đầu câu
        {
            for (int k = i; k < i + count; k++)
            {
                OutArray[j] = InArray[k];
                j++;
            }
        }
    }
    for (int i = 0; i < len; i++)       //In chuỗi đã được đảo ra
    {
        printf("%c", OutputArray[i]);
    }  
}

int main(int argc, char const *argv[])
{
    // printf("%d\n", sizeof(InputArray));
    // printf("%d\n", sizeof(OutputArray));
    ReverseString(InputArray, OutputArray);
    return 0;
}
