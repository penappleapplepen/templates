# Types of template parameters
There are three types of template parameters
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