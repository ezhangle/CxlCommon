//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#include <Windows.h>
#include <D3D11.h>
#include "GDT_DX11.h"

using namespace GDT_DX11;

HRESULT GDT_DX11::CreateBlendState(const ID3D11DevicePtr& pDevice, const D3D11_BLEND_DESC* pDesc, ID3D11BlendStatePtr& rpBlendState)
{
    ID3D11BlendState* pBlendState;
    HRESULT hr = pDevice->CreateBlendState(pDesc, &pBlendState);
    rpBlendState = GDT_DX11::ID3D11BlendStatePtr(pBlendState, false);
    return hr;
}

HRESULT GDT_DX11::CreateBuffer(const ID3D11DevicePtr& pDevice, const D3D11_BUFFER_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11BufferPtr& rpBuffer)
{
    ID3D11Buffer* pBuffer;
    HRESULT hr = pDevice->CreateBuffer(pDesc, pInitialData, &pBuffer);
    rpBuffer = GDT_DX11::ID3D11BufferPtr(pBuffer, false);
    return hr;
}

HRESULT GDT_DX11::CreateClassLinkage(const ID3D11DevicePtr& pDevice, ID3D11ClassLinkagePtr& rpClassLinkage)
{
    ID3D11ClassLinkage* pClassLinkage;
    HRESULT hr = pDevice->CreateClassLinkage(&pClassLinkage);
    rpClassLinkage = GDT_DX11::ID3D11ClassLinkagePtr(pClassLinkage, false);
    return hr;
}

HRESULT GDT_DX11::CreateComputeShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11ComputeShaderPtr& rpComputeShader)
{
    ID3D11ComputeShader* pComputeShader;
    HRESULT hr = pDevice->CreateComputeShader(pShaderBytecode, BytecodeLength, pClassLinkage, &pComputeShader);
    rpComputeShader = GDT_DX11::ID3D11ComputeShaderPtr(pComputeShader, false);
    return hr;
}

HRESULT GDT_DX11::CreateCounter(const ID3D11DevicePtr& pDevice, const D3D11_COUNTER_DESC* pDesc, ID3D11CounterPtr& rpCounter)
{
    ID3D11Counter* pCounter;
    HRESULT hr = pDevice->CreateCounter(pDesc, &pCounter);
    rpCounter = GDT_DX11::ID3D11CounterPtr(pCounter, false);
    return hr;
}

HRESULT GDT_DX11::CreateDeferredContext(const ID3D11DevicePtr& pDevice, const UINT ContextFlags, ID3D11DeviceContextPtr& rpDeferredContext)
{
    ID3D11DeviceContext* pDeferredContext;
    HRESULT hr = pDevice->CreateDeferredContext(ContextFlags, &pDeferredContext);
    rpDeferredContext = GDT_DX11::ID3D11DeviceContextPtr(pDeferredContext, false);
    return hr;
}

HRESULT GDT_DX11::CreateDepthStencilState(const ID3D11DevicePtr& pDevice, const D3D11_DEPTH_STENCIL_DESC* pDesc, ID3D11DepthStencilStatePtr& rpDepthStencilState)
{
    ID3D11DepthStencilState* pDepthStencilState;
    HRESULT hr = pDevice->CreateDepthStencilState(pDesc, &pDepthStencilState);
    rpDepthStencilState = GDT_DX11::ID3D11DepthStencilStatePtr(pDepthStencilState, false);
    return hr;
}

HRESULT GDT_DX11::CreateDepthStencilView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc, ID3D11DepthStencilViewPtr& rpDepthStencilView)
{
    ID3D11DepthStencilView* pDepthStencilView;
    HRESULT hr = pDevice->CreateDepthStencilView(pResource, pDesc, &pDepthStencilView);
    rpDepthStencilView = GDT_DX11::ID3D11DepthStencilViewPtr(pDepthStencilView, false);
    return hr;
}

HRESULT GDT_DX11::CreateDomainShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11DomainShaderPtr& rpDomainShader)
{
    ID3D11DomainShader* pDomainShader;
    HRESULT hr = pDevice->CreateDomainShader(pShaderBytecode, BytecodeLength, pClassLinkage, &pDomainShader);
    rpDomainShader = GDT_DX11::ID3D11DomainShaderPtr(pDomainShader, false);
    return hr;
}

