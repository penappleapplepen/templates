#ifndef SVR_INSTANTIATION
#define SVR_INSTANTIATION

namespace svr
{
    // Implicit is when you use it in program
    // Only used parts will be compiled
    template<typename T>
    struct Implicit
    {
        void foo()
        {

        }
    };

    // Explicit instantiation definition is done
    // with template keyword at the beginning
    template<typename T>
    struct wrapper
    {
        T value;
    };

    // Explicit instantiation definition
    template struct wrapper<int>;

    // Explicit instantiation definition
    // for function template
    template<typename T>
    T add(T a, T b)
    {
        return a + b;
    }

    template int add(int, int);
}

#endif

// Explicit instantiation definition should only happen
// at namespace scope
template struct svr::wrapper<double>;
template double svr::add(double, double);
// Explicit instantiation declaration
// You can add this in header file and just one 
// template float svr::add(float, float) in any cpp file
// This makes sure that all cpp files see the declaration
// but they can also allocate space on stack since they see 
// the template structure. There is no code generation, just
// type inference
extern template float svr::add(float, float);

void test()
{
    // foo() is not instantiated
    svr::Implicit<int> imp;
}