#pragma once

#include <iostream>

namespace pp
{
template <typename T>
concept Printable = requires(T val) { std::cout << val; };

template <typename T>
concept Iterable = requires(T val) {
    val.begin();
    val.end();
};

template <typename T>
concept NonPrintableIterable = !Printable<T> && Iterable<T>;

template <Printable P> void print(const P &p)
{
    std::cout << p;
}

template <NonPrintableIterable T> void print(const T &val)
{
    std::cout << "[";

    auto it = val.begin();

    if (it != val.end())
    {
        print(*it);

        while (++it != val.end())
        {
            std::cout << ", ";
            print(*it);
        }
    }

    std::cout << "]";
}

template <typename T> void println(const T &p)
{
    print(p);
    std::cout << '\n';
}

} // namespace pp
