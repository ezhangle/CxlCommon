//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#include <Windows.h>
#include <D3D9.h>
#include "GDT_DX9.h"

using namespace GDT_DX9;


HRESULT GDT_DX9::CreateCubeTexture(const IDirect3DDevice9Ptr& pDevice, UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9Ptr& rpCubeTexture, HANDLE* pSharedHandle)
{
    IDirect3DCubeTexture9* pCubeTexture;
    HRESULT hr = pDevice->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, &pCubeTexture, pSharedHandle);
    rpCubeTexture = GDT_DX9::IDirect3DCubeTexture9Ptr(pCubeTexture, false);
    return hr;
}

HRESULT GDT_DX9::CreateTexture(const IDirect3DDevice9Ptr& pDevice, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9Ptr& rpTexture, HANDLE* pSharedHandle)
{
    IDirect3DTexture9* pTexture;
    HRESULT hr = pDevice->CreateTexture(Width, Height, Levels, Usage, Format, Pool, &pTexture, pSharedHandle);
    rpTexture = GDT_DX9::IDirect3DTexture9Ptr(pTexture, false);
    return hr;
}

HRESULT CreateVolumeTexture(const IDirect3DDevice9Ptr& pDevice, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9Ptr& rpVolumeTexture, HANDLE* pSharedHandle)
{
    IDirect3DVolumeTexture9* pVolumeTexture;
    HRESULT hr = pDevice->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, &pVolumeTexture, pSharedHandle);
    rpVolumeTexture = GDT_DX9::IDirect3DVolumeTexture9Ptr(pVolumeTexture, false);
    return hr;
}
