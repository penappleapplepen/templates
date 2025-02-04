#ifndef PARAMETER_TYPES
#define PARAMETER_TYPES

#include<memory>

namespace svr
{
    // Can take any type
    template<typename T>
    class TypeParameter
    {

    };

    // Can take any value
    // Useful for array[n] because if you take n from constructor
    // it would need to be on the heap
    template<auto T>
    class NonTypeParameter
    {

    };


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
            const T& get() &
            {
                return value;
            }
            T& get() &
            {
                return value;
            }

            T get() &&
            {
                return std::move(value);
            }
        private:
            T value;
    };

    template<typename T, typename U, template<typename> typename W = fancy_wrapper>
    class TemplateTypeParameter
    {

    };
}

#endif

#include <iostream>

void test()
{
    svr::TypeParameter<int> t;
    svr::NonTypeParameter<5> nt;
    svr::TemplateTypeParameter<decltype(t), decltype(nt), svr::simple_wrapper> tt;
    std::cout << "Success";
}