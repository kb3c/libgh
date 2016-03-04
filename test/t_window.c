/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_window.c
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

void showWindowGeometry( ghWINDOW* pw ) {

  gh_printf( "X, Y   : %d, %d\n", ghWindowGetX(pw), ghWindowGetY(pw) );
  gh_printf( "X2, Y2 : %d, %d\n", ghWindowGetX2(pw), ghWindowGetY2(pw) );
  gh_printf( "W, H   : %d, %d\n", ghWindowGetWidth(pw), ghWindowGetHeight(pw) );
  
}

void showWindowDetails( ghWINDOW* pw ) {
  showWindowGeometry( pw );
  /* gh_printf( "TITLE  : %s\n", ghWindowGetCaption(pw) ); */
}

int main( int argc, char** argv ) {
  ghRUNNABLE* pdr;
  ghWINDOW* pmw;
  unsigned int dm;
  unsigned int mww, mwh;
  
  ut_showheader( "t_window", 0 );
  
  /* ut_showsection( "INIT libgh" ); */
  pdr = ghInit( &argc, &argv );
  
  /* ut_showsection( "GET Default Monitor GEOMETRY" ); */
  dm = ghRunnableGetMonitorDefault( pdr );
  ghMonitorGetExtent( dm, &mww, &mwh );
  
  ut_showsection( "CREATE WINDOW / SET EACH A / BEFORE INIT" );
  pmw = ghWindowCreate();
  
  ghWindowSetX( pmw, mww/4 );
  ghWindowSetY( pmw, mwh/4 );
  ghWindowSetWidth( pmw, mww/2 );
  ghWindowSetHeight( pmw, mwh/2 );
  ghWindowSetCaption( pmw, "t_window|E-A|B" );
  showWindowDetails( pmw );

  ut_showsection( "INIT / SHOW WINDOW" );
  pmw = ghWindowInit( pmw );
  ghWindowShow( pmw );
  
  gh_sleep( 3 );

  ut_showsection( "SHUTDOWN / DESTROY WINDOW" );
  ghWindowShutdown( pmw );
  ghWindowDestroy( pmw );
  
  gh_sleep( 1 );

  ut_showsection( "CREATE WINDOW / SET EACH B / BEFORE INIT" );
  pmw = ghWindowCreate();
  
  ghWindowSetX( pmw, mww/4 );
  ghWindowSetY( pmw, mwh/4 );
  ghWindowSetX2( pmw, mww/4*3 );
  ghWindowSetY2( pmw, mwh/4*3 );
  ghWindowSetCaption( pmw, "t_window|E-B|B" );
  showWindowDetails( pmw );

  ut_showsection( "INIT / SHOW WINDOW" );
  pmw = ghWindowInit( pmw );
  ghWindowShow( pmw );
  
  gh_sleep( 3 );

  ut_showsection( "SHUTDOWN / DESTROY WINDOW" );
  ghWindowShutdown( pmw );
  ghWindowDestroy( pmw );
  
  gh_sleep( 1 );

  
  ut_showsection( "CREATE WINDOW / SET PAIRS / BEFORE INIT" );
  pmw = ghWindowCreate();
  
  ghWindowSetPosition( pmw, mww/4, mwh/4 );
  ghWindowSetExtent( pmw, mww/2, mwh/2 );
  ghWindowSetCaption( pmw, "t_window|P|B" );
  showWindowDetails( pmw );

  ut_showsection( "INIT / SHOW WINDOW" );
  pmw = ghWindowInit( pmw );
  ghWindowShow( pmw );
  
  gh_sleep( 3 );
  
  ut_showsection( "SHUTDOWN / DESTROY WINDOW" );
  ghWindowShutdown( pmw );
  ghWindowDestroy( pmw );
  
  gh_sleep( 1 );
  
  ut_showsection( "CREATE WINDOW / SET PAIRS / AFTER INIT" );
  pmw = ghWindowCreate();
  
  ghWindowSetPosition( pmw, mww/4, mwh/4 );
  ghWindowSetExtent( pmw, mww/2, mwh/2 );
  ghWindowSetCaption( pmw, "t_window|P|A" );
  showWindowDetails( pmw );

  ut_showsection( "INIT / SHOW WINDOW" );
  pmw = ghWindowInit( pmw );
  ghWindowShow( pmw );
  
  gh_sleep( 1 );
  
  ghWindowSetPosition( pmw, mww/4, mwh/4 );
  ghWindowSetExtent( pmw, mww/2, mwh/2 );
  ghWindowSetCaption( pmw, "t_window|P|A" );
  showWindowDetails( pmw );
  
  gh_sleep( 3 );
  
  ut_showsection( "SHUTDOWN / DESTROY WINDOW" );
  ghWindowShutdown( pmw );
  ghWindowDestroy( pmw );
  
  gh_sleep( 1 );
  
  /* ut_showsection( "RUN LIBGH" ); */
  ghRun( );
  
  /*
  ghWindowShutdown( pmw );
  ghWindowDestroy( pmw );
  */
  
  ut_showheader( "t_window", 1 );

  
  return 0;
}