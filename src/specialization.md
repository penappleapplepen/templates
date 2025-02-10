# Template Specialization
- Specialization refers to providing alternative definitions of the template for certain arguments
- There are two types of Specialization
- The definition created from template instantiation is called a specialization too. We can also have custom defined ones
## Specialization Tricks
- Alias templates cannot be partially or fully specialized, so you might have to add a type inside a class
- Function templates only support full specialization, class templates support full and partial specialization
- When partial specialization of function is required, we use the trick of class partial specialization by having a static function inside a struct and having partial specialization there
## Partial Specialization
- This is an alternative implementation provided for only some of the template parameters
```cpp
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
```

## (Explicit) Full Specialization
- This is a specialization of a template when all the template arguments are provided
- The following can be fully specialized
    1. Function templates including member functions, member function templates
    2. class templates
    3. variable templates including static data members of a class template
```cpp
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
```
