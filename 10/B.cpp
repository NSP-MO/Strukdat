#include <iostream>
using namespace std;

void fun1(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        fun1(arr, n, largest);
    }
}

void fun2(int arr[], int n){
    int startIdx = n / 2 - 1;
    for(int i = startIdx; i >= 0; i--){
        fun1(arr, n, i);
    }
}

void fun3(int arr[], int& n){
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    fun1(arr, n, 0);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {20, 16, 11, 2, 4, 5, 1, 6, 10, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    fun2(arr, n);
    cout << "Setelah fun2: ";
    printArray(arr, n);

    fun3(arr, n);
    cout << "Setelah fun3: ";
    printArray(arr, n);

    return 0;
}