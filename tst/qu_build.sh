#! /bin/bash

## qu_rebuild.sh
## pluggable rebuild script for LCP_01
## Copyright (c) 2015-2016, polarysekt
######################################

#echo -n "    libgh_JESYKA/tst:: qu_build ( FLAGS= "
echo -n "::qu_build ( FLAGS= "
if [[ ( "f" == $1 ) || ( "f" == $2 ) || ( "f" == $3 ) ]];
then
  echo -n "[f]orce "
  ghbsz_OPT="-B";
fi

if [[ ( "d" == $1 ) || ( "d" == $2 ) || ( "d" == $3 ) ]];
then
  echo -n "[d]ebug "
  ghbsz_TARGET="all_debug"
fi

if [[ ( "v" == $1 ) || ( "v" == $2 ) || ( "v" == $3 ) ]];
then
  echo -n "[v]erbose "
  ghbsz_TARGET="all_debug_verbose";
fi

echo ") >>"

echo "libgh/tst make:: $ghbsz_TARGET >"
make $ghbsz_OPT -sf makefile.t $ghbsz_TARGET
