#include <iostream>

/*
Trong ví dụ trên, lớp Singleton có một phương thức tĩnh getInstance() để truy xuất đối 
tượng Singleton. Phương thức này kiểm tra xem nếu biến instance chưa được khởi tạo (giá trị ban đầu là nullptr), 
nó sẽ tạo một thể hiện mới của Singleton thông qua toán tử new. Nếu instance đã tồn tại, nó sẽ trả về thể hiện hiện tại. 
Do đó, chỉ có một đối tượng Singleton duy nhất được tạo ra và các lời gọi getInstance() sau đó sẽ trả về thể hiện này.

Trong ví dụ trên, khi chúng ta thiết lập giá trị của singleton và lấy giá trị của nó thông qua hai lời 
gọi singleton->getValue() và anotherSingleton->getValue(), cả hai lời gọi này trả về giá trị 42. 
Điều này chứng tỏ rằng hai con trỏ singleton và anotherSingleton đều trỏ đến cùng một đối tượng Singleton.
*/

class Singleton {
private:
    static Singleton* instance;
    int value;

    Singleton() {
        value = 0;
    }

public:
    static Singleton* getInstance() {       
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    int getValue() {
        return value;
    }

    void setValue(int newValue) {
        value = newValue;
    }
};

// Khởi tạo con trỏ instance với giá trị ban đầu là nullptr
Singleton* Singleton::instance = nullptr;

int main() {
    // Lấy thể hiện duy nhất của Singleton
    Singleton* singleton = Singleton::getInstance();

    // Truy cập và thiết lập giá trị của singleton
    singleton->setValue(42);
    std::cout << singleton->getValue() << std::endl;

    // Lấy lại thể hiện duy nhất của Singleton
    Singleton* anotherSingleton = Singleton::getInstance();
    std::cout << anotherSingleton->getValue() << std::endl;

    // Kết quả in ra màn hình:
    // 42
    // 42

    return 0;
}
