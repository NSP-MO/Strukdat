//Nama: Rahma Dhana (G6401231023)
//Nama: Arief Abdul Rahman (G6401231038)
//Nama: Johanna Davina H (G6401231087)

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, bool ascending) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && (ascending ? (arr[j] > key) : (arr[j] < key))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int order;
    
    cout << "Type 1 for ascending or 0 for descending: ";
    cin >> order;
    
    insertionSort(arr, n, order);
    printArray(arr, n);
    
    return 0;
}