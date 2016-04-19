//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_FILEUTILS_H
#define GDT_FILEUTILS_H

#include "GDT_Assert.h"

/// File utility functions.
namespace GDT_FileUtils
{
bool GetDirectory(const TCHAR* pszPath, TCHAR* pszDirectory, size_t nSize);
bool CreateDirectoryPath(const TCHAR* pszDirectory);
bool DirectoryExists(const TCHAR* pszDirectory);
bool FileExists(const TCHAR* pszFileName);
void SetExtension(TCHAR* pszFileName, size_t nSize, const TCHAR* pszExtension);
bool DeleteDirectory(const TCHAR* pszDirectory);
} // namespace GDT_FileUtils

#endif // SHADERDEBUGGERBUFFER_H
