/* -*- mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* gh.h
 * 
 *     the ^muddy^ *OFFICIAL* master include file
 *        ^ruddy^
 * 
 *      2016feb
 * 
 * Copyright (c) 2012-2016, polarysekt, kb3c
 */

#ifndef ghinc_gh_h__
#  define ghinc_gh_h__

/*** stdlib headers (required) ***/
#  include <limits.h>	/* INT_MIN */ /* also, TODO: */
#  include <stdarg.h>	/* __VA_ARGS__, va_, ... (argument notation) */
#  include <stddef.h>	/* size_t */


/* finally break this out to allow for minimal inclusion
 * STAY ON THAT DEPLOYMENT SCENARIO
 * 
 */

#  include "ghio.h" /* for NDEBUG cases */
#  include "ghdbg.h"

/*** ghP (Platform Defines) ***/
#  define ghP_NONE	0
/* 'c' */
#  define ghP_CURSES	100
/* 'w' */
#  define ghP_MSWIN	201
#  define ghP_MSWIN64   202
#  define ghP_WIN	ghP_MSWIN
/* 'm' */
#  define ghP_MAC	300
#  define ghP_CARBON	301
/* 'o' : tentative */
#  define ghP_OSX	302
/* 'i' */
#  define ghP_IOS	303
/* 'x' */
#  define ghP_X		400
#  define ghP_X11 	ghP_X
/* 'a' */
#  define ghP_ANDROID	401


/***
 *	 TODO: THIS IS FOR DEBUG ONLY!!! 
 * 
 * 	remove when build actual
 ***/
#ifndef ghP
/*default to curses */
#  define ghP ghP_CURSES
#endif


#  if (ghP==ghP_MSWIN)
#    include "windows.h"
#  elif (ghP==ghP_X11)
#    include "X11/Xlib.h"
#  elif (ghP==ghP_CURSES)
#    include "curses.h"
#  else
#    warning !!! UNDETECTED PLATFORM !!! Errors to Ensue.
#  endif

#  define ghNULL		0
typedef unsigned char ghBOOL;
#  define ghTRUE		1
#  define ghFALSE		0
typedef int	ghRET;

/*TODO: determine proper type for ghCOLOR*/
typedef long	ghCOLOR;

/*** ERROR enum ***/
/* TODO: integrate shorter error defines */
typedef enum t_ghERROR {
  ghERROR_GENERIC = INT_MIN,
  ghERROR_OUT_OF_MEMORY,
  ghERROR_UNSUPPORTED_PLATFORM,
  ghERROR_NOT_IMPLEMENTED,
  ghERROR_INVALID_ARGUMENT,
  ghERROR_INVALID_CONTEXT,
  ghERROR_INVALID_COORDINATE,
  ghERROR_INVALID_DISPLAY,
  ghERROR_INVALID_DRAWABLE,
  ghERROR_INVALID_FILESPEC,
  ghERROR_INVALID_FUNCTION_PTR,
  ghERROR_UNINITIALIZED_PLATFORM,
  ghERROR_INVALID_PLATFORM,
  ghERROR_INVALID_RECT,
  ghERROR_INVALID_RENDERABLE,
  ghERROR_INVALID_RUNNABLE,
  ghERROR_UNINITIALIZED_RUNNABLE,
  ghERROR_INVALID_SCREEN,
  ghERROR_INVALID_WINDOW,
  ghERROR_UNINITIALIZED_WINDOW,
  ghERROR_NONE = 0
} ghERROR;

/*TODO: fix, as this was a workaround */
#define ghERROR_INVALID_COORD ghERROR_INVALID_COORDINATE
/*    */

#define ghERR_INV_COORD	ghERROR_INVALID_COORDINATE
#define ghERR_GENERIC	ghERROR_GENERIC
#define ghERR_OOM		ghERROR_OUT_OF_MEMORY
#define ghERR_NOTSUPP	ghERROR_UNSUPPORTED_PLATFORM
#define ghERR_INV_ARG	ghERROR_INVALID_ARGUMENT
#define ghERR_NONE		ghERROR_NONE

#define ghSUCCESS		ghERROR_NONE


/* TODO: integrate new name for type */
typedef enum t_ghVERSIONFIELD {
  ghVF_major = 0,
  ghVF_minor,
  ghVF_release,
  ghVF_revision,
  ghVF_minorbuild,
  ghVF_releasebuild,
  ghVF_revisionbuild,
  ghVF_build,
  ghVF_title,
  ghVF_author,
  ghVF_copyright,
  ghVF_architecture,
  ghVF_platform
} ghVERSIONFIELD;
#define ghVERSIONFIELDREF	ghVERSIONFIELD;
#define ghVFR				ghVERSIONFIELD;

