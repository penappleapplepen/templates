# Introduction to Templates
- Template metaprogramming is a programming technique that uses templates as blueprints for the compiler to generate code and help developers avoid writing repititive code
- The alternative is to use void*, but this is bad practices as we can't know all the types that a function can receive, so we may not be able to cast it properly
### 1. Templated max function
```cpp
template <typename T>
T max(T a, T b)
{
    return ((a < b) ? b : a);
}

int main()
{
  max(5, 6); // calls max<int>(5, 6)
  max<double>(1.0, 2.0); // calls max<double>(1.0, 2.0)
}
```
### 2. Variable template
```cpp
#include <bits/stdc++.h>

template<typename T>
static constexpr T NewLine = T('\n');

int main()
{
  std::wstring test = L"demo";
  test += NewLine<wchar_t>;
  std::wcout << test;

  std::string test2 = "demo";
  test2 += NewLine<char>;
  std::cout << test2;
}
```
