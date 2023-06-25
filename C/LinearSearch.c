#include <stdio.h>

/*Thuật toán tìm kiếm phần tử trong mảng số nguyên*/

int linearSearch(int arr[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Trả về vị trí của phần tử nếu tìm thấy
        }
    }
    return -1;  // Trả về -1 nếu không tìm thấy phần tử
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d\n", target, result);
    } else {
        printf("Phan tu %d khong ton tai trong mang\n", target);
    }
    return 0;
}
