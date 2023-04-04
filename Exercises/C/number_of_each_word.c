#include "stdio.h"
/*
    Bài tập: Kiểm tra các từ trong câu lặp lại mấy lần
    Tách các từ ra, rồi so sánh
    2 mảng bằng nhau cần: kích thước bằng nhau, giá trị mỗi kỹ tự bằng nhau
*/

#define LENG(arr) (sizeof(arr)/sizeof(arr[0]))

char array[] = "Binh thuong moi ngay toi deu lam viec, lam viec vat va de kiem tiem, kiem tiem de co the song, song mot cuoc song vui ve.";
//Đoạn văn có 27 từ, size của từ lớn nhất là 6

// Function so sánh 2 chuỗi bằng nhau không?
int wordCompare(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    if (*s1 > *s2) {
        return 1;
    } else if (*s1 < *s2) {
        return -1;
    } else {
        return 0;
    }
}

void numberOfEachWord(const char *InArray){
    char word[28][7];       
    int word_count = 0;     
    int word_index = 0;     
    int counts[28] = {0};   //Lưu số lần xuất hiện của từ trong đoạn văn
    for (int i = 0; InArray[i] != '\0'; i++)
    {
        if(InArray[i] == ' ' || (InArray[i] == ',' && InArray[i+1] == ' ') || InArray[i] == '.' || InArray[i] == '\0'){
            if(word_index > 0){
                word[word_count][word_index] = '\0';
                word_count++;
                word_index = 0;
            }
        }
        else{
            word[word_count][word_index] = InArray[i];
            word_index++;
        }
    }
    // printf("Number of words in sentence: %d\n", word_count);

    // Đếm số lần xuất hiện của từ trong đoạn văn
    for (int i = 0; i < word_count ; i++){
        if (counts[i] == 0) {       
            counts[i] = 1;
            for (int j = i + 1; j < word_count; j++)
            {
                if(wordCompare(word[i], word[j]) == 0){
                    counts[i]++;
                    counts[j] = -1;     // Đánh dẫu đã xét
                }
            } 
            // printf("%d ", counts[i]);
        }
    }
    //In ra các từ giống nhau và số lần xuất hiện 
    for (int i = 0; i < word_count; i++) {
        if (counts[i] > 0) {        //Điều kiện để bỏ qua counts[i] = -1
            printf("%s: %d\n", word[i], counts[i]);
        }
    }
} 

int main(int argc, char const *argv[])
{
    numberOfEachWord(array);
}

