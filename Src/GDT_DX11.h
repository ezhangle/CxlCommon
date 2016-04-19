//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_DX11_H
#define GDT_DX11_H

#include <boost/intrusive_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>
#include <tchar.h>
#include "GDT_DXGI.h"
#include "D3D11.h"

/// Namespace for smart-pointer wrappers for DirectX11.
namespace GDT_DX11
{
typedef boost::intrusive_ptr<ID3D11Asynchronous>         ID3D11AsynchronousPtr;        ///< Smart pointer for ID3D11Asynchronous.
typedef boost::intrusive_ptr<ID3D11BlendState>           ID3D11BlendStatePtr;          ///< Smart pointer for ID3D11BlendState.
typedef boost::intrusive_ptr<ID3D11Buffer>               ID3D11BufferPtr;              ///< Smart pointer for ID3D11Buffer.
typedef boost::intrusive_ptr<ID3D11ClassInstance>        ID3D11ClassInstancePtr;       ///< Smart pointer for ID3D11ClassInstance.
typedef boost::intrusive_ptr<ID3D11ClassLinkage>         ID3D11ClassLinkagePtr;        ///< Smart pointer for ID3D11ClassLinkage.
typedef boost::intrusive_ptr<ID3D11CommandList>          ID3D11CommandListPtr;         ///< Smart pointer for ID3D11CommandList.
typedef boost::intrusive_ptr<ID3D11ComputeShader>        ID3D11ComputeShaderPtr;       ///< Smart pointer for ID3D11ComputeShader.
typedef boost::intrusive_ptr<ID3D11Counter>              ID3D11CounterPtr;             ///< Smart pointer for ID3D11Counter.
typedef boost::intrusive_ptr<ID3D11DepthStencilState>    ID3D11DepthStencilStatePtr;   ///< Smart pointer for ID3D11DepthStencilState.
typedef boost::intrusive_ptr<ID3D11DepthStencilView>     ID3D11DepthStencilViewPtr;    ///< Smart pointer for ID3D11DepthStencilView.
typedef boost::intrusive_ptr<ID3D11Device>               ID3D11DevicePtr;              ///< Smart pointer for ID3D11Device.
typedef boost::intrusive_ptr<ID3D11DeviceChild>          ID3D11DeviceChildPtr;         ///< Smart pointer for ID3D11DeviceChild.
typedef boost::intrusive_ptr<ID3D11DeviceContext>        ID3D11DeviceContextPtr;       ///< Smart pointer for ID3D11DeviceContext.
typedef boost::intrusive_ptr<ID3D11DomainShader>         ID3D11DomainShaderPtr;        ///< Smart pointer for ID3D11DomainShader.
typedef boost::intrusive_ptr<ID3D11GeometryShader>       ID3D11GeometryShaderPtr;      ///< Smart pointer for ID3D11GeometryShader.
typedef boost::intrusive_ptr<ID3D11InputLayout>          ID3D11InputLayoutPtr;         ///< Smart pointer for ID3D11InputLayout.
typedef boost::intrusive_ptr<ID3D11HullShader>           ID3D11HullShaderPtr;          ///< Smart pointer for ID3D11HullShader.
typedef boost::intrusive_ptr<ID3D11PixelShader>          ID3D11PixelShaderPtr;         ///< Smart pointer for ID3D11PixelShader.
typedef boost::intrusive_ptr<ID3D11Predicate>            ID3D11PredicatePtr;           ///< Smart pointer for ID3D11Predicate.
typedef boost::intrusive_ptr<ID3D11Query>                ID3D11QueryPtr;               ///< Smart pointer for ID3D11Query.
typedef boost::intrusive_ptr<ID3D11RasterizerState>      ID3D11RasterizerStatePtr;     ///< Smart pointer for ID3D11RasterizerState.
typedef boost::intrusive_ptr<ID3D11RenderTargetView>     ID3D11RenderTargetViewPtr;    ///< Smart pointer for ID3D11RenderTargetView.
typedef boost::intrusive_ptr<ID3D11Resource>             ID3D11ResourcePtr;            ///< Smart pointer for ID3D11Resource.
typedef boost::intrusive_ptr<ID3D11SamplerState>         ID3D11SamplerStatePtr;        ///< Smart pointer for ID3D11SamplerState.
typedef boost::intrusive_ptr<ID3D11ShaderResourceView>   ID3D11ShaderResourceViewPtr;  ///< Smart pointer for ID3D11ShaderResourceView.
typedef boost::intrusive_ptr<ID3D11Texture1D>            ID3D11Texture1DPtr;           ///< Smart pointer for ID3D11Texture1D.
typedef boost::intrusive_ptr<ID3D11Texture2D>            ID3D11Texture2DPtr;           ///< Smart pointer for ID3D11Texture2D.
typedef boost::intrusive_ptr<ID3D11Texture3D>            ID3D11Texture3DPtr;           ///< Smart pointer for ID3D11Texture3D.
typedef boost::intrusive_ptr<ID3D11UnorderedAccessView>  ID3D11UnorderedAccessViewPtr; ///< Smart pointer for ID3D11UnorderedAccessView.
typedef boost::intrusive_ptr<ID3D11VertexShader>         ID3D11VertexShaderPtr;        ///< Smart pointer for ID3D11VertexShader.
typedef boost::intrusive_ptr<ID3D11View>                 ID3D11ViewPtr;                ///< Smart pointer for ID3D11View.

/// Create a blend-state object that encapsulates blend state for the output-merger stage.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateBlendState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a blend-state description.
/// \param[out]   rpBlendState            The newly-created ID3D11BlendState object.
/// \return                               The error code returned by ID3D11Device::CreateBlendState.
HRESULT CreateBlendState(const ID3D11DevicePtr& pDevice, const D3D11_BLEND_DESC* pDesc, ID3D11BlendStatePtr& rpBlendState);

/// Create a buffer (vertex buffer, index buffer, or shader-constant buffer).
/// This function acts as smart pointer wrapper of ID3D11Device::CreateBuffer.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a buffer description.
/// \param[in]    pInitialData            Pointer to the initialization data (see D3D11_SUBRESOURCE_DATA); use NULL to allocate space only (with the exception that it cannot be NULL if the usage flag is D3D11_USAGE_IMMUTABLE).
/// \param[out]   rpBuffer                The newly-created ID3D11BufferPtr object.
/// \return                               The error code returned by ID3D11Device::CreateBuffer.
HRESULT CreateBuffer(const ID3D11DevicePtr& pDevice, const D3D11_BUFFER_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11BufferPtr& rpBuffer);

/// Creates class linkage libraries to enable dynamic shader linkage.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateClassLinkage.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[out]   rpClassLinkage          The newly-created ID3D11ClassLinkagePtr object.
/// \return                               The error code returned by ID3D11Device::CreateClassLinkage.
HRESULT CreateClassLinkage(const ID3D11DevicePtr& pDevice, ID3D11ClassLinkagePtr& rpClassLinkage);

/// Create an ID3D11ComputeShader object.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateComputeShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pClassLinkage           A pointer to a class linkage interface (see ID3D11ClassLinkage); the value can be NULL.
/// \param[out]   rpComputeShader         The newly-created ID3D11ComputeShaderPtr object.
/// \return                               The error code returned by ID3D11Device::CreateComputeShader.
HRESULT CreateComputeShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11ComputeShaderPtr& rpComputeShader);

