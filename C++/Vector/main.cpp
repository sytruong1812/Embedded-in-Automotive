#include <iostream>
#include <vector>

using namespace std;

int main() {
    // int size = 0;
    // vector<string> arr;     // Khai báo vector arr gồm các phần tử dạng string
    // size = arr[1].size();          //Lấy kích thước của phần tử thứ 1 trong vector arr

    vector<int> v;          // Khai báo vector v gồm các phần tử dạng int
    v.push_back(1);         //Thêm 1 vào cuối vector
    v.push_back(2);
    v.push_back(3);
    v.resize(5);        //Hàm resize(5) dùng thay đổi kích thước của vector[5] = {1,2,3,0,0}
    v.resize(8, 5);     //Hàm resize(8, 5) khởi tạo giá trị cho các phần tử giống nhau vector[8] = {1,2,3,0,0,5,5,5};
    v.size();           //Lấy kích thước của vector đó
    v.erase(v.begin(), v.begin() + 2);          //Xóa các phần tử từ đầu v[0] đến v[2] -> vector[6] = {3,0,0,5,5,5};
                                                //Vậy sau khi xóa các phần tử thì size của vector đó cũng thay đổi.

    // Khai báo iterator
    vector<int>::iterator it;

    // Sử dụng iterator để duyệt vector
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}