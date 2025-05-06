#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *a, *b;

    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    b = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        *(a + i) = rand() % 10;
        *(b + n - i - 1) = *(a + i);
    }

    for (i = 0; i < n; i++) printf("%d ", *(a + i));
    for (i = 0; i < n; i++) printf("%d ", *(b + i));

    free(a);
    free(b);
    
    return 0;
}
