#include <bits/stdc++.h>
using namespace std;

/* Nilai B (menyatakan ordo atau jumlah key yang diperbolehkan disimpan pada 1 node adalah N-1 */
#define N 4

struct node {
    int key[N - 1]; // Key dari N-1
    struct node* child[N]; // Array Child dari Panjang 'N'
    int isleaf; // Menyatakan posisi node pada leaf (1) atau tidak (0)
    int n; // Jumlah key dalam suatu node
    struct node* parent; // Menyatakan node parent

    node() {
        for (int i = 0; i < N; i++) {
            child[i] = NULL;
        }
        isleaf = 1;
        n = 0;
        parent = NULL;
    }
};

struct node* searchforleaf(struct node* root, int k, struct node* parent, int chindex) {
    if (root) {
        if (root->isleaf == 1)
            return root;
        else {
            int i;
            if (k < root->key[0])
                root = searchforleaf(root->child[0], k, root, 0);
            else {
                for (i = 0; i < root->n; i++)
                    if (root->key[i] > k)
                        return searchforleaf(root->child[i], k, root, i);
                return searchforleaf(root->child[i], k, root, i);
            }
        }
    } else {
        struct node* newleaf = new struct node;
        newleaf->isleaf = 1;
        newleaf->n = 0;
        parent->child[chindex] = newleaf;
        newleaf->parent = parent;
        return newleaf;
    }
}

struct node* insert(struct node* root, int k) {
    if (root) {
        struct node* p = searchforleaf(root, k, NULL, 0);
        struct node* q = NULL;
        int e = k;

        for (; p; p = p->parent) {
            if (p->n == 0) {
                p->key[0] = e;
                p->n = 1;
                return root;
            }

            if (p->n < N - 1) {
                int i;
                for (i = 0; i < p->n; i++) {
                    if (p->key[i] > e) {
                        for (int j = p->n - 1; j >= i; j--)
                            p->key[j + 1] = p->key[j];
                        break;
                    }
                }
                p->key[i] = e;
                p->n = p->n + 1;
                return root;
            }

            if (p->n == N - 1 && p->parent && p->parent->n < N) {
                int m;
                for (int i = 0; i < p->parent->n; i++)
                    if (p->parent->child[i] == p) {
                        m = i;
                        break;
                    }
                if (m + 1 <= N - 1) {
                    q = p->parent->child[m + 1];
                    if (q) {
                        if (q->n == N - 1) {
                            struct node* r = new struct node;
                            int* z = new int[(2 * N) / 3];
                            int parent1, parent2;
                            int* marray = new int[2 * N];
                            int i;
                            for (i = 0; i < p->n; i++)
                                marray[i] = p->key[i];
                            marray[i] = e;
                            marray[i + 1] = p->parent->key[m];
                            for (int j = i + 2; j < ((i + 2) + (q->n)); j++)
                                marray[j] = q->key[j - (i + 2)];

                            for (int i = 0; i < (2 * N - 2) / 3; i++)
                                p->key[i] = marray[i];
                            parent1 = marray[(2 * N - 2) / 3];

                            for (int j = ((2 * N - 2) / 3) + 1; j < (4 * N) / 3; j++)
                                q->key[j - ((2 * N - 2) / 3 + 1)] = marray[j];
                            parent2 = marray[(4 * N) / 3];

                            for (int f = ((4 * N) / 3 + 1); f < 2 * N; f++)
                                r->key[f - ((4 * N) / 3 + 1)] = marray[f];

                            if (m == 0 || m == 1) {
                                p->parent->key[0] = parent1;
                                p->parent->key[1] = parent2;
                                p->parent->child[0] = p;
                                p->parent->child[1] = q;
                                p->parent->child[2] = r;
                                return root;
                            } else {
                                p->parent->key[m - 1] = parent1;
                                p->parent->key[m] = parent2;
                                p->parent->child[m - 1] = p;
                                p->parent->child[m] = q;
                                p->parent->child[m + 1] = r;
                                return root;
                            }
                        }
                    } else {
                        int put;
                        if (m == 0 || m == 1)
                            put = p->parent->key[0];
                        else
                            put = p->parent->key[m - 1];
                        for (int j = q->n - 1; j >= 1; j--)
                            q->key[j + 1] = q->key[j];
                        q->key[0] = put;
                        p->parent->key[m == 0 ? m : m - 1] = p->key[p->n - 1];
                    }
                }
            }
        }
    } else {
        root = new struct node;
        root->key[0] = k;
        root->isleaf = 1;
        root->n = 1;
        root->parent = NULL;
        return root;
    }
}

void printTree(struct node* root, int level) {
    if (root) {
        for (int i = 0; i < level; i++)
            cout << "    ";
        for (int i = 0; i < root->n; i++)
            cout << root->key[i] << " ";
        cout << endl;
        for (int i = 0; i <= root->n; i++)
            printTree(root->child[i], level + 1);
    }
}

int main() {

    // Mulai dengan Empty Root 
    struct node* root = NULL;

    // Tambahkan 9 dan 24
    root = insert(root, 9);
    root = insert(root, 24);

    // Tambahkan 7, 6, 8 Ke kiri dari 9
    root->child[0] = insert(root->child[0], 7); 
    root->child[0] = insert(root->child[0], 6); 
    root->child[0] = insert(root->child[0], 8); 
    root->child[0]->parent = root; 

    // Tambahkan 12, 17, 19 Ke kanan dari 9 dan kiri dari 24
    root->child[1] = insert(root->child[1], 12); 
    root->child[1] = insert(root->child[1], 17); 
    root->child[1] = insert(root->child[1], 19); 
    root->child[1]->parent = root;

    // Tambahkan 29, 31, 41 Ke kanan dari 24
    root->child[2] = insert(root->child[2], 29); 
    root->child[2] = insert(root->child[2], 31); 
    root->child[2] = insert(root->child[2], 41); 
    root->child[2]->parent = root;

    // Cetak Tree Original
    cout << "Original tree: " << endl; 
    for (int i = 0; i < root->n; i++) 
        cout << "     " << root->key[i] << " "; 
    cout << endl; 
    for (int i = 0; i < N-1; i++) { 
        cout << root->child[i]->key[0] << " "; 
        cout << root->child[i]->key[1] << " "; 
        cout << root->child[i]->key[2] << " "; 
        cout << " ";
    } 
    cout << endl;

    return 0;
}