/*** libgh Declarations ***/

/*NOTE: this is not complete! */
typedef enum t_ghTTYSEQUENCE {
  ghTS_CUU = 'A',	/* Cursor Up */
  ghTS_CUD,		/* Cursor Down */
  ghTS_CUF,		/* Cursor Forward */
  ghTS_CUB,		/* Cursor Back */
  ghTS_CNL,		/* Cursor Next Line */
  ghTS_CPL,		/* Cursor Previous Line */
  ghTS_CHA,		/* Cursor Horizontal Absolute */
  ghTS_CUP,		/* Cursor Position [2 param] */
  ghTS_ED = 'J',	/* Erase Display [0, 1, or 2] */
  ghTS_EL,		/* Erase Line */
  ghTS_SU = 'S',	/* Scroll Up (whole page) */
  ghTS_SD,		/* Scroll Down (whole page) */
  ghTS_HVP = 'f',	/* Horizontal and Vertical Position [same as CUP] */
  ghTS_SGR = 'm',	/* Select Graphic Rendition */
  ghTS_SCP = 's',	/* Save Cursor Position [no param] */
  ghTS_RCP = 'u'	/* Restore Cursor Position [no param] */
} ghTTYSEQUENCE;

/* NOTE: incomplete [needs 0, 1 ] */
typedef enum t_ghTTYERASE {
  ghTE_FULL = 2
} ghTTYERASE;

typedef enum t_ghTTYCOLOR {
  ghTC_BLACK = 0,
  ghTC_RED,
  ghTC_GREEN,
  ghTC_YELLOW,
  ghTC_BLUE,
  ghTC_MAGENTA,
  ghTC_CYAN,
  ghTC_WHITE
} ghTTYCOLOR;

typedef enum t_ghTTYATTR {
  ghTA_RESET = 0,
  ghTA_BRIGHT,
  ghTA_DIM,
  ghTA_ITALIC,
  ghTA_UNDERLINE,
  ghTA_BLINK,
  /* skip blink rapid */
  ghTA_REVERSE = 7,
  ghTA_HIDDEN,
  ghTA_STRIKETHRU,
  /* skip font setting */
  ghTA_DOUBLEUNDERLINE = 21, /* sometimes bold off? */
  ghTA_NORMAL,
  ghTA_NOITALIC,							/* also no fraktur */
  ghTA_NOUNDERLINE,
  ghTA_NOBLINK,
  /* skips */
  ghTA_NOHIDDEN = 28,
  ghTA_NOSTRIKETHRU
} ghTTYATTR;

/*** Forward Declarations ***/
/*typedef struct t_ghAPPLICATION	ghAPPLICATION;*/
typedef struct t_ghCONTEXT		ghCONTEXT;
typedef struct t_ghDRAWABLE		ghDRAWABLE;
typedef struct t_ghFONT			ghFONT;
typedef struct t_ghGENERIC		ghGENERIC;
typedef struct t_ghHANDLER		ghHANDLER;
typedef struct t_ghIMAGE		ghIMAGE;
typedef struct t_ghLISTABLE		ghLISTABLE;
typedef struct t_ghMONITOR		ghMONITOR;
typedef struct t_ghRECT			ghRECT;
typedef struct t_ghRENDERABLE		ghRENDERABLE;
typedef struct t_ghRUNNABLE 		ghRUNNABLE;
/*typedef struct t_ghTGAIMAGE	ghTGAIMAGE;*/
typedef struct t_ghSHAPE		ghSHAPE;
typedef struct t_ghSPRITE		ghSPRITE;
typedef struct t_ghSTACKABLE		ghSTACKABLE;
typedef struct t_ghWINDOW		ghWINDOW;

/*** Actual Declarations ***/
typedef struct t_gh2DCOORD {
  int x;
  int y;
} gh2DCOORD;
#define ghXY gh2DCOORD

typedef struct t_ghXYZ {
  int x;
  int y;
  int z;
} ghXYZ;

typedef struct t_ghEXTENT	{
  unsigned int w;
  unsigned int h;
} ghEXTENT;
#define ghWH ghEXTENT

/*** STDLIB WRAPPERS ***/
#ifndef gh_printf
int		gh_printf( const char *fmt, ... );
#endif
int		gh_sprintf( char* str, const char *fmt, ... );
int		gh_atexit( void (*fn)(void) );
void*		gh_malloc( size_t size );
void		gh_free( void* ptr );
unsigned int	gh_sleep( unsigned int s );
char*		gh_strcpy( char* s1, const char* s2 );
size_t		gh_strlen( const char* s );
int		gh_strcmp( const char* s1, const char* s2 );
int		gh_strncmp( const char* s1, const char* s2, size_t n );
/* TODO: */
int		gh_strcat( char* s1, const char* s2 );
int		gh_strncat( char* s1, const char* s2, size_t n );


