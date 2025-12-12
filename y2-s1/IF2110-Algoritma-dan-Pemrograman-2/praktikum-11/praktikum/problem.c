#include "graph.h"
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Graph g;
    AdrNode temp;

    // Initialize graph dgn 1 
    CreateGraph(1, &g);

    for (int i = 2; i <= N; i++) {
        insertNode(&g, i, &temp);
    }

    /* Insert edges */
    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(&g, u, v);
    }

    int A, B;
    scanf("%d %d", &A, &B);

    AdrNode nodeA = searchNode(g, A);
    AdrAdjNode adjA = TRAIL(nodeA);

    int count = 0;
    while (adjA != NULL) {
        int neighbor = SUCC_ID(adjA);

        if (searchEdge(g, B, neighbor) != NULL) {
            if (count > 0) printf(" ");
            printf("%d", neighbor);
            count++;
        }

        adjA = NEXTSUCC(adjA);
    }

    if (count == 0) {
        printf("0");
    }
    printf("\n");

    return 0;
}
