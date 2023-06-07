## I: Class
    - Class (lớp) là một mô tả hoặc một bản thiết kế cho một đối tượng cụ thể. Dùng để định nghĩa các thuộc tính (đặc điểm) 
      và phương thức (hành vi) mà đối tượng có thể có.
    - Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
    - Một class bao gồm các thành phần dữ liệu (thuộc tính hay Property) và các phương thức (hàm thành phần hay method)
    - Class gần giống với struct. Khác ở chỗ các member trong struct là các biến còn trong class được gọi là các property.
    - Phân vùng nhớ của Class phụ thuộc vào đối tượng được của Class được khai báo ở đâu và như thế nào.
#### 1: Khai báo các thuộc tính (Property) 
    - Thuộc tính của Class có thể là biến, mảng, con trỏ có kiểu chuẩn (int, char, float...),hoặc kiểu ngoài đã được 
      định nghĩa trước (struct, union, class...)
    - Thuộc tính của Class không thể có kiểu của chính lớp đó, nhưng có thể là kiểu con trỏ của lớp đó.
```Cpp
class MyClass {
public:
    int num;
    float values[10];
    OtherClass* ptr;
    struct InnerStruct {
        //...
    };
    union InnerUnion {
        //...
    };
    //...
};
```
#### 2: Khai báo các phương thức (Methods)
    - Phương thức cũng giống như một hàm bình thường thể hiện hành động của đối tượng.
    - Các phương thức thường để chế độ Public để chúng có thể gọi tới (sử dụng) từ các hàm khác trong chương trình. 
    - Trong thân các Methods của Class có thể sử dụng các thuộc tính và Methods của lớp đó và cả các hàm tự tạo 
      trong chương trình (hàm không thuộc Class) vì phạm vi của hàm là toàn chương trình.
    - Phạm vi sử dụng của một Methods trong Class là toàn chương trình, vì vậy nó có thể được gọi và sử dụng từ 
      bất kỳ nơi nào trong chương trình, miễn là có quyền truy cập đến lớp đó.
```Cpp
class MyClass {
public:
    int num;
    void myMethod() {
        // Sử dụng thuộc tính của lớp
        num = 10;
        // Gọi phương thức của lớp
        anotherMethod();
        // Gọi hàm tự lập trong chương trình
        externalFunction();
    }
    void anotherMethod() {
        //...
    }
};
// Hàm tự lập trong chương trình
void externalFunction() {
    //...
}
int main() {
    MyClass obj;
    obj.myMethod();
    return 0;
}
```
#### 3: Các phạm vi truy cập các thuộc tính và phương thức trong Class: Public, Private, Protected
    - Public: Các thành viên ở chế độ Public có thể được truy cập từ bất kỳ đâu trong chương trình, bao gồm cả từ các Class bên ngoài.
    - Private: Các thành viên ở chế độ Private chỉ có thể được truy cập từ bên trong Class định nghĩa chúng. 
      Các thành viên Private không thể được truy cập từ các Class kế thừa hoặc từ bên ngoài Class hoặc đối tượng.
    - Protected: Các thành viên ở chế độ protected chỉ có thể được truy cập từ bên trong Class định nghĩa chúng 
      hoặc từ các Class kế thừa của Class đó. Các thành viên protected không thể được truy cập từ bên ngoài Class hoặc đối tượng.

    - Các đặc điểm chính của từ khóa Protected, Private, và Public:
        + Public: Có phạm vi rộng nhất, cho phép truy cập từ mọi nơi trong chương trình.
        + Private: Chỉ cho phép truy cập từ bên trong Class định nghĩa chúng.
        + Protected: Chỉ cho phép truy cập từ bên trong Class định nghĩa chúng và các Class kế thừa (dẫn xuất).
    - Sử dụng đúng từ khóa phù hợp là một phần quan trọng trong thiết kế Class và quản lý độ an toàn của dữ liệu trong OOP.
