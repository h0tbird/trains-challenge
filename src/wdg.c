//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include "wdg.h"

//-----------------------------------------------------------------------------
// wdg_node:
//-----------------------------------------------------------------------------

PNODE wdg_node(int dst, int wgt) {

  PNODE node = (PNODE) malloc(sizeof(NODE));
  node->dst = dst;
  node->wgt = wgt;
  node->next = NULL;
  return node;
}

//-----------------------------------------------------------------------------
// wdg_new:
//-----------------------------------------------------------------------------

PWDG wdg_new(int count) {

  int i;
  PWDG wdg = (PWDG) malloc(sizeof(WDG));
  wdg->count = count;
  wdg->list = (PLIST) malloc(count * sizeof(LIST));
  for (i=0; i<count; ++i) wdg->list[i].head = NULL;
  return wdg;
}

//-----------------------------------------------------------------------------
// wdg_insert:
//-----------------------------------------------------------------------------

void wdg_insert(PWDG wdg, int src, int dst, int wgt) {

  PNODE node = wdg_node(dst, wgt);
  node->next = wdg->list[src].head;
  wdg->list[src].head = node;
}

//-----------------------------------------------------------------------------
// wdg_print:
//-----------------------------------------------------------------------------

void wdg_print(PWDG wdg) {

  int i;

  printf("\nNon-negative weighted directed graph (WDG)\n\n");

  for(i=0; i<wdg->count; ++i) {

    PNODE node = wdg->list[i].head;
    printf(" Node %d: head", i);

    while (node) {
      printf(" -> %d(%d)", node->dst, node->wgt);
      node = node->next;
    }

    printf("\n");
  }

  printf("\n");
}
