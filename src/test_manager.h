//
//  test_manager.h
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#ifndef __SqVsLua__test_manager__
#define __SqVsLua__test_manager__

#include <vector>
#include "test_case.h"

class TestManager : public TestCase
{
public:
    TestManager();
    ~TestManager();
    
    void addTestCase(TestCase *tcase);
    
    void doTest();
    
    virtual const char* getName() TC_OVERRIDE { return "manager"; }
    
    virtual bool init() TC_OVERRIDE { return true; }
    
    virtual void testEmptyFunCall(int n) TC_OVERRIDE;
    
    virtual void testNumber(int n) TC_OVERRIDE;
    
    virtual void testStringConcat(int n) TC_OVERRIDE;
    
    virtual void testArrayGetSet(int n) TC_OVERRIDE;
    
    virtual void testTableCreate(int n) TC_OVERRIDE;
    
    virtual void testTableFind(int n) TC_OVERRIDE;
    
    virtual void testTableFailedFind(int n) TC_OVERRIDE;
    
private:
    typedef std::vector<TestCase*> TestCases;
    TestCases   testCases_;
};

#endif /* defined(__SqVsLua__test_manager__) */
