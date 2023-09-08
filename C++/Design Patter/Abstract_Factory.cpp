#include <iostream>

/*
Trong ví dụ, chúng ta có các lớp trừu tượng AbstractProductA và AbstractProductB đại 
diện cho các loại sản phẩm. Chúng ta cũng có các lớp cụ thể ConcreteProductA1, ConcreteProductA2, 
ConcreteProductB1, ConcreteProductB2 triển khai các lớp trừu tượng để cung cấp triển khai cụ thể của các sản phẩm.

Sau đó, chúng ta định nghĩa một lớp trừu tượng AbstractFactory để khởi tạo các đối tượng. 
Lớp này chứa các phương thức tạo ra các đối tượng liên quan hoặc có quan hệ với nhau. 
Chúng ta cũng có các lớp cụ thể ConcreteFactory1 và ConcreteFactory2 triển khai lớp trừu tượng này.

Trong main(), chúng ta sử dụng AbstractFactory để tạo ra các đối tượng liên quan mà không 
cần biết rõ lớp cụ thể của chúng. Sau đó, chúng ta sử dụng các đối tượng này để thực hiện các hành động cụ thể.
*/

// Abstract product A
class AbstractProductA {
public:
    virtual void use() = 0;     //Định nghĩa 1 phương thức ảo, cần định nghĩa lại trong class kế thừa nó
};

// Concrete product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA1" << std::endl;
    }
};

// Concrete product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using ConcreteProductA2" << std::endl;
    }
};

// Abstract product B
class AbstractProductB {
public:
    virtual void interact(AbstractProductA* productA) = 0;       //Định nghĩa 1 phương thức ảo, cần định nghĩa lại trong class kế thừa nó
};

// Concrete product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void interact(AbstractProductA* productA) override {
        std::cout << "Interacting with ConcreteProductA in ConcreteProductB1" << std::endl;
        productA->use();
    }
};

// Concrete product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void interact(AbstractProductA* productA) override {
        std::cout << "Interacting with ConcreteProductA in ConcreteProductB2" << std::endl;
        productA->use();
    }
};

// Abstract factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;      //Định nghĩa 1 phương thức ảo, cần định nghĩa lại trong class kế thừa nó
    virtual AbstractProductB* createProductB() = 0;      //Định nghĩa 1 phương thức ảo, cần định nghĩa lại trong class kế thừa nó
};

// Concrete factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }
    
    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// Concrete factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }
    
    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    // Create concrete factory 1
    AbstractFactory* factory1 = new ConcreteFactory1();
    
    // Create products from factory 1
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    
    // Use the products
    productA1->use();
    productB1->interact(productA1);
    
    // Create concrete factory 2
    AbstractFactory* factory2 = new ConcreteFactory2();
    
    // Create products from factory 2
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();
    
    // Use the products
    productA2->use();
    productB2->interact(productA2);
    
    delete factory1;
    delete productA1;
    delete productB1;
    
    delete factory2;
    delete productA2;
    delete productB2;
    
    return 0;
}
