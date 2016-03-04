/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_runnable.c
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {
  ghRUNNABLE *pdr;

  ut_showheader( "t_runnable", 0 );
  
  pdr = ghInit( &argc, &argv );
  
  gh_printf( "RUNNABLE HANDLE: %x\n", pdr );
  
  ut_showheader( "t_runnable", 1 );
  
  return 0;
}