#### 4: Constructor (Hàm tạo)
    - Constructor cũng là một methods của class dùng để tạo dựng một đối tượng mới từ đầu, và sẽ chạy đầu tiên.
    - Nếu không khai báo constructor thì class sẽ tự động tạo ra constructor mặc định (constructor không có tham số).
      Và constructor này sẽ không làm gì cả.
    - Có 3 điểm khác biệt của Constructor so với các methods khác:
        + Tên của constructor bắc buộc phải trùng với tên của Class
        + Không khai báo kiểu cho constructor.
        + Constructor không có kết quả trả về.
    - Ngoài 3 điểm khác trên thì constructor giống với các methods khác:
        + Có thể được định nghĩa (xây dựng) bên trong hoặc ngoài class
        + Có thể input parameter hoặc không  input parameter (Có đối số / Không có đối số)
        + Trong class có thể có nhiều constructor cùng tên, nhưng khác input parameter.
### 5: Ví dụ:
```c
class className{
    private:                //Các thành phần private (riêng) chỉ được sử dụng trong class đó
        //Khai báo các thuộc tính
        int a, b;           //Variable
        char arr[];         //Array
        int *ptr;           //Pointer
        className *ptr;       //Kiểu con trỏ của class đó
    protected:              //Các thành phần protected chỉ được sử dụng trong class hoặc các class kế thừa của class đó
    public:                 //Các thành phần public (công cộng) được phép sử dụng ở cả ngoài và trong class đó
        className(int _a = 0, int _b = 0);       //Khai báo constructor className có 2 đối là _a và _b
        void sum();         //Khai báo methods (phương thức): Hàm tính tổng
};
//Định nghĩa (xây dựng) các constructor bên ngoài class
className::className(int _a, int _b){
    className::a = _a;
    className::b = _b;
}
//Định nghĩa (xây dựng) các phương thức bên ngoài class
void className::sum(){
    int sum;
    sum = a + b;
    printf("Sum %d + %d = %d", a, b, sum);
}
```
## II: Các tính chất trong lập trình hướng đối tượng (OOP): Kế thừa, Trừu tượng, Đa hình, Đóng gói.
#### 1. Tính kế thừa: 
    - Một class có thể sử dụng các *thuộc tính* và *phương thức* đặt trong phạm vi *public* hoặc *protected* 
      của *class* khác mà không cần phải viết lại từ đầu.
    - Ví dụ: *class B* muốn sử dụng các *thuộc tính* và *phương thức* giống *class A* mà không phải viết lại từ đầu, 
      khi đó *class B* sẽ *kế thừa* từ *class A*. Sử dụng toán tử `:`
```Cpp
class ClassA:ClassB { 
    ...
}
```
    - Ngoài ra, *class B* cũng có thể ghi đè/implement lại *phương thức* kế thừa từ *class A*.
#### 2. Tính trừu tượng: 
    - Người dùng chỉ cần tập trung vào đầu vào và đầu ra của dữ liệu cần xử lý, không cần biết dữ liệu đầu vào 
      được xử lý ra làm sao để có được đầu ra.Tức là người dùng chỉ cần gọi các *phương thức* ra sử dụng, sau đó 
      nhận kết quả chứ không cần quan tâm phần implement của phương thức đó. Có thể hiểu là chương trình bỏ qua sự phức tạp 
      bằng cách tập trung vào cốt lõi của thông tin cần xử lý.
#### 3. Tính đa hình: 
    - Các *phương thức* trong *class* có thể có cùng tên nhưng lại có thể cho ra các kết quả khác nhau, phụ thuộc 
      vào kiểu trả về của *phương thức*, kiểu dữ liệu *input parameter* và thứ tự của chúng.
```Cpp
class TinhTong {
    public:
        void tong(int, int);
        int tong(int, int);
        float tong(float, float);
};
...
int main() {
    TinhTong sum;
    sum.tong(1, 1);
    printf("%d", sum.tong(1, 1));
    printf("%f", sum.tong(1.1, 1.2));

    return 0;
}
```
#### 4. Tính đóng gói:
    - Chỉ để lộ ra các dữ liệu mà người dùng cần, che dấu đi các dữ liệu cần thiết. 
    - Người dùng không thể tác động vào các dữ liệu bị che dấu mà chỉ bên trong đối tượng đó mới có thể tác động. 
      Do đó, đảm bảo được tính an toàn của đối tượng. 
    - Ví dụ:
