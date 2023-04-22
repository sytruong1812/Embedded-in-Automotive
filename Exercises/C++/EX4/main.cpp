#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp động vật với các thuộc tính tên, tuổi và trọng lượng, và các
phương thức để tính chỉ số BMI, so sánh tuổi và trọng lượng của các động vật khác nhau.
*/

class Animal{
    private:
        string name;
        int8_t age;
        double height;
        double weight;
    public:
        Animal(string _name, int8_t _age, double _height, double _weight);
        double canculationBMI();
        double ageCompareAndWeight(Animal otherAnimal);
};

Animal::Animal(string _name, int8_t _age, double _height, double _weight){
    Animal::name = _name;
    Animal::age = _age;
    Animal::height = _height;
    Animal::weight = _weight;
}

double Animal::canculationBMI(){
    double BIM = height / (weight * weight);
    printf("Chi so BIM cua %s = %f\n", name.c_str(), BIM);
    return BIM;
}

double Animal::ageCompareAndWeight(Animal otherAnimal){
    if(age > otherAnimal.age && weight > otherAnimal.weight){
        printf("Tuoi va trong luong cua %s cao hon %s\n", name.c_str(), otherAnimal.name.c_str());
    }
    else if(age < otherAnimal.age && weight < otherAnimal.weight){
        printf("Tuoi va trong luong cua %s thap hon %s\n", name.c_str(), otherAnimal.name.c_str());
    }
    else{
        if(age > otherAnimal.age && weight < otherAnimal.weight){
            printf("Tuoi cua %s cao hon %s, trong luong %s thap hon %s",  name.c_str(), otherAnimal. name.c_str(),  name.c_str(), otherAnimal. name.c_str());
        }
        else{
            printf("Tuoi cua %s thap hon %s, trong luong %s cao hon %s",  name.c_str(), otherAnimal. name.c_str(),  name.c_str(), otherAnimal. name.c_str());
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string cat_name = "Miu";
    Animal cat("Miu", 7, 0.5, 18);
    string dog_name = "Gau";
    Animal dog("Gau", 8, 0.8, 15);
    cat.canculationBMI();
    dog.canculationBMI();
    cat.ageCompareAndWeight(dog);
    return 0;
}
