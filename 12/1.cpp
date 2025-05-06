struct node* searchforleaf(struct node* root, int k, struct node* parent, int chindex) {
    if (root) {
        if (root->isleaf == 1)
            return root;
        else {
            int i;
            if (k < root->key[0])
                return searchforleaf(root->child[0], k, root, 0);
            else {
                for (i = 1; i < root->n; i++)
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


