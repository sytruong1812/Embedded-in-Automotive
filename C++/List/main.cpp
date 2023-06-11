#include <iostream>
#include <vector>
#include <list>

int main() {
    // Sử dụng Vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Vector: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Sử dụng List
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::cout << "List: ";
    for (int i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Chèn phần tử vào vị trí bất kỳ
    vec.insert(vec.begin() + 1, 4); // Chèn số 4 vào vị trí thứ 2 trong Vector

    std::cout << "Updated Vector: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    lst.insert(++lst.begin(), 4); // Chèn số 4 vào vị trí thứ 2 trong List

    std::cout << "Updated List: ";
    for (int i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
