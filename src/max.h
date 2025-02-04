#ifndef SVR_MAX
#define SVR_MAX

namespace svr
{
    template <typename T>
    T max(T a, T b)
    {
        return ((a < b) ? b : a);
    }

    template<typename T>
    constexpr T NewLine = T('\n');
}

#endif

#include <iostream>
#include <cstring>

void test()
{
    // This would generate svr::max<double>(double a, double b)
    // Note how <double> is part of function signature
    // You can also call it svr::max<double>(5.55, 6.0)
    // to make it explicit what you want
    // you can also do svr::max<double>(5.5, 6);
    std::cout << svr::max<double>(5.55, 6.0) << std::endl;

    std::wstring word = L"demo";
    word += svr::NewLine<wchar_t>;
    std::wcout << word << std::endl;
}