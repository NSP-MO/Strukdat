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
