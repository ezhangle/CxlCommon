//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_COM_H
#define GDT_COM_H

#include <boost/intrusive_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/type_traits.hpp>

/// Basic smart-pointer support for COM objects.

template<typename T>
inline typename boost::enable_if < boost::is_base_of<IUnknown, T> >::type
intrusive_ptr_add_ref(T* pObject)
{
    pObject->AddRef();
}

template<typename T>
inline typename boost::enable_if < boost::is_base_of<IUnknown, T> >::type
intrusive_ptr_release(T* pObject)
{
    pObject->Release();
}

#endif // GDT_COM_H
