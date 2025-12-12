#include "graph.h"
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph g;
    g.first = NULL;

    int idList[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &idList[i]);
        AdrNode p;
        insertNode(&g, idList[i], &p);
    }

    int u, v;
    for (int j = 0; j < m; j++) {
        scanf("%d %d", &u, &v);
        insertEdge(&g, u, v);
    }

    for (int i = 0; i < n; i++) {
        AdrNode p = searchNode(g, idList[i]);
        printf("%d %d\n", ID(p), NPRED(p));
    }

    return 0;
}