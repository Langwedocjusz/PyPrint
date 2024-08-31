#pragma once

#include "AutoCaptureCout.h"

#include <catch2/catch_test_macros.hpp>

#include <string_view>

template <typename Fn>
void TestCoutFn(Fn f, std::string_view expected)
{
    pp::AutoCaptureCout a;
    f();
    const bool condition = (a.str() == expected);
    REQUIRE(condition);
}