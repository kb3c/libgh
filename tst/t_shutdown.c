/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_shutdown.c
 *
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {

  ut_showheader( "t_shutdown", 0 );

  ut_showsection( "ATTEMPT 'DRY' SHUTDOWN\n");
  ghRunnableShutdownDefault();
  
  ut_showsection( "ATTEMPT NORMAL Init/Shutdown\n" );
  
  ghInit( &argc, &argv );
  ghRunnableShutdownDefault();
  
  
  ut_showheader( "t_shutdown", 1 );

  return 0;
}
