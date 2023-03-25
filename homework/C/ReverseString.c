#include "stdio.h"


char InputArray[] = {"Make no mistake. All your attempts to create a chilling effect a throttling effect a strangulating effect on open fearless speech relating to public influence will not stop either Rahul Gandhi or the Congress Party"};
char OutputArray[sizeof(InputArray)-1];
//Đảo ngược chuỗi thành: Party Congress the or Gandhi Rahul.....


void ReverseString(const char InArray[], char OutArray[]){
    int count = 0;
    int j = 0;
    for (int i = sizeof(InputArray); i >= 0; i--)        
    {
        if(i == sizeof(InputArray) || i == sizeof(InputArray)-1) continue;

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
    for (int i = 0; i < sizeof(OutputArray); i++)
    {
        printf("%c", OutputArray[i]);
    }  
}

int main(int argc, char const *argv[])
{
    // printf("Leng: %d\n", sizeof(InputArray));
    ReverseString(InputArray, OutputArray);
    return 0;
}
