#ifndef SVR_SPECIALIZATION
#define SVR_SPECIALIZATION

namespace svr
{
    // Full specialization
    template <typename T>
    struct is_floating_point
    {
        constexpr static bool value = false;
    };

    template <>
    struct is_floating_point<float>
    {
        constexpr static bool value = true;
    };

    template <>
    struct is_floating_point<double>
    {
        constexpr static bool value = true;
    };

    template <>
    struct is_floating_point<long double>
    {
        constexpr static bool value = true;
        constexpr static bool trial = false;
    };

    template <typename T>
    inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

    template <typename T, int S>
    struct collection
    {
    };

    template <typename T>
    struct collection<T, 5>
    {
    };

    template <int S>
    struct collection<int, S>
    {
    };

    // This is a specialization for pointer
    template <typename T, int S>
    struct collection<T *, S>
    {
    };

    // We can restrict arguments to same generic type
    auto lambWithTemplate = [] template <typename T>
                            (T a, T b) -> decltype(a + b)
    {
        return (a + b);
    };

    // We cannot restrict arguments to same generic type
    // unless you do the below
    // This is internally implemented using template<typename>
    auto lambWithAuto = [](auto a, auto b) -> decltype(a + b)
    {
        return (a + b);
    };
    // However, this implies that the type of the second parameter, b, must be convertible
    // to the type of the first parameter, a. This allows us to write the following calls:
    auto lambWithAuto = [](auto a, decltype(a) b) -> decltype(a + b)
    {
        return (a + b);
    };

    // Internal implementation of recursive lambda
    struct ____lambda6
    {
        template <typename T>
        auto operator()(T f, const int n) const
        {
            if (n < 2)
                return -1;
            else
                return n * f(n - 1);
        }

        template <>
        auto operator()(____lambda6 f, const int n) const
        {
            if (n < 2)
                return -1;
            else
                return n * f(n - 1);
        }
    };
    __lambda_6 factorial = __lambda_6{};
    factorial(factorial, 5);
}

#endif

#include <iostream>

void test()
{
    std::cout << svr::is_floating_point<int>::value << '\n';
    std::cout << svr::is_floating_point<float>::value << '\n';
    std::cout << svr::is_floating_point<double>::value << '\n';
    std::cout << svr::is_floating_point<long double>::value << '\n';
    std::cout << svr::is_floating_point<std::string>::value << '\n';
}