//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#include <Windows.h>
#include <D3D10.h>
#include <D3DCommon.h>
#include "GDT_DX10.h"

using namespace GDT_DX10;

HRESULT GDT_DX10::CreateBlendState(const ID3D10DevicePtr& pDevice, const D3D10_BLEND_DESC* pDesc, ID3D10BlendStatePtr& rpBlendState)
{
    ID3D10BlendState* pBlendState;
    HRESULT hr = pDevice->CreateBlendState(pDesc, &pBlendState);
    rpBlendState = GDT_DX10::ID3D10BlendStatePtr(pBlendState, false);
    return hr;
}

HRESULT GDT_DX10::CreateBuffer(const ID3D10DevicePtr& pDevice, const D3D10_BUFFER_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10BufferPtr& rpBuffer)
{
    ID3D10Buffer* pBuffer;
    HRESULT hr = pDevice->CreateBuffer(pDesc, pInitialData, &pBuffer);
    rpBuffer = GDT_DX10::ID3D10BufferPtr(pBuffer, false);
    return hr;
}

HRESULT GDT_DX10::CreateCounter(const ID3D10DevicePtr& pDevice, const D3D10_COUNTER_DESC* pDesc, ID3D10CounterPtr& rpCounter)
{
    ID3D10Counter* pCounter;
    HRESULT hr = pDevice->CreateCounter(pDesc, &pCounter);
    rpCounter = GDT_DX10::ID3D10CounterPtr(pCounter, false);
    return hr;
}

HRESULT GDT_DX10::CreateDepthStencilState(const ID3D10DevicePtr& pDevice, const D3D10_DEPTH_STENCIL_DESC* pDesc, ID3D10DepthStencilStatePtr& rpDepthStencilState)
{
    ID3D10DepthStencilState* pDepthStencilState;
    HRESULT hr = pDevice->CreateDepthStencilState(pDesc, &pDepthStencilState);
    rpDepthStencilState = GDT_DX10::ID3D10DepthStencilStatePtr(pDepthStencilState, false);
    return hr;
}

HRESULT GDT_DX10::CreateDepthStencilView(const ID3D10DevicePtr& pDevice, ID3D10Resource* pResource, const D3D10_DEPTH_STENCIL_VIEW_DESC* pDesc, ID3D10DepthStencilViewPtr& rpDepthStencilView)
{
    ID3D10DepthStencilView* pDepthStencilView;
    HRESULT hr = pDevice->CreateDepthStencilView(pResource, pDesc, &pDepthStencilView);
    rpDepthStencilView = GDT_DX10::ID3D10DepthStencilViewPtr(pDepthStencilView, false);
    return hr;
}

HRESULT GDT_DX10::CreateGeometryShader(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D10GeometryShaderPtr& rpGeometryShader)
{
    ID3D10GeometryShader* pGeometryShader;
    HRESULT hr = pDevice->CreateGeometryShader(pShaderBytecode, BytecodeLength, &pGeometryShader);
    rpGeometryShader = GDT_DX10::ID3D10GeometryShaderPtr(pGeometryShader, false);
    return hr;
}

HRESULT GDT_DX10::CreateGeometryShaderWithStreamOutput(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, const D3D10_SO_DECLARATION_ENTRY* pSODeclaration, UINT NumEntries, UINT OutputStreamStride, ID3D10GeometryShaderPtr& rpGeometryShader)
{
    ID3D10GeometryShader* pGeometryShader;
    HRESULT hr = pDevice->CreateGeometryShaderWithStreamOutput(pShaderBytecode, BytecodeLength, pSODeclaration, NumEntries, OutputStreamStride, &pGeometryShader);
    rpGeometryShader = GDT_DX10::ID3D10GeometryShaderPtr(pGeometryShader, false);
    return hr;
}

HRESULT GDT_DX10::CreateInputLayout(const ID3D10DevicePtr& pDevice, const D3D10_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderWithInputSig, SIZE_T BytecodeLength, ID3D10InputLayoutPtr& rpInputLayout)
{
    ID3D10InputLayout* pInputLayout;
    HRESULT hr = pDevice->CreateInputLayout(pInputElementDescs, NumElements, pShaderWithInputSig, BytecodeLength, &pInputLayout);
    rpInputLayout = GDT_DX10::ID3D10InputLayoutPtr(pInputLayout, false);
    return hr;
}

HRESULT GDT_DX10::CreatePixelShader(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D10PixelShaderPtr& rpPixelShader)
{
    ID3D10PixelShader* pPixelShader;
    HRESULT hr = pDevice->CreatePixelShader(pShaderBytecode, BytecodeLength, &pPixelShader);
    rpPixelShader = GDT_DX10::ID3D10PixelShaderPtr(pPixelShader, false);
    return hr;
}

HRESULT GDT_DX10::CreatePredicate(const ID3D10DevicePtr& pDevice, const D3D10_QUERY_DESC* pDesc, ID3D10PredicatePtr& rpPredicate)
{
    ID3D10Predicate* pPredicate;
    HRESULT hr = pDevice->CreatePredicate(pDesc, &pPredicate);
    rpPredicate = GDT_DX10::ID3D10PredicatePtr(pPredicate, false);
    return hr;
}

HRESULT GDT_DX10::CreateQuery(const ID3D10DevicePtr& pDevice, const D3D10_QUERY_DESC* pDesc, ID3D10QueryPtr& rpQuery)
{
    ID3D10Query* pQuery;
    HRESULT hr = pDevice->CreateQuery(pDesc, &pQuery);
    rpQuery = GDT_DX10::ID3D10QueryPtr(pQuery, false);
    return hr;
}

