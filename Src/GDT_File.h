//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_FILE_H
#define GDT_FILE_H

#include <boost/shared_ptr.hpp>
#include <tchar.h>

#include "GDT_Assert.h"

/// Smart pointer support for standard C file handling.
namespace GDT_File
{
/// Smart pointer version of FILE.
typedef boost::shared_ptr<FILE> File;

inline File file_open(TCHAR const* pszFileName, TCHAR const* pszMode)
{
    _GDT_Assert(pszFileName != NULL);
    _GDT_Assert(pszMode != NULL);

    FILE* pFile = NULL;
    _tfopen_s(&pFile, pszFileName, pszMode);

    _GDT_Assert(pFile != NULL);

    return File(pFile, fclose);
}

inline int file_close(File& pFile)
{
    _GDT_Assert(pFile != NULL);
    pFile.reset();
    return 0;
}

inline int file_seek(File const& pFile, long lOffset, int nOrigin)
{
    _GDT_Assert(pFile != NULL);
    return fseek(pFile.get(), lOffset, nOrigin);
}

inline long file_tell(File const& pFile)
{
    _GDT_Assert(pFile != NULL);
    return ftell(pFile.get());
}

inline size_t file_read(void* pDstBuf, size_t nElementSize, size_t nCount, File const& pFile)
{
    _GDT_Assert(pFile != NULL);
    return fread(pDstBuf, nElementSize, nCount, pFile.get());
}

inline size_t file_read_s(void* pDstBuf, size_t nDstSize, size_t nElementSize, size_t nCount, File const& pFile)
{
    _GDT_Assert(pFile != NULL);
    return fread_s(pDstBuf, nDstSize, nElementSize, nCount, pFile.get());
}

inline size_t file_write(const void* pSrcBuf, size_t nSize, size_t nCount, File const& pFile)
{
    _GDT_Assert(pFile != NULL);
    return fwrite(pSrcBuf, nSize, nCount, pFile.get());
}

} // namespace GDT_File

#endif // SHADERDEBUGGERBUFFER_H
