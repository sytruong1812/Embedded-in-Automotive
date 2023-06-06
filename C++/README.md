## I: Class
    - Class (lớp) là một mô tả hoặc một bản thiết kế cho một đối tượng cụ thể. Dùng để định nghĩa các thuộc tính (đặc điểm) 
      và phương thức (hành vi) mà đối tượng có thể có.
    - Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
    - Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method)
    - Class gần giống với struct. Khác ở chỗ các member trong struct là các biến còn trong class được gọi là các property.
### 1: Khai báo các thuộc tính (Peroperties) 
    - Thuộc tính của lớp có thể là biến, mảng, con trỏ có kiểu chuẩn (int, char, float...),hoặc kiểu ngoài đã được 
      định nghĩa trước (struct, union, class...)
    - Thuộc tính của lớp không thể có kiểu của chính lớp đó, nhưng có thể là kiểu con trỏ của lớp đó.
### 2: Khai báo các phương thức (methods)
    - Các phương thức thường để publis để chúng có thể gọi tới (sử dụng) từ các hàm khác trong chương trình. 
    - Trong thân phương thức của lớp có thể sử dụng các thuộc tính, phương thức của lớp đó, các hàm tự lập trong chương trình. 
      Vì phạm vi sử dụng của hàm là toàn chương trình.
### 3: Constructor (Hàm tạo)
    - Constructor cũng là một methods của class dùng để tạo dựng một đối tượng mới từ đầu, và sẽ chạy đầu tiên.
    - 3 điểm khác biệt của Constructor so với các methods khác:
        + Tên của constructor bắc buộc phải trùng với tên của Class
        + Không khai báo kiểu cho constructor.
        + Constructor không có kết quả trả về.
    - Ngoài 3 điểm khác trên thì constructor giống với các methods khác:
        + Có thể được định nghĩa (xây dựng) bên trong hoặc ngoài class
        + Có thể có đối hoặc không có đối.
        + Trong class có thể có nhiều constructor cùng tên, nhưng khác bộ đối.
### 4: Các từ khóa Public, Private, Protected:
    - Public: Các thành viên công khai (public) có thể được truy cập từ bất kỳ đâu trong chương trình, bao gồm cả 
      từ các lớp bên ngoài. Đây là phạm vi rộng nhất và cho phép tất cả các thành viên của lớp hoặc đối tượng được 
      truy cập một cách tự do.

    - Private: Các thành viên riêng tư (private) chỉ có thể được truy cập từ bên trong lớp định nghĩa chúng. 
      Các thành viên private không thể được truy cập từ các lớp dẫn xuất (kế thừa) hoặc từ bên ngoài lớp hoặc đối tượng.

    - Protected: Các thành viên được bảo vệ (protected) chỉ có thể được truy cập từ bên trong lớp định nghĩa chúng 
      hoặc từ các lớp dẫn xuất (kế thừa) của lớp đó. Các thành viên protected không thể được truy cập từ bên ngoài lớp hoặc đối tượng.

    - Các đặc điểm chính của từ khóa Protected, Private, và Public:
        + Public: Có phạm vi rộng nhất, cho phép truy cập từ mọi nơi.
        + Protected: Chỉ cho phép truy cập từ bên trong lớp định nghĩa chúng và các lớp dẫn xuất (kế thừa).
        + Private: Chỉ cho phép truy cập từ bên trong lớp định nghĩa chúng.
    - Sử dụng đúng từ khóa phù hợp là một phần quan trọng trong thiết kế lớp và quản lý độ an toàn của dữ liệu 
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
        void sum();         //methods (phương thức): Hàm tính tổng
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
## II: Các tính chất trong lập trình hướng đối tượng (OOP)
#### 6.1: Tính kế thừa (Inheritance)
    - Nếu class con có dạng kế thừa là public, thì class cha kiểu gì qua class con giữ nguyên 
    - Nếu class con có dạng kế thừa là private, thì nếu:
        + Class cha kiểu plulic -> Class con kiểu private
        + Class cha kiểu private -> Class con kiểu private
        + Class cha kiểu protected - > Class con kiểu private
    - Nếu class con có dạng kế thừa là protected, thì nếu:
        + Class cha kiểu plulic -> Class con kiểu protected
        + Class cha kiểu private -> Class con kiểu private
        + Class cha kiểu protected - > Class con kiểu protected 
#### 6.2: Tính trừu tượng (Abstraction)
    - Tính chất này giúp bỏ qua sự phức tạp bên trong method mà chỉ quan tâm đến kết quả đạt được.
#### 6.3: Tính đa hình (Polymorphism)
    - Tính đa hình cho phép trong cùng 1 class có thể đưa ra nhiều method có cùng tên nhưng khác nhau về các input
    parameter hoặc kiểu dữ liệu trả về
#### 6.4: Tính đóng gói (Encapsulation)
    - Tính đóng gói có ý nghĩa không cho phép người sử dụng cái object có thể thay đổi các trạng thái nội 
    tại của đối tượng, mà chỉ có thể thay đổi thông qua method
    - Khi thay đổi thông qua method, chúng ta có thể kiểm soát giá trị thay đổi 

## III: Namespace
    - Namespace trong C++ là một cơ chế cho phép nhóm các tên (biến, hàm, lớp, v.v.) vào một tên duy nhất. 
    - Nó giúp ngăn chặn xung đột tên và hỗ trợ việc tổ chức và quản lý mã nguồn trong dự án lớn. 
    - Bằng cách đặt các thành phần vào các namespace khác nhau, chúng ta có thể xác định rõ ngữ cảnh của 
```Cpp
#include <iostream>
// Định nghĩa namespace MyMath
namespace MyMath {
    int add(int a, int b) {
        return a + b;
    }
}
int main() {
    // Sử dụng hàm add() trong namespace MyMath
    int result = MyMath::add(5, 3);
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
template <typename T>   
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
