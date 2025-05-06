#include <iostream>
// Definisi struktur Node
struct Node {
    int data;
    Node* next;
};
// Fungsi untuk menambahkan node di awal linked list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
// Fungsi untuk menambahkan node di akhir linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = newNode;
}
// Fungsi untuk menghapus node di awal linked list
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        std::cout << "Linked list is empty. Cannot delete from the beginning." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}
// Fungsi untuk menghapus node di akhir linked list
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        std::cout << "Linked list is empty. Cannot delete from the end." << std::endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }

    delete secondLast->next;
    secondLast->next = nullptr;
}
// Fungsi untuk mencari data tertentu dan menggantinya dengan nilai baru
void updateData(Node* head, int oldData, int newData) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == oldData) {
            current->data = newData;
            std::cout << "Data updated successfully." << std::endl;
            return;
        }
        current = current->next;
    }

    std::cout << "Data not found in the linked list." << std::endl;
}
// Fungsi untuk mencetak seluruh isi linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
// Fungsi untuk menghapus seluruh linked list
void deleteLinkedList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
//Fungsi untuk menghitung jumlah node dalam linked list
int countAll (Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) 
    {   
        count++;
        current = current -> next;
    }
    return count;
}
//Fungsi untuk memasukkan node ke posisi 4 dalam linked list
void insertAs4(Node*& head, int newData) {
    int count = countAll(head);
    if (count < 3) 
    {
        std::cout << "Tidak ada cukup elemen dalam linked list. (minimum 3)" << std::endl;
        return;
    }

    Node* newNode = new Node{newData, nullptr};

    Node* current = head;
    for (int i = 1; i < 3; i++) 
    { 
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

//Fungsi untuk mencetak bilangan genap dalam linked list
void cetak_genap(Node* head) {
    Node* current = head;
    while (current != nullptr) 
    {
        if (current->data % 2 == 0) 
        {
            std::cout << current->data << " ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}
//Fungsi untuk menghapus data 2 node sebelum terakhir 
void delbefore2end(Node*& head) {
    int count = countAll(head);
    if (count < 3) 
    {
        std::cout << "Tidak ada cukup elemen dalam linked list (minimum 3)" << std::endl;
        return;
    }

    Node* current = head;
    for (int i = 1; i < count - 3; i++) 
    {  
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

int main() {
    Node* head = nullptr;
    int choice;

    do {
        std::cout << "\nMenu:\n1. Insert di Awal\n2. Insert di Akhir\n3. Hapus di Awal\n4. Hapus di Akhir\n5. Update Data\n6. Cetak Linked List\n7. Hitung semua Node\n8. Memasukkan Elemen ke-4\n9. Cetak Genap\n10. Menghapus Data sebelum 2 Node terakhir\n0. Keluar\n";
        std::cout << "Pilih operasi (0-10): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int insertData;
                std::cout << "Masukkan data untuk di-insert di awal: ";
                std::cin >> insertData;
                insertAtBeginning(head, insertData);
                break;

            case 2:
                int insertDataEnd;
                std::cout << "Masukkan data untuk di-insert di akhir: ";
                std::cin >> insertDataEnd;
                insertAtEnd(head, insertDataEnd);
                break;

            case 3:
                deleteAtBeginning(head);
                break;

            case 4:
                deleteAtEnd(head);
                break;

            case 5:
                int oldData, newData;
                std::cout << "Masukkan data yang ingin di-update: ";
                std::cin >> oldData;
                std::cout << "Masukkan nilai baru: ";
                std::cin >> newData;
                updateData(head, oldData, newData);
                break;

            case 6:
                printLinkedList(head);
                break;

            case 7:
                std::cout << "Jumlah node dalam linked list: " << countAll(head) << std::endl;
                break;

            case 8:
                int insertData4;
                std::cout << "masukkan data untuk di-insert di posisi ke-4: ";
                std::cin >> insertData4;
                insertAs4(head, insertData4);
                break;

            case 9:
                std::cout << "Bilangan Genap pada linked list: ";
                cetak_genap(head);
                break;

            case 10:
                delbefore2end(head);
                break;

            case 0:
                std::cout << "Keluar dari program.\n";
                break;

            default:
                std::cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (choice != 0);
    
    // Hapus seluruh linked list sebelum keluar dari program
    deleteLinkedList(head);

    return 0;
}