HRESULT GDT_DX10::CreateRasterizerState(const ID3D10DevicePtr& pDevice, const D3D10_RASTERIZER_DESC* pDesc, ID3D10RasterizerStatePtr& rpRasterizerState)
{
    ID3D10RasterizerState* pRasterizerState;
    HRESULT hr = pDevice->CreateRasterizerState(pDesc, &pRasterizerState);
    rpRasterizerState = GDT_DX10::ID3D10RasterizerStatePtr(pRasterizerState, false);
    return hr;
}

HRESULT GDT_DX10::CreateRenderTargetView(const ID3D10DevicePtr& pDevice, ID3D10Resource* pResource, const D3D10_RENDER_TARGET_VIEW_DESC* pDesc, ID3D10RenderTargetViewPtr& rpRenderTargetView)
{
    ID3D10RenderTargetView* pRenderTargetView;
    HRESULT hr = pDevice->CreateRenderTargetView(pResource, pDesc, &pRenderTargetView);
    rpRenderTargetView = GDT_DX10::ID3D10RenderTargetViewPtr(pRenderTargetView, false);
    return hr;
}

HRESULT GDT_DX10::CreateSamplerState(const ID3D10DevicePtr& pDevice, const D3D10_SAMPLER_DESC* pDesc, ID3D10SamplerStatePtr& rpSamplerState)
{
    ID3D10SamplerState* pSamplerState;
    HRESULT hr = pDevice->CreateSamplerState(pDesc, &pSamplerState);
    rpSamplerState = GDT_DX10::ID3D10SamplerStatePtr(pSamplerState, false);
    return hr;
}

HRESULT GDT_DX10::CreateShaderResourceView(const ID3D10DevicePtr& pDevice, ID3D10Resource* pResource, const D3D10_SHADER_RESOURCE_VIEW_DESC* pDesc, ID3D10ShaderResourceViewPtr& rpShaderResourceView)
{
    ID3D10ShaderResourceView* pShaderResourceView;
    HRESULT hr = pDevice->CreateShaderResourceView(pResource, pDesc, &pShaderResourceView);
    rpShaderResourceView = GDT_DX10::ID3D10ShaderResourceViewPtr(pShaderResourceView, false);
    return hr;
}

HRESULT GDT_DX10::CreateTexture1D(const ID3D10DevicePtr& pDevice, const D3D10_TEXTURE1D_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10Texture1DPtr& rpTexture1D)
{
    ID3D10Texture1D* pTexture1D;
    HRESULT hr = pDevice->CreateTexture1D(pDesc, pInitialData, &pTexture1D);
    rpTexture1D = GDT_DX10::ID3D10Texture1DPtr(pTexture1D, false);
    return hr;
}

HRESULT GDT_DX10::CreateTexture2D(const ID3D10DevicePtr& pDevice, const D3D10_TEXTURE2D_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10Texture2DPtr& rpTexture2D)
{
    ID3D10Texture2D* pTexture2D;
    HRESULT hr = pDevice->CreateTexture2D(pDesc, pInitialData, &pTexture2D);
    rpTexture2D = GDT_DX10::ID3D10Texture2DPtr(pTexture2D, false);
    return hr;
}

HRESULT GDT_DX10::CreateTexture3D(const ID3D10DevicePtr& pDevice, const D3D10_TEXTURE3D_DESC* pDesc, const D3D10_SUBRESOURCE_DATA* pInitialData, ID3D10Texture3DPtr& rpTexture3D)
{
    ID3D10Texture3D* pTexture3D;
    HRESULT hr = pDevice->CreateTexture3D(pDesc, pInitialData, &pTexture3D);
    rpTexture3D = GDT_DX10::ID3D10Texture3DPtr(pTexture3D, false);
    return hr;
}

HRESULT GDT_DX10::CreateVertexShader(const ID3D10DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D10VertexShaderPtr& rpVertexShader)
{
    ID3D10VertexShader* pVertexShader;
    HRESULT hr = pDevice->CreateVertexShader(pShaderBytecode, BytecodeLength, &pVertexShader);
    rpVertexShader = GDT_DX10::ID3D10VertexShaderPtr(pVertexShader, false);
    return hr;
}

bool GDT_DX10::SetResourceName(const ID3D10DeviceChildPtr& pResource, const std::string& strName)
{
    if (pResource != NULL)
    {
        const TCHAR* pszName = (strName.empty()) ? NULL : strName.c_str();

        if (SUCCEEDED(pResource->SetPrivateData(WKPDID_D3DDebugObjectName, (UINT)strName.size(), pszName)))
        {
            return true;
        }
    }

    return false;
}

bool GDT_DX10::GetResourceName(const ID3D10DeviceChildPtr& pResource, std::string& strName)
{
    strName.clear();

    if (pResource != NULL)
    {
        UINT nDataSize = 0;

        if (SUCCEEDED(pResource->GetPrivateData(WKPDID_D3DDebugObjectName, &nDataSize, NULL)))
        {
            if (nDataSize > 0)
            {
                TCHAR* pszName = (TCHAR*) malloc(nDataSize * sizeof(TCHAR));

                if (pszName == NULL)
                {
                    return false;
                }

                if (FAILED(pResource->GetPrivateData(WKPDID_D3DDebugObjectName, &nDataSize, pszName)))
                {
                    free(pszName);
                    return false;
                }

                strName.assign(pszName, nDataSize);
                free(pszName);
            }

            return true;
        }
    }

    return false;
}