/// Create a counter object for measuring GPU performance.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateCounter.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a buffer description.
/// \param[out]   rpCounter               The newly-created ID3D11CounterPtr object.
/// \return                               The error code returned by ID3D11Device::CreateCounter.
HRESULT CreateCounter(const ID3D11DevicePtr& pDevice, const D3D11_COUNTER_DESC* pDesc, ID3D11CounterPtr& rpCounter);

/// Creates a deferred context for play back of command lists.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateDeferredContext.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    ContextFlags            Reserved for future use. Pass 0.
/// \param[out]   rpDeferredContext       The newly-created ID3D11DeviceContextPtr object.
/// \return                               The error code returned by ID3D11Device::CreateDeferredContext.
HRESULT CreateDeferredContext(const ID3D11DevicePtr& pDevice, const UINT ContextFlags, ID3D11DeviceContextPtr& rpDeferredContext);

/// Create a depth-stencil state object that encapsulates depth-stencil test information for the output-merger stage.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateDepthStencilState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a blend-state description.
/// \param[out]   rpDepthStencilState     The newly-created ID3D11DepthStencilStatePtr object.
/// \return                               The error code returned by ID3D11Device::CreateDepthStencilState.
HRESULT CreateDepthStencilState(const ID3D11DevicePtr& pDevice, const D3D11_DEPTH_STENCIL_DESC* pDesc, ID3D11DepthStencilStatePtr& rpDepthStencilState);

