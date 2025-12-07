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
}

/* Get node ID by index 
 * return -1 if index invalid
 */
int getNodeIdByIndex(Graph g, int index) {
}

/* Find index of node by ID
 * return -1 if id not found
 */
int findNodeIndex(Graph g, int nodeId) {
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

    boolean visited[MAX_NODES];
    int parent[MAX_NODES];
    int key[MAX_NODES];

    /* Initialize arrays */
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    /* Start from first node (index 0) */
    key[0] = 0;
    int totalWeight = 0;
    int edgeCount = 0;

    printf("Building MST using Prim's Algorithm (starting from first node):\n");
    printf("----------------------------------------------------------\n");

    // TODO: IMPLEMENT PRIM's ALGORITHM

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
