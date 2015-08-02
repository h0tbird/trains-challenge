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

  // Feed the digraph:
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
// distab
//-----------------------------------------------------------------------------

int distab(PWDG wdg, int src, int dst) {

  PNODE node = wdg->list[src].head;

  while (node) {
    if (node->dst == dst) return node->wgt;
    node = node->next;
  }

  return -1;
}

//-----------------------------------------------------------------------------
// Entry point:
//-----------------------------------------------------------------------------

int main(int argc, char *argv[]) {

  // Usage:
  if (argc != 2) {
    printf("Usage: %s <data_file>\n", argv[0]);
    return 1;
  }

  // Load data from file:
  PWDG wdg; if ((wdg = loadData(argv[1])) == NULL) return 1;

  #ifdef DEBUG
  wdg_print(wdg);
  #endif

  //---------------------------------------------
  // Output #1: The distance of the route A-B-C:
  //---------------------------------------------

  int ab,bc;
  if ((ab = distab(wdg, 0, 1)) < 0 || (bc = distab(wdg, 1, 2)) < 0) {
    printf("Output #1: NO SUCH ROUTE\n");
  } else printf("Output #1: %d\n", ab + bc);

  //-------------------------------------------
  // Output #2: The distance of the route A-D:
  //-------------------------------------------

  int ad;
  if ((ad = distab(wdg, 0, 3)) < 0) {
    printf("Output #2: NO SUCH ROUTE\n");
  } else printf("Output #2: %d\n", ad);

  //---------------------------------------------
  // Output #3: The distance of the route A-D-C:
  //---------------------------------------------

  int dc;
  if (ad < 0 || (dc = distab(wdg, 3, 2)) < 0) {
    printf("Output #3: NO SUCH ROUTE\n");
  } else printf("Output #3: %d\n", ad + dc);

  //-------------------------------------------------
  // Output #4: The distance of the route A-E-B-C-D:
  //-------------------------------------------------

  int ae,eb,cd;
  if ((ae = distab(wdg, 0, 4)) < 0 || (eb = distab(wdg, 4, 1)) < 0 || bc < 0 || (cd = distab(wdg, 2, 3)) < 0) {
    printf("Output #4: NO SUCH ROUTE\n");
  } else printf("Output #4: %d\n", ae + eb + bc + cd);

  //---------------------------------------------
  // Output #5: The distance of the route A-E-D:
  //---------------------------------------------

  int ed;
  if (ae < 0 || (ed = distab(wdg, 4, 3)) < 0) {
    printf("Output #5: NO SUCH ROUTE\n");
  } else printf("Output #5: %d\n", ae + ed);

  //------------------------------------------------------------------
  // Output #6: # of trips starting and ending at C with 3 stops max.
  //------------------------------------------------------------------

  //----------------------------------------------------------
  // Output #8: The length of the shortest route from A to C:
  //----------------------------------------------------------

  int ac;
  if ((ac = dijkstra(wdg, 0, 2)) < 0) {
    printf("Output #8: NO SUCH ROUTE\n");
  } else printf("Output #8: %d\n", ac);

  //----------------------------------------------------------
  // Output #9: The length of the shortest route from B to B:
  //----------------------------------------------------------

  int bb;
  if ((bb = dijkstra(wdg, 1, 1)) < 0) {
    printf("Output #9: NO SUCH ROUTE\n");
  } else printf("Output #9: %d\n", bb);

  printf("\n");
  return 0;
}
