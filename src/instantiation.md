# Template Instantiation
- Instantiation refers to compiler generating the actual code when all arguments are substituted for template parameters used in template definition
- Template instantiation can have two forms:

## 1. Implicit instantiation: 
- This occurs when the compiler instantiates a template due to its use in code. This happens only for those combinations or arguments that are in use. For instance, if the compiler encounters the use of `vector<int>` and `vector<double>`, it will instantiate the vector class template for the types int and double and nothing more
### a) Compiler only instantiates what is called, and declares the rest
```cpp
template<typename T>
struct Implicit
{
    void foo()
    {

    }
};

template<>
struct Implicit<int>
{
  // Declared, not defined
  inline void foo();
};

int main()
{
    Implicit<int> i;
}
```
### b) Compiler doesn't even instantiate in case complete type is not required. For example in pointers
```cpp
template<typename T>
struct Implicit
{
    void foo()
    {

    }
};
// No instantiation
int main()
{
    Implicit<int>* i;
}
```
## 2. Explicit instantiation: 
- This is a way to explicitly tell the compiler what instantiations of a template to create, even if those instantiations are not explicitly used in your code. This is useful, for instance, when creating library files, because uninstantiated templates are not put into object files. They also help reduce compile times and object sizes, in ways that we will see at a later time. It has two types: Explicit instantiation definition and Explicit instantiation declaration
- This can be done for both class and function templates
### a) Explicit instantiation definition
```cpp
template<typename T>
struct wrapper
{
    T value;
};

// Explicit instantiation definition
template struct wrapper<int>;
```
### b) Explicit instantiation declaration
- Class definition is visible in all translation units, but the actual instantiation happens in just one and the linker makes sure to find the definition
- This reduces compilation times and object file size
- You can add extern in header file and make just one cpp file explicitly instantiate the template
```cpp
template<typename T>
struct wrapper
{
    T value;
};

// Explicit instantiation definition
extern template struct wrapper<int>;
```
