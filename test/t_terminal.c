/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_terminal.c
 * terminal functionality tests
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {
  ghTTYCOLOR c1 = ghTC_BLACK, c2 = ghTC_BLACK;

  gh_printf( "Unit Test t_terminal\n" );

  gh_printf( "=== ATTRIBUTES ===\n" );

  gh_printf( "--- BRIGHT ---\n" );
  ghTerminalSetAttribute( ghTA_BRIGHT );

  gh_printf( "~testext~\n" );

  ghTerminalSetAttribute( ghTA_RESET );

  gh_printf( "--- DIM ---\n" );
  ghTerminalSetAttribute( ghTA_DIM );

  gh_printf( "~testext~\n" );

  ghTerminalSetAttribute( ghTA_RESET );

  gh_printf( "--- UNDERLINE ---\n" );
  ghTerminalSetAttribute( ghTA_UNDERLINE );

  gh_printf( "~testext~\n" );

  ghTerminalSetAttribute( ghTA_RESET );

  gh_printf( "--- BLINK ---\n" );
  ghTerminalSetAttribute( ghTA_BLINK );

  gh_printf( "~testext~\n" );

  ghTerminalSetAttribute( ghTA_RESET );

  gh_printf( "=== COLORS ===\n" );

  for( c1=ghTC_BLACK; c1<=ghTC_WHITE; c1++ ) {
    for( c2=ghTC_BLACK; c2<=ghTC_WHITE; c2++ ) {
      ghTerminalSetColor2i( c2, c1 );
      gh_printf( "X" );	
    }
    ghTerminalSetAttribute( ghTA_RESET );
    gh_printf( "\n" );
  }

  gh_printf( "===END OF UT t_terminal===\n" );
  return 0;
}
