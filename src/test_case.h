//
//  test_case.h
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#ifndef SqVsLua_test_case_h
#define SqVsLua_test_case_h

#include <stdint.h>

#ifndef TC_OVERRIDE
#define TC_OVERRIDE override
#endif

class TestCase
{
public:
    TestCase();
    virtual ~TestCase();
    
    virtual const char* getName() = 0;
    
    virtual bool init() = 0;
    
    //n为c++调用脚本函数的次数
    virtual void testEmptyFunCall(int n) = 0;
    
    //double类型相加，从1加到n
    virtual void testNumber(int n) = 0;
    
    //两个长度为100的字符串连接，n为操作次数
    virtual void testStringConcat(int n) = 0;
    
    //测试数组提取元素和设置元素，n为操作次数。数组长度为1000
    virtual void testArrayGetSet(int n) = 0;
    
    //测试哈希表的构造时间，n为哈希表大小。
    virtual void testTableCreate(int n) = 0;
    
    //测试哈希表查找存在的元素，n为操作次数。哈希表长度为1000，
    virtual void testTableFind(int n) = 0;
    
    //测试哈希表查找不存在的元素，n为操作次数。哈希表长度为1000，
    virtual void testTableFailedFind(int n) = 0;
};

int64_t get_time_ms();

#endif
