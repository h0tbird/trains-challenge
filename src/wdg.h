//-----------------------------------------------------------------------------
// Include guard:
//-----------------------------------------------------------------------------

#ifndef _WDG_
#define _WDG_

//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

//-----------------------------------------------------------------------------
// Typedefs:
//-----------------------------------------------------------------------------

typedef struct _NODE {

  int dst, wgt;
  struct _NODE* next;

} NODE, *PNODE;

typedef struct _LIST {

  PNODE head;

} LIST, *PLIST;

typedef struct _WDG {

  int count;
  PLIST list;

} WDG, *PWDG;

//-----------------------------------------------------------------------------
// Prototypes:
//-----------------------------------------------------------------------------

PNODE wdg_node(int dst, int wgt);
PWDG wdg_new(int count);
void wdg_insert(PWDG wdg, int src, int dst, int wgt);
void wdg_print(PWDG wdg);
void wdg_clone(PWDG wdg, int src);
void wdg_unclone(PWDG wdg);

//-----------------------------------------------------------------------------
// End of include guard:
//-----------------------------------------------------------------------------

#endif
