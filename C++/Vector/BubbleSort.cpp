#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    for(int x = 0; x < arr.size(); x++){
        cout << arr[x] << endl;
    }
}

void BubbleSort(vector<int> arr){
    int n = (int) arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int x = 0; x < arr.size(); x++){
        cout << arr[x] << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {5,4,3,2,1};
    sortArray(arr);
    BubbleSort(arr);
    return 0;
}
