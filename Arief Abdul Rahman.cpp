#include <stdio.h>        
#include <stdlib.h>        
#include <string.h>        
#include <vector>        
  
struct Mahasiswa {        
    char nama[50];        
    int nim;        
    float ipk;        
};        

void addmhs(std::vector<Mahasiswa>& mhs, const char* nama, int nim, float ipk) {    
    Mahasiswa temp;    
    strcpy(temp.nama, nama);    
    temp.nim = nim;    
    temp.ipk = ipk;    
    mhs.push_back(temp);    
}    

void printmhs(const std::vector<Mahasiswa>& mhs) {
    printf("Data Semua Mahasiswa:\n");
    for (const Mahasiswa* ptr = mhs.data(); ptr < mhs.data() + mhs.size(); ++ptr) {
        printf("Nama: %s\n", ptr->nama);
        printf("NIM: %d\n", ptr->nim);
        printf("IPK: %.2f\n", ptr->ipk);
        printf("\n");
    }
}

void srcmhs(const std::vector<Mahasiswa>& mhs, int nim) {  
    bool found = false;  
    for (const auto& mahasiswa : mhs) {  
        if (mahasiswa.nim == nim) {  
            printf("Mahasiswa ditemukan:\n");  
            printf("Nama: %s\n", mahasiswa.nama);  
            printf("NIM: %d\n", mahasiswa.nim);  
            printf("IPK: %.2f\n", mahasiswa.ipk);
            printf("\n\n");  
            found = true;  
            break;  
        }  
    }  
    if (!found) {  
        printf("Mahasiswa dengan NIM %d tidak ditemukan.\n", nim);  
    }  
}  
  
int main() {        
    int angka = 10;        
    int *ptrAngka = &angka;        
    printf("Nilai angka: %d\n", *ptrAngka);        
        
    int arrayAngka[5] = {1, 2, 3, 4, 5};        
    printf("Elemen-elemen array: ");        
    for (int i = 0; i < 5; ++i) {        
        printf("%d ", arrayAngka[i]);        
    }        
    printf("\n");        
        
    std::vector<Mahasiswa> mhs;       
        
    addmhs(mhs, "A", 64011, 4.00);      
    addmhs(mhs, "B", 64012, 3.90);      
    addmhs(mhs, "C", 64013, 3.90);      
    addmhs(mhs, "D", 64014, 3.80);    
    addmhs(mhs, "E", 64015, 3.70);    
        
    printf("Data Mahasiswa:\n");          
    for (size_t i = 0; i < mhs.size(); ++i) {          
        printf("Mahasiswa %zu:\n", i + 1);          
        printf("Nama: %s\n", mhs[i].nama);          
        printf("NIM: %d\n", mhs[i].nim);          
        printf("IPK: %.2f\n", mhs[i].ipk);          
        printf("\n");        
    }        
  
    // Mencari mahasiswa dengan NIM tertentu  
    int nimDicari = 64012; // Ganti dengan NIM yang ingin dicari  
    srcmhs(mhs, nimDicari);  
  
    std::vector<int> vectorAngka;        
    for (int i = 0; i < 5; ++i) {        
        vectorAngka.push_back(i * 2);        
    }        
    printf("Elemen-elemen vector: ");        
    for (int i = 0; i < vectorAngka.size(); ++i) {        
        printf("%d ", vectorAngka[i]);        
    }        
    printf("\n");        
        
    *ptrAngka = 20;        
        
    float *ptrIpk = &mhs[0].ipk;        
    *ptrIpk = 3.90;        
        
    vectorAngka.push_back(12);        
    vectorAngka.push_back(15);        
        
    printf("Setelah dimodifikasi:\n");        
    printf("Nilai angka setelah dimodifikasi: %d\n", *ptrAngka);        
    printf("IPK mahasiswa pertama setelah dimodifikasi: %.2f\n", mhs[0].ipk);        
    printf("Elemen-elemen vector setelah dimodifikasi: ");        
    for (int i = 0; i < vectorAngka.size(); ++i) {        
        printf("%d ", vectorAngka[i]);        
    }        
    printf("\n");        
        
    return 0;        
}
