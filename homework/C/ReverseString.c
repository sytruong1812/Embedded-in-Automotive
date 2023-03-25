#include "stdio.h"
#include "string.h"

#define LENG_ARRAY(arr)  (sizeof(arr)/sizeof(arr[0]))

char InputArray[] = {"Make no mistake. All your attempts to create a chilling effect a throttling effect a strangulating effect on open fearless speech relating to public influence will not stop either Rahul Gandhi or the Congress Party"};
char OutputArray[LENG_ARRAY(InputArray)];
//Đảo ngược chuỗi thành: Party Congress the or Gandhi Rahul.....


void ReverseString(const char InArray[], char OutArray[]){
    int count = 0;
    int j = 0;
    for (int i = LENG_ARRAY(InputArray); i >= 0; i--)        
    {
        if(i == LENG_ARRAY(InputArray) || i == LENG_ARRAY(InputArray)-1) continue;

        count++;

        if(InArray[i] == ' ')
        {
            for (int k = i; k < i + count; k++)
            {
                OutArray[j] = InArray[k+1];
                j++;
            }
            OutArray[j-1] = ' ';
            count = 0;
        }
        if(i == 0)
        {
            for (int k = i; k < i + count; k++)
            {
                OutArray[j] = InArray[k];
                j++;
            }
        }
    }
    for (int i = 0; i < LENG_ARRAY(InputArray); i++)
    {
        printf("%c", OutputArray[i]);
    }  
}

int main(int argc, char const *argv[])
{
    // printf("%d\n", sizeof(InputArray));
    ReverseString(InputArray, OutputArray);
    return 0;
}