/*** libgh API ***/
int		ghErrorEnum( void );
#define ghErrorCount ghErrorEnum
int		ghErrorClear( void );
ghERROR		ghErrorPeek( void );
ghERROR		ghErrorPop( void );
ghERROR		ghErrorPush( ghERROR e );

unsigned int	ghErrorGetStringLength( ghERROR e );
char*		ghErrorGetString( ghERROR e );
ghRET		ghErrorGetStringSZ( ghERROR e, char pszErr[] );

int		ghVersionGetMajor( void );
int		ghVersionGetMinor( void );
int		ghVersionGetRelease( void );
int		ghVersionGetRevision( void );
int		ghVersionGetBuild( void );
/*int	ghVersionGetProfileBuild( void );*/
/* TODO: see const revisions */
char*		ghVersionGetTitle( void );
char*		ghVersionGetAuthor( void );
char*		ghVersionGetArchitecture( void );
char*		ghVersionGetPlatform( void );
char*		ghVersionGetCopyright( void );

unsigned int 	ghVersionGetStringLength( ghVERSIONFIELD vr );
ghRET		ghVersionGetTitleSZ( char ps[] );
ghRET		ghVersionGetAuthorSZ( char ps[] );
ghRET		ghVersionGetCopyrightSZ( char ps[] );
ghRET		ghVersionGetArchitectureSZ( char ps[] ); 
ghRET		ghVersionGetPlatformSZ( char ps[] );


/*** :tty: ***/
/* TODO: name changers -> con sole (with foot), better than terminal (disease) */
void	ghTerminalSetAttribute( ghTTYATTR attr );
#define ghConsoleSetAttribute ghTerminalSetAttribute
void	ghTerminalSetColor2i( ghTTYCOLOR fg, ghTTYCOLOR bg );
#define ghConsoleSetColor2i ghTerminalSetColor2i
#define ghTerminalSetColor ghTerminalSetColor2i
#define ghConsoleSetColor ghTerminalSetColor2i
#define ghTerminalSetColour ghTerminalSetColor2i
#define ghConsoleSetColour ghConsoleSetColour
void	ghTerminalSetBackcolor( ghTTYCOLOR c );
void	ghTerminalSetForecolor( ghTTYCOLOR c );
/*TODO:*/
void	ghTerminalEraseDisplay( ghTTYERASE v );
void	ghTerminalClear( void );

/*** :ghRECT: ***/
ghRECT*		ghRectCreate();
ghRET	ghRectDestroy( ghRECT* pr );
ghRET	ghRectSetHeight( ghRECT* pr, unsigned int height );
ghRET	ghRectSetWidth( ghRECT* pr, unsigned int width );
ghRET	ghRectSetExtent2ui( ghRECT* pr, unsigned int width, unsigned int height );
#define ghRectSetExtent ghRectSetExtent2ui
#define ghRectResize	ghRectSetExtent2ui
ghRET	ghRectSetX( ghRECT* pr, int x );
#define ghRectSetLeft ghRectSetX
ghRET	ghRectSetY( ghRECT* pr, int y );
#define ghRectSetTop ghRectSetY
ghRET	ghRectSetPosition2i( ghRECT* pr, int x, int y );
#define ghRectSetPosition ghRectSetPosition2i
#define ghRectMove ghRectSetPosition2i
ghRET	ghRectSetX2( ghRECT* pr, int x2 );
#define ghRectSetRight ghRectSetX2
#define ghRectSetExtentX ghRectSetX2
ghRET	ghRectSetY2( ghRECT* pr, int y2 );
#define ghRectSetBottom ghRectSetY2
#define ghRectSetExtentY ghRectSetY2
ghRET	ghRectSetExtentPosition2i( ghRECT* pr, int x2, int y2 );
#define ghRectSetExtentPosition ghRectSetExtentPosition2i
int		ghRectGetX( ghRECT* pr );
#define ghRectGetLeft ghRectGetX
int		ghRectGetY( ghRECT* pr );
#define ghRectGetTop ghRectGetTop
ghRET	ghRectGetPosition2i( ghRECT* pr, int* x, int* y );
#define ghRectGetPosition ghRectGetPosition2i
unsigned int	ghRectGetHeight( ghRECT* pr );
unsigned int	ghRectGetWidth( ghRECT* pr );
ghRET	ghRectGetExtent2ui( ghRECT* pr, unsigned int* width, unsigned int* height );
#define ghRectGetExtent ghRectGetExtent2ui
int		ghRectGetX2( ghRECT* pr );
#define ghRectGetRight ghRectGetX2
#define ghRectGetExtentX ghRectGetX2
int	ghRectGetY2( ghRECT* pr );
#define ghRectGetBottom ghRectGetY2
#define ghRectGetExtentY ghRectGetY2
ghRET	ghRectGetExtentPosition2i( ghRECT* pr, int* x2, int* y2 );
#define ghRectGetExtentPosition ghRectGetExtentPosition2i
/* TODO:
 * ghRET	ghRectSetExtent1s( ghRECT* pr, ghEXTENT* px );
*/


