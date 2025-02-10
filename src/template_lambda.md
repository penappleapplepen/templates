# Template Lambda
- Provides a way to use templates in lambdas
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
