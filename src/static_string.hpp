#pragma once

#include <cstddef>
#include <ostream>
#include <string>

using namespace std;

template<size_t N>
class static_string
{
    const char (&data)[N];

public:
    constexpr explicit static_string(const char (&str)[N]) : data{ str }
    {
    }

    constexpr char operator[](size_t n) const
    {
        return n < N - 1 ? data[n] : throw out_of_range("");
    }

    constexpr size_t size() const
    {
        return N - 1;
    }

    constexpr const char * c_str() const
    {
        return data;
    }
};

template<size_t N>
constexpr static_string<N> literal(const char(&a)[N])
{
    return static_string<N>(a);
}

template<size_t N1, size_t N2>
class array_string
{
public:
    char data[N1 - 1 + N2 - 1 + 1];

    constexpr explicit array_string(const static_string<N1> & s1,
                                    const static_string<N2> & s2)
    {
        for (size_t i = 0; i < N1 - 1; ++i)
            data[i] = s1[i];

        for (size_t i = 0; i < N2 - 1; ++i)
            data[N1 - 1 + i] = s2[i];

        data[N1 - 1 + N2 - 1] = '\0';
    }

    constexpr const char * c_str() const
    {
        return data;
    }

    operator string()
    {
        return data;
    }

    /*constexpr operator static_string<N1 - 1 + N2 - 1 + 1>()
    {
        return static_string<N1 - 1 + N2 - 1 + 1>(data);
    }*/
};

template<size_t N>
constexpr ostream & operator<<(ostream & out, const static_string<N> & s)
{
    return out << s.c_str();
}

template<size_t N1, size_t N2>
constexpr ostream & operator<<(ostream & out, const array_string<N1, N2> & a)
{
    return out << a.c_str();
}

template<size_t N1, size_t N2>
constexpr array_string<N1, N2> operator+(const static_string<N1> & s1,
                                         const static_string<N2> & s2)
{
    return array_string<N1, N2>(s1, s2);
}

template<size_t N1, size_t N2, size_t N3>
constexpr array_string<N1 + N2 - 1, N3> operator+(const array_string<N1, N2> & a,
                                                  const static_string<N3> & s)
{
    return array_string<N1 + N2 - 1, N3>(static_string<N1 + N2 - 1>(a.data), s);
}
