//-----------------------------------------------------------------------------
// Include guard:
//-----------------------------------------------------------------------------

#ifndef _MINHEAP_
#define _MINHEAP_

//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdbool.h>

//-----------------------------------------------------------------------------
// Typedefs:
//-----------------------------------------------------------------------------

typedef struct _MinHeapNode {

  int  v;
  int dist;

} MinHeapNode, *pMinHeapNode;

typedef struct _MinHeap {

  int size;
  int capacity;
  int *pos;
  pMinHeapNode *array;

} MinHeap, *pMinHeap;

//-----------------------------------------------------------------------------
// Prototypes:
//-----------------------------------------------------------------------------

pMinHeapNode newMinHeapNode(int v, int dist);
pMinHeap createMinHeap(int capacity);
void swapMinHeapNode(pMinHeapNode* a, pMinHeapNode* b);
void minHeapify(pMinHeap minHeap, int idx);
int isEmpty(pMinHeap minHeap);
pMinHeapNode extractMin(pMinHeap minHeap);
void decreaseKey(pMinHeap minHeap, int v, int dist);
bool isInMinHeap(pMinHeap minHeap, int v);

//-----------------------------------------------------------------------------
// End of include guard:
//-----------------------------------------------------------------------------

#endif
