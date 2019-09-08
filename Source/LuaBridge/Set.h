// https://github.com/Fulgen301/LuaBridge
//
// Copyright 2019, George Tokmaji
// Copyright 2019, Dmitry Tarakanov
// SPDX-License-Identifier: MIT

#pragma once

#include <LuaBridge/detail/Stack.h>

#include <set>

namespace luabridge {

template<class T>
struct Stack<std::set<T>>
{
  static void push(lua_State *L, const std::set<T> &set)
  {
	lua_createtable(L, static_cast <int>(set.size()), 0);
	size_t i = 0;
	for (auto it = set.begin(); it != set.end(); ++it)
	{
	  lua_pushinteger(L, static_cast <lua_Integer>(i + 1));
	  Stack <T>::push(L, *it);
	  lua_settable(L, -3);
	  ++i;
	}
  }

  static std::set<T> get(lua_State *L, int index)
  {
	if (!lua_istable (L, index))
	{
	  luaL_error (L, "#%d argument must be table", index);
	}

	std::set<T> set;

	int const absindex = lua_absindex(L, index);
	lua_pushnil(L);
	while (lua_next(L, absindex) != 0)
	{
	  set.insert(Stack<T>::get(L, -1));
	  lua_pop(L, 1);
	}
	return set;
  }
};

} // namespace luabridge
