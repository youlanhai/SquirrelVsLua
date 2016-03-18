//
//  test_lua.cpp
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#include "test_lua.h"

extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <assert.h>

TestLua::TestLua()
{
    state_ = luaL_newstate();
    luaL_openlibs(state_);
}

TestLua::~TestLua()
{
    lua_close(state_);
}

bool TestLua::init()
{
    if(LUA_OK != luaL_loadfile(state_, "script/main.lua"))
    {
        printf("lua: init failed. %s\n", lua_tostring(state_, -1));
        lua_pop(state_, 1);
        return false;
    }
    
    return lua_pcall(state_, 0, 0, 0) == LUA_OK;
}

void TestLua::callScript(const char *funName, int n)
{
    lua_getglobal(state_, funName);
    if(!lua_isfunction(state_, -1))
    {
        lua_pop(state_, 1);
        printf("error: lua - failed to find function '%s'\n", funName);
        return;
    }
    
    lua_pushinteger(state_, n);
    lua_pcall(state_, 1, 0, 0);
}

void TestLua::testEmptyFunCall(int n)
{
    lua_getglobal(state_, "testEmptyFunCall");
    assert(lua_isfunction(state_, -1));
    
    for(int i = 0; i < n; ++i)
    {
        lua_pushvalue(state_, -1);
        lua_call(state_, 0, 0);
    }
    lua_pop(state_, 1);
}

void TestLua::testNumber(int n)
{
    callScript("testNumber", n);
}

void TestLua::testStringConcat(int n)
{
    callScript("testStringConcat", n);
}

void TestLua::testArrayGetSet(int n)
{
    callScript("testArrayGetSet", n);
}

void TestLua::testTableCreate(int n)
{
    callScript("testTableCreate", n);
}

void TestLua::testTableFind(int n)
{
    callScript("testTableFind", n);
}

void TestLua::testTableFailedFind(int n)
{
    callScript("testTableFailedFind", n);
}
