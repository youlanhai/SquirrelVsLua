//
//  test_squirrel.cpp
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#include "test_squirrel.h"

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <new>

#include <squirrel.h>
#include <sqstdaux.h>
#include <sqstdmath.h>
#include <sqstdstring.h>
#include <sqstdio.h>
#include <sqvm.h>

#ifdef SQUNICODE
#define scfprintf fwprintf
#define scfopen	_wfopen
#define scvprintf vfwprintf
#else
#define scfprintf fprintf
#define scfopen	fopen
#define scvprintf vfprintf
#endif


void printfunc(HSQUIRRELVM v,const SQChar *s,...)
{
    va_list vl;
    va_start(vl, s);
    scvprintf(stdout, s, vl);
    va_end(vl);
}

void sqCompileError(HSQUIRRELVM vm, const SQChar *desc,const SQChar *source, SQInteger line, SQInteger column)
{
    printf("sq compile error: %s, file: %s, line: %d, column: %d\n",
           desc, source, (int)line, (int)column);
}

TestSquirrel::TestSquirrel()
{
#ifdef SQUSEDOUBLE
    printf("squirrel compile use double\n");
#endif
#ifdef _SQ64
    printf("squirrel compile use sq64\n");
#endif
    
    // open squirrel vm
    vm_ = sq_open(1024);
    sqstd_register_mathlib(vm_);
    sqstd_register_stringlib(vm_);
    sqstd_register_iolib(vm_);
    sq_setprintfunc(vm_, printfunc, printfunc);
    sqstd_seterrorhandlers(vm_);
    
    sq_pushroottable(vm_);
}

TestSquirrel::~TestSquirrel()
{
    sq_close(vm_);
}

bool TestSquirrel::init()
{
    if(SQ_SUCCEEDED(sqstd_dofile(vm_, "script/main.nut", 0, SQTrue)))
    {
        return true;
    }
    
    const SQChar *err;
    sq_getlasterror(vm_);
    if(SQ_SUCCEEDED(sq_getstring(vm_, -1, &err)))
    {
        scprintf(_SC("Error [%s]\n"), err);
    }
    return false;
}

void TestSquirrel::callScript(const char *funName, int n)
{
    sq_pushroottable(vm_);
    sq_pushstring(vm_, funName, -1);
    if(SQ_FAILED(sq_get(vm_, -2)))
    {
        printf("error squirrel: function was not found '%s'", funName);
        sq_pop(vm_, 1); // pop top
    }
    else
    {
        sq_pushroottable(vm_); // push 'this'
        sq_pushinteger(vm_, n);
        sq_call(vm_, 2, 0, SQTrue);
        sq_pop(vm_, 2); // pop root and top function.
    }
}

void TestSquirrel::testEmptyFunCall(int n)
{
    sq_pushroottable(vm_);
    sq_pushstring(vm_, "testEmptyFunCall", -1);
    if(SQ_FAILED(sq_get(vm_, -2)))
    {
        printf("error squirrel: function was not found 'testEmptyFunCall'");
        sq_pop(vm_, 1); //pop top
    }
    else
    {
        for(int i = 0; i < n; ++i)
        {
            sq_pushroottable(vm_); // push 'this'
            sq_call(vm_, 1, 0, SQTrue);
        }
        sq_pop(vm_, 2); //pop the root and top function
    }
}

void TestSquirrel::testNumber(int n)
{
    callScript("testNumber", n);
}

void TestSquirrel::testStringConcat(int n)
{
    callScript("testStringConcat", n);
}

void TestSquirrel::testArrayGetSet(int n)
{
    callScript("testArrayGetSet", n);
}

void TestSquirrel::testTableCreate(int n)
{
    callScript("testTableCreate", n);
}

void TestSquirrel::testTableFind(int n)
{
    callScript("testTableFind", n);
}

void TestSquirrel::testTableFailedFind(int n)
{
    callScript("testTableFailedFind", n);
}
