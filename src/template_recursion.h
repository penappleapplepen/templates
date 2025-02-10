#ifndef SVR_TEMPLATE_RECURSION
#define SVR_TEMPLATE_RECURSION

namespace svr
{
    // compile time calculation
    template <int N>
    constexpr int template_factorial()
    {
        return N * template_factorial<N - 1>();
    }

    template <>
    constexpr int template_factorial<0>()
    {
        return 1;
    }

    template <int N>
    constexpr int fact = N * fact<N - 1>;

    template <>
    constexpr int fact<0> = 1;

    template <typename T>
    struct wrapper
    {
    };

    template <int N>
    struct manyfold_wrapper
    {
        using value_type = wrapper<typename manyfold_wrapper<N - 1>::value_type>;
    };

    template <>
    struct manyfold_wrapper<0>
    {
        using value_type = unsigned int;
    };
}

#endif

#include <iostream>

void test()
{
    // constexpr int fac = svr::template_factorial<5>();
    // std::cout << svr::fact<5> << "\n";

    std::cout << typeid(svr::manyfold_wrapper<0>::value_type).name() << '\n';
    std::cout << typeid(svr::manyfold_wrapper<1>::value_type).name() << '\n';
    std::cout << typeid(svr::manyfold_wrapper<2>::value_type).name() << '\n';
    std::cout << typeid(svr::manyfold_wrapper<3>::value_type).name() << '\n';
}