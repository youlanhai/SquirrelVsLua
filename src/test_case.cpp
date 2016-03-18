//
//  test_case.cpp
//  SqVsLua
//
//  Created by C218-pc on 16/3/17.
//  Copyright (c) 2016年 youlanhai. All rights reserved.
//

#include "test_case.h"

#include <time.h>
#include <sys/time.h>

TestCase::TestCase()
{}

TestCase::~TestCase()
{}

int64_t get_time_ms()
{
    struct timeval val;
    gettimeofday(&val, 0);
    return (int64_t)val.tv_sec * 1000 + (int64_t)val.tv_usec / 1000;
}