/// Create a depth-stencil view for accessing resource data.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateDepthStencilView.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pResource               Pointer to the resource that will serve as the depth-stencil surface. This resource must have been created with the D3D11_BIND_DEPTH_STENCIL flag.
/// \param[in]    pDesc                   Pointer to a depth-stencil-view description (see D3D11_DEPTH_STENCIL_VIEW_DESC). Set this parameter to NULL to create a view that accesses mipmap level 0 of the entire resource (using the format the resource was created with).
/// \param[out]   rpDepthStencilView      The newly-created ID3D11DepthStencilViewPtr object.
/// \return                               The error code returned by ID3D11Device::CreateDepthStencilView.
HRESULT CreateDepthStencilView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc, ID3D11DepthStencilViewPtr& rpDepthStencilView);

/// Create an ID3D11DomainShader object.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateDomainShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pClassLinkage           A pointer to a class linkage interface (see ID3D11ClassLinkage); the value can be NULL.
/// \param[out]   rpDomainShader          The newly-created ID3D11DomainShaderPtr object.
/// \return                               The error code returned by ID3D11Device::CreateDomainShader.
HRESULT CreateDomainShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11DomainShaderPtr& rpDomainShader);

/// Create an ID3D11GeometryShader object.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateGeometryShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pClassLinkage           A pointer to a class linkage interface (see ID3D11ClassLinkage); the value can be NULL.
/// \param[out]   rpGeometryShader        The newly-created ID3D11GeometryShaderPtr object.
/// \return                               The error code returned by ID3D11Device::CreateGeometryShader.
HRESULT CreateGeometryShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11GeometryShaderPtr& rpGeometryShader);

/// Create an ID3D11GeometryShader object with stream output.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateGeometryShaderWithStreamOutput.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pSODeclaration          Pointer to a D3D11_SO_DECLARATION_ENTRY array. Cannot be NULL if NumEntries > 0.
/// \param[in]    NumEntries              The number of entries in the stream output declaration ( ranges from 0 to D3D11_SO_STREAM_COUNT * D3D11_SO_OUTPUT_COMPONENT_COUNT ).
/// \param[in]    pBufferStrides          An array of buffer strides; each stride is the size of an element for that buffer.
/// \param[in]    NumStrides              The number of strides (or buffers) in pBufferStrides (ranges from 0 to D3D11_SO_BUFFER_SLOT_COUNT).
/// \param[in]    RasterizedStream        The index number of the stream to be sent to the rasterizer stage (ranges from 0 to D3D11_SO_STREAM_COUNT - 1). Set to D3D11_SO_NO_RASTERIZED_STREAM if no stream is to be rasterized.
/// \param[in]    pClassLinkage           A pointer to a class linkage interface (see ID3D11ClassLinkage); the value can be NULL.
/// \param[out]   rpGeometryShader        The newly-created ID3D11GeometryShaderPtr object.
/// \return                               The error code returned by ID3D11Device::CreateGeometryShader.
HRESULT CreateGeometryShaderWithStreamOutput(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, const D3D11_SO_DECLARATION_ENTRY* pSODeclaration, UINT NumEntries, const UINT* pBufferStrides, UINT NumStrides, UINT RasterizedStream, ID3D11ClassLinkage* pClassLinkage, ID3D11GeometryShaderPtr& rpGeometryShader);

/// Create an ID3D11HullShader object.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateHullShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pClassLinkage           A pointer to a class linkage interface (see ID3D11ClassLinkage); the value can be NULL.
/// \param[out]   rpHullShader            The newly-created ID3D11HullShaderPtr object.
/// \return                               The error code returned by ID3D11Device::CreateHullShader.
HRESULT CreateHullShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11HullShaderPtr& rpHullShader);

/// Create an input-layout object to describe the input-buffer data for the input-assembler stage.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateInputLayout.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pInputElementDescs      An array of the input-assembler stage input data types; each type is described by an element description.
/// \param[in]    NumElements             The number of input-data types in the array of input-elements.
/// \param[in]    pShaderWithInputSig     A pointer to the compiled shader. The compiled shader code contains a input signature which is validated against the array of elements.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[out]   rpInputLayout           The newly-created ID3D11InputLayoutPtr object.
/// \return                               The error code returned by ID3D11Device::CreateInputLayout.
HRESULT CreateInputLayout(const ID3D11DevicePtr& pDevice, const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderWithInputSig, SIZE_T BytecodeLength, ID3D11InputLayoutPtr& rpInputLayout);

