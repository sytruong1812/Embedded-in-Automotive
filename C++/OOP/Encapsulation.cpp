#include <stdio.h>
#include <string.h>

class Animal {
public:
    virtual void sound() = 0; 
};

class Cat : public Animal {
public:
    void sound() {
        printf("MEOW");
    }
};

class Dog : public Animal {
public:
    void sound() {
        printf("GAUU");
    }
};

// Tính đóng gói
class Person {
    private:
        char name[20];
        int age;
    public:
        Person(char* name, int age) {

            printf("Name: %s, Tuoi: %d", name, age);
        }
};

int main() {
    Cat cat;
    cat.sound(); 
    
    Dog dog;
    dog.sound();
    
    Person person("Anh", 25);
    return 0;
}
