#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

/*
File: main.c
Author: Sy Truong
Date: 18/4/2023
Description: Tạo một lớp sách với các thuộc tính tên sách, tác giả, năm xuất bản
và số lượng, và các phương thức để in thông tin sách, mượn sách và trả sách.
*/

class Books{
    private:
        string name;
        string author;
        uint16_t year;
        uint8_t quantity;
    public:
        Books(string _name, string _author, uint16_t _year, uint8_t _quantity);
        void showInformation();
        void borrowBooks();
        void returnBooks();
};

Books::Books(string _name, string _author, uint16_t _year, uint8_t _quantity){
    this->name = _name;
    this->author = _author;
    this->year = _year;
    this->quantity = _quantity;
}

void Books::showInformation(){
    printf("Name of the book: %s\nAuthor: %s\nYear: %d\nQuatity: %d\n", name.c_str(), author.c_str(), year, quantity);
}

void Books::borrowBooks(){

}

void Books::returnBooks(){

}

int main(int argc, char const *argv[])
{
    Books x("Khong bao gio la that bai! Tat ca chi la thu thach", "Chung Ju Yung", 2020, 1);
    x.showInformation();
    return 0;
}
