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

### Build & run
```
[0] ~/trains-challenge (master) >> make
if [ ! -d 'bin' ]; then mkdir bin; fi
make -C src
make[1]: Entering directory '/home/marc/trains-challenge/src'
cc -Wall -Werror -g   -c -o trains.o trains.c
gcc -Wall -Werror -g -c trains.c
cc -Wall -Werror -g   -c -o wdg.o wdg.c
gcc -Wall -Werror -g -c wdg.c
cc -Wall -Werror -g   -c -o minheap.o minheap.c
gcc -Wall -Werror -g -c minheap.c
cc -Wall -Werror -g   -c -o dijkstra.o dijkstra.c
gcc -Wall -Werror -g -c dijkstra.c
gcc -Wall -Werror -g trains.o wdg.o minheap.o dijkstra.o  -o ../bin/trains
rm -f *.o
make[1]: Leaving directory '/home/marc/trains-challenge/src'
```

```
[0] ~/trains-challenge (master) >> ./bin/trains graph.data 
Output #1: 9
Output #2: 5
Output #3: 13
Output #4: 22
Output #5: NO SUCH ROUTE
Output #6: Perhaps using Breadth First Traversal?
Output #7: Perhaps using Breadth First Traversal?
Output #8: 9
Output #9: 9
Output #10: Seems complex. I don't know.
```
