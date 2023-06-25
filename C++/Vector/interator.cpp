#include <iostream>
#include <vector>

using namespace std;

/*
Iterator trong C++ là đối tượng được dùng để duyệt qua các phần tử trong các 
cấu trúc dữ liệu như vector, map, set, list, ... bạn cũng có thể hiểu nó giống 
như 1 con trỏ mà trỏ tới các phần tử trong các cấu trúc dữ liệu này. 
Ví dụ về sử dụng iterator để duyệt qua các phẩn tử trong vector:
*/

/*
Trong đó:
    - it = v.begin(): cho biến it trỏ tới phần tử đầu tiên trong vector
    
    - it != v.end(): kiểm tra xem biến it đã trỏ qua phần tử cuối cùng trong vector hay chưa. 
      Bạn có thể hiểu v.end() là phần tử mà đứng sau phần tử cuối cùng trong vector.

    - it++: cho biến it trỏ tới phần tử tiếp theo trong vector.

    - *it: lấy ra giá trị của phần tử mà biến it đang trỏ tới, bạn cũng có thể dùng *it để gán 
      giá trị cho các phần tử trong vector (ví dụ: *it = 0).
*/

int main(int argc, char const *argv[])
{
    // Khai báo vector
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3); 

    // Khai báo iterator
    vector<int>::iterator it;

    // Sử dụng iterator để duyệt vector
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}

