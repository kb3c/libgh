## makefile.t
## test makefile for libgh/tst
## Copyright(c) 2015-2016, polarysekt

## TODO: append proper extension per platform
## esp. MS-WIN platforms!!!

## NOTE: may not full clean when platform
## has been changed. FF_DONTCARE

## NOTE: requires binary-compatible build
## of libgh

GHSRC = $(wildcard *.c)
GHBIN = $(patsubst %.c, %.out, $(GHSRC))
GHBINDBG = $(patsubst %.c, %.debug.out, $(GHSRC))
GHBINDBGVRB = $(patsubst %.c, %.debug.verbose.out, $(GHSRC))

## TODO: hook with master setting
EXLIB = -lX11

all: t_ghbin

all_debug: $(GHBINDBG)

all_debug_verbose: $(GHBINDBGVRB)

t_ghbin: $(GHBIN)

%.out: %.c
	@echo "        ++ $@"
	@gcc -Wall -DNDEBUG -O2 -o $@ $^ ../libgh.a $(EXLIB)

%.debug.out: %.c
	@echo "        ++ $@"
	@gcc -Wall -g -o $@ $^ ../libgh_debug.a $(EXLIB)

%.debug.verbose.out: %.c
	@echo "        ++ $@"
	@gcc -Wall -g -o $@ $^ ../libgh_debug_v.a $(EXLIB)	
	
clean:
	@echo "Remove BIN files..."
	@rm -f $(GHBIN)
	@echo "Remove DEBUG BIN files..."
	@rm -f $(GHBINDBG)
	@echo "Remove DEBUG VERBOSE files..."
	@rm -f $(GHBINDBGVRB)