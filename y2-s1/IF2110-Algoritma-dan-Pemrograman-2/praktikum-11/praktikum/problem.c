#include "graph.h"
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph g;

    // insert edge
    int u, v;
    for (int j = 0; j < m; j++) {
        scanf("%d %d", &u, &v);
        insertEdge(&g, u, v);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    int count = 0;
    AdrNode vertex = g.first;
    AdrAdjNode aEx, bEx;
    while (vertex != NULL) {
        aEx = searchEdge(g, a, vertex->id);
        bEx = searchEdge(g, b, vertex->id);

        if (aEx != NULL && bEx != NULL) {
            count++;
            printf("%d ", vertex->id);
        }
        
        vertex = vertex->next;
    }

    if (count == 0) printf("0\n");
    else printf("\n");
    
}