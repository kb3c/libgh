/* -*- Mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* t_init.c
 * WARNING: will not call shutdown
 *
 * Updated for 1.x
 * 
 * Copyright (c) 2015-2016, polarysekt
 */

#include "tst.h"

int main( int argc, char** argv ) {

  ut_showheader( "t_init", 0 );

  ghInit( &argc, &argv );

  ut_showheader( "t_init", 1 );

  return 0;
}

