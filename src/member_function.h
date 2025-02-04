#ifndef SVR_MEMBER_FUNCTION
#define SVR_MEMBER_FUNCTION

// template member function on 
// template class
template<typename T>
class composition1
{
    public:
        T add(const T a, const T b)
        {
            return a + b;
        }
};

// template member function
// on non-template class
class composition2
{
    public:
        template<typename T>
        T add(const T a, const T b)
        {
            return a + b;
        }
};

template<typename T>
class composition3
{
    public:
        template<typename U>
        U add(const T a, const T b);
};

template<typename T>
template<typename U>
U composition3<T>::add(const T a, const T b)
{
    return static_cast<U>(a + b);
}

#endif

#include <iostream>

void test()
{
    composition1<int> a;
    composition2 b;
    composition3<int> c;
    std::cout << a.add(1, 2);
    std::cout << b.add<int>(1, 2);
    std::cout << c.add<int>(3, 5);
}