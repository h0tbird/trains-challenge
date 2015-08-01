# trains-challenge

### Design considerations
- The chosen data structure for the problem is a non-negative Weighted Directed Graph (WDG).
- An adjacency lists is used to represent the structure.
- The shortest path is computed with Dijkstra's algorithm and a binary heap.

### Problem statement interpretation
I understand `route` as an ordered collection of *navigation nodes* in a graph. Whereas the suggested solution implies that a `route` is an ordered collection of *adjacent nodes* in a graph. For output 1 to 5 I am computing the sum of the shortest paths for each `route` section (adjacent or not). The distance of the route A-E-D is resolved as A-E-(B-C)-D which computes 22.
