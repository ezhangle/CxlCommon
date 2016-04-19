set srcdir=..\..\Libs\Iex
cd %srcdir%
set instdir=..\include64
mkdir %instdir%
copy IexBaseExc.h %instdir%
copy IexMathExc.h %instdir%
copy IexThrowErrnoExc.h %instdir%
copy IexErrnoExc.h %instdir%
copy IexMacros.h %instdir%
copy Iex.h %instdir%
