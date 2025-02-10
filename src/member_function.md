# Member function templates
### 1. Regular member function that is a member of class template
```cpp
template<typename T>
class composition
{
    public:
        T add(const T a, const T b)
        {
            return a + b;
        }
};

int main()
{
    composition<int> c;
    c.add(5, 6);
}
```
### 2. Member function template on a regular class
```cpp
class composition
{
    public:
        template<typename T>
        T add(const T a, const T b)
        {
            return a + b;
        }
};

int main()
{
    composition c;
    c.add<int>(5, 6);
}
```
### 3. Member function template on class template
```cpp
template<typename T>
class composition
{
    public:
        template<typename U>
        U add(const T a, const T b);
};

template<typename T>
template<typename U>
U composition<T>::add(const T a, const T b)
{
    return static_cast<U>(a + b);
}

int main()
{
    composition<int> c;
    c.add<double>(5, 6);
}
```