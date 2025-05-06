#include <stdio.h>
#include <stdlib.h>

int main() {

// Deklarasi dan alokasi array dinamis
int *dynamicArray = (int *)malloc(5 * sizeof(int));

// Inisialisasi elemen array dinamis
for (int i = 0; i < 5; ++i) { 
    dynamicArray[i] = i + 1;
}
// Akses dan cetak elemen array
for (int i = 0; i < 5; ++i) { 
    printf("%d ", dynamicArray[i]);
}

int newSize = 8;
dynamicArray = (int *)realloc(dynamicArray, newSize * sizeof(int));

for (int i = 5; i < newSize; ++i) {
    dynamicArray[i] = i + 1;
}
for (int i = 0; i < newSize; ++i) {
    printf("%d ", dynamicArray[i]);
}

// Dealokasi array dinamis
free(dynamicArray);
return 0;
}