//Nama: Rahma Dhana (G6401231023)
//Nama: Arief Abdul Rahman (G6401231038)
//Nama: Johanna Davina H (G6401231087)

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct dataMhs {
    string nim;
    string nama;
    string nilai;
};

void swap2(dataMhs* a, dataMhs* b) {
    dataMhs temp = *a;
    *a = *b;
    *b = temp;
}

int partition2(dataMhs arr[], int low, int high, int sortBy) {
    dataMhs pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high-1; j++) {
        bool condition = false;
        switch(sortBy) {
            case 0: // NIM
                condition = arr[j].nim <= pivot.nim;
                break;
            case 1: // Nama
                condition = arr[j].nama <= pivot.nama;
                break;
            case 2: // Nilai
                condition = arr[j].nilai <= pivot.nilai;
                break;
        }
        if (condition) {
            i++;
            swap2(&arr[i], &arr[j]);
        }
    }
    swap2(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort2(dataMhs arr[], int low, int high, int sortBy) {
    if (low < high) {
        int pi = partition2(arr, low, high, sortBy);
        quickSort2(arr, low, pi-1, sortBy);
        quickSort2(arr, pi+1, high, sortBy);
    }
}

void addMhs(dataMhs* data, string nim, string nama, string nilai) {
    data->nim = nim;
    data->nama = nama;
    data->nilai = nilai;
}

void printDataMhs(dataMhs data[], int n) {
    for(int i = 0; i < n; i++) {
        cout << left << setw(7) << data[i].nim 
             << setw(12) << data[i].nama 
             << data[i].nilai << endl;
    }
}

int main() {
    const int jmlMhs = 5;
    dataMhs data[jmlMhs];

    addMhs(&data[0], "G6001", "Yuliarto", "B");
    addMhs(&data[1], "G6002", "Zainal", "C");
    addMhs(&data[2], "G6003", "Rudi", "A");
    addMhs(&data[3], "G6404", "Hani", "B");
    addMhs(&data[4], "G6405", "Fitri", "A");

    cout << "Data belum terurut:" << endl;
    printDataMhs(data, jmlMhs);
    cout << endl;

    quickSort2(data, 0, jmlMhs-1, 1);
    cout << "Data terurut berdasarkan nama:" << endl;
    printDataMhs(data, jmlMhs);
    cout << endl;

    quickSort2(data, 0, jmlMhs-1, 2);
    cout << "Data terurut berdasarkan nilai:" << endl;
    printDataMhs(data, jmlMhs);
    cout << endl;

    quickSort2(data, 0, jmlMhs-1, 0);
    cout << "Data terurut berdasarkan nim:" << endl;
    printDataMhs(data, jmlMhs);

    return 0;
}