#include <iostream>
using namespace std;

// định nghĩa số phần tử mảng
#define MAX 1000

// khai báo prototype
void nhapMang(int arr[], int &n);
void xuatMang(int arr[], int n);

int main()
{
	int myArray[MAX]; // mảng myArray có MAX phần tử
	int nSize; // nSize là số phần tử được sử dụng, do user nhập

	// nhập xuất mảng
	nhapMang(myArray, nSize);
	xuatMang(myArray, nSize);

	return 0;
}

// hàm nhập mảng
void nhapMang(int arr[], int &n)        // int &n truyền 1 tham chiếu vào hàm làm thay đổi giá trị biến n từ bên trong hàm
{
	cout << "Nhap so luong phan tu n : ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

// hàm xuất mảng
void xuatMang(int arr[], int n)
{
	// xuất từng phần tử cho mảng từ chỉ số 0 đến n – 1
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}
