#include "TestCoutFn.h"

#include "PyPrint.h"

#include <array>

TEST_CASE("String literal")
{
    TestCoutFn([]() { pp::println("String literal!"); }, "String literal!\n");
}

TEST_CASE("std::string")
{
    TestCoutFn(
        []() {
            std::string str{"A std::string"};

            pp::println(str);
        },
        "A std::string\n");
}

TEST_CASE("std::string_view")
{
    TestCoutFn(
        []() {
            std::string_view sv{"A std::string_view"};

            pp::println(sv);
        },
        "A std::string_view\n");
}

TEST_CASE("Printing numbers")
{
    TestCoutFn([]() { pp::println(4); }, "4\n");

    TestCoutFn([]() { pp::println(139.48f); }, "139.48\n");
}

TEST_CASE("Printing array-likes")
{
    TestCoutFn(
        []() {
            std::array<int, 4> arr{0, 1, 2, 3};
            pp::println(arr);
        },
        "[0, 1, 2, 3]\n");

    TestCoutFn(
        []() {
            std::vector<float> arr{0.5f, 7.8f, 12.4f, 159.6f, 242.1f};
            pp::println(arr);
        },
        "[0.5, 7.8, 12.4, 159.6, 242.1]\n");

    TestCoutFn(
        []() {
            std::array<std::array<unsigned int, 2>, 2> arr{{{{0, 1}}, {{2, 3}}}};
            pp::println(arr);
        },
        "[[0, 1], [2, 3]]\n");

    TestCoutFn(
        []() {
            std::vector<std::vector<double>> arr{{0.0f, 1.0f, 2.0f}, {3.0f, 4.0f, 5.0f}, {6.0f, 7.0f, 8.0f}};
            pp::println(arr);
        },
        "[[0, 1, 2], [3, 4, 5], [6, 7, 8]]\n");
}