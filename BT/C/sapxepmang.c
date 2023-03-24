#include "stdio.h"
#include "stdint.h"

uint8_t arr[] = {1,2,3,4,6,5,5,3,2,5,5,1,4,1};

//Sắp xếp mảng từ lớn đến bé
//Liệt kê các phần tử xuất hiện bao nhiêu lần

void Sort_Array_And_Count_Occurrences(){
    int x;
    int count = 1; 
    printf("Sort array from largest to smallest: ");
    for (int i = 0; i < sizeof(arr); i++){
        for (int j = i + 1; j < sizeof(arr); j++){
            if(arr[i] < arr[j]){
                x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            } 
        }
        printf("%d ", arr[i]);
    }
    printf("\nThe number of occurrences of the variables in the array is:\n");
    for (int i = 0; i < sizeof(arr); i++)
    {
        if(arr[i] == arr[i+1]){
            count++;
        }
        else{
            printf("Variable %d appears in the array %d times!\n", arr[i], count); 
            count = 1;
        } 
    }   
}

int main(int argc, char const *argv[])
{
    Sort_Array_And_Count_Occurrences();

    return 0;
}
