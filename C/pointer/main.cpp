#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100
#define LENGTH(arr) (int)(sizeof(arr)/sizeof(arr[0]))

void swapTwoNumbers(int &numberOne, int &numberTwo){
    int temp = numberOne;
    numberOne = numberTwo;
    numberTwo = temp;
}

void stringLengthSearch(){
    char array[MAX_SIZE];
    int count;
    cout << "Enter your string (100 word limit): ";
    cin >> array;
    while(array[count] != '\0'){
        count++;
    }
    cout << "Your string length is: " << count << endl;
}

void sortAndSumNumberInArray() {
    int N;
    cout << "Enter the number of elements N: ";
    cin >> N;
    /* 
    Cấp phát một mảng số nguyên có N phần tử, và con 
    trỏ arr sẽ trỏ tới địa chỉ đầu tiên của mảng đó.
    */
    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    /*Sort elements from smallest to largest*/
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    /*Sum of elements in array*/
    int sum = 0;
    for (int k = 0; k < N; k++) {
        sum += arr[k];
    }
    cout << "The sum of the numbers in the array is: " << sum << endl;

    /*Giải phóng vùng nhớ đã cấp phát động*/
    delete[] arr;
}


int main(int argc, char const *argv[])
{
    sortAndSumNumberInArray();
    return 0;
}

/*https://docs.google.com/document/d/1YLSyipMK4Hi4jqU1G_o91vm-yARyViFc-UwEwuJGjmM/edit*/