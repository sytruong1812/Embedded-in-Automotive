# I: CLASS
### 1: Khai báo các thuộc tính (Peroperties) 
- Thuộc tính của lớp có thể là biến, mảng, con trỏ có kiểu chuẩn (int, char, float...),hoặc kiểu ngoài 
đã được định nghĩa trước (struct, union, class...).
- Thuộc tính của lớp không thể có kiểu của chính lớp đó, nhưng có thể là kiểu con trỏ của lớp đó.
### 2: Khai báo các phương thức (methods)
- Các phương thức thường để publis để chúng có thể gọi tới (sử dụng) từ các hàm khác trong chương trình. 
- Trong thân phương thức của lớp có thể sử dụng các thuộc tính, phương thức của lớp đó, các hàm tự lập trong 
chương trình. Vì phạm vi sử dụng của hàm là toàn chương trình.
### 3: Hàm tạo (Constructor)
- Constructor cũng là một methods của class dùng để tạo dựng một đối tượng mới từ đầu, và sẽ chạy đầu tiên.
- 3 điểm khác biệt của Constructor so với các methods khác:
    + Tên của constructor bắc buộc phải trùng với tên của Class
    + Không khai báo kiểu cho constructor.
    + Constructor không có kết quả trả về.
- Ngoài 3 điểm khác trên thì constructor giống với các methods khác:
    + Có thể được định nghĩa (xây dựng) bên trong hoặc ngoài class
    + Có thể có đối hoặc không có đối.
    + Trong class có thể có nhiều constructor cùng tên, nhưng khác bộ đối.
### 4: Ví dụ:
```c
class className{
    private:                //Các thành phần private (riêng) chỉ được sử dụng trong class đó
        int a, b;           //Variable
        char arr[];         //Array
        int *ptr;           //Pointer
        className *ptr;       //Kiểu con trỏ của class đó
    public:                 //Các thành phần public (công cộng) được phép sử dụng ở cả ngoài và trong class đó
        void sum();         //methods: Hàm tính tổng
        className(int _a = 0, int _b = 0);       //Khai báo constructor className có 2 đối là _a và _b
};

//Định nghĩa (xây dựng) các phương thức bên ngoài class
void className::sum(){
    int sum;
    sum = a + b;
    printf("Sum %d + %d = %d", a, b, sum);
}
//Định nghĩa (xây dựng) các constructor bên ngoài class
className::className(int _a, int _b){
    className::a = _a;
    className::b = _b;
}
```
