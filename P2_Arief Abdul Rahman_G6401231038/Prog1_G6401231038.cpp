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

// Dealokasi array dinamis
free(dynamicArray);
return 0;
}