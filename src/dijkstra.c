//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include "dijkstra.h"

//-----------------------------------------------------------------------------
// printArr
//-----------------------------------------------------------------------------

void printArr(int dist[], int n, int src) {

  printf("Vertex   Distance from Source [%d]\n", src);
  for (int i=0; i<n; ++i) printf("%d \t\t %d\n", i, dist[i]);
  printf("\n");
}

//-----------------------------------------------------------------------------
// dijkstra
//-----------------------------------------------------------------------------

int dijkstra(PWDG graph, int src, int dst) {

  int V = graph->count;
  int dist[V];

  pMinHeap minHeap = createMinHeap(V);

  for (int v=0; v<V; ++v) {
    dist[v] = INT_MAX;
    minHeap->array[v] = newMinHeapNode(v, dist[v]);
    minHeap->pos[v] = v;
  }

  minHeap->array[src] = newMinHeapNode(src, dist[src]);
  minHeap->pos[src]   = src;
  dist[src] = 0;
  decreaseKey(minHeap, src, dist[src]);
  minHeap->size = V;

  while (!isEmpty(minHeap)) {

    pMinHeapNode minHeapNode = extractMin(minHeap);
    int u = minHeapNode->v;
    if (u == dst) return dist[u];
    PNODE pCrawl = graph->list[u].head;

    while (pCrawl != NULL) {

      int v = pCrawl->dst;

      if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->wgt + dist[u] < dist[v]) {
        dist[v] = dist[u] + pCrawl->wgt;
        decreaseKey(minHeap, v, dist[v]);
      }

      pCrawl = pCrawl->next;
    }
  }

  return -1;
}
