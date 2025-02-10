# Table of Contents
[Introduction](src/introduction.md)

- T is called a type template parameter
- There can be four types of templates: 
    - function template
    - class template
    - variable template
    - alias template
- There can be three types of template parameters: 
    - Type template parameters, such as in template<typename T>, where the parameter represents a type specified when the template is used.
    - Non-type template parameters, such as in template<size_t N> or template<auto n>, where each parameter must have a structural type, which includes integral types, floating-point types (as for C++20), pointer types, enumeration types, lvalue reference types, and others.
    - Template template parameters, such as in template<typename K, typename V, template<typename> typename C>, where the type of a parameter is another template.
- There can be two types of specialization
    -  Partial specialization: This is an alternative implementation provided for only some of the template parameters.
    - (Explicit) full specialization: This is a specialization of a template when all the template arguments are provided.
- Template instantiation can have two forms:
    - Implicit instantiation: This occurs when the compiler instantiates a template due to its use in code. This happens only for those combinations or arguments that are in use. For instance, if the compiler encounters the use of vector<int> and vector<double>, it will instantiate the vector class template for the types int and double and nothing more.
    - Explicit instantiation: This is a way to explicitly tell the compiler what instantiations of a template to create, even if those instantiations are not explicitly used in your code. This is useful, for instance, when creating library files, because uninstantiated templates are not put into object files. They also help reduce compile times and object sizes, in ways that we will see at a later time. It has two types: Explicit instantiation definition and Explicit instantiation declaration
- For value, you can use variable template and for types, you can use alias templates. Alias templates cannot be partially or fully specialized, so you might have to add a type inside a class. Function templates only support full specialization, class templates support full and partial specialization
- Variadic templates
    - To specify a pack of parameters in the template parameters list, as in typename... Args. This is called a template parameter pack. Template parameter packs can be defined for type templates, non-type templates, and template template parameters.
    - To specify a pack of parameters in the function parameters list, as in Args... args. This is called a function parameter pack.
    - To expand a pack in the body of a function, as in args…, seen in the call min(args…). This is called a parameter pack expansion. The result of such an expansion is a comma-separated list of zero or more values (or expressions). This topic will be covered in more detail in the next section.
- Use __PRETTY_FUNCTION__ to see the generated function
- Standard doesn't limit parameter pack max, but compilers might. Standard recommends minimum instead. Use sizeof to get size of parameter packs
- sizeof...(args) or sizeof...(Args) gives size of parameter pack, but sizeof(args)... gives sizeof(args) multiple times
- When partial specialization of function is required, we use the trick of class partial specialization by having a static function inside a struct and having partial specialization there
- Name binding for non-dependant names happens at template definition and for dependent names at template instantiation
- Two phase name lookup: First phase template syntax and non-dependant names. Second phase dependant names binding 
- No name lookup happens in base class for non-dependant names. You can make it dependant name by calling "this->" or "base_parser<T>::"
- template keyword can follow ::, . or -> operator within class for calling function
- There can be a 1024 limit on template recursion depth
- Since C++20, make functions consteval if they shouldn't be used at runtime
- Before C++17, there was no class template argument deduction, so make_pair functions
helped by using function template argument deduction which was supported before, but beward of differences. Sometimes copy constructor is called instead of normal constructor. You can also write custom deduction guide in same namespace
- You can also use deduction guides when compiler parameters and class type deduction must be different
- T&& is universal references, but const T&& is not. It has to be just T&&
- Using auto&& for variable assignment or in loop means universal reference, but not const auto&&
