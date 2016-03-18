//
//  test_squirrel.h
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#ifndef __SqVsLua__test_squirrel__
#define __SqVsLua__test_squirrel__

#include "test_case.h"

typedef struct SQVM* HSQUIRRELVM;

class TestSquirrel : public TestCase
{
public:
    TestSquirrel();
    ~TestSquirrel();
    
    virtual const char* getName() TC_OVERRIDE { return "squirrel"; }
    
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
    
    HSQUIRRELVM vm_;
};


#endif /* defined(__SqVsLua__test_squirrel__) */
