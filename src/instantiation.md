# Template Instantiation
- Instantiation refers to compiler generating the actual code when all arguments are substituted for template parameters used in template definition
- Template instantiation can have two forms:

### 1. Implicit instantiation: 
- This occurs when the compiler instantiates a template due to its use in code. This happens only for those combinations or arguments that are in use. For instance, if the compiler encounters the use of `vector<int>` and `vector<double>`, it will instantiate the vector class template for the types int and double and nothing more
### 2. Explicit instantiation: 
- This is a way to explicitly tell the compiler what instantiations of a template to create, even if those instantiations are not explicitly used in your code. This is useful, for instance, when creating library files, because uninstantiated templates are not put into object files. They also help reduce compile times and object sizes, in ways that we will see at a later time. It has two types: Explicit instantiation definition and Explicit instantiation declaration
