//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_DX9_H
#define GDT_DX9_H

#include <boost/intrusive_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>

#include "GDT_DXGI.h"

#include "D3D9.h"

/// Namespace for smart-pointer wrappers for DirectX9.
namespace GDT_DX9
{
typedef boost::intrusive_ptr<IDirect3DBaseTexture9>         IDirect3DBaseTexture9Ptr;        ///< Smart pointer for IDirect3DBaseTexture9.
typedef boost::intrusive_ptr<IDirect3DCubeTexture9>         IDirect3DCubeTexture9Ptr;        ///< Smart pointer for IDirect3DCubeTexture9.
typedef boost::intrusive_ptr<IDirect3DDevice9>              IDirect3DDevice9Ptr;             ///< Smart pointer for IDirect3DDevice9.
typedef boost::intrusive_ptr<IDirect3DDevice9Ex>            IDirect3DDevice9ExPtr;           ///< Smart pointer for IDirect3DDevice9Ex.
typedef boost::intrusive_ptr<IDirect3DIndexBuffer9>         IDirect3DIndexBuffer9Ptr;        ///< Smart pointer for IDirect3DIndexBuffer9.
typedef boost::intrusive_ptr<IDirect3DPixelShader9>         IDirect3DPixelShader9Ptr;        ///< Smart pointer for IDirect3DPixelShader9.
typedef boost::intrusive_ptr<IDirect3DQuery9>               IDirect3DQuery9Ptr;              ///< Smart pointer for IDirect3DQuery9.
typedef boost::intrusive_ptr<IDirect3DResource9>            IDirect3DResource9Ptr;           ///< Smart pointer for IDirect3DResource9.
typedef boost::intrusive_ptr<IDirect3DStateBlock9>          IDirect3DStateBlock9Ptr;         ///< Smart pointer for IDirect3DStateBlock9.
typedef boost::intrusive_ptr<IDirect3DSurface9>             IDirect3DSurface9Ptr;            ///< Smart pointer for IDirect3DSurface9.
typedef boost::intrusive_ptr<IDirect3DSwapChain9>           IDirect3DSwapChain9Ptr;          ///< Smart pointer for IDirect3DSwapChain9.
typedef boost::intrusive_ptr<IDirect3DSwapChain9Ex>         IDirect3DSwapChain9ExPtr;        ///< Smart pointer for IDirect3DSwapChain9Ex.
typedef boost::intrusive_ptr<IDirect3DTexture9>             IDirect3DTexture9Ptr;            ///< Smart pointer for IDirect3DTexture9.
typedef boost::intrusive_ptr<IDirect3DVertexBuffer9>        IDirect3DVertexBuffer9Ptr;       ///< Smart pointer for IDirect3DVertexBuffer9.
typedef boost::intrusive_ptr<IDirect3DVertexDeclaration9>   IDirect3DVertexDeclaration9Ptr;  ///< Smart pointer for IDirect3DVertexDeclaration9.
typedef boost::intrusive_ptr<IDirect3DVertexShader9>        IDirect3DVertexShader9Ptr;       ///< Smart pointer for IDirect3DVertexShader9.
typedef boost::intrusive_ptr<IDirect3DVolume9>              IDirect3DVolume9Ptr;             ///< Smart pointer for IDirect3DVolume9.
typedef boost::intrusive_ptr<IDirect3DVolumeTexture9>       IDirect3DVolumeTexture9Ptr;      ///< Smart pointer for IDirect3DVolumeTexture9.

/// Creates a texture resource.
/// This function acts as smart pointer wrapper of IDirect3DDevice9::CreateCubeTexture.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    EdgeLength              Size of the edges of all the top-level faces of the cube texture. The pixel dimensions of subsequent levels of each face will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0 (zero), 1 will be taken instead.
/// \param[in]    Levels                  Number of levels in each face of the cube texture. If this is zero, Direct3D will generate all cube texture sublevels down to 1x1 pixels for each face for hardware that supports mipmapped cube textures. Call IDirect3DBaseTexture9::GetLevelCount to see the number of levels generated.
/// \param[in]    Usage                   Usage can be 0, which indicates no usage value. However, if usage is desired, use a combination of one or more D3DUSAGE constants. It is good practice to match the usage parameter in CreateCubeTexture with the behavior flags in IDirect3D9::CreateDevice. For more information, see Remarks.
/// \param[in]    Format                  Member of the D3DFORMAT enumerated type, describing the format of all levels in all faces of the cube texture.
/// \param[in]    Pool                    Member of the D3DPOOL enumerated type, describing the memory class into which the cube texture should be placed.
/// \param[out]   rpCubeTexture           The newly-created IDirect3DCubeTexture9Ptr object.
/// \param[in]    pSharedHandle           Reserved. Set this parameter to NULL. This parameter can be used in Direct3D 9 for Windows Vista to share resources.
/// \return                               The error code returned by IDirect3DDevice9::CreateCubeTexture.
HRESULT CreateCubeTexture(const IDirect3DDevice9Ptr& pDevice, UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9Ptr& rpCubeTexture, HANDLE* pSharedHandle);

/// Creates a texture resource.
/// This function acts as smart pointer wrapper of IDirect3DDevice9::CreateTexture.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    Width                   Width of the top-level of the texture, in pixels. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0, 1 will be taken instead.
/// \param[in]    Height                  Height of the top-level of the texture, in pixels. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0, 1 will be taken instead.
/// \param[in]    Levels                  Number of levels in the texture. If this is zero, Direct3D will generate all texture sublevels down to 1 by 1 pixels for hardware that supports mipmapped textures. Call IDirect3DBaseTexture9::GetLevelCount to see the number of levels generated.
/// \param[in]    Usage                   Usage can be 0, which indicates no usage value. However, if usage is desired, use a combination of one or more D3DUSAGE constants. It is good practice to match the usage parameter with the behavior flags in IDirect3D9::CreateDevice.
/// \param[in]    Format                  Member of the D3DFORMAT enumerated type, describing the format of all levels in the texture.
/// \param[in]    Pool                    Member of the D3DPOOL enumerated type, describing the memory class into which the texture should be placed.
/// \param[out]   rpTexture               The newly-created IDirect3DTexture9Ptr object.
/// \param[in]    pSharedHandle           Reserved. Set this parameter to NULL. This parameter can be used in Direct3D 9 for Windows Vista to share resources.
/// \return                               The error code returned by IDirect3DDevice9::CreateTexture.
HRESULT CreateTexture(const IDirect3DDevice9Ptr& pDevice, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9Ptr& rpTexture, HANDLE* pSharedHandle);

/// Creates a texture resource.
/// This function acts as smart pointer wrapper of IDirect3DDevice9::CreateTexture.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    Width                   Width of the top-level of the volume texture, in pixels. This value must be a power of two if the D3DPTEXTURECAPS_VOLUMEMAP_POW2 member of D3DCAPS9 is set. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by two results in 0 (zero), 1 will be taken instead. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in D3DCAPS9.
/// \param[in]    Height                  Height of the top-level of the volume texture, in pixels. This value must be a power of two if the D3DPTEXTURECAPS_VOLUMEMAP_POW2 member of D3DCAPS9 is set. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0 (zero), 1 will be taken instead. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in D3DCAPS9.
/// \param[in]    Depth                   Depth of the top-level of the volume texture, in pixels. This value must be a power of two if the D3DPTEXTURECAPS_VOLUMEMAP_POW2 member of D3DCAPS9 is set. The pixel dimensions of subsequent levels will be the truncated value of half of the previous level's pixel dimension (independently). Each dimension clamps at a size of 1 pixel. Thus, if the division by 2 results in 0 (zero), 1 will be taken instead. The maximum dimension that a driver supports (for width, height, and depth) can be found in MaxVolumeExtent in D3DCAPS9.
/// \param[in]    Levels                  Number of levels in the texture. If this is zero, Direct3D will generate all texture sublevels down to 1x1 pixels for hardware that supports mipmapped volume textures. Call IDirect3DBaseTexture9::GetLevelCount to see the number of levels generated.
/// \param[in]    Usage                   Usage can be 0, which indicates no usage value. If usage is desired, use D3DUSAGE_DYNAMIC or D3DUSAGE_SOFTWAREPROCESSING. For more information, see D3DUSAGE.
/// \param[in]    Format                  Member of the D3DFORMAT enumerated type, describing the format of all levels in the volume texture.
/// \param[in]    Pool                    Member of the D3DPOOL enumerated type, describing the memory class into which the volume texture should be placed.
/// \param[out]   rpVolumeTexture         The newly-created IDirect3DVolumeTexture9Ptr object.
/// \param[in]    pSharedHandle           Reserved. Set this parameter to NULL. This parameter can be used in Direct3D 9 for Windows Vista to share resources.
/// \return                               The error code returned by IDirect3DDevice9::CreateTexture.
HRESULT CreateVolumeTexture(const IDirect3DDevice9Ptr& pDevice, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9Ptr& rpVolumeTexture, HANDLE* pSharedHandle);

} // namespace GDT_DX9

#endif // GDT_DX9_H