/*** :ghSTACKABLE: ***/
void* ghStackablePeek( ghSTACKABLE* ps );
ghSTACKABLE* ghStackablePush( ghSTACKABLE* ps, void* pv );
ghSTACKABLE* ghStackablePop( ghSTACKABLE* ps, void* pv );
unsigned int ghStackableEnum( ghSTACKABLE* ps );
#define ghStackableCount ghStackableEnum
ghRET ghStackableClear( ghSTACKABLE* ps );


/*** :ghLISTABLE: ***/


/*** :ghRUNNABLE: ***/
ghRUNNABLE* ghInit( int* pargc, char*** pargv );
ghRET ghRun( void );
/* ghRET ghRunModalWindow( ghWINDOW* pw ); */

ghRUNNABLE*	ghRunnableCreate( void );
void		ghRunnableDestroy( ghRUNNABLE* pr );
ghRUNNABLE*	ghRunnableInit( ghRUNNABLE* pr, int* pargc, char*** pargv );

/* #define ghInit(x,y) ghRunnableInit( ghRunnableGetDefault(), */
/* ghRUNNABLE*	ghRunnableInitDefault( int* pargc, char*** pargv ); */

ghRET		ghRunnableShutdown( ghRUNNABLE* pr );
void		ghRunnableShutdownDefault( void );
ghRUNNABLE*	ghRunnableGetDefault( void );
void		ghRunnableSetDefault( ghRUNNABLE* pr );
int		ghRunnableGetArgC( ghRUNNABLE* pr );
int*		ghRunnableGetPArgC( ghRUNNABLE* pr );
char***		ghRunnableGetArgV( ghRUNNABLE* pr );

/***TODO
    See the C++ implementation...
 ***/
int		ghRunnableEnumWindows( ghRUNNABLE* pr );
ghRET		ghRunnableAddWindow( ghRUNNABLE* pr, ghWINDOW* pw );
ghRET		ghRunnableRemoveWindow( ghRUNNABLE* pr, ghWINDOW* pw );

unsigned int	ghRunnableGetMonitorDefault( ghRUNNABLE* pr );
ghWINDOW*	ghRunnableGetWindowDefault( ghRUNNABLE* pr );

unsigned int	ghMonitorGetWidth( unsigned int m );
unsigned int	ghMonitorGetHeight( unsigned int m );
unsigned int	ghMonitorGetExtent( unsigned int m );
ghRET		ghMonitorGetExtent2i( unsigned int m, unsigned int* w, unsigned int* h );
#define ghMonitorGetExtent ghMonitorGetExtent2i


/*** :ghWINDOW: ***/
ghWINDOW*	ghWindowCreate( void );
ghWINDOW*	ghWindowInit( ghWINDOW* pw );
ghRET 		ghWindowCheckInit( ghWINDOW* pw );
ghRET		ghWindowShutdown( ghWINDOW* pw );
ghRET		ghWindowDestroy( ghWINDOW* pw );
ghRET		ghWindowSetParent( ghWINDOW* pw, ghWINDOW* pp );
unsigned int ghWindowGetBorderWidth( ghWINDOW* pw );
ghRET		ghWindowSetBorderWidth( ghWINDOW* pw, unsigned int bw );
ghRET		ghWindowShow( ghWINDOW* pw );
ghRET		ghWindowHide( ghWINDOW* pw );

ghRET		ghWindowRaise( ghWINDOW* pw );
ghRET		ghWindowLower( ghWINDOW* pw );

