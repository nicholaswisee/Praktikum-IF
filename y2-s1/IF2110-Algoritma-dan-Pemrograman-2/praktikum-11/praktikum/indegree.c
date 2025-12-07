#include "graph.h"
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph g;

    // insert vertices
    int tempN;
    AdrNode p;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tempN);
        insertNode(&g, tempN, &p);
    }

    // insert edge
    int u, v;
    for (int j = 0; j < m; j++) {
        scanf("%d %d", &u, &v);
        insertEdge(&g, u, v);
    }

    AdrNode point = g.first;

    int succId;
    int count;
    AdrNode precCheck;
    AdrAdjNode exists;

    while (point != NULL) {
        count = 0;
        succId = point->id;
        precCheck = g.first;

        // check for every preceding node
        while (precCheck != NULL) {
            if (precCheck->id == succId) {
                precCheck = precCheck->next;
                continue;
            }
            exists = searchEdge(g, precCheck->id, succId);
            if (exists != NULL) count++;

            precCheck = precCheck->next;
        }

        printf("%d %d\n", succId, count);
        point = point->next;
    }

    AdrNode del = g.first;
    AdrNode tempDel;
    while (del != NULL) {
        tempDel = del;
        del = del->next;
        deleteNode(&g, tempDel->id);
    }
    
    return 0;
}