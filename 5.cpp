
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insertEnd(Node* head, int data) {
    if (head == NULL)
        return newNode(data);
    else
        head->next = insertEnd(head->next, data);
    return head;
}

void traverse(Node* head) {
    if (head == NULL)
        return;
    cout << head->data << " ";
    traverse(head->next);
}

// Jawaban Soal 3: Fungsi insertAfterKey
void insertAfterKey(Node* p, int key, int data) {
    // jika linked kosong
    if (p == NULL) {
        p = newNode(data);
        return;
    }

    // jika node sekarang punya key yang dicari
    if (p->data == key) {
        Node* new_node = newNode(data);
        new_node->next = p->next;
        p->next = new_node;
        return;
    }

    // jika udah di node akhir dan key belum ditemukan
    if (p->next == NULL) {
        p->next = newNode(data);
        return;
    }
    insertAfterKey(p->next, key, data);
}

// Jawaban Soal 4: Fungsi deleteKey
void deleteKey(Node* prev, Node* p, int key) {
    if (p == NULL) return;
    if (p->data == key) {
        prev->next = p->next;
        delete p;
        return;
    }
    deleteKey(p, p->next, key);
}

int main() {
    Node* head = NULL;
    head = insertEnd(head, 6);
    head = insertEnd(head, 8);
    head = insertEnd(head, 10);
    head = insertEnd(head, 12);
    head = insertEnd(head, 14);
    traverse(head); // Output: 6 8 10 12 14
    
    insertAfterKey(head, 12, 13);
    insertAfterKey(head, 8, 9);
    insertAfterKey(head, 15, 16);
    
    cout << "\n";
    traverse(head); // Output: 6 8 9 10 12 13 14 16
    
    cout << "\n";
    deleteKey(head, head, 12);
    traverse(head); // Output: 6 8 9 10 13 14 16
    
    return 0;
}