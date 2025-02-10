#ifndef SVR_NAME_BINDING
#define SVR_NAME_BINDING

#include <iostream>

namespace svr
{
    template <typename T>
    struct nonDependentParser; // [1] template declaration
    void handle(double value)  // [2] handle(double) definition
    {
        std::cout << "processing a double: " << value << '\n';
    }
    template <typename T>
    struct nonDependentParser // [3] template definition
    {
        void parse()
        {
            handle(42); // [4] non-dependent name
        }
    };
    void handle(int value) // [5] handle(int) definition
    {
        std::cout << "processing an int: " << value << '\n';
    }

    template <typename T>
    struct dependentHandler // [1] template definition
    {
        void handle(T value)
        {
            std::cout << "not this one dependentHandler<T>: " << value << '\n';
        }
    };

    struct dependentParser // [2] template definition
    {
        template <typename T>
        void parse(T arg)
        {
            arg.handle(42); // [3] dependent name
        }
    };
    template <>
    struct dependentHandler<int> // [4] template specialization
    {
        void handle(int value)
        {
            std::cout << "dependentHandler<int>: " << value << '\n';
        }
    };

    template <typename T>
    struct base_parser
    {
        void init()
        {
            std::cout << "Base template \n";
        }
    };

    template <typename T>
    struct parser : base_parser<T>
    {
        void foo()
        {
            /**
             * Although base_parser<T>::init() exists
             * compiler doesn't find it because base_parser
             * can be later specialized and that function can be removed also
             * It could be a free function also
             */
            // init();
            base_parser<T>::init();
        }
    };

    template <>
    struct base_parser<int>
    {
    };

    template <typename T>
    struct base_parser2
    {
        using value_type = T;
    };

    template <typename T>
    struct parser2 : public base_parser2<T>
    {
        value_type v{};                   // Error because non-dependant name
        base_parser2<T>::value_type v1{}; // Error because specialzation
        // can have a static variable
        typename base_parser2<T>::value_type v2{}; // Will work
    };

    template <>
    struct base_parser2<int>
    {
        const static int value_type = 0;
    };

    // Dependant template names
    // function example
    template <typename T>
    struct base_parser3
    {
        template <typename U>
        void init()
        {
        }
    };

    template <typename T>
    struct parser3 : base_parser<T>
    {
        void foo()
        {
            /**
             * Error because base_parser<int>::init is considered
             * a value and it does < comparison, so below line actuall
             * read by compiler as
             * base_parser<int>::init   <   int>();
             */
            base_parser<T>::init<int>();          // error
            base_parser<T>::template init<int>(); // correct
        }
    };

    // class example
    template <typename T>
    struct base_parser4
    {
        template <typename U>
        struct inner
        {
        };
    };

    template <typename T>
    struct parser4 : base_parser4<T>
    {
        void foo()
        {
            typename base_parser4<T>::template inner<int> var{};
        }
    };

    template <typename T>
    struct parser5
    {
        // CI -> current instantiation
        parser5 *p1;      // parser is the CI
        parser5<T> *p2;   // parser<T> is the CI
        ::parser5<T> *p3; // ::parser<T> is the CI
        parser5<T *> p4;  // parser<T*> is not the CI
        struct token
        {
            token *t1;            // token is the CI
            parser5<T>::token *t2; // parser<T>::token is the CI
            typename parser5<T *>::token *t3;
            // parser<T*>::token is not the CI
        };
    };
    template <typename T>
    struct parser6<T *>
    {
        parser6<T *> *p1; // parser<T*> is the CI
        parser6<T> *p2;   // parser<T> is not the CI
    };
}

#endif

void test()
{
    svr::nonDependentParser<int> p1;
    p1.parse();
    svr::dependentHandler<int> h;
    svr::dependentParser p2;
    p2.parse(h);

    svr::parser<int> p;
    p.foo();
}