```Cpp
class Person {
    private:
        string _ten;
        int _tuoi;
        string _queQuan;
        int _sdt;
    public:
        Person(string, int, string, int);
        void hienThiThongTin();
        void suaThongTin(string, int, string, int);
};
...
int main() {
    Person A("Ngoc", 25, "Bac Ninh", 0987654321);
    A.hienThiThongTin();
    A.suaThongTin();
    A._ten;         //lỗi, không được phép

    return 0;
}
```
    - Trong ví dụ trên, ta không thể truy cập trực tiếp vào các *thuộc tính* của *class Person* vì nó thuộc 
      *private* mà phải thông qua các *phương thức* được *public*.
    - Do đó, các *thuộc tính* đã bị *đóng gói* không thể được truy xuất bằng cách thông thường `A._ten` mà phải 
      thông qua *phương thức* được *public* thuộc *class Person*.

## III: Namespace
    - Namespace trong C++ là một cơ chế cho phép nhóm các tên (biến, hàm, lớp, v.v.) vào một tên duy nhất. 
    - Nó giúp ngăn chặn xung đột tên và hỗ trợ việc tổ chức và quản lý mã nguồn trong dự án lớn. 
    - Bằng cách đặt các thành phần vào các namespace khác nhau, chúng ta có thể xác định rõ ngữ cảnh của 
```Cpp
#include <iostream>
// Định nghĩa namespace MyMath
namespace MyMath {
    int sum(int a, int b) {
        return a + b;
    }
    int abc(int a, int b){
        return a - b
    }
}
int main() {
    // Sử dụng hàm sum() trong namespace MyMath
    int result = MyMath::sum(5, 3);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```
## IV: Typedef
    - Trong C++, typedef được sử dụng để định danh (alias) một kiểu dữ liệu có sẵn (int, float, long, double...) 
      bằng một cái tên khác, tạo ra một tên mới cho kiểu dữ liệu đó. Điều này giúp làm cho mã nguồn dễ đọc 
      hơn và cung cấp tính linh hoạt trong việc thay đổi kiểu dữ liệu.
    - VD: Khai báo Typedef
```Cpp
typedef int myInt;     //myInt được định danh (alias) cho kiểu dữ liệu int.
myInt x = 5;           //Có thể sử dụng myInt như một kiểu dữ liệu tương tự như int:

typedef int MyArray[10];       //MyArray là một định danh (alias) cho kiểu mảng int[10].
MyArray arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};      //Có thể sử dụng MyArray để định nghĩa một mảng int có độ dài 10:
```
## V: Template
    - Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho 
      các kiểu dữ liệu int, float, double, bool...
    - Template trong C++ có 2 loại đó là function template & class template.
    - Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) 
      cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.
    - VD: Viết 1 hàm template tính tổng của hai giá trị
```Cpp
template <typename T>   //khai báo một template với một tham số kiểu T.
T sum(T a, T b) {
    return a + b;
}
//Sau đó, hàm sum có thể được sử dụng cho nhiều kiểu dữ liệu khác nhau như int, float, double,...
main(){
    int result1 = sum(10, 5);       // result1 = 15
    float result2 = sum(3.14, 2.71); // result2 = 5.85
}
```
## VI: Virtual Function (Hàm ảo)
    - Hàm ảo (virtual function) là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần phải định nghĩa lại.
    - Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định nghĩa lại trong lớp dẫn xuất. 
      Việc này rất cần thiết trong trường hợp con trỏ có kiểu là lớp cơ sở trỏ đến đối tượng của lớp dẫn xuất.
    - Hàm ảo là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa được hỗ trợ bởi nguồn ngữ C++.
    - Lưu ý: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, nhưng ngược lại thì không được.
    - Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử dụng hàm ảo khi muốn con trỏ đang trỏ 
      tới đối tượng của lớp nào thì hàm thành phần của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.
```Cpp
#include <iostream>
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a sound." << std::endl;
    }
};
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks." << std::endl;
    }
};
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows." << std::endl;
    }
};
//Hai lớp con Dog và Cat kế thừa từ lớp Animal và ghi đè hàm makeSound() để cung cấp triển khai riêng.
int main() {
// Tạo hai đối tượng thông qua con trỏ của lớp cơ sở Animal, nhưng khi gọi phương thức makeSound(), 
// hành vi được xác định bởi loại đối tượng thực tế mà con trỏ đang trỏ tới.
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound(); // Kết quả: "Dog barks."
    animal2->makeSound(); // Kết quả: "Cat meows."
// Cùng một phương thức được gọi, nhưng cho ra kết quả khác nhau dựa trên loại đối tượng thực tế.
    delete animal1;
    delete animal2;
    return 0;
}
```