HRESULT GDT_DX11::CreateGeometryShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11GeometryShaderPtr& rpGeometryShader)
{
    ID3D11GeometryShader* pGeometryShader;
    HRESULT hr = pDevice->CreateGeometryShader(pShaderBytecode, BytecodeLength, pClassLinkage, &pGeometryShader);
    rpGeometryShader = GDT_DX11::ID3D11GeometryShaderPtr(pGeometryShader, false);
    return hr;
}

HRESULT GDT_DX11::CreateGeometryShaderWithStreamOutput(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, const D3D11_SO_DECLARATION_ENTRY* pSODeclaration, UINT NumEntries, const UINT* pBufferStrides, UINT NumStrides, UINT RasterizedStream, ID3D11ClassLinkage* pClassLinkage, ID3D11GeometryShaderPtr& rpGeometryShader)
{
    ID3D11GeometryShader* pGeometryShader;
    HRESULT hr = pDevice->CreateGeometryShaderWithStreamOutput(pShaderBytecode, BytecodeLength, pSODeclaration, NumEntries, pBufferStrides, NumStrides, RasterizedStream, pClassLinkage, &pGeometryShader);
    rpGeometryShader = GDT_DX11::ID3D11GeometryShaderPtr(pGeometryShader, false);
    return hr;
}

HRESULT GDT_DX11::CreateHullShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11HullShaderPtr& rpHullShader)
{
    ID3D11HullShader* pHullShader;
    HRESULT hr = pDevice->CreateHullShader(pShaderBytecode, BytecodeLength, pClassLinkage, &pHullShader);
    rpHullShader = GDT_DX11::ID3D11HullShaderPtr(pHullShader, false);
    return hr;
}

HRESULT GDT_DX11::CreateInputLayout(const ID3D11DevicePtr& pDevice, const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderWithInputSig, SIZE_T BytecodeLength, ID3D11InputLayoutPtr& rpInputLayout)
{
    ID3D11InputLayout* pInputLayout;
    HRESULT hr = pDevice->CreateInputLayout(pInputElementDescs, NumElements, pShaderWithInputSig, BytecodeLength, &pInputLayout);
    rpInputLayout = GDT_DX11::ID3D11InputLayoutPtr(pInputLayout, false);
    return hr;
}

HRESULT GDT_DX11::CreatePixelShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11PixelShaderPtr& rpPixelShader)
{
    ID3D11PixelShader* pPixelShader;
    HRESULT hr = pDevice->CreatePixelShader(pShaderBytecode, BytecodeLength, pClassLinkage, &pPixelShader);
    rpPixelShader = GDT_DX11::ID3D11PixelShaderPtr(pPixelShader, false);
    return hr;
}

HRESULT GDT_DX11::CreatePredicate(const ID3D11DevicePtr& pDevice, const D3D11_QUERY_DESC* pDesc, ID3D11PredicatePtr& rpPredicate)
{
    ID3D11Predicate* pPredicate;
    HRESULT hr = pDevice->CreatePredicate(pDesc, &pPredicate);
    rpPredicate = GDT_DX11::ID3D11PredicatePtr(pPredicate, false);
    return hr;
}

HRESULT GDT_DX11::CreateQuery(const ID3D11DevicePtr& pDevice, const D3D11_QUERY_DESC* pDesc, ID3D11QueryPtr& rpQuery)
{
    ID3D11Query* pQuery;
    HRESULT hr = pDevice->CreateQuery(pDesc, &pQuery);
    rpQuery = GDT_DX11::ID3D11QueryPtr(pQuery, false);
    return hr;
}

HRESULT GDT_DX11::CreateRasterizerState(const ID3D11DevicePtr& pDevice, const D3D11_RASTERIZER_DESC* pDesc, ID3D11RasterizerStatePtr& rpRasterizerState)
{
    ID3D11RasterizerState* pRasterizerState;
    HRESULT hr = pDevice->CreateRasterizerState(pDesc, &pRasterizerState);
    rpRasterizerState = GDT_DX11::ID3D11RasterizerStatePtr(pRasterizerState, false);
    return hr;
}

HRESULT GDT_DX11::CreateRenderTargetView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_RENDER_TARGET_VIEW_DESC* pDesc, ID3D11RenderTargetViewPtr& rpRenderTargetView)
{
    ID3D11RenderTargetView* pRenderTargetView;
    HRESULT hr = pDevice->CreateRenderTargetView(pResource, pDesc, &pRenderTargetView);
    rpRenderTargetView = GDT_DX11::ID3D11RenderTargetViewPtr(pRenderTargetView, false);
    return hr;
}

