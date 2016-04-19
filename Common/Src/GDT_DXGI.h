//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_DXGI_H
#define GDT_DXGI_H

#include <boost/intrusive_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>

#include "GDT_COM.h"

#include "DXGI.h"

namespace GDT_DXGI
{
typedef boost::intrusive_ptr<IDXGIObject>          IDXGIObjectPtr;
typedef boost::intrusive_ptr<IDXGIDeviceSubObject> IDXGIDeviceSubObjectPtr;
typedef boost::intrusive_ptr<IDXGIResource>        IDXGIResourcePtr;
typedef boost::intrusive_ptr<IDXGIKeyedMutex>      IDXGIKeyedMutexPtr;
typedef boost::intrusive_ptr<IDXGISurface>         IDXGISurfacePtr;
typedef boost::intrusive_ptr<IDXGISurface1>        IDXGISurface1Ptr;
typedef boost::intrusive_ptr<IDXGIAdapter>         IDXGIAdapterPtr;
typedef boost::intrusive_ptr<IDXGIOutput>          IDXGIOutputPtr;
typedef boost::intrusive_ptr<IDXGISwapChain>       IDXGISwapChainPtr;
typedef boost::intrusive_ptr<IDXGIFactory>         IDXGIFactoryPtr;
typedef boost::intrusive_ptr<IDXGIDevice>          IDXGIDevicePtr;
typedef boost::intrusive_ptr<IDXGIFactory1>        IDXGIFactory1Ptr;
typedef boost::intrusive_ptr<IDXGIAdapter1>        IDXGIAdapter1Ptr;
typedef boost::intrusive_ptr<IDXGIDevice1>         IDXGIDevice1Ptr;
} // namespace GDT_DXGI

#endif // GDT_DXGI_H
