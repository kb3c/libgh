/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_window_ext.c
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {
  //ghRUNNABLE* pdr;
  ghWINDOW* pmw;
    
  ut_showheader( "t_window_child", 0 );
  
  //pdr = 
  ghInit( &argc, &argv );
  
  pmw = ghWindowCreate();
  
  ghWindowSetCaption( pmw, "t_window_ext" );

/*  
  ghWindowSetWidth( pmw, 320 );
  ghWindowSetHeight( pmw, 200 );
  
  ghWindowSetPosition( pmw, 100, 100 );
*/

  pmw = ghWindowInit( pmw );
  
  ghWindowShow( pmw );
  
  ghRun( );
  
  ghWindowShutdown( pmw );
  ghWindowDestroy( pmw );
  
  ut_showheader( "t_window_ext", 1 );

  
  return 0;
}