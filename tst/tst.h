/* tst.h
 * Unit Test common header
 *
 * Copyright (c) 2015, polarysekt
 */
 
#ifndef libghinc_test_ut_h__
#  define libghinc_test_ut_h__

#  include "../gh.h"


inline void ut_showheader( char* text, char isEnd ) {
	ghTerminalSetForecolor( ghTC_YELLOW );
	ghTerminalSetAttribute( ghTA_BRIGHT );

	gh_printf( "=== " );
	
	if( isEnd )
		gh_printf( "END " );
	else
		gh_printf( "BEGIN " );
	
	gh_printf( "UNIT TEST: %s\n", text );
	ghTerminalSetAttribute( ghTA_RESET );
}

inline void ut_showsection( char* text ) {
	ghTerminalSetForecolor( ghTC_YELLOW );
//	ghTerminalSetColor( ghTC_BLUE, ghTC_BLACK );

	gh_printf( "--- %s\n", text );
	
	ghTerminalSetAttribute( ghTA_RESET );
}

#endif

