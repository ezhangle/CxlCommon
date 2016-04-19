set srcdir=..\..\Libs\IlmThread
cd %srcdir%
set instdir=..\include64
mkdir %instdir%
copy IlmThreadPool.h %instdir%
copy IlmThread.h %instdir%
copy IlmThreadSemaphore.h %instdir%
copy IlmThreadMutex.h %instdir%
set srcdir=..\..\Include\config.windows
cd %srcdir%
copy OpenEXRConfig.h %instdir%
