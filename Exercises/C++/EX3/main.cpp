#include <stdio.h>
#include <stdint.h>

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp hình tròn với bán kính và các phương thức để tính chu vi
và diện tích của hình tròn.
*/

#define PI 3.141592

class circle{
    private:
        int8_t radius;
    public:
        circle(int8_t _radius);
        double perimeter();
        double area();
};

circle::circle(int8_t _radius){
    circle::radius = _radius;
}

double circle::perimeter(){
    double p = PI * (2 * radius);
    printf("Perimeter = %f\n", p);
    return p;
}

double circle::area(){
    double s = PI * (radius * radius);
    printf("Area = %f\n", s);
    return s;
}

int main(int argc, char const *argv[])
{
    circle object(2);
    object.perimeter();
    object.area();
    return 0;
}
