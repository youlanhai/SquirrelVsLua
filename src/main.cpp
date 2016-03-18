//
//  main.c
//  SqVsLua
//
//  Created by C218-pc on 16/3/16.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#include <stdio.h>
#include "test_lua.h"
#include "test_squirrel.h"

#include "test_manager.h"


template<typename T>
bool registerTestCase(TestManager &manager)
{
    TestCase *p = new T();
    if(p->init())
    {
        manager.addTestCase(p);
        return true;
    }
    else
    {
        printf("Failed to create test case '%s'.\n", typeid(T).name());
        delete p;
        return false;
    }
}

int main(int argc, const char * argv[])
{
#ifdef DEBUG
    printf("build in debug mode.\n");
#endif
#ifdef NDEBUG
    printf("build in release mode.\n");
#endif
    
    TestManager manager;
    
    registerTestCase<TestLua>(manager);
    registerTestCase<TestSquirrel>(manager);
    
    manager.doTest();
    return 0;
}
