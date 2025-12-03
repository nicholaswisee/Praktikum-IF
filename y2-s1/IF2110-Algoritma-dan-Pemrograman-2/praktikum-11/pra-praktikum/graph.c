#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

/* *** KONTRAKTOR *** */

Graph NewGraph(int x) {
/* Menghasilkan Graph dengan satu simpul ber-id x jika alokasi berhasil.
   Menghasilkan Graph kosong jika alokasi gagal. */
    Graph g;
    CreateGraph(x, &g);
    return g;
}

void CreateGraph(int x, Graph *g) {
/* I.S. Sembarang
   F.S. Terbentuk Graph dengan satu simpul dengan Id = x */
    AdrNode p = newGraphNode(x);
    if (p != NULL) {
        g->first = p;
    } else {
        g->first = NULL;
    }
}

AdrNode newGraphNode(int x) {
/* Mengembalikan address hasil alokasi simpul x. */
    AdrNode p = (AdrNode) malloc(sizeof(GraphNode));
    if (p != NULL) {
        ID(p) = x;
        NPRED(p) = 0;
        TRAIL(p) = NULL;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocGraphNode(AdrNode p) {
/* I.S. p terdefinisi
   F.S. p terdealokasi */
    free(p);
}

AdrAdjNode newAdjNode(int succId) {
/* Mengembalikan address hasil alokasi adjacency. */
    AdrAdjNode p = (AdrAdjNode) malloc(sizeof(GraphAdjNode));
    if (p != NULL) {
        SUCC_ID(p) = succId;
        NEXTSUCC(p) = NULL;
    }
    return p;
}

void deallocAdjNode(AdrAdjNode p) {
/* I.S. p terdefinisi
   F.S. p terdealokasi */
    free(p);
}

AdrNode searchNode(Graph g, int x) {
/* Mengembalikan address simpul dengan id = x jika sudah ada pada graph g,
   NULL jika belum */
    AdrNode p = g.first;
    while (p != NULL) {
        if (ID(p) == x) {
            return p;
        }
        p = NEXT(p);
    }
    return NULL;
}

AdrAdjNode searchEdge(Graph g, int prec, int succ) {
/* Mengembalikan address adjacency yang menyimpan info edge <prec, succ>
   jika sudah ada pada graph g, NULL jika belum */
    AdrNode p = searchNode(g, prec);
    if (p == NULL) {
        return NULL;
    }

    AdrAdjNode adj = TRAIL(p);
    while (adj != NULL) {
        if (SUCC_ID(adj) == succ) {
            return adj;
        }
        adj = NEXTSUCC(adj);
    }
    return NULL;
}

void insertNode(Graph *g, int x, AdrNode *pn) {
/* Menambahkan simpul x ke dalam graph g, jika alokasi x berhasil. */
    *pn = newGraphNode(x);
    if (*pn != NULL) {
        if (g->first == NULL) {
            g->first = *pn;
        } else {
            AdrNode p = g->first;
            /* Iterasi sampai elemen terakhir */
            while (NEXT(p) != NULL) {
                p = NEXT(p);
            }
            NEXT(p) = *pn;
        }
    }
}

void insertEdge(Graph *g, int prec, int succ) {
/* Menambahkan edge dari prec menuju succ ke dalam g. */
    AdrNode pPrec = searchNode(*g, prec);
    AdrNode pSucc = searchNode(*g, succ);
    AdrNode tempNode;

    /* Jika simpul prec belum ada, tambahkan */
    if (pPrec == NULL) {
        insertNode(g, prec, &pPrec);
        if (pPrec == NULL) return; /* Gagal alokasi */
    }

    /* Jika simpul succ belum ada, tambahkan */
    if (pSucc == NULL) {
        insertNode(g, succ, &pSucc);
        if (pSucc == NULL) return; /* Gagal alokasi */
    }

    /* Cek apakah edge sudah ada */
    if (searchEdge(*g, prec, succ) != NULL) {
        return; /* Edge sudah ada, tidak melakukan apa-apa */
    }

    /* Buat adj node baru */
    AdrAdjNode newAdj = newAdjNode(succ);
    if (newAdj != NULL) {
        /* Masukkan ke trail pPrec (insert last atau first, di sini insert last agar rapi) */
        if (TRAIL(pPrec) == NULL) {
            TRAIL(pPrec) = newAdj;
        } else {
            AdrAdjNode adj = TRAIL(pPrec);
            while (NEXTSUCC(adj) != NULL) {
                adj = NEXTSUCC(adj);
            }
            NEXTSUCC(adj) = newAdj;
        }
        /* Update nPred simpul successor */
        NPRED(pSucc)++;
    }
}

/* *** OPERASI DELETE *** */

void deleteNode(Graph *g, int x) {
/* Menghapus simpul x dari g. */
    AdrNode pDel = searchNode(*g, x);
    
    if (pDel == NULL) return; /* Node tidak ditemukan */

    /* 1. HAPUS EDGES YANG MENUJU KE X (INCOMING EDGES) */
    /* Kita harus iterasi semua node lain untuk cek apakah mereka punya edge ke x */
    AdrNode pIter = g->first;
    while (pIter != NULL) {
        if (ID(pIter) != x) {
            /* Cek trail milik pIter */
            AdrAdjNode adj = TRAIL(pIter);
            AdrAdjNode prevAdj = NULL;
            
            while (adj != NULL) {
                if (SUCC_ID(adj) == x) {
                    /* Edge ditemukan, hapus dari list adjacency */
                    if (prevAdj == NULL) {
                        TRAIL(pIter) = NEXTSUCC(adj);
                    } else {
                        NEXTSUCC(prevAdj) = NEXTSUCC(adj);
                    }
                    deallocAdjNode(adj);
                    /* Karena simple graph, hanya ada max 1 edge, bisa break */
                    break; 
                }
                prevAdj = adj;
                adj = NEXTSUCC(adj);
            }
        }
        pIter = NEXT(pIter);
    }

    /* 2. HAPUS EDGES YANG KELUAR DARI X (OUTGOING EDGES) */
    /* Sekaligus update nPred dari node-node yang ditunjuk oleh x */
    AdrAdjNode adjDel = TRAIL(pDel);
    while (adjDel != NULL) {
        AdrAdjNode nextAdj = NEXTSUCC(adjDel);
        
        /* Cari node tujuan untuk mengurangi nPred-nya */
        AdrNode targetNode = searchNode(*g, SUCC_ID(adjDel));
        if (targetNode != NULL) {
            NPRED(targetNode)--;
        }
        
        deallocAdjNode(adjDel);
        adjDel = nextAdj;
    }
    TRAIL(pDel) = NULL;

    /* 3. HAPUS NODE X DARI LIST GRAPH */
    if (g->first == pDel) {
        g->first = NEXT(pDel);
    } else {
        AdrNode prevNode = g->first;
        while (prevNode != NULL && NEXT(prevNode) != pDel) {
            prevNode = NEXT(prevNode);
        }
        if (prevNode != NULL) {
            NEXT(prevNode) = NEXT(pDel);
        }
    }

    /* 4. DEALOKASI MEMORI NODE */
    deallocGraphNode(pDel);
}