/// Create an ID3D11PixelShader object.
/// This function acts as smart pointer wrapper of ID3D11Device::CreatePixelShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pClassLinkage           A pointer to a class linkage interface (see ID3D11ClassLinkage); the value can be NULL.
/// \param[out]   rpPixelShader           The newly-created ID3D11PixelShaderPtr object.
/// \return                               The error code returned by ID3D11Device::CreatePixelShader.
HRESULT CreatePixelShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11PixelShaderPtr& rpPixelShader);

/// Creates a predicate.
/// This function acts as smart pointer wrapper of ID3D11Device::CreatePredicate.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a query description where the type of query must be a D3D11_QUERY_SO_OVERFLOW_PREDICATE or D3D11_QUERY_OCCLUSION_PREDICATE.
/// \param[out]   rpPredicate             The newly-created ID3D11PredicatePtr object.
/// \return                               The error code returned by ID3D11Device::CreatePredicate.
HRESULT CreatePredicate(const ID3D11DevicePtr& pDevice, const D3D11_QUERY_DESC* pDesc, ID3D11PredicatePtr& rpPredicate);

/// This interface encapsulates methods for querying information from the GPU.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateQuery.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a query description.
/// \param[out]   rpQuery                 The newly-created ID3D11QueryPtr object.
/// \return                               The error code returned by ID3D11Device::CreateQuery.
HRESULT CreateQuery(const ID3D11DevicePtr& pDevice, const D3D11_QUERY_DESC* pDesc, ID3D11QueryPtr& rpQuery);

/// Create a rasterizer state object that tells the rasterizer stage how to behave.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateRasterizerState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a rasterizer state description.
/// \param[out]   rpRasterizerState       The newly-created ID3D11RasterizerStatePtr object.
/// \return                               The error code returned by ID3D11Device::CreateRasterizerState.
HRESULT CreateRasterizerState(const ID3D11DevicePtr& pDevice, const D3D11_RASTERIZER_DESC* pDesc, ID3D11RasterizerStatePtr& rpRasterizerState);

/// Create a render-target view for accessing resource data.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateRenderTargetView.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pResource               Pointer to a ID3D11Resource which represents a render target. This resource must have been created with the D3D11_BIND_RENDER_TARGET flag.
/// \param[in]    pDesc                   Pointer to a D3D11_RENDER_TARGET_VIEW_DESC which represents a render-target-view description. Set this parameter to NULL to create a view that accesses all of the subresources in mipmap level 0.
/// \param[out]   rpRenderTargetView      The newly-created ID3D11RenderTargetViewPtr object.
/// \return                               The error code returned by ID3D11Device::CreateRenderTargetView.
HRESULT CreateRenderTargetView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_RENDER_TARGET_VIEW_DESC* pDesc, ID3D11RenderTargetViewPtr& rpRenderTargetView);

/// Create a sampler-state object that encapsulates sampling information for a texture.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateSamplerState.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a sampler state description.
/// \param[out]   rpSamplerState          The newly-created ID3D11SamplerStatePtr object.
/// \return                               The error code returned by ID3D11Device::CreateSamplerState.
HRESULT CreateSamplerState(const ID3D11DevicePtr& pDevice, const D3D11_SAMPLER_DESC* pDesc, ID3D11SamplerStatePtr& rpSamplerState);

/// Create a render-target view for accessing resource data.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateShaderResourceView.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pResource               Pointer to the resource that will serve as input to a shader. This resource must have been created with the D3D11_BIND_SHADER_RESOURCE flag.
/// \param[in]    pDesc                   Pointer to a shader-resource-view description (see D3D11_SHADER_RESOURCE_VIEW_DESC). Set this parameter to NULL to create a view that accesses the entire resource (using the format the resource was created with).
/// \param[out]   rpShaderResourceView    The newly-created ID3D11ShaderResourceViewPtr object.
/// \return                               The error code returned by ID3D11Device::CreateShaderResourceView.
HRESULT CreateShaderResourceView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc, ID3D11ShaderResourceViewPtr& rpShaderResourceView);

