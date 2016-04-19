//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_DX10_H
#define GDT_DX10_H

#include <boost/intrusive_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>

#include "GDT_DXGI.h"

#include "D3D10.h"

/// Namespace for smart-pointer wrappers for DirectX10.
namespace GDT_DX10
{
typedef boost::intrusive_ptr<ID3D10Asynchronous>         ID3D10AsynchronousPtr;        ///< Smart pointer for ID3D10Asynchronous.
typedef boost::intrusive_ptr<ID3D10BlendState>           ID3D10BlendStatePtr;          ///< Smart pointer for ID3D10BlendState.
typedef boost::intrusive_ptr<ID3D10Buffer>               ID3D10BufferPtr;              ///< Smart pointer for ID3D10Buffer.
typedef boost::intrusive_ptr<ID3D10Counter>              ID3D10CounterPtr;             ///< Smart pointer for ID3D10Counter.
typedef boost::intrusive_ptr<ID3D10DepthStencilState>    ID3D10DepthStencilStatePtr;   ///< Smart pointer for ID3D10DepthStencilState.
typedef boost::intrusive_ptr<ID3D10DepthStencilView>     ID3D10DepthStencilViewPtr;    ///< Smart pointer for ID3D10DepthStencilView.
typedef boost::intrusive_ptr<ID3D10Device>               ID3D10DevicePtr;              ///< Smart pointer for ID3D10Device.
typedef boost::intrusive_ptr<ID3D10DeviceChild>          ID3D10DeviceChildPtr;         ///< Smart pointer for ID3D10DeviceChild.
typedef boost::intrusive_ptr<ID3D10GeometryShader>       ID3D10GeometryShaderPtr;      ///< Smart pointer for ID3D10GeometryShader.
typedef boost::intrusive_ptr<ID3D10InputLayout>          ID3D10InputLayoutPtr;         ///< Smart pointer for ID3D10InputLayout.
typedef boost::intrusive_ptr<ID3D10PixelShader>          ID3D10PixelShaderPtr;         ///< Smart pointer for ID3D10PixelShader.
typedef boost::intrusive_ptr<ID3D10Predicate>            ID3D10PredicatePtr;           ///< Smart pointer for ID3D10Predicate.
typedef boost::intrusive_ptr<ID3D10Query>                ID3D10QueryPtr;               ///< Smart pointer for ID3D10Query.
typedef boost::intrusive_ptr<ID3D10RasterizerState>      ID3D10RasterizerStatePtr;     ///< Smart pointer for ID3D10RasterizerState.
typedef boost::intrusive_ptr<ID3D10RenderTargetView>     ID3D10RenderTargetViewPtr;    ///< Smart pointer for ID3D10RenderTargetView.
typedef boost::intrusive_ptr<ID3D10Resource>             ID3D10ResourcePtr;            ///< Smart pointer for ID3D10Resource.
typedef boost::intrusive_ptr<ID3D10SamplerState>         ID3D10SamplerStatePtr;        ///< Smart pointer for ID3D10SamplerState.
typedef boost::intrusive_ptr<ID3D10ShaderResourceView>   ID3D10ShaderResourceViewPtr;  ///< Smart pointer for ID3D10ShaderResourceView.
typedef boost::intrusive_ptr<ID3D10Texture1D>            ID3D10Texture1DPtr;           ///< Smart pointer for ID3D10Texture1D.
typedef boost::intrusive_ptr<ID3D10Texture2D>            ID3D10Texture2DPtr;           ///< Smart pointer for ID3D10Texture2D.
typedef boost::intrusive_ptr<ID3D10Texture3D>            ID3D10Texture3DPtr;           ///< Smart pointer for ID3D10Texture3D.
typedef boost::intrusive_ptr<ID3D10VertexShader>         ID3D10VertexShaderPtr;        ///< Smart pointer for ID3D10VertexShader.
typedef boost::intrusive_ptr<ID3D10View>                 ID3D10ViewPtr;                ///< Smart pointer for ID3D10View.

/// Create a blend-state object that encapsulates blend state for the output-merger stage.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateBlendState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a blend-state description.
/// \param[out]   rpBlendState            The newly-created ID3D10BlendState object.
/// \return                               The error code returned by ID3D10Device::CreateBlendState.
HRESULT CreateBlendState(const ID3D10DevicePtr& pDevice, const D3D10_BLEND_DESC* pDesc, ID3D10BlendStatePtr& rpBlendState);

/// Create a buffer (vertex buffer, index buffer, or shader-constant buffer).
/// This function acts as smart pointer wrapper of ID3D10Device::CreateBuffer.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a buffer description.
/// \param[in]    pInitialData            Pointer to the initialization data (see D3D10_SUBRESOURCE_DATA); use NULL to allocate space only (with the exception that it cannot be NULL if the usage flag is D3D10_USAGE_IMMUTABLE).
/// \param[out]   rpBuffer                The newly-created ID3D10BufferPtr object.
/// \return                               The error code returned by ID3D10Device::CreateBuffer.
HRESULT CreateBuffer(const ID3D10DevicePtr& pDevice, const D3D10_BUFFER_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10BufferPtr& rpBuffer);

/// Create a counter object for measuring GPU performance.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateCounter.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a buffer description.
/// \param[out]   rpCounter               The newly-created ID3D10CounterPtr object.
/// \return                               The error code returned by ID3D10Device::CreateCounter.
HRESULT CreateCounter(const ID3D10DevicePtr& pDevice, const D3D10_COUNTER_DESC* pDesc, ID3D10CounterPtr& rpCounter);

/// Create a depth-stencil state object that encapsulates depth-stencil test information for the output-merger stage.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateDepthStencilState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a blend-state description.
/// \param[out]   rpDepthStencilState     The newly-created ID3D10DepthStencilStatePtr object.
/// \return                               The error code returned by ID3D10Device::CreateDepthStencilState.
HRESULT CreateDepthStencilState(const ID3D10DevicePtr& pDevice, const D3D10_DEPTH_STENCIL_DESC* pDesc, ID3D10DepthStencilStatePtr& rpDepthStencilState);

/// Create a depth-stencil view for accessing resource data.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateDepthStencilView.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pResource               Pointer to the resource that will serve as the depth-stencil surface. This resource must have been created with the D3D10_BIND_DEPTH_STENCIL flag.
/// \param[in]    pDesc                   Pointer to a depth-stencil-view description (see D3D10_DEPTH_STENCIL_VIEW_DESC). Set this parameter to NULL to create a view that accesses mipmap level 0 of the entire resource (using the format the resource was created with).
/// \param[out]   rpDepthStencilView      The newly-created ID3D10DepthStencilViewPtr object.
/// \return                               The error code returned by ID3D10Device::CreateDepthStencilView.
HRESULT CreateDepthStencilView(const ID3D10DevicePtr& pDevice, ID3D10Resource* pResource, const D3D10_DEPTH_STENCIL_VIEW_DESC* pDesc, ID3D10DepthStencilViewPtr& rpDepthStencilView);

/// Create an ID3D10GeometryShader object.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateGeometryShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[out]   rpGeometryShader        The newly-created ID3D10GeometryShaderPtr object.
/// \return                               The error code returned by ID3D10Device::CreateGeometryShader.
HRESULT CreateGeometryShader(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D10GeometryShaderPtr& rpGeometryShader);

/// Create an ID3D10GeometryShader object with stream output.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateGeometryShaderWithStreamOutput.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pSODeclaration          Pointer to a D3D10_SO_DECLARATION_ENTRY array. Cannot be NULL if NumEntries > 0.
/// \param[in]    NumEntries              The number of entries in the stream output declaration ( ranges from 0 to D3D10_SO_STREAM_COUNT * D3D10_SO_OUTPUT_COMPONENT_COUNT ).
/// \param[in]    OutputStreamStride      The size, in bytes, of each element in the array pointed to by pSODeclaration. This parameter is only used when the output slot is 0 for all entries in pSODeclaration.
/// \param[out]   rpGeometryShader        The newly-created ID3D10GeometryShaderPtr object.
/// \return                               The error code returned by ID3D10Device::CreateGeometryShader.
HRESULT CreateGeometryShaderWithStreamOutput(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, const D3D10_SO_DECLARATION_ENTRY* pSODeclaration, UINT NumEntries, UINT OutputStreamStride, ID3D10GeometryShaderPtr& rpGeometryShader);

/// Create an input-layout object to describe the input-buffer data for the input-assembler stage.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateInputLayout.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pInputElementDescs      An array of the input-assembler stage input data types; each type is described by an element description.
/// \param[in]    NumElements             The number of input-data types in the array of input-elements.
/// \param[in]    pShaderWithInputSig     A pointer to the compiled shader. The compiled shader code contains a input signature which is validated against the array of elements.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[out]   rpInputLayout           The newly-created ID3D10InputLayoutPtr object.
/// \return                               The error code returned by ID3D10Device::CreateInputLayout.
HRESULT CreateInputLayout(const ID3D10DevicePtr& pDevice, const D3D10_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderWithInputSig, SIZE_T BytecodeLength, ID3D10InputLayoutPtr& rpInputLayout);

/// Create an ID3D10PixelShader object.
/// This function acts as smart pointer wrapper of ID3D10Device::CreatePixelShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[out]   rpPixelShader           The newly-created ID3D10PixelShaderPtr object.
/// \return                               The error code returned by ID3D10Device::CreatePixelShader.
HRESULT CreatePixelShader(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D10PixelShaderPtr& rpPixelShader);

/// Creates a predicate.
/// This function acts as smart pointer wrapper of ID3D10Device::CreatePredicate.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a query description where the type of query must be a D3D10_QUERY_SO_OVERFLOW_PREDICATE or D3D10_QUERY_OCCLUSION_PREDICATE.
/// \param[out]   rpPredicate             The newly-created ID3D10PredicatePtr object.
/// \return                               The error code returned by ID3D10Device::CreatePredicate.
HRESULT CreatePredicate(const ID3D10DevicePtr& pDevice, const D3D10_QUERY_DESC* pDesc, ID3D10PredicatePtr& rpPredicate);

/// This interface encapsulates methods for querying information from the GPU.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateQuery.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a query description.
/// \param[out]   rpQuery                 The newly-created ID3D10QueryPtr object.
/// \return                               The error code returned by ID3D10Device::CreateQuery.
HRESULT CreateQuery(const ID3D10DevicePtr& pDevice, const D3D10_QUERY_DESC* pDesc, ID3D10QueryPtr& rpQuery);

/// Create a rasterizer state object that tells the rasterizer stage how to behave.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateRasterizerState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a rasterizer state description.
/// \param[out]   rpRasterizerState       The newly-created ID3D10RasterizerStatePtr object.
/// \return                               The error code returned by ID3D10Device::CreateRasterizerState.
HRESULT CreateRasterizerState(const ID3D10DevicePtr& pDevice, const D3D10_RASTERIZER_DESC* pDesc, ID3D10RasterizerStatePtr& rpRasterizerState);

/// Create a render-target view for accessing resource data.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateRenderTargetView.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pResource               Pointer to a ID3D10Resource which represents a render target. This resource must have been created with the D3D10_BIND_RENDER_TARGET flag.
/// \param[in]    pDesc                   Pointer to a D3D10_RENDER_TARGET_VIEW_DESC which represents a render-target-view description. Set this parameter to NULL to create a view that accesses all of the subresources in mipmap level 0.
/// \param[out]   rpRenderTargetView      The newly-created ID3D10RenderTargetViewPtr object.
/// \return                               The error code returned by ID3D10Device::CreateRenderTargetView.
HRESULT CreateRenderTargetView(const ID3D10DevicePtr& pDevice, ID3D10Resource* pResource, const D3D10_RENDER_TARGET_VIEW_DESC* pDesc, ID3D10RenderTargetViewPtr& rpRenderTargetView);

/// Create a sampler-state object that encapsulates sampling information for a texture.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateSamplerState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a sampler state description.
/// \param[out]   rpSamplerState          The newly-created ID3D10SamplerStatePtr object.
/// \return                               The error code returned by ID3D10Device::CreateSamplerState.
HRESULT CreateSamplerState(const ID3D10DevicePtr& pDevice, const D3D10_SAMPLER_DESC* pDesc, ID3D10SamplerStatePtr& rpSamplerState);

/// Create a render-target view for accessing resource data.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateShaderResourceView.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pResource               Pointer to the resource that will serve as input to a shader. This resource must have been created with the D3D10_BIND_SHADER_RESOURCE flag.
/// \param[in]    pDesc                   Pointer to a shader-resource-view description (see D3D10_SHADER_RESOURCE_VIEW_DESC). Set this parameter to NULL to create a view that accesses the entire resource (using the format the resource was created with).
/// \param[out]   rpShaderResourceView    The newly-created ID3D10ShaderResourceViewPtr object.
/// \return                               The error code returned by ID3D10Device::CreateShaderResourceView.
HRESULT CreateShaderResourceView(const ID3D10DevicePtr& pDevice, ID3D10Resource* pResource, const D3D10_SHADER_RESOURCE_VIEW_DESC* pDesc, ID3D10ShaderResourceViewPtr& rpShaderResourceView);

/// Create an array of 1D textures.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateTexture1D.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a 1D texture description (see D3D10_TEXTURE1D_DESC). To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.
/// \param[in]    pInitialData            Pointer to an array of subresource descriptions (see D3D10_SUBRESOURCE_DATA); one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see D3D10_USAGE). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.
/// \param[out]   rpTexture1D             The newly-created ID3D10Texture1DPtr object.
/// \return                               The error code returned by ID3D10Device::CreateTexture1D.
HRESULT CreateTexture1D(const ID3D10DevicePtr& pDevice, const D3D10_TEXTURE1D_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10Texture1DPtr& rpTexture1D);

/// Create an array of 2D textures.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateTexture2D.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a 2D texture description (see D3D10_TEXTURE2D_DESC). To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.
/// \param[in]    pInitialData            Pointer to an array of subresource descriptions (see D3D10_SUBRESOURCE_DATA); one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see D3D10_USAGE). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.
/// \param[out]   rpTexture2D             The newly-created ID3D10Texture2DPtr object.
/// \return                               The error code returned by ID3D10Device::CreateTexture2D.
HRESULT CreateTexture2D(const ID3D10DevicePtr& pDevice, const D3D10_TEXTURE2D_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10Texture2DPtr& rpTexture2D);

/// Create a single 3D texture.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateTexture3D.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a 3D texture description (see D3D10_TEXTURE3D_DESC). To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.
/// \param[in]    pInitialData            Pointer to an array of subresource descriptions (see D3D10_SUBRESOURCE_DATA); one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see D3D10_USAGE). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.
/// \param[out]   rpTexture3D             The newly-created ID3D10Texture3DPtr object.
/// \return                               The error code returned by ID3D10Device::CreateTexture3D.
HRESULT CreateTexture3D(const ID3D10DevicePtr& pDevice, const D3D10_TEXTURE3D_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10Texture3DPtr& rpTexture3D);

/// Create an ID3D10VertexShader object.
/// This function acts as smart pointer wrapper of ID3D10Device::CreateVertexShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[out]   rpVertexShader          The newly-created ID3D10VertexShaderPtr object.
/// \return                               The error code returned by ID3D10Device::CreateVertexShader.
HRESULT CreateVertexShader(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D10VertexShaderPtr& rpVertexShader);

/// Attach a name to a resource.
/// This name can be used by the D3D debug runtime & other tools to report the name of the resource.
/// \param[in]    pResource               A pointer to the resource.
/// \param[in]    strName                 The resource name string. Pass an empty string to remove the resource name.
/// \return                               True if successful, otherwise false.
bool SetResourceName(const ID3D10DeviceChildPtr& pResource, const std::string& strName);

/// Retrieve a resource's name.
/// This name can be used by the D3D debug runtime & other tools to report the name of the resource.
/// \param[in]    pResource               A pointer to the resource.
/// \param[in]    strName                 The resource name string.
/// \return                               True if successful, otherwise false.
bool GetResourceName(const ID3D10DeviceChildPtr& pResource, std::string& strName);
} // namespace GDT_DX10

#endif // GDT_DX10_H
