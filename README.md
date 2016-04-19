## CxlCommon

CxlCommon is the set of infrastructure libraries that is used by the CodeXL and Compressionator projects, all of which are part of the GPUOpen.com initiative. CxlCommon provides general purpose classes, OS abstraction services (e.g.  file system operations, threading and process control, inter-process communication, etc.), logging, string classes, implementation of useful patterns, wrappers for OpenCL and OpenGL runtime interfaces and Qt-based GUI widgets.
CxlCommon supports Windows® 32/64-bit and Linux® 64-bit.
CxlCommon is included as a Git sub-module in the CodeXL GitHub repository. See https://github.com/GPUOpen-Tools/CodeXL

## Build

CxlCommon is best built as part of codeXL. Refer to the build instructions in the CodeXL repository at https://github.com/GPUOpen-Tools/CodeXL.

## Contributors

CxlCommon's GitHub repository (http://github.com/GPUOpen-Tools/CxlCommon) is moderated by Advanced Micro Devices, Inc. as part of the GPUOpen initiative.

AMD encourages any and all contributors to submit changes, features, and bug fixes via Git pull requests to this repository.

Users are also encouraged to submit issues and feature requests via the repository's issue tracker.

## License

CxlCommon is part of the GPUOpen.com initiative. CxlCommon source code and binaries are released under the following MIT license.

Copyright © 2016 Advanced Micro Devices, Inc. All rights reserved.

MIT LICENSE:
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Attribution and Copyrights

Component licenses can be found under the CodeXL GitHub repository source root, in the /Setup/Legal/ folder.

OpenCL is a trademark of Apple Inc. used by permission by Khronos. OpenGL is a registered trademark of Silicon Graphics, Inc. in the United States and/or other countries worldwide. Microsoft, Windows, DirectX and Visual Studio are registered trademarks of Microsoft Corporation in the United States and/or other jurisdictions. Vulkan is a registered trademark of Khronos Group Inc. in the United States and/or other jurisdictions. Linux is the registered trademark of Linus Torvalds in the United States and/or other jurisdictions.

LGPL (Copyright ©1991, 1999 Free Software Foundation, Inc.  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA). Use of the Qt library is governed by the GNU Lesser General Public License version 2.1 (LGPL v 2.1). CodeXL uses QT 5.5.1. Source code for QT is available here: http://qt-project.org/downloads. The QT source code has not been tempered with and the built binaries are identical to what any user that downloads the source code from the web and builds them will produce.

* Boost is Copyright © Beman Dawes, 2003.
* jqPlot is copyright © 2009-2011 Chris Leonello.
* glew - The OpenGL Extension Wrangler Library is Copyright © 2002-2007, Milan Ikits <milan ikits[]ieee org>, Copyright © 2002-2007, Marcelo E. Magallon <mmagallo[]debian org>, Copyright © 2002, Lev Povalahev, All rights reserved.
* lgplib is Copyright © 1994-1998, Thomas G. Lane., Copyright © 1991-2013, Thomas G. Lane, Guido Vollbeding. 
* LibDwarf (BSD) is Copyright © 2007 John Birrell (jb@freebsd.org),  Copyright © 2010 Kai Wang,  All rights reserved.
* libpng is Copyright © 1998-2014 Glenn Randers-Pehrson, (Version 0.96 Copyright © 1996, 1997 Andreas Dilger) (Version 0.88 Copyright © 1995, 1996 Guy Eric Schalnat, Group 42, Inc.).
* QScintilla is Copyright © 2005 by Riverbank Computing Limited <info@riverbankcomputing.co.uk>.
* TinyXML is released under the zlib license © 2000-2007, Lee Thomason, © 2002-2004, Yves Berquin © 2005, Tyge Lovset.
* UTF8cpp is Copyright © 2006 Nemanja Trifunovic.
* zlib is Copyright © 1995-2010 Jean-loup Gailly and Mark Adler, Copyright © 2003 Chris Anderson <christop@charm.net>, Copyright © 1998-2010 Gilles Vollant (minizip) ( http://www.winimage.com/zLibDll/minizip.html ), Copyright © 2009-2010 Mathias Svensson ( http://result42.com ), Copyright © 2007-2008 Even Rouault.
* QCustomPlot, an easy to use, modern plotting widget for Qt, Copyright (C) 2011-2015 Emanuel Eichhammer