# Types of template parameters
- For all template parameter types, you can specify default
- There are three types of template parameters
### 1. Template Type Parameter
```cpp
// You could use class instead of typename
// template<class T>
template<typename T>
class TypeParameter
{

};

int main()
{
  TypeParameter<int> t;
}
```
### 2. Template Non-type Parameter
- This is very important for std::array because we cannot take in the size from the constructor
- C++17 allows auto
- The following types are allowed along with cv-qualified forms
  1. integral types
  2. floating-point types, as of c++20
  3. enumerations
  4. pointer to objects/functions/member objects/member functions
  5. l-value reference to objects/functions
  6. class types
 - We could pass std::string using class types

```cpp
/*
  auto can take any kind of value
  Other non-types such as int, float, char, double
*/
template<auto T>
class NonTypeParameter
{
};

int main()
{
  NonTypeParameter<5> a;
  NonTypeParameter<4.5> b;
}
```
### 3. Template Template Parameter
```cpp
// Note that we can only pass a type that is itself a template
template<typename T>
class simple_wrapper
{
    public:
        T value;
};

template<typename T>
class fancy_wrapper
{
    public:
        void foo()
        {

        }
    private:
        T value;
};

template<typename T, typename U, template<typename> typename W = fancy_wrapper>
class TemplateTypeParameter
{

};

int main()
{
  TemplateTypeParameter<int, int, simple_wrapper> tt;
}
```