HRESULT GDT_DX11::CreateSamplerState(const ID3D11DevicePtr& pDevice, const D3D11_SAMPLER_DESC* pDesc, ID3D11SamplerStatePtr& rpSamplerState)
{
    ID3D11SamplerState* pSamplerState;
    HRESULT hr = pDevice->CreateSamplerState(pDesc, &pSamplerState);
    rpSamplerState = GDT_DX11::ID3D11SamplerStatePtr(pSamplerState, false);
    return hr;
}

HRESULT GDT_DX11::CreateShaderResourceView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc, ID3D11ShaderResourceViewPtr& rpShaderResourceView)
{
    ID3D11ShaderResourceView* pShaderResourceView;
    HRESULT hr = pDevice->CreateShaderResourceView(pResource, pDesc, &pShaderResourceView);
    rpShaderResourceView = GDT_DX11::ID3D11ShaderResourceViewPtr(pShaderResourceView, false);
    return hr;
}

HRESULT GDT_DX11::CreateTexture1D(const ID3D11DevicePtr& pDevice, const D3D11_TEXTURE1D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture1DPtr& rpTexture1D)
{
    ID3D11Texture1D* pTexture1D;
    HRESULT hr = pDevice->CreateTexture1D(pDesc, pInitialData, &pTexture1D);
    rpTexture1D = GDT_DX11::ID3D11Texture1DPtr(pTexture1D, false);
    return hr;
}

HRESULT GDT_DX11::CreateTexture2D(const ID3D11DevicePtr& pDevice, const D3D11_TEXTURE2D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture2DPtr& rpTexture2D)
{
    ID3D11Texture2D* pTexture2D;
    HRESULT hr = pDevice->CreateTexture2D(pDesc, pInitialData, &pTexture2D);
    rpTexture2D = GDT_DX11::ID3D11Texture2DPtr(pTexture2D, false);
    return hr;
}

HRESULT GDT_DX11::CreateTexture3D(const ID3D11DevicePtr& pDevice, const D3D11_TEXTURE3D_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture3DPtr& rpTexture3D)
{
    ID3D11Texture3D* pTexture3D;
    HRESULT hr = pDevice->CreateTexture3D(pDesc, pInitialData, &pTexture3D);
    rpTexture3D = GDT_DX11::ID3D11Texture3DPtr(pTexture3D, false);
    return hr;
}

HRESULT GDT_DX11::CreateUnorderedAccessView(const ID3D11DevicePtr& pDevice, ID3D11Resource* pResource, const D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc, ID3D11UnorderedAccessViewPtr& rpUnorderedAccessView)
{
    ID3D11UnorderedAccessView* pUnorderedAccessView;
    HRESULT hr = pDevice->CreateUnorderedAccessView(pResource, pDesc, &pUnorderedAccessView);
    rpUnorderedAccessView = GDT_DX11::ID3D11UnorderedAccessViewPtr(pUnorderedAccessView, false);
    return hr;
}

HRESULT GDT_DX11::CreateVertexShader(const ID3D11DevicePtr& pDevice, const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11VertexShaderPtr& rpVertexShader)
{
    ID3D11VertexShader* pVertexShader;
    HRESULT hr = pDevice->CreateVertexShader(pShaderBytecode, BytecodeLength, pClassLinkage, &pVertexShader);
    rpVertexShader = GDT_DX11::ID3D11VertexShaderPtr(pVertexShader, false);
    return hr;
}

bool GDT_DX11::ReportLiveDeviceObjects(const ID3D11DevicePtr& pDevice, bool bDetailed)
{
    ID3D11Debug* pDebugLayer = NULL;

    if (pDevice != NULL && SUCCEEDED(pDevice->QueryInterface(IID_ID3D11Debug, (void**) &pDebugLayer)))
    {
        pDebugLayer->ReportLiveDeviceObjects(bDetailed ? D3D11_RLDO_DETAIL : D3D11_RLDO_SUMMARY);
        pDebugLayer->Release();
        return true;
    }

    return false;
}

bool GDT_DX11::SetResourceName(const ID3D11DeviceChildPtr& pResource, const std::string& strName)
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

bool GDT_DX11::GetResourceName(const ID3D11DeviceChildPtr& pResource, std::string& strName)
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
