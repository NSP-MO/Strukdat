//Nama: Rahma Dhana (G6401231023)
//Nama: Arief Abdul Rahman (G6401231038)
//Nama: Johanna Davina H (G6401231087)

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high-1; j++) {
        if ((ascending && arr[j] <= pivot) || (!ascending && arr[j] >= pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi-1, ascending);
        quickSort(arr, pi+1, high, ascending);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int order;
    
    cout << "Type 1 for ascending or 0 for descending: ";
    cin >> order;
    
    quickSort(arr, 0, n-1, order);
    printArray(arr, n);
    
    return 0;
}