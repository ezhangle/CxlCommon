set srcdir=..\..\Libs\Half
cd %srcdir%
set instdir=..\include
mkdir %instdir%
copy half.h %instdir%
copy halfFunction.h %instdir%
copy halfLimits.h %instdir%
