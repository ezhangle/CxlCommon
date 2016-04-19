// GDT_FileUtils.cpp : Utility functions for file & directory processing
//

#include <Windows.h>
#include <shellapi.h>
#include <tchar.h>
#include <stdio.h>
#include "ShObjIdl.h"
#include "GDT_FileUtils.h"

using namespace GDT_FileUtils;

bool GDT_FileUtils::GetDirectory(const TCHAR* pszPath, TCHAR* pszDirectory, size_t nSize)
{
    if (pszPath == NULL || pszDirectory == NULL)
    {
        return false;
    }

    const TCHAR* pszSubDirectory = _tcsrchr(pszPath, '\\');

    if (pszSubDirectory == NULL)
    {
        pszSubDirectory = _tcsrchr(pszPath, '/');
    }

    if (pszSubDirectory)
    {
        DWORD_PTR dwChars = (pszSubDirectory - pszPath);

        if (dwChars > 2 && dwChars < nSize)
        {
            _tcsncpy_s(pszDirectory, nSize, pszPath, dwChars);
            pszDirectory[dwChars] = '\0';
            return true;
        }
    }

    pszDirectory[0] = '\0';
    return false;
}

bool GDT_FileUtils::CreateDirectoryPath(const TCHAR* pszDirectory)
{
    TCHAR szSubDirectory[_MAX_PATH];

    if (GetDirectory(pszDirectory, szSubDirectory, _MAX_PATH))
    {
        CreateDirectoryPath(szSubDirectory);
    }

    if (CreateDirectory(pszDirectory, NULL))
    {
        return true;
    }
    else if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GDT_FileUtils::DirectoryExists(const TCHAR* pszDirectory)
{
    if (pszDirectory == NULL || *pszDirectory == '\0')
    {
        return false;
    }

    SHFILEINFO shFileInfo;

    if (SHGetFileInfo(pszDirectory, 0, &shFileInfo, sizeof(shFileInfo), SHGFI_ATTRIBUTES))
        if (shFileInfo.dwAttributes & SFGAO_FOLDER)
        {
            return true;
        }

    return false;
}

bool GDT_FileUtils::FileExists(const TCHAR* pszFileName)
{
    return (GetFileAttributes(pszFileName) != INVALID_FILE_ATTRIBUTES);
}

void GDT_FileUtils::SetExtension(TCHAR* pszFileName, size_t nSize, const TCHAR* pszExtension)
{
    if (pszFileName)
    {
        TCHAR* pszDot = _tcsrchr(pszFileName, '.');

        if (pszDot)
        {
            *pszDot = '\0';
        }

        _tcsncat_s(pszFileName, nSize, _T("."), _TRUNCATE);
        _tcsncat_s(pszFileName, nSize, pszExtension, _TRUNCATE);
    }
}

bool GDT_FileUtils::DeleteDirectory(const TCHAR* pszDirectory)
{
    HANDLE hFile;
    WIN32_FIND_DATA FindFileData;

    TCHAR szSearchPath[MAX_PATH];
    TCHAR szFileName[MAX_PATH];
    _sntprintf_s(szSearchPath, MAX_PATH, _TRUNCATE, _T("%s\\*.*"), pszDirectory);

    if ((hFile = FindFirstFile(szSearchPath, &FindFileData)) != INVALID_HANDLE_VALUE)
    {
        do
        {
            _sntprintf_s(szFileName, MAX_PATH, _TRUNCATE, _T("%s\\%s"), pszDirectory, FindFileData.cFileName);

            if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (strncmp(FindFileData.cFileName, ".", 1) != 0)
                {
                    DeleteDirectory(szFileName);
                }
            }
            else
            {
                DeleteFile(szFileName);
            }
        }
        while (FindNextFile(hFile, &FindFileData));

        FindClose(hFile);
    }

    return RemoveDirectory(pszDirectory) ? true : false;
}