/// Create an array of 1D textures.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateTexture1D.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a 1D texture description (see D3D11_TEXTURE1D_DESC). To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.
/// \param[in]    pInitialData            Pointer to an array of subresource descriptions (see D3D11_SUBRESOURCE_DATA); one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see D3D11_USAGE). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.
/// \param[out]   rpTexture1D             The newly-created ID3D11Texture1DPtr object.
/// \return                               The error code returned by ID3D11Device::CreateTexture1D.
HRESULT CreateTexture1D(const ID3D11DevicePtr& pDevice, const D3D11_TEXTURE1D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture1DPtr& rpTexture1D);

/// Create an array of 2D textures.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateTexture2D.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a 2D texture description (see D3D11_TEXTURE2D_DESC). To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.
/// \param[in]    pInitialData            Pointer to an array of subresource descriptions (see D3D11_SUBRESOURCE_DATA); one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see D3D11_USAGE). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.
/// \param[out]   rpTexture2D             The newly-created ID3D11Texture2DPtr object.
/// \return                               The error code returned by ID3D11Device::CreateTexture2D.
HRESULT CreateTexture2D(const ID3D11DevicePtr& pDevice, const D3D11_TEXTURE2D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture2DPtr& rpTexture2D);

/// Create a single 3D texture.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateTexture3D.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pDesc                   Pointer to a 3D texture description (see D3D11_TEXTURE3D_DESC). To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.
/// \param[in]    pInitialData            Pointer to an array of subresource descriptions (see D3D11_SUBRESOURCE_DATA); one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see D3D11_USAGE). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.
/// \param[out]   rpTexture3D             The newly-created ID3D11Texture3DPtr object.
/// \return                               The error code returned by ID3D11Device::CreateTexture3D.
HRESULT CreateTexture3D(const ID3D11DevicePtr& pDevice, const D3D11_TEXTURE3D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture3DPtr& rpTexture3D);

/// Create a view for accessing an unordered access resource.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateUnorderedAccessView.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pResource               Pointer to an ID3D11Resource that represents a resources that will be serve as an input to a shader.
/// \param[in]    pDesc                   Pointer to an D3D11_UNORDERED_ACCESS_VIEW_DESC that represents a shader-resource-view description. Set this parameter to NULL to create a view that accesses the entire resource (using the format the resource was created with).
/// \param[out]   rpUnorderedAccessView   The newly-created ID3D11UnorderedAccessViewPtr object.
/// \return                               The error code returned by ID3D11Device::CreateUnorderedAccessView.
HRESULT CreateUnorderedAccessView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc, ID3D11UnorderedAccessViewPtr& rpUnorderedAccessView);

/// Create an ID3D11VertexShader object.
/// This function acts as smart pointer wrapper of ID3D11Device::CreateVertexShader.
/// \param[in]    pDevice                 Smart pointer to the device.
/// \param[in]    pShaderBytecode         A pointer to the compiled shader.
/// \param[in]    BytecodeLength          Size of the compiled shader.
/// \param[in]    pClassLinkage           A pointer to a class linkage interface (see ID3D11ClassLinkage); the value can be NULL.
/// \param[out]   rpVertexShader          The newly-created ID3D11VertexShaderPtr object.
/// \return                               The error code returned by ID3D11Device::CreateVertexShader.
HRESULT CreateVertexShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11VertexShaderPtr& rpVertexShader);

/// Report the live objects for a given device.
/// \param[in]    pDevice                 A pointer to the device.
/// \param[in]    bDetailed               A detailed report or a summary?
/// \return                               True if successful, otherwise false.
bool ReportLiveDeviceObjects(const ID3D11DevicePtr& pDevice, bool bDetailed);

/// Attach a name to a resource.
/// This name can be used by the D3D debug runtime & other tools to report the name of the resource.
/// \param[in]    pResource               A pointer to the resource.
/// \param[in]    strName                 The resource name string. Pass an empty string to remove the resource name.
/// \return                               True if successful, otherwise false.
bool SetResourceName(const ID3D11DeviceChildPtr& pResource, const std::string& strName);

/// Retrieve a resource's name.
/// This name can be used by the D3D debug runtime & other tools to report the name of the resource.
/// \param[in]    pResource               A pointer to the resource.
/// \param[in]    strName                 The resource name string.
/// \return                               True if successful, otherwise false.
bool GetResourceName(const ID3D11DeviceChildPtr& pResource, std::string& strName);

} // namespace GDT_DX11

#endif // GDT_DX11_H
