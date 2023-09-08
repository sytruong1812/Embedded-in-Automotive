#include <iostream>

/*
Trong ví dụ, chúng ta có một interface Product đại diện cho các sản phẩm. 
Hai lớp ConcreteProduct1 và ConcreteProduct2 triển khai interface này để định nghĩa 
cách sử dụng (use) của từng sản phẩm cụ thể.

Lớp ProductFactory là factory class, có một phương thức tĩnh createProduct() nhận một tham số 
type để quyết định lớp cụ thể nào sẽ được tạo. Trong ví dụ này, nếu type là 1, nó tạo một đối 
tượng ConcreteProduct1, nếu type là 2, nó tạo một đối tượng ConcreteProduct2.

Trong main(), chúng ta sử dụng ProductFactory để tạo ra các đối tượng Product mà không cần biết 
trước lớp cụ thể của chúng. Sau đó, chúng ta gọi phương thức use() của mỗi đối tượng để thực hiện các hành động cụ thể.
*/


// Abstract product interface
class Product {
public:
    virtual void use() = 0;
};

// Concrete product 1
class ConcreteProduct1 : public Product {
public:
    void use() override {       //Override : 1 method ở Class con đang ghi đè 1 method ở Class cha 
        std::cout << "Using ConcreteProduct1" << std::endl;
    }
};

// Concrete product 2
class ConcreteProduct2 : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProduct2" << std::endl;
    }
};

// Factory class
class ProductFactory {
public:
    static Product* createProduct(int type) {
        switch (type) {
            case 1:
                return new ConcreteProduct1();
            case 2:
                return new ConcreteProduct2();
            default:
                return nullptr;
        }
    }
};

int main() {
    Product* product1 = ProductFactory::createProduct(1);
    product1->use();

    Product* product2 = ProductFactory::createProduct(2);
    product2->use();

    delete product1;
    delete product2;

    return 0;
}
