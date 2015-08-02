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
  wdg->list = (PLIST) malloc((count+1) * sizeof(LIST));
  for (i=0; i<count+1; ++i) wdg->list[i].head = NULL;
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
// wdg_clone:
//-----------------------------------------------------------------------------

void wdg_clone(PWDG wdg, int src) {

  PNODE node = wdg->list[src].head;
  int dst = wdg->count;
  if(wdg->list[dst].head != NULL) return;

  while(node) {
    wdg_insert(wdg, dst, node->dst, node->wgt);
    node = node->next;
  }

  for(int i=0; i<wdg->count; ++i) {
    node = wdg->list[i].head;

    while(node) {
      if(node->dst == src) wdg_insert(wdg, i, dst, node->wgt);
      node = node->next;
    }
  }
}

//-----------------------------------------------------------------------------
// wdg_unclone:
//-----------------------------------------------------------------------------

void wdg_unclone(PWDG wdg) {

  int src = wdg->count;
  PNODE kill, node = wdg->list[src].head;
  if(node == NULL) return;

  while(node) {
    kill=node;
    node = node->next;
    free(kill);
  }

  wdg->list[src].head = NULL;

  for(int i=0; i<wdg->count; ++i) {
    node = wdg->list[i].head;

    while(node) {
      if(node->dst == src) {
        kill=node;
        node = node->next;
        wdg->list[i].head = node;
        free(kill);
      } else node = node->next;
    }
  }
}

//-----------------------------------------------------------------------------
// wdg_print:
//-----------------------------------------------------------------------------

void wdg_print(PWDG wdg) {

  int i;

  printf("[DEBUB] Dump of the adjacency list:\n");

  for(i=0; i<wdg->count+1; ++i) {

    PNODE node = wdg->list[i].head;
    printf("[DEBUG] - Node %d: head", i);

    while (node) {
      printf(" -> %d(%d)", node->dst, node->wgt);
      node = node->next;
    }

    printf("\n");
  }

  printf("\n");
}
