#pragma once

#include <iostream>

namespace pp{

template <typename T>
concept Printable = requires(T val) {
    std::cout << val;
};

template <Printable P>
void print(const P& p)
{
    std::cout << p;
}

template <Printable P>
void println(const P& p)
{
    print(p);
    std::cout << '\n';
}

}


