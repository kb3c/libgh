/* -*- mode: C; tab-width: 2; indent-tabs-mode: t; c-basic-offset: 2 -*- */
/* ghstr.h
 * 
 *     libgh... details...
 *                         str        
 * 
 *      2016feb
 * 
 * Copyright (c) 2012-2016, polarysekt, kb3c
 */

#ifndef ghinc_deja_ghstr_inc_h__
#  define ghinc_deja_ghstr_inc_h__

void*		gh_malloc( size_t size );
void		gh_free( void* ptr );

char*		gh_strcpy( char* s1, const char* s2 );
size_t		gh_strlen( const char* s );
int		gh_strcmp( const char* s1, const char* s2 );
int		gh_strncmp( const char* s1, const char* s2, size_t n );
/* TODO: */
int		gh_strcat( char* s1, const char* s2 );
int		gh_strncat( char* s1, const char* s2, size_t n );

#endif
