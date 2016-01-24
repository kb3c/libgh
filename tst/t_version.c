/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_version.c
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {

  ut_showheader( "t_version", 0 );

  gh_printf( "%s ", ghVersionGetTitle() );

  gh_printf( "%s/%s ", ghVersionGetArchitecture(), ghVersionGetPlatform() );

  gh_printf( "%d.%d.%d.%d ", ghVersionGetMajor(), ghVersionGetMinor(), ghVersionGetRelease(), ghVersionGetRevision() );
  gh_printf( "(%d)\n", ghVersionGetBuild() );

  gh_printf( "\t%s\n", ghVersionGetCopyright() );

  ut_showheader( "t_version", 1 );

  return 0;
}
