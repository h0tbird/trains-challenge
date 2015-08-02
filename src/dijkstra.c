//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include "dijkstra.h"

//-----------------------------------------------------------------------------
// printArr
//-----------------------------------------------------------------------------

void printArr(int dist[], int n, int src) {

  printf("[DEBUG] Vertex   Distance from Source [%d]\n", src);
  for (int i=0; i<n; ++i) printf("[DEBUG] %d \t\t %d\n", i, dist[i]);
  printf("\n");
}

//-----------------------------------------------------------------------------
// dijkstra
//-----------------------------------------------------------------------------

int dijkstra(PWDG graph, int src, int dst) {

  int V = graph->count;
  int dist[V];

  // Clone node:
  if (src == dst) {
    wdg_clone_node(graph, src, V);
    dst = V; V++;
  }

  pMinHeap minHeap = createMinHeap(V);

  for (int v=0; v<V; ++v) {
    dist[v] = INT_MAX;
    minHeap->array[v] = newMinHeapNode(v, dist[v]);
    minHeap->pos[v] = v;
  }

  dist[src] = 0;
  decreaseKey(minHeap, src, dist[src]);
  minHeap->size = V;

  while (!isEmpty(minHeap)) {

    pMinHeapNode minHeapNode = extractMin(minHeap);
    int u = minHeapNode->v;
    if (u == dst) {
      // (TODO) Call Deckard to kill the clone
      return dist[u];
    }
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

  #ifdef DEBUG
  printArr(dist, V, src);
  #endif

  // (TODO) Call Deckard to kill the clone
  return -1;
}
