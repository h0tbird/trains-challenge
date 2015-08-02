# trains-challenge

### Design considerations
- The chosen data structure is a non-negative Weighted Directed Graph (WDG).
- An adjacency lists is used to represent the structure.
- An extra node slot is allocated in order to compute loops to source.
- The shortest path is computed with Dijkstra's algorithm and a binary heap.
