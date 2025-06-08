#ifndef CYCLE_H
#define CYCLE_H
#include "listlinier.h"
#include "Boolean.h"

/**
 * I.S. List l terdefinisi
 * F.S. Mengembalikan address node yang merupakan entrypoint dari cycle
 * Jika tidak ada cycle, kembalikan NULL
 */
Address findCycleEntryPoint(List l);

#endif