int			ghWindowGetX( ghWINDOW* pw );
int			ghWindowGetY( ghWINDOW* pw );
ghRET		ghWindowGetPosition2i( ghWINDOW* pw, int* x, int* y );
#define ghWindowGetPosition ghWindowGetPosition2i
unsigned int	ghWindowGetWidth( ghWINDOW* pw );
unsigned int	ghWindowGetHeight( ghWINDOW* pw );
ghRET		ghWindowGetExtent2i( ghWINDOW* pw, unsigned int* w, unsigned int* h );
#define ghWindowGetExtent ghWindowGetExtent2ui
int			ghWindowGetX2( ghWINDOW* pw );
#define ghWindowGetRight ghWindowGetX2
#define ghWindowGetExtentX ghWindowGetX2
int			ghWindowGetY2( ghWINDOW* pw );
#define ghWindowGetBottom ghWindowGetY2
#define ghWindowGetExtentY ghWindowGetY2
ghRET		ghWindowGetExtentPosition2i( ghWINDOW* pw, int* x2, int* y2 );
#define ghWindowGetExtentPosition ghWindowGetExtentPosition2i
/* ghWindowGetRect() */
ghRET		ghWindowSetCaption( ghWINDOW* pw, const char* str );
#define ghWindowSetTitle ghWindowSetCaption
ghRET		ghWindowSetX( ghWINDOW* pw, int x );
#define ghWindowSetLeft ghWindowSetX
ghRET		ghWindowSetY( ghWINDOW* pw, int y );
#define ghWindowSetTop ghWindowSetY
ghRET		ghWindowSetPosition2i( ghWINDOW* pw, int x, int y );
#define ghWindowSetPosition ghWindowSetPosition2i
ghRET		ghWindowSetWidth( ghWINDOW* pw, unsigned int width );
ghRET		ghWindowSetHeight( ghWINDOW* pw, unsigned int height );
ghRET		ghWindowSetExtent2ui( ghWINDOW* pw, unsigned int width, unsigned int height );
#define ghWindowSetExtent ghWindowSetExtent2ui
ghRET		ghWindowSetX2( ghWINDOW* pw, int x2 );
ghRET		ghWindowSetY2( ghWINDOW* pw, int y2 );
ghRET		ghWindowSetExtentPosition2i( ghWINDOW* pw, int x2, int y2 );
#define ghWindowSetExtentPosition ghWindowSetExtentPosition2i
ghRET	ghWindowSetRect( ghWINDOW* pw, ghRECT* pr);

/*** :ghDRAWABLE: ***/
/* todo: should we use RASTER somewhere? */
/* TODO: backend mode: buffer | window */
ghDRAWABLE*	ghDrawableCreate();
ghDRAWABLE*	ghDrawableInit( ghDRAWABLE* pd );
ghDRAWABLE*	ghDrawableShutdown( ghDRAWABLE *pd );
ghRET		ghDrawableDestroy( ghDRAWABLE* pd );

/*** :ghRENDERABLE: ***/
/* TODO: backend mode: DX | GL */
ghRENDERABLE*	ghRenderableCreate();
ghRENDERABLE*	ghRenderableInit( ghRENDERABLE* pr );
ghRENDERABLE*	ghRenderableShutdown( ghRENDERABLE* pr );
ghRET		ghRenderableDestroy( ghRENDERABLE* pr );


/*** :ghIMAGE: ***/
ghIMAGE*	ghImageCreate( );
//ghIMAGE*	ghImageCreateFromDrawable( );

void		ghImageDestroy( ghIMAGE* pi );

ghRET		ghImageSetExtent2i( ghIMAGE* pi, unsigned int width, unsigned int height );
ghRET		ghImageSetWidth( ghIMAGE* pi, unsigned int width );
ghRET		ghImageSetHeight( ghIMAGE* pi, unsigned int height );
ghRET		ghImageSetDepth( ghIMAGE* pi, int depth );
unsigned int	ghImageGetWidth( ghIMAGE* pi );
unsigned int	ghImageGetHeight( ghIMAGE* pi );
ghRET		ghImageGetExtent2i( ghIMAGE* pi, unsigned int* pwidth, unsigned int *pheight );
int		ghImageGetDepth( ghIMAGE* pi );

ghRET		ghImageInitColor( ghIMAGE* pi, unsigned long c );
ghRET		ghImageInitBMP( ghIMAGE* pi, char* bmpsz );
ghRET		ghImageInitTGA( ghIMAGE* pi, char* tgasz );
ghRET		ghImageInitPCX( ghIMAGE* pi, char*  pcxsz );
ghRET		ghImageInitPNG( ghIMAGE* pi, char* pngsz );
//ghRET		ghImageInitFromDrawable( ghIMAGE* pi, ghDRAWABLE* pd );


ghSPRITE*	ghSpriteCreate( );
void		ghSpriteDestroy( );


#endif /*ghinc_gh_h__*/
