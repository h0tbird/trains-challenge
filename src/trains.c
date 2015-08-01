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

  wdg_print(wdg);
  dijkstra(wdg, 0);
  dijkstra(wdg, 1);
  dijkstra(wdg, 2);
  dijkstra(wdg, 3);
  dijkstra(wdg, 4);

  return 0;
}
