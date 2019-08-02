// https://github.com/vinniefalco/LuaBridge
//
// Copyright 2019, Dmitry Tarakanov
// Copyright 2019, George Tokmaji
// SPDX-License-Identifier: MIT

#pragma once

#if !defined (LUABRIDGE_NO_CXX11) && (__cplusplus >= 201103L || (defined (_MSC_VER) && _MSC_VER >= 1900))
#define LUABRIDGE_CXX11
#endif

#if __cplusplus < 201703L
#error This LuaBridge fork requires C++17!
#endif
