# Variadic templates
- The ellipsis(...) is used in three different places, with different meanings
    1. To specify a pack of parameters in the template parameters list, as in typename... Args. This is called a template parameter pack. Template parameter packs can be defined for type templates, non-type templates, and template template parameters
    2. To specify a pack of parameters in the function parameters list, as in Args... args. This is called a function parameter pack.
    3. To expand a pack in the body of a function, as in args…, seen in the call min{args…}. This is called a parameter pack expansion. The result of such an expansion is a comma-separated list of zero or more values (or expressions). args... expands to arg1, arg2, arg3, arg4, .... , argn
- **Variadic template trick is to use recursion**
### 1. Parameter pack min
```cpp
// Note that this is using function overloading
// as partial specialization of function templates is not allowed
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
```
- sizeof...(args) returns size of parameter pack whereas sizeof(args)... is sizeof(arg1), sizeof(arg2), ... sizeof(argn). For sizeof(args...), we must give it a context
- Even though template recursion creates a lot of functions, in reality, compiler optimizes a lot of it away. Alternatively, we can use fold expressions
- You can use cppinsights or `__PRETTY_FUNCTION__` to see the generated function
- **Template or function parameter pack can accept 0, 1 or more arguments**
- There is no upper limit, but usually atleast 1024 for template parameter pack and 256 for function parameter pack must be supported
### 2. Using sizeof...(args) and if constexpr
```cpp
template <typename T, typename... Args>
T sumWithIfConstexpr(T a, Args... args)
{
    if constexpr (sizeof...(args) == 0)
        return a;
    else
        return a + sum(args...);
}

template<typename T>
T sumWithRecursion(T val)
{
    return val;
}

template<typename T, typename... Args>
T sumWithRecursion(T val, Args... args)
{
    return val + sumWithRecursion(args...);
}
```
- Note that **`sizeof...(args)` and `sizeof...(Args)`** return the same value
### 3. Using both sizeof...(args) and sizeof(args)...
```cpp
template<typename... Ts>
auto getTypeSizes()
{
    return std::array<size_t, sizeof...(Ts)>{sizeof(Ts)...};
}
```