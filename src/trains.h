//-----------------------------------------------------------------------------
// Include guard:
//-----------------------------------------------------------------------------

#ifndef _TRAINS_
#define _TRAINS_

//-----------------------------------------------------------------------------
// Includes:
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "wdg.h"
#include "dijkstra.h"

//-----------------------------------------------------------------------------
// Defines:
//-----------------------------------------------------------------------------

#define DEBUG

#define MyDBG(x) do {printf("(%d) %s:%d\n", errno, __FILE__, __LINE__); goto x;} while (0)
#define MAXLINE 255
#define CAP_A 65
#define CAP_Z 90

//-----------------------------------------------------------------------------
// End of include guard:
//-----------------------------------------------------------------------------

#endif
