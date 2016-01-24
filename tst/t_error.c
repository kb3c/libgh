/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_error.c
 * ghERROR functionality tests
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {

  ut_showheader( "t_error", 0 );
  gh_printf( "Error Count: %d\n", ghErrorEnum() );

  ut_showsection( "PUSH 1 ERROR" );

  ghErrorPush( ghERROR_INVALID_ARGUMENT );
	
  gh_printf( "Error Count: %d\n", ghErrorEnum() );
	
  gh_printf( "Last Error (Pop): %s\n", ghErrorGetString( ghErrorPop() ) );

  gh_printf( "Error Count: %d\n", ghErrorEnum() );

  gh_printf( "Last Error (Pop): %s\n", ghErrorGetString( ghErrorPop() ) );

  gh_printf( "Error Count: %d\n", ghErrorEnum() );

  ut_showsection( "PUSH 3 ERRORs" );

  ghErrorPush( ghERROR_INVALID_ARGUMENT );
  ghErrorPush( ghERROR_INVALID_WINDOW );
  ghErrorPush( ghERROR_INVALID_RECT );

  gh_printf( "Error Count: %d\n", ghErrorEnum() );
  gh_printf( "Last Error (Peek): %s\n", ghErrorGetString( ghErrorPeek() ) );
  gh_printf( "Error Count: %d\n", ghErrorEnum() );

  ut_showsection( "ERROR CLEAR" );
  ghErrorClear();

  gh_printf( "Error Count: %d\n", ghErrorEnum() );
  gh_printf( "Last Error (Peek): %s\n", ghErrorGetString( ghErrorPeek() ) );
  gh_printf( "Last Error (Pop): %s\n", ghErrorGetString( ghErrorPop() ) );

  ut_showheader( "t_error", 1 );

  return 0;
}
