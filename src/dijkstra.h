//-----------------------------------------------------------------------------
// Include guard:
//-----------------------------------------------------------------------------

#ifndef _DIJKSTRA_
#define _DIJKSTRA_

//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include "wdg.h"
#include "minheap.h"
#include <limits.h>

//-----------------------------------------------------------------------------
// Defines:
//-----------------------------------------------------------------------------

// #define DEBUG

//-----------------------------------------------------------------------------
// Prototypes:
//-----------------------------------------------------------------------------

void printArr(int dist[], int n, int src);
int dijkstra(PWDG graph, int src, int dst);

//-----------------------------------------------------------------------------
// End of include guard:
//-----------------------------------------------------------------------------

#endif
