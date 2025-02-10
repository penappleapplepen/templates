# Table of Contents
[Introduction](src/introduction.md)
[Template Updates](src/template_updates.md)
[Template Types](src/template_types.md)
[Template Parameters](src/template_parameters.md)
[Template Specialization](src/specialization.md)
[Template Instantiation](src/instantiation.md)
[Template Member Function Examples](src/member_function.md)
[Template Lambda Example](src/template_lambda.md)
[Variadic Template](src/variadic_template.md)

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
