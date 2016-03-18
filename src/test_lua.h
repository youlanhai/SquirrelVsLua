//
//  test_lua.h
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#ifndef __SqVsLua__test_lua__
#define __SqVsLua__test_lua__

#include "test_case.h"

typedef struct lua_State lua_State;

class TestLua : public TestCase
{
public:
    TestLua();
    ~TestLua();
    
    virtual const char* getName() TC_OVERRIDE { return "lua"; }
    
    virtual bool init() TC_OVERRIDE;
    
    virtual void testEmptyFunCall(int n) TC_OVERRIDE;
    
    virtual void testNumber(int n) TC_OVERRIDE;
    
    virtual void testStringConcat(int n) TC_OVERRIDE;
    
    virtual void testArrayGetSet(int n) TC_OVERRIDE;
    
    virtual void testTableCreate(int n) TC_OVERRIDE;
    
    virtual void testTableFind(int n) TC_OVERRIDE;
    
    virtual void testTableFailedFind(int n) TC_OVERRIDE;
    
private:
    void callScript(const char *funName, int n);
    
    lua_State*  state_;
};

#endif /* defined(__SqVsLua__test_lua__) */
