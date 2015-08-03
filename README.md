# trains-challenge

### Design considerations
- The chosen data structure is a non-negative Weighted Directed Graph (WDG).
- An adjacency lists is used to represent the structure.
- An extra node slot is allocated in order to compute loops to source (hack).
- The shortest path is computed with Dijkstra's algorithm using a min-heap.

### Improvements
- The input parsing implementation is very lazy. It will only work with capital letters (A-Z) and single digit weights (0-9).

### Resources
#### Code
- http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/

#### Background
I don't have academical background on graphs and algorithms so I first 'attended' a few lectures:
- https://www.youtube.com/watch?v=ylWAB6CMYiY
- https://www.youtube.com/watch?v=2E7MmKv0Y24
- https://www.youtube.com/watch?v=s-CYnVz-uh4
