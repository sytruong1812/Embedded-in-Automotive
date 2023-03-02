#include<stdio.h>

/*Khi 1 biến cục bộ được khai báo với từ khóa static. 
Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt 
thời gian chạy chương trình. Giá trị của nó không bị 
mất đi ngay cả khi kết thúc hàm*/

int in_so_thu_tu(void)
{
   static int x = 0;
   x = x + 1;
   printf("%d\r\n",x);
} 
 
int main() {
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 0
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 1
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 2
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 3
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 4
   return 0;
}