/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_window_child.c
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {
  //ghRUNNABLE* pdr;
  ghWINDOW* pmw;
  /* forgo the array for now, just put something here*/
  ghWINDOW* pc1;
  ghWINDOW* pc2;
  ghWINDOW*	pc4;
  
  ghWINDOW* pc5;
  ghWINDOW* pc5A;
    
  ut_showheader( "t_window_child", 0 );
  
  //pdr = 
  ghInit( &argc, &argv );
  
  pmw = ghWindowCreate();
  
  ghWindowSetCaption( pmw, "t_window_child" );
  
  ghWindowSetWidth( pmw, 320 );
  ghWindowSetHeight( pmw, 200 );
  
  ghWindowSetPosition( pmw, 100, 100 );

  pmw = ghWindowInit( pmw );
  
  ghWindowShow( pmw );
  
  pc1 = ghWindowCreate();
  ghWindowSetParent( pc1, pmw );
  ghWindowSetExtent( pc1, 23, 23 );
  ghWindowSetPosition( pc1, 10, 10 );
  ghWindowSetBorderWidth( pc1, 1 );
  
  pc1 = ghWindowInit( pc1 );
  ghWindowShow( pc1 );

  pc2 = ghWindowCreate();
  ghWindowSetParent( pc2, pmw );
  ghWindowSetExtent( pc2, 23, 23 );
  ghWindowSetPosition( pc2, 50, 10 );
  ghWindowSetBorderWidth( pc2, 2 );
  
  pc2 = ghWindowInit( pc2 );
  ghWindowShow( pc2 );
  
  pc4 = ghWindowCreate();
  ghWindowSetParent( pc4, pmw );
  ghWindowSetExtent( pc4, 23, 23 );
  ghWindowSetPosition( pc4, 50, 50 );
  ghWindowSetBorderWidth( pc4, 4 );
  
  pc4 = ghWindowInit( pc4 );
  ghWindowShow( pc4 );
  
  pc5 = ghWindowCreate();
  ghWindowSetParent( pc5, pmw );
  ghWindowSetExtent( pc5, 56, 56 );
  ghWindowSetPosition( pc5, 100, 10 );
  ghWindowSetBorderWidth( pc5, 5 );
  
  pc5 = ghWindowInit( pc5 );
  ghWindowShow( pc5 );
  
  
  pc5A = ghWindowCreate();
  ghWindowSetParent( pc5A, pc5 );
  ghWindowSetExtent( pc5A, 23, 23 );
  ghWindowSetPosition( pc5A, 5, 5 );
  ghWindowSetBorderWidth( pc5A, 1 );
  
  pc5 = ghWindowInit( pc5A );
  ghWindowShow( pc5A );
  
  
  ghRun( );
  
  ghWindowShutdown( pmw );
  ghWindowDestroy( pmw );
  
  ut_showheader( "t_window_child", 1 );

  return 0;
}