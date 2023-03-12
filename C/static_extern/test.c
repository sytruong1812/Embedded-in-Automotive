#include <stdio.h>

static int c = 5;     //Biến static toàn cục, chỉ có giá trị trong file chứa nó
                        //Muốn người ta không thể can thiệp vào hàm, thư viện của mình
                        
static int MAX(int a, int b){      //Dùng biến static để ngăn người dùng gọi hàm ấy vào
    int max;                        //Qua file main.c mình không thể extern hàm test() này được
    if(a>b){
        max = a;
    }
    else{
        max = b;
    }
    return max;
}
void Count(){
    printf("Count: %d\n", c);
    c++;
}