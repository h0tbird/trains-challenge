//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include "minheap.h"

//-----------------------------------------------------------------------------
// newMinHeapNode
//-----------------------------------------------------------------------------

pMinHeapNode newMinHeapNode(int v, int dist) {

  pMinHeapNode node = (pMinHeapNode) malloc(sizeof(MinHeapNode));
  node->v = v;
  node->dist = dist;
  return node;
}

//-----------------------------------------------------------------------------
// createMinHeap
//-----------------------------------------------------------------------------

pMinHeap createMinHeap(int capacity) {

  pMinHeap heap = (pMinHeap) malloc(sizeof(MinHeap));
  heap->pos = (int *)malloc(capacity * sizeof(int));
  heap->size = 0;
  heap->capacity = capacity;
  heap->array = (pMinHeapNode*) malloc(capacity * sizeof(pMinHeapNode));
  return heap;
}

//-----------------------------------------------------------------------------
// swapMinHeapNode
//-----------------------------------------------------------------------------

void swapMinHeapNode(pMinHeapNode* a, pMinHeapNode* b) {

  pMinHeapNode t = *a;
  *a = *b;
  *b = t;
}

//-----------------------------------------------------------------------------
// minHeapify
//-----------------------------------------------------------------------------

void minHeapify(pMinHeap minHeap, int idx) {

  int smallest, left, right;
  smallest = idx;
  left = 2 * idx + 1;
  right = 2 * idx + 2;

  if (left<minHeap->size && minHeap->array[left]->dist<minHeap->array[smallest]->dist)
    smallest = left;

  if (right<minHeap->size && minHeap->array[right]->dist<minHeap->array[smallest]->dist)
    smallest = right;

  if (smallest != idx) {
    pMinHeapNode smallestNode = minHeap->array[smallest];
    pMinHeapNode idxNode = minHeap->array[idx];
    minHeap->pos[smallestNode->v] = idx;
    minHeap->pos[idxNode->v] = smallest;
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

//-----------------------------------------------------------------------------
// isEmpty
//-----------------------------------------------------------------------------

int isEmpty(pMinHeap minHeap) {

  return minHeap->size == 0;
}

//-----------------------------------------------------------------------------
// extractMin
//-----------------------------------------------------------------------------

pMinHeapNode extractMin(pMinHeap minHeap) {

  if (isEmpty(minHeap)) return NULL;
  pMinHeapNode root = minHeap->array[0];
  pMinHeapNode lastNode = minHeap->array[minHeap->size - 1];
  minHeap->array[0] = lastNode;
  minHeap->pos[root->v] = minHeap->size-1;
  minHeap->pos[lastNode->v] = 0;
  --minHeap->size;
  minHeapify(minHeap, 0);
  return root;
}

//-----------------------------------------------------------------------------
// decreaseKey
//-----------------------------------------------------------------------------

void decreaseKey(pMinHeap minHeap, int v, int dist) {

  int i = minHeap->pos[v];
  minHeap->array[i]->dist = dist;

  while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
    minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
    minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
    swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

//-----------------------------------------------------------------------------
// isInMinHeap
//-----------------------------------------------------------------------------

bool isInMinHeap(pMinHeap minHeap, int v) {

  if (minHeap->pos[v] < minHeap->size) return true;
  return false;
}
