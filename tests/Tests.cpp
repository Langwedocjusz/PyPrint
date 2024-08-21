#include "TestCoutFn.h"

#include "PyPrint.h"

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

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

TEST_CASE("Printing sequence containers")
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

    TestCoutFn(
        []() {
            std::deque<int> d{4, 5, 8, 9, 12};
            pp::println(d);
        },
        "[4, 5, 8, 9, 12]\n");

    TestCoutFn(
        []() {
            std::list<int> d{4, 5, 8, 9, 12};
            pp::println(d);
        },
        "[4, 5, 8, 9, 12]\n");

    TestCoutFn(
        []() {
            std::forward_list<int> d{4, 5, 8, 9, 12};
            pp::println(d);
        },
        "[4, 5, 8, 9, 12]\n");
}

TEST_CASE("Printing maps")
{
    TestCoutFn(
        []() {
            std::map<int, std::string> m{{0, "Zero"}, {1, "One"}, {2, "Two"}};

            pp::println(m);
        },
        "{0 : Zero, 1 : One, 2 : Two}\n");
}

TEST_CASE("Printing sets")
{
    TestCoutFn(
        []() {
            std::set<char> s{'a', 'b', 'c', 'd'};

            pp::println(s);
        },
        "{a, b, c, d}\n");
}

TEST_CASE("Printing combined containers")
{
    TestCoutFn(
        []() {
            std::vector<std::map<int, std::string>> we{{{0, "Zero"}, {1, "One"}}, {{1, "I"}, {2, "II"}, {3, "III"}}};

            pp::println(we);
        },
        "[{0 : Zero, 1 : One}, {1 : I, 2 : II, 3 : III}]\n");

    TestCoutFn(
        []() {
            std::set<std::vector<int>> we{{0, 1, 2}, {3, 4, 5}};

            pp::println(we);
        },
        "{[0, 1, 2], [3, 4, 5]}\n");
}

TEST_CASE("Printing tuples")
{
    TestCoutFn(
        []() {
            auto tup = std::make_tuple(4, 12.5, "we", std::vector<int>{4, 12});

            pp::println(tup);
        },
        "(4, 12.5, we, [4, 12])\n");
}

TEST_CASE("Formatted printing")
{
    TestCoutFn(
        []() {
            int we = 4;
            std::vector<float> wy{3.5f, 8.9f};
            auto wu = std::make_tuple("AAA", 48);

            pp::println("WE: {}, WY: {}, WU: {}", we, wy, wu);
        },
        "WE: 4, WY: [3.5, 8.9], WU: (AAA, 48)\n");
}