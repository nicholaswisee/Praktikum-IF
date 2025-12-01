#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree T = (BinTree)(malloc(sizeof(TreeNode)));
    if(T != NULL){
        ROOT(T) = root;
        LEFT(T) = left_tree;
        RIGHT(T) = right_tree;
    }

    return T;

}
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root,left_tree,right_tree);
}
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val){
    Address t = (Address)malloc(sizeof(TreeNode));
    if(t!=NULL){
        ROOT(t) = val;
        RIGHT(t) = NULL;
        LEFT(t) = NULL;
        }   
    return t; 
}
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p){
    free(p);
}
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p){
    return (p == NULL);
}
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p){
    if(!isTreeEmpty(p)) {
        return (LEFT(p) == NULL && RIGHT(p) == NULL);
    }
    else {
        return false;
    }
}
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p){
    if (!isTreeEmpty(p)) {
        return (LEFT(p) != NULL && RIGHT(p) == NULL);
    }
    else {
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p){
    if (!isTreeEmpty(p)) {
        return (LEFT(p) == NULL && RIGHT(p) != NULL);
    }
    else {
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p){
    return (ROOT(p) != NULL && LEFT(p) != NULL && RIGHT(p) != NULL);
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */

void printPreorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeHelper(BinTree p, int h, int level)
{
    if (!isTreeEmpty(p))
    {
        int i;
        for (i = 0; i < h * level; i++)
        {
            printf(" ");
        }
        printf("%d\n", ROOT(p));

        printTreeHelper(LEFT(p), h, level + 1);
        printTreeHelper(RIGHT(p), h, level + 1);
    }
}

void printTree(BinTree p, int h)
{
    printTreeHelper(p, h, 0);
}