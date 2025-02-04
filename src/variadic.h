#ifndef SVR_VARIADIC
#define SVR_VARIADIC

#include <algorithm>
#include <array>
#include <iostream>

namespace svr
{
    template <typename T>
    T min(T a, T b)
    {
        return std::min(a, b);
    }

    template <typename T, typename... Args>
    T min(T a, Args... args)
    {
        return svr::min(a, min(args...));
    }

    template <typename T, typename... Args>
    T sum(T a, Args... args)
    {
        if constexpr (sizeof...(args) == 0)
            return a;
        else
            return a + sum(args...);
    }

    template <typename... Ts>
    constexpr auto get_type_sizes()
    {
        return std::array<std::size_t, sizeof...(Ts)>{sizeof(Ts)...};
    }

    template <typename... Ts, typename... Us>
    constexpr auto multipacks(Ts... args1, Us... args2)
    {
        // If we want parameter packs of equal sizes
        // static_assert(sizeof...(args1) == sizeof...(args2))
        std::cout << sizeof...(args1) << " " << sizeof...(args2) << "\n";
    }

    // template parameter list
    template <typename... T>
    struct outer
    {
        template <T... args>
        struct inner
        {
        };
    };

    // template argument list
    template <typename... T>
    struct tag
    {
    };
    template <typename T, typename U, typename... Args>
    void tagger()
    {
        tag<T, U, Args...> t1;
        tag<T, Args..., U> t2;
        tag<Args..., T, U> t3;
        tag<U, T, Args...> t4;
    }

    // function parameter list
    template <typename... Args>
    void make_it(Args... args)
    {
    }
    make_it(42);
    make_it(42, 'a');

    // function argument list
    template <typename T>
    T step_it(T value)
    {

        return value + 1;
    }

    template <typename... T>
    int sum(T... args)
    {
        return (... + args);
    }

    template <typename... T>
    void do_sums(T... args)
    {
        auto s1 = sum(args...);
        // sum(1, 2, 3, 4)
        auto s2 = sum(42, args...);
        // sum(42, 1, 2, 3, 4)
        auto s3 = sum(step_it(args)...);
        // sum(step_it(1), step_it(2),... step_it(4))
    }
    do_sums(1, 2, 3, 4);
}

#endif

#include <iostream>

void test()
{
    std::cout << "Min: " << svr::min(1, 2, 3, 4, 5, 6, -1) << "\n";

    std::cout << "Sum: " << svr::sum(1, 2, 3, 4) << "\n";

    auto sizes = svr::get_type_sizes<short, int, long, long long>();

    svr::multipacks<int>(1, 2, 3, 4);
    svr::multipacks<int, int>(1, 2, 3, 4);
    svr::multipacks(1, 2, 3, 4);
    svr::multipacks<int, int, int, int>(1, 2, 3, 4);

    svr::outer<int, double, char[5]> a;
}