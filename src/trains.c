//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include "trains.h"

//-----------------------------------------------------------------------------
// loadData
//-----------------------------------------------------------------------------

PWDG loadData(char *file) {

  // AB5, BC4, CD8, DC8, DE6, AD5, CE2, EB3, AE7
  // 015, 124, 238, 328, 346, 035, 242, 413, 047

  FILE *fp;
  char buf[MAXLINE];
  char nodes[MAXLINE];
  int i;

  // Read the data file:
  if ((fp = fopen(file, "r")) == NULL) MyDBG(end0);
  if (fgets(buf, MAXLINE, fp) == NULL) MyDBG(end1);
  fclose(fp);

  #ifdef DEBUG
  printf("\n[DEBUG] Input data: %s", buf);
  #endif

  // Count nodes:
  for (i=0; i<strlen(buf); i++) {
    if (buf[i] < CAP_A || buf[i] > CAP_Z) continue;
    if (strchr(nodes, buf[i]) != NULL) continue;
    strncat(nodes, &buf[i], 1);
  }

  // Create a new structure:
  PWDG wdg = wdg_new((int)strlen(nodes));

  // Feed the dirgraph:
  for (i=0; i<strlen(buf)-3; i++) {
    if (buf[i] == ',' || buf[i] == ' ') continue;
    wdg_insert(wdg, buf[i]-65, buf[i+1]-65, buf[i+2]-48);
    i = i+2;
  }

  // Return on success:
  return wdg;

  // Return on error:
  end1: fclose(fp);
  end0: return NULL;
}

//-----------------------------------------------------------------------------
// Entry point:
//-----------------------------------------------------------------------------

int main(int argc, char *argv[]) {

  PWDG wdg;
  int ab, ac, bb, bc, ad, dc, ae, eb, cd, ed;

  // Load data from file:
  if ((wdg = loadData(argv[1])) == NULL) return 1;

  #ifdef DEBUG
  wdg_print(wdg);
  #endif

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
