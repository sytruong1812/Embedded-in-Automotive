#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string name = "Nguyen Van A";
   
    vector<int>arr;         //vector<kiểu dữ liệu> tên vector;
    arr.push_back(1);       //Thêm 1 phần tử vào mảng arr
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);

    arr.pop_back();         //Xóa phần tử cuối cùng
    
    arr.insert(arr.begin() + 4 , 6);        //Chèn 6 vào vị trí thứ 4 trong mảng

    arr.erase(arr.begin() + 2);             //Xóa phần tử thứ 2 trong mảng

    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d\n", arr[i]);
    }


    return 0;
}
