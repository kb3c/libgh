/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_rect.c
 *
 * Updated for 1.0.0.3
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

void showRectInfo( ghRECT* pr ) {
  gh_printf( "X     : %d\n", ghRectGetX(pr) );
  gh_printf( "Y     : %d\n", ghRectGetY(pr) );
  gh_printf( "WIDTH : %d\n", ghRectGetWidth(pr) );
  gh_printf( "HEIGHT: %d\n", ghRectGetHeight(pr) );
  gh_printf( "X2    : %d\n", ghRectGetX2(pr) );
  gh_printf( "Y2    : %d\n", ghRectGetY2(pr) );
}

int main( int argc, char** argv ) {

  /* pointer to ghRECT to be created/destroyed */
  ghRECT* pr;

  /* Allocate some manual get/set variables */
  /*TODO 
   *   int	rx, ry, rx2, ry2;
   *   unsigned int rw, rh;
   */

  ut_showheader( "t_rect", 0 );

  ut_showsection( "CREATE ghRECT : DISPLAY EACH" );
  
  pr = ghRectCreate();

  showRectInfo( pr );
  
  ut_showsection( "SET ghRECT EACH : DISPLAY EACH" );

  ghRectSetX( pr, 10 );
  ghRectSetY( pr, 10 );
  ghRectSetWidth( pr, 100 );
  ghRectSetHeight( pr, 100 );

  showRectInfo( pr );

  ut_showsection( "SET ghRECT X2,Y2 : DISPLAY EACH" );
  ghRectSetX2( pr, 200 );
  ghRectSetY2( pr, 200 );

  showRectInfo( pr );
  
  ut_showsection( "SET ghRECT PAIRS : DISPLAY PAIRS" );

  ghRectSetPosition( pr, 12, 12 );
  ghRectSetExtent( pr, 120, 120 );

  /*
  ghRectGetPosition( pr, &rx, &ry );
  ghRectGetExtent( pr, &rw, &rh );
  ghRectGetExtentPosition( pr, &rx2, &ry2 );
  */
  
  showRectInfo( pr );

  ut_showsection( "DESTROY ghRECT" ); 
  
  ghRectDestroy( pr );
  
  ut_showheader( "t_rect", 1 );

  return 0;
}

