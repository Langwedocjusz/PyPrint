#pragma once

#include <iostream>

#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

namespace pp
{
template <typename T>
struct is_map_like : std::false_type {};

template <typename Key, typename Value>
struct is_map_like<std::map<Key, Value>> : std::true_type {};

template <typename Key, typename Value>
struct is_map_like<std::unordered_map<Key, Value>> : std::true_type {};

template <typename T>
struct is_set_like : std::false_type {};

template <typename Key>
struct is_set_like<std::set<Key>> : std::true_type {};

template <typename Key>
struct is_set_like<std::unordered_set<Key>> : std::true_type {};

template <typename T>
concept Printable = requires(T val) { std::cout << val; };

template <typename T>
concept MapLike = is_map_like<T>::value;

template <typename T>
concept SetLike = is_set_like<T>::value;

template <typename T>
concept Iterable = requires(T val) {
    val.begin();
    val.end();
};

template <typename T>
concept IterableNoOtherConcepts = Iterable<T> && !Printable<T> && !MapLike<T> && !SetLike<T>;

template <Printable P>
void print(const P &p)
{
    std::cout << p;
}

template <MapLike T>
void print(const T &val);

template <SetLike T>
void print(const T &val);

template <IterableNoOtherConcepts T>
void print(const T &val)
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

template <MapLike T>
void print(const T &val)
{
    std::cout << "{";

    auto it = val.begin();

    if (it != val.end())
    {
        const auto &[key, value] = *it;

        print(key);
        std::cout << " : ";
        print(value);

        while (++it != val.end())
        {
            std::cout << ", ";

            const auto &[key, value] = *it;

            print(key);
            std::cout << " : ";
            print(value);
        }
    }

    std::cout << "}";
}

template <SetLike T>
void print(const T &val)
{
    std::cout << "{";

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

    std::cout << "}";
}

template <typename Tuple, std::size_t N>
struct TuplePrinter {
    static void run(const Tuple &t)
    {
        TuplePrinter<Tuple, N - 1>::run(t);
        std::cout << ", ";
        print(std::get<N - 1>(t));
    }
};

template <typename Tuple>
struct TuplePrinter<Tuple, 1> {
    static void run(const Tuple &t)
    {
        print(std::get<0>(t));
    }
};

template <typename... Args>
void print(const std::tuple<Args...> &val)
{
    std::cout << "(";
    TuplePrinter<decltype(val), sizeof...(Args)>::run(val);
    std::cout << ")";
}

template <typename T>
void println(const T &p)
{
    print(p);
    std::cout << '\n';
}

} // namespace pp
