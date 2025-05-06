#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int info;
    node *left;
    node *right;
} *root;

class BST {
public:
    void search(int item, node **parent, node **location);
    void deleteNode(int item);
    void insert(node *tree, node *newnode);
    void display(node *ptr, int level);
    void caseA(node *par, node *loc);
    void caseB(node *par, node *loc);
    void caseC(node *par, node *loc);
    BST() { root = NULL; }
};

int main() {
    int choice, num;
    BST bst;
    node *temp;

    while (1) {
        cout << "\nMenu Operasi BST:\n";
        cout << "1. Tampilkan Tree\n";
        cout << "2. Hapus Node\n";
        cout << "3. Tambah Node\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Struktur BST:\n";
                bst.display(root, 0);
                break;
            case 2:
                if (root == NULL) {
                    cout << "Tree kosong!\n";
                    break;
                }
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> num;
                bst.deleteNode(num);
                break;
            case 3:
                temp = new node;
                cout << "Masukkan angka ke BST: ";
                cin >> temp->info;
                temp->left = temp->right = NULL;
                bst.insert(root, temp);
                break;
            case 4:
                exit(0);
            default:
                cout << "Opsi tidak valid!\n";
        }
    }
}

void BST::search(int item, node **parent, node **location) {
    node *ptr, *parentTemp;
    if (root == NULL) {
        *location = *parent = NULL;
        return;
    }
    if (item == root->info) {
        *location = root;
        *parent = NULL;
        return;
    }
    parentTemp = root;
    ptr = (item < root->info) ? root->left : root->right;

    while (ptr != NULL) {
        if (item == ptr->info) {
            *location = ptr;
            *parent = parentTemp;
            return;
        }
        parentTemp = ptr;
        ptr = (item < ptr->info) ? ptr->left : ptr->right;
    }
    *location = NULL;
    *parent = parentTemp;
}

void BST::insert(node *tree, node *newnode) {
    if (root == NULL) {
        root = newnode;
        cout << "Node root ditambahkan.\n";
        return;
    }
    if (newnode->info == tree->info) {
        cout << "Node sudah ada!\n";
        return;
    }
    if (newnode->info < tree->info) {
        if (tree->left != NULL) {
            insert(tree->left, newnode);
        } else {
            tree->left = newnode;
            cout << "Node ditambahkan ke kiri.\n";
        }
    } else {
        if (tree->right != NULL) {
            insert(tree->right, newnode);
        } else {
            tree->right = newnode;
            cout << "Node ditambahkan ke kanan.\n";
        }
    }
}

void BST::deleteNode(int item) {
    node *parent, *location;
    if (root == NULL) {
        cout << "Tree kosong!\n";
        return;
    }
    search(item, &parent, &location);
    if (location == NULL) {
        cout << "Node tidak ditemukan!\n";
        return;
    }
    if (location->left == NULL && location->right == NULL) {
        caseA(parent, location);
    } else if (location->left != NULL && location->right != NULL) {
        caseC(parent, location);
    } else {
        caseB(parent, location);
    }
    free(location);
}

void BST::caseA(node *par, node *loc) {
    if (par == NULL) {
        root = NULL;
    } else {
        if (loc == par->left) par->left = NULL;
        else par->right = NULL;
    }
}

void BST::caseB(node *par, node *loc) {
    node *child = (loc->left != NULL) ? loc->left : loc->right;
    if (par == NULL) {
        root = child;
    } else {
        if (loc == par->left) par->left = child;
        else par->right = child;
    }
}

void BST::caseC(node *par, node *loc) {
    node *successor = loc->right;
    node *parentSucc = loc;

    while (successor->left != NULL) {
        parentSucc = successor;
        successor = successor->left;
    }

    loc->info = successor->info;
    if (successor->right == NULL) {
        caseA(parentSucc, successor);
    } else {
        caseB(parentSucc, successor);
    }
}

void BST::display(node *ptr, int level) {
    if (ptr != NULL) {
        display(ptr->right, level + 1);
        cout << endl;
        for (int i = 0; i < level; i++) cout << "   ";
        cout << ptr->info;
        display(ptr->left, level + 1);
    }
}
