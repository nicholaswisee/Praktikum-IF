#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List removeDuplicates(List l) {
    if (l == NIL) return NIL;
    if (l->next == NIL) return l;

    if (l->info == l->next->info) {
        deleteX(&l, l->info);
        return removeDuplicates(l);
    } else {
        return konso(l->info, removeDuplicates(l->next));
    }
}