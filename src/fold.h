#ifndef SVR_FOLD
#define SVR_FOLE

#include <iostream>

namespace svr
{
    /**
     * In these two examples with sum and sum_from_zero, 
     * the parameter pack args appears directly within the fold expression. 
     * However, it can be part of an expression, as long as it is not expanded. 
     * This is shown in the following example:
     */
    template <typename... T>
    void printl(T... args)
    {
        (..., (std::cout << args)) << '\n';
    }

    template <typename... T>
    void printr(T... args)
    {
        ((std::cout << args), ...) << '\n';
    }

    template<typename T, typename... Args>
    void push_back_many(std::vector<T>& v, Args&&... args)
    {
        (v.push_back(args), ...);
    }
    push_back_many(v, 1, 2, 3, 4, 5); // v = {1, 2, 3, 4, 5}


    // Alias fold expression
    

    // Variable fold expression
    template<int... R>
    constexpr int sum = (... + R);

    sum<1>;
    sum<1,2>;

}

#endif