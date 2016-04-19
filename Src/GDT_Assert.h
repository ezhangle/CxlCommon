//==============================================================================
// Copyright (c) 2009-2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
//==============================================================================

#pragma once

#ifndef GDT_ASSERT_H
#define GDT_ASSERT_H

#include <assert.h>
#include <boost/static_assert.hpp>

/// Extended support for asserts & static asserts.


#ifdef _DEBUG
    #define GDT_Assert assert
    #define GDT_Break(_Expression) assert(!_Expression)
    #define GDT_Verify(_Expression) GDT_Assert(_Expression)
#else
    #define GDT_Assert(_Expression)  // Asserts boil away to nothing in release builds
    #define GDT_Break(_Expression)   // Asserts boil away to nothing in release builds
    #define GDT_Verify(_Expression) (_Expression)
#endif

#define GDT_StaticAssert BOOST_STATIC_ASSERT

#ifndef _GDT_Assert
    #define _GDT_Assert GDT_Assert
#endif

#ifndef _GDT_Verify
    #define _GDT_Verify GDT_Verify
#endif

#ifndef _GDT_Break
    #define _GDT_Break GDT_Break
#endif

#ifndef _GDT_StaticAssert
    #define _GDT_StaticAssert GDT_StaticAssert
#endif

#endif // GDT_ASSERT_H
