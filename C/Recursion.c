#include <stdio.h>

/*
Một hàm đệ quy thường có cấu trúc như sau:

    - Điều kiện dừng (base case): Đây là điều kiện để dừng việc gọi đệ quy và trả về kết quả cuối cùng. 
      Nếu không có điều kiện dừng, hàm có thể gọi chính nó một cách vô tận và gây ra lỗi tràn bộ nhớ (stack overflow).
    - Công thức đệ quy: Hàm gọi chính nó với một đầu vào giảm dần hoặc thay đổi để tiến tới điều kiện dừng.
      
Khi một hàm được gọi đệ quy, mỗi lần gọi tạo ra một bản sao riêng của hàm trên ngăn xếp (stack) để lưu trữ 
các biến cục bộ và điểm tiếp theo cần thực hiện. Hàm được gọi đệ quy sẽ tiếp tục gọi chính nó cho đến khi 
đạt tới điều kiện dừng, sau đó các bản sao hàm sẽ được giải phóng từ ngăn xếp một cách tuần tự. 

VD: Tính giai thừa n! = n*(n-1)*....*3*2*1 bằng cách dùng đệ quy 
*/

int Recursion(int nInput) {
    if (nInput == 0) {
        return 1;
    }
    return nInput * Recursion(nInput - 1);      //Dùng đệ quy gọi lại chính nó.
}

int main() {
    int Result;
    int nInput;
    scanf("%d", &nInput);
    Result = Recursion(nInput);
    printf("%d! = %d", nInput, Result);
    return 0;
}
