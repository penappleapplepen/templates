# Types of templates
There are four types of templates, namely:
### 1. Function template
```cpp
template<typename T>
void foo(T val)
{

}
```
### 2. Class template
```cpp
template<typename T>
struct foo{};
```
### 3. Variable template
```cpp
template<typename T>
static constexpr T NewLine = T{'\n'};
```
### 4. Alias template
```cpp
template<typename T>
using Type = T;
```