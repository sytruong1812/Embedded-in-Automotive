#include <iostream>
#include <map>
#include <string>

int main(int argc, char const *argv[])
{
    std::map<int, std::string> studentMap;

    // Thêm các cặp key-value vào map
    studentMap[1] = "John";
    studentMap[2] = "Emily";
    studentMap[3] = "David";
    studentMap[4] = "Sophia";

    // Truy xuất giá trị dựa trên key
    std::cout << "Student with ID 2: " << studentMap[2] << std::endl;

    // Kiểm tra xem key có tồn tại trong map hay không
    if (studentMap.find(3) != studentMap.end()) {
        std::cout << "Student with ID 3 exists." << std::endl;
    }

    // Lặp qua tất cả các cặp key-value trong map
    for (const auto & pair : studentMap) {
        std::cout << "Student ID: " << pair.first << ", Name: " << pair.second << std::endl;
    }

    return 0;
}
