# Template Lambda
- Provides a way to use templates in lambdas
- C++11 introduced lambdas
- C++14 allowed use of auto keyword in lambdas
- C++20 allows template lambdas
### Template lambda
```cpp
auto lambWithTemplate = [] template <typename T>
                            (T a, T b) -> decltype(a + b)
{
    return (a + b);
};

// This is not equivalent because b could be convertible to type of a
auto lambWithAuto = [](auto a, decltype(a) b) -> decltype(a + b)
{
    return (a + b);
};

int main()
{
    lambWithTemplate(42, 1.0); // Error
    lambWithAuto(42, 1.0); // Allowed
}
```
### Templates make it possible to take std::array in lambdas
- This is not possible to restrict with lambdas
```cpp
auto l = []template<typename T, size_t N>(
    std::array<T,N> &arr
)
{

};

// Compiler generates this
struct __lambda
{
    template<typename T, size_t N>
    auto operator()(std::array<T,N> &arr)
    {
        
    }
};

int main()
{
    l(std::array<int,3>{1, 2, 3});
}
```
### Recursive template lambda internal implementation
```cpp
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
```
