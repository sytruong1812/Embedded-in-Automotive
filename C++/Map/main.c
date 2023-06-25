#include <iostream>
#include <map>
#include <string>

/*
- Map là một loại associative container. Mỗi phần tử của map là sự kết hợp của khóa (key value) 
  và ánh xạ của nó (mapped value). Cũng giống như set, trong map không chứa các khóa mang giá trị giống nhau.

- Trong map, các khóa được sử dụng để xác định giá trị các phần tử. Kiểu của khóa và ánh xạ có thể khác nhau.

- Và cũng giống như set, các phần tử trong map được sắp xếp theo một trình tự nào đó theo cách so sánh.

- Map được cài đặt bằng red-black tree (cây đỏ đen) – một loại cây tìm kiếm nhị phân tự cân bằng. Mỗi phần tử 
  của map lại được cài đặt theo kiểu pair (xem thêm ở thư viện utility).

    map <kiểu_dữ_liệu_1,kiểu_dữ_liệu_2>
    // kiểu dữ liệu 1 là khóa, kiểu dữ liệu 2 là giá trị của khóa. 
*/


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
