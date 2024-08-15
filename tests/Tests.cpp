#include "TestCoutFn.h"

#include "PyPrint.h"

TEST_CASE("String literal")
{
    TestCoutFn([](){
        pp::println("String literal!");

    }, "String literal!\n");
}

TEST_CASE("std::string")
{
    TestCoutFn([](){
        std::string str{"A std::string"};

        pp::println(str);

    }, "A std::string\n");
}

TEST_CASE("std::string_view")
{
    TestCoutFn([](){
        std::string_view sv{"A std::string_view"};

        pp::println(sv);

    }, "A std::string_view\n");
}