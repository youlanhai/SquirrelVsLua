//
//  test_manager.cpp
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#include "test_manager.h"

#define DO_TEST_CASE(KEY, METHOD)\
for(TestCases::iterator it = testCases_.begin(); it != testCases_.end(); ++it)\
{\
    int64_t start = get_time_ms();\
    (*it)->METHOD(n);\
    int64_t end = get_time_ms();\
    printf("%s: %s - %lld ms\n", KEY, (*it)->getName(), end - start);\
}\
printf("\n");

TestManager::TestManager()
{
}

TestManager::~TestManager()
{
    for(TestCases::iterator it = testCases_.begin(); it != testCases_.end(); ++it)
    {
        delete (*it);
    }
}


void TestManager::addTestCase(TestCase *tcase)
{
    testCases_.push_back(tcase);
}

void TestManager::doTest()
{
    int n = 100000;
    
    testEmptyFunCall(n);
    testNumber(n);
    testStringConcat(n);
    
    testArrayGetSet(n);
    
    testTableCreate(n);
    testTableFind(n);
    testTableFailedFind(n);
}

void TestManager::testEmptyFunCall(int n)
{
    DO_TEST_CASE("empty-fun-call", testEmptyFunCall)
}

void TestManager::testNumber(int n)
{
    DO_TEST_CASE("number-add", testNumber)
}

void TestManager::testStringConcat(int n)
{
    DO_TEST_CASE("string-concact", testStringConcat)
}

void TestManager::testArrayGetSet(int n)
{
    DO_TEST_CASE("array-getset", testArrayGetSet)
}

void TestManager::testTableCreate(int n)
{
    DO_TEST_CASE("table-create", testTableCreate)
}

void TestManager::testTableFind(int n)
{
    DO_TEST_CASE("table-find", testTableFind)
}

void TestManager::testTableFailedFind(int n)
{
    DO_TEST_CASE("table-failed-find", testTableFailedFind)
}
