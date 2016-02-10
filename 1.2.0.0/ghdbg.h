/* -*- mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* ghdbg.h
 * 
 *     libgh... details...
 *                         DEBUG        
 * 
 *      2016feb
 * 
 * Copyright (c) 2012-2016, polarysekt, kb3c
 */

#ifndef ghinc_deja_ghdbg_deja_h__
#  define ghinc_deja_ghdbg_deja_h__

/* ONLY MINIMAL NECESSARY */
//#include "ghio.h"


/*** DEBUGGING ***/
#  ifndef NDEBUG
#    define ghDBGprintf(...)	gh_printf( __VA_ARGS__ )
#    ifdef GHDBG_VERBOSE
#      define ghDBGVRBprintf(...)	gh_printf( __VA_ARGS__ )
#    else
#      define ghDBGVRBprintf(...)	((void)0)
#    endif
#  else
#    define ghDBGprintf(...)	((void)0)
#    define ghDBGVRBprintf(...)	((void)0)
#  endif

/* WONK in some MACROS */
#  define ghDpf		ghDBGprintf
#  define ghDVpf	ghDBGVRBprintf 

#endif