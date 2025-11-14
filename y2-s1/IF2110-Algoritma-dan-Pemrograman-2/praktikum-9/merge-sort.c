#include "list.h"
#include <stdio.h>

static List merge(List left, List right);

List mergeSort(List l) {
    int len = length(l);
    if (len <= 1) {
        return copy(l);
    }

    int mid = len / 2;
    List left = NULL;
    List right = NULL;
    List x = l;
    int i = 0;

    while (x != NULL) {
        if (i < mid) {
            left = konsDot(left, x->info);
        } else {
            right = konsDot(right, x->info);
        }
        x = x->next;
        i++;
    }

    List left2 = mergeSort(left);
    List right2 = mergeSort(right);

    List l3 = merge(left2, right2);
    displayList(l3);
    printf("\n");
    return l3;
}

static List merge(List left, List right) {
    if (isEmpty(left)) {
        return right;
    }
    if (isEmpty(right)) {
        return left;
    }

    if (head(left) <= head(right)) {
        left->next = merge(tail(left), right);
        return left;
    } else {
        right->next = merge(left, tail(right));
        return right;
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    List l = NIL;
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 0;
        }
        l = konsDot(l, value);
    }

    List result = mergeSort(l);
    return 0;
}