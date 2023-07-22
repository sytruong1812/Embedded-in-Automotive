#include "stdio.h"
#include "stdint.h"
#include "string.h"

#define LENG_ARRAY(arr) (int)(sizeof(arr)/sizeof(arr[0]))

uint8_t array[] = {0,1,2,3,4,6,5,5,3,2,5,5,1,4,1,0};

//Sắp xếp mảng từ lớn đến bé
//Liệt kê các phần tử xuất hiện bao nhiêu lần

int len = LENG_ARRAY(array);

void Sort_Array_And_Count_Occurrences(){
    int x;
    int count = 1; 
    printf("Sort array from largest to smallest: ");
    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if(array[i] < array[j]){        //Check the previous variable < the following variable
                x = array[i];         
                array[i] = array[j];        //Reverse the position of 2 variables
                array[j] = x;             
            } 
        }
        printf("%d ", array[i]);
    }
    printf("\nThe number of occurrences of the variables in the array is:\n");
    for (int i = 0; i < len; i++)
    {
        if(array[i] == array[i+1]){         //Check the previous variable = the following variable
            count++;                    //Increase the count variable 
        }
        else{
            printf("Variable %d appears in the array %d times!\n", array[i], count); 
            count = 1;                  //Reassign counter = 1, a new count
        } 
    }   
}

int main(int argc, char const *argv[])
{
    // printf("Size array: %d\n", sizeof(array));       //Kích thước của kiểu dữ liệu
    // printf("Size array: %d\n", strlen(array));       //Chiều dài chuỗi
    // printf("Size array: %d\n", LENG_ARRAY(array));
    Sort_Array_And_Count_Occurrences();

    return 0;
}
