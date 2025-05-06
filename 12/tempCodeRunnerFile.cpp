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
