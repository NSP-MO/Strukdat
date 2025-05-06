//Nama: Rahma Dhana (G6401231023)
//Nama: Arief Abdul Rahman (G6401231038)
//Nama: Johanna Davina H (G6401231087)

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, bool ascending) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r, bool ascending) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m, ascending);
        mergeSort(arr, m+1, r, ascending);
        merge(arr, l, m, r, ascending);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int order;
    
    cout << "Type 1 for ascending or 0 for descending: ";
    cin >> order;
    
    mergeSort(arr, 0, arr_size-1, order);
    printArray(arr, arr_size);
    
    return 0;
}