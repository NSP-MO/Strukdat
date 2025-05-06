#include <iostream>
using namespace std;

struct Student {
    int studentNumber;
    string name;
    Student *next;
};

// 1. Insert Beginning (Corrected)
void insertBeginning(Student* &head, Student* &tail, int studentNumber, string name) {
    Student *newNode = new Student;
    newNode->studentNumber = studentNumber;
    newNode->name = name;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// 2. Print (Corrected)
void print(Student *head) {
    Student *temp = head;
    while (temp != nullptr) {
        cout << "Student Number: " << temp->studentNumber << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

// 3. Insert Middle (Corrected)
void insertMiddle(Student* &head, int studentNumber, string name) {
    Student *newNode = new Student;
    newNode->studentNumber = studentNumber;
    newNode->name = name;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Student *temp = head;
        // Find the position to insert (assuming the list is sorted)
        while (temp->next != nullptr && temp->next->studentNumber < newNode->studentNumber) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// 4. Search Node (Corrected)
bool searchNode(Student *head, int element) {
    Student *temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->studentNumber == element) { // Assuming search is based on studentNumber
            found = true;
            break;
        }
        temp = temp->next;
    }
    return found;
}

// 5. Update (Corrected)
void updateNode(Student *head, int oldStudentNumber, int newStudentNumber) {
    Student *temp = head;
    while (temp != nullptr && temp->studentNumber != oldStudentNumber) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data not found!" << endl;
    } else {
        temp->studentNumber = newStudentNumber; // Update studentNumber
    }
}

// Procedure to Reverse Linked List (Part B.a)
void reverseList(Student* &head, Student* &tail) {
    if (head == nullptr) return;

    Student *temp = nullptr;
    Student *current = head;
    tail = head; // Tail moves to the first node

    while (current != nullptr) {
        Student *nextNode = current->next;
        current->next = temp;
        temp = current;
        current = nextNode;
    }
    head = temp; // Head is now at the last node
}

// Example usage:
int main() {
    Student *head = nullptr, *tail = nullptr;
    
    // Insert sample data
    insertBeginning(head, tail, 123, "Nuri");
    insertBeginning(head, tail, 456, "Intan");
    insertBeginning(head, tail, 789, "Karin");
    insertBeginning(head, tail, 101, "Azka");
    
    // Procedure to reverse the list
    reverseList(head, tail);
    
    // Print the result (Part B.b)
    cout << "Result after reversing:" << endl;
    print(head); // Output: Azka, Karin, Intan, Nuri
    
    return 0;
}

