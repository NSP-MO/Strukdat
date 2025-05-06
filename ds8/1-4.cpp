#include <stdio.h>
#define MAXNUM_VERTICES 100

typedef struct {
    int n_vertices;
    int n_edges;
    int adjacency_matrix[MAXNUM_VERTICES][MAXNUM_VERTICES];
} Graph;

void init_graph(Graph *g, int n_vertices, int n_edges) {
    int i, j;

    g->n_vertices = n_vertices;
    g->n_edges = n_edges;

    for(i = 0; i < MAXNUM_VERTICES; i++) {

        for(j = 0; j < MAXNUM_VERTICES; j++) {
            if(i < n_vertices && j < n_vertices) {
                g->adjacency_matrix[i][j] = 0;
            } else {
                g->adjacency_matrix[i][j] = -1;
            }
        }
    }
}

void print_adjacency_matrix(Graph *g) {
    int i, j;

    for(i = 0; i < g->n_vertices; i++) {
        printf("\t%d", i);
    } printf("\n");

    for(i = 0; i < g->n_vertices; i++) {
        printf("%d: ", i);
        for(j = 0; j < g->n_vertices; j++) {
            printf("\t%d", g->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n_vertices = 0;
    int n_edges = 0;
    int i;
    scanf("%d %d", &n_vertices, &n_edges);

    Graph g;
    init_graph(&g, n_vertices, n_edges);

    for(i = 0; i < n_edges; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g.adjacency_matrix[a][b] = 1;
        g.adjacency_matrix[b][a] = 1;  // tambahkan untuk graph tak berarah atau hapus untuk graph berarah
    }

    print_adjacency_matrix(&g);

    return 0;
}

