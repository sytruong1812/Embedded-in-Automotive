## I: CLASS
### 1: Khai báo các thuộc tính (Peroperties) 
    - Thuộc tính của lớp có thể là biến, mảng, con trỏ có kiểu chuẩn (int, char, float...),hoặc kiểu ngoài đã được 
    định nghĩa trước (struct, union, class...).
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
### 4: Các từ khóa public, private, protected:
    - public: Các thành viên công khai (public) có thể được truy cập từ bất kỳ đâu trong chương trình, bao gồm cả 
    từ các lớp bên ngoài. Đây là phạm vi rộng nhất và cho phép tất cả các thành viên của lớp hoặc đối tượng được 
    truy cập một cách tự do.

    - protected: Các thành viên được bảo vệ (protected) chỉ có thể được truy cập từ bên trong lớp định nghĩa chúng 
    hoặc từ các lớp dẫn xuất (kế thừa) của lớp đó. Các thành viên protected không thể được truy cập từ bên ngoài lớp 
    hoặc đối tượng.

    - private: Các thành viên riêng tư (private) chỉ có thể được truy cập từ bên trong lớp định nghĩa chúng. 
    Các thành viên private không thể được truy cập từ các lớp dẫn xuất (kế thừa) hoặc từ bên ngoài lớp hoặc đối tượng.

    - Các đặc điểm chính của từ khóa protected, private, và public:
        + public: Có phạm vi rộng nhất, cho phép truy cập từ mọi nơi.
        + protected: Chỉ cho phép truy cập từ bên trong lớp định nghĩa chúng và các lớp dẫn xuất (kế thừa).
        + private: Chỉ cho phép truy cập từ bên trong lớp định nghĩa chúng.
        Sử dụng đúng từ khóa phù hợp là một phần quan trọng trong thiết kế lớp và quản lý độ an toàn của dữ liệu 
        trong lập trình hướng đối tượng.
### 5: Ví dụ:
```c
class className{
    private:                //Các thành phần private (riêng) chỉ được sử dụng trong class đó
        int a, b;           //Variable
        char arr[];         //Array
        int *ptr;           //Pointer
        className *ptr;       //Kiểu con trỏ của class đó
    protected:              //Các thành phần protected chỉ được sử dụng trong class hoặc các class kế thừa của class đó
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
## 6: Các tính chất trong lập trình hướng đối tượng (OOP)
### 1: Tính kế thừa
### 2: Tính trừu tượng
### 3: Tính đa hình
### 4: Tính đóng gói