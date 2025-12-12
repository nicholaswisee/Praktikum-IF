#include "graph.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int node;
    int weight;
} Edge;

/* Count number of nodes in graph */
int countNodes(Graph g) {
	int count = 0;
	AdrNode p = g.first;
	while (p != NULL) {
		count++;
		p = NEXT(p);
	}

	return count;
}

/* Get node ID by index 
 * return -1 if index invalid
 */
int getNodeIdByIndex(Graph g, int index) {
	AdrNode p = g.first;
	int i = 0;
	while (p != NULL) {
		if (i == index) return ID(p);
		p = NEXT(p);
		i++;
	}

	return -1;

}

/* Find index of node by ID
 * return -1 if id not found
 */
int findNodeIndex(Graph g, int nodeId) {
	AdrNode p = g.first;
	int idx = 0;
	while (p != NULL) {
		if (ID(p) == nodeId) return idx;
		p = NEXT(p);
		idx++;
	}

	return -1;
}

/* Get weight of edge from u to v */
int getEdgeWeight(Graph g, int u, int v) {
    AdrNode node = searchNode(g, u);
    if (node == NULL)
        return -1;

    AdrAdjNode adj = TRAIL(node);
    while (adj != NULL) {
        if (SUCC_ID(adj) == v) {
            return WEIGHT(adj);
        }
        adj = NEXTSUCC(adj);
    }
    return -1;
}

/* Prim's Algorithm - always starts from first node */
void primMST(Graph g) {
    int n = countNodes(g);
    if (n == 0) {
        printf("Graph is empty!\n");
        return;
    }

    boolean visited[MAX_NODES] = {false};
    int parent[MAX_NODES];
    int key[MAX_NODES];

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    key[0] = 0;   // mulai dari node index 0

    printf("Building MST using Prim's Algorithm (starting from first node):\n");
    printf("----------------------------------------------------------\n");

    int totalWeight = 0;
    int edgesUsed = 0;

    for (int count = 0; count < n; count++) {
        // pilih node dengan key minimum
        int uIndex = -1;
        int minKey = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                uIndex = i;
            }
        }

        if (uIndex == -1) break; // tidak ada node yang bisa dijangkau lagi

        visited[uIndex] = true;
        
        // print edge yang baru ditambahkan ke MST (kecuali node pertama)
        if (parent[uIndex] != -1) {
            edgesUsed++;
            int u = getNodeIdByIndex(g, parent[uIndex]);
            int v = getNodeIdByIndex(g, uIndex);
            int w = getEdgeWeight(g, u, v);

            printf("Edge %d: Node %d -- Node %d (weight: %d)\n",
                   edgesUsed, u, v, w);

            totalWeight += w;
        }

        int u = getNodeIdByIndex(g, uIndex);

        // update tetangga (adjacent nodes)
        AdrNode node = searchNode(g, u);
        if (node == NULL) continue;
        
        AdrAdjNode adj = TRAIL(node);

        while (adj != NULL) {
            int v = adj->succId;
            int vIndex = findNodeIndex(g, v);

            if (vIndex != -1 && !visited[vIndex] && adj->weight < key[vIndex]) {
                key[vIndex] = adj->weight;
                parent[vIndex] = uIndex;
            }

            adj = adj->next;
        }
    }

    printf("----------------------------------------------------------\n");
    printf("Total MST Weight: %d\n", totalWeight);
}

int main() {
    Graph g;
    int n, m;

    // Enter number of nodes
    scanf("%d", &n);

    // Enter number of edges
    scanf("%d", &m);

    /* Create graph with first node */
    // Enter node IDs (space-separated)
    int firstNode;
    scanf("%d", &firstNode);
    CreateGraph(firstNode, &g);

    /* Add remaining nodes */
    for (int i = 1; i < n; i++) {
        int nodeId;
        scanf("%d", &nodeId);
        AdrNode temp;
        insertNode(&g, nodeId, &temp);
    }

    /* Add edges */
    // Enter edges (u v weight)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        insertEdge(&g, u, v, w);
        insertEdge(&g, v, u, w); // For undirected graph
    }

    primMST(g);

    return 0;
}
