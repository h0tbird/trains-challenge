//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include "trains.h"

//-----------------------------------------------------------------------------
// Entry point:
//-----------------------------------------------------------------------------

int main(int argc, char *argv[]) {

  // AB5, BC4, CD8, DC8, DE6, AD5, CE2, EB3, AE7
  // 015, 124, 238, 328, 346, 035, 242, 413, 047

  PWDG wdg = wdg_new(5);

  wdg_insert(wdg, 0, 1, 5);
  wdg_insert(wdg, 1, 2, 4);
  wdg_insert(wdg, 2, 3, 8);
  wdg_insert(wdg, 3, 2, 8);
  wdg_insert(wdg, 3, 4, 6);
  wdg_insert(wdg, 0, 3, 5);
  wdg_insert(wdg, 2, 4, 2);
  wdg_insert(wdg, 4, 1, 3);
  wdg_insert(wdg, 0, 4, 7);

  int ab, ac, bb, bc, ad, dc, ae, eb, cd, ed;

  // The distance of the route A-B-C:
  if ((ab = dijkstra(wdg, 0, 1)) < 0 || (bc = dijkstra(wdg, 1, 2)) < 0) {
    printf("Output #1: NO SUCH ROUTE\n");
  } else printf("Output #1: %d\n", ab + bc);

  // The distance of the route A-D:
  if ((ad = dijkstra(wdg, 0, 3)) < 0) {
    printf("Output #2: NO SUCH ROUTE\n");
  } else printf("Output #2: %d\n", ad);

  // The distance of the route A-D-C:
  if (ad < 0 || (dc = dijkstra(wdg, 3, 2)) < 0) {
    printf("Output #3: NO SUCH ROUTE\n");
  } else printf("Output #3: %d\n", ad + dc);

  // The distance of the route A-E-B-C-D:
  if ((ae = dijkstra(wdg, 0, 4)) < 0 || (eb = dijkstra(wdg, 4, 1)) < 0 || bc < 0 || (cd = dijkstra(wdg, 2, 3)) < 0) {
    printf("Output #4: NO SUCH ROUTE\n");
  } else printf("Output #4: %d\n", ae + eb + bc + cd);

  // The distance of the route A-E-D: (FAIL!)
  if (ae < 0 || (ed = dijkstra(wdg, 4, 3)) < 0) {
    printf("Output #5: NO SUCH ROUTE\n");
  } else printf("Output #5: %d\n", ae + ed);

  // The length of the shortest route from A to C:
  if ((ac = dijkstra(wdg, 0, 2)) < 0) {
    printf("Output #8: NO SUCH ROUTE\n");
  } else printf("Output #8: %d\n", ac);

  // The length of the shortest route from B to B: (FAIL!)
  if ((bb = dijkstra(wdg, 1, 1)) < 0) {
    printf("Output #9: NO SUCH ROUTE\n");
  } else printf("Output #9: %d\n", bb);

  return 0;
}
