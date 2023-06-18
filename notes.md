## why C++?

C++ is one of the fastest and most efficient programming languages; it's widely used to build applications that are fast and use memory efficiently.

## naming files

Good practice to add the name of the file in a comment at the start of the file. Unlike other languages like Java, there is no expectation as to what the file name is going to be. Java forces you to name your file based on the name of the class it contains, this isn't the case in c++.

So it's good practice to include a comment block that has the name of the file and a description of it's content at the top.

You can also include the name of the dev who wrote the code.

## using libraries

When you use #include, the content of a header file(s) is inserted into your code at the location of the #include directive.

The `#include` directive is a preprocessor directive that tells the C++ compiler to insert the contents of the specified file into your source code at the location of the directive.

When you include a library using `#include`, the compiler reads the contents of the specified file (header file) and processes it during the compilation phase. The header file typically contains function declarations, class definitions, constants, and other declarations required to use the functionalities provided by the library.

During the compilation process, the compiler uses the information from the header file to understand the syntax and declarations of the library components you are using in your code. It does not physically copy the library file itself.

The actual library file (often a compiled binary file with a `.lib`, `.a`, or `.so` extension) is linked to your program during the linking phase of compilation. The linking phase combines your compiled object code with the library code, resolving symbols and references, and creating the final executable file.

So, in summary, the `#include` directive in C++ allows you to include the declarations and definitions from a header file, which facilitates using the functionalities provided by a library, but it does not copy the library file into your code.

## Namespaces

In C++, namespaces are used to organize code into logical groups and prevent naming conflicts.

Basically, it's a declarative region that provides scope for identifiers (variables, functions, classes).
This way, you can create separate, independent containers

std is not a namespace created by the user, but rather provided by the c++ standard library.
-
std::cout           
this refers to the standard output stream
-
std::end1           
end1 is a manipulator used to insert a new line into the output stream

To access elements inside the std space, you need to use the scope resolution operator ::
It specifies that cout and end1 belong to the std namespace.

Example with iostream: once we use the include directive to tell the compiler that we are going to need iostream, we need to make sure we have a way of accessing things inside of iostream. 

There are two ways to go about this. Either we put the name of the iostream namespace before elements from the library every single time  by using the :: operator.

A more convinient approach is to declare that you are using that namespace. You can't use names that are already inside that namespace or you will create conflicts though.

```cpp
#include <iostream>
using namespace std
```

## the main function

the entrypoint to your program, the function that is first run when your program is executed.
It doesn't need arguments: int main(){...}
but it can take an array of strings, just like in C:
int main(int argc, char *argv[]){...}

## the insertion operator

The insertion operator (looks like <<) is an operator used for output operations, specially for sending data to the standard output stream (cout, which stands for character out). It is commonly used to display data on the console or write data to a file.

It takes two operands, the left one is the stream object, where the data will be sent (example cout), and the right expression is the value or expression itself.

### IMPORTANT NOTE 
As you may have noticed, the insertion operator looks the same as the bitwise left shift operator. This is the result of operator overloading.

C++ allows operators to be overloaded; their behavior changes depending on the type of data they are used on.

The behavior of the insertion operator (<<) is determined at compile time.

In C++, operator overloading is a compile-time mechanism. The compiler resolves which overloaded version of the << operator to use based on the types of the operands involved. The appropriate overload is resolved during the compilation phase, and the corresponding code is generated accordingly.


## Bitwise Shift Operations

Bitwise shift operations on integral operands involve manipulating the individual bits of integer values. These operations allow you to shift the bits either to the left or to the right.

When you perform a left shift (`<<`) operation on an integer, you move the bits towards the left. This effectively multiplies the integer value by a power of 2, depending on the number of positions shifted. Each bit is shifted by the specified number of positions, and the empty bit positions on the right are filled with zeros.

For example, if you have the binary representation `00001010` (decimal 10) and perform a left shift by 2 positions, you get `00101000` (decimal 40).

Conversely, when you perform a right shift (`>>`) operation on an integer, you move the bits towards the right. This effectively divides the integer value by a power of 2, depending on the number of positions shifted. Each bit is shifted by the specified number of positions, and the empty bit positions on the left are filled based on the sign (for signed types) or with zeros (for unsigned types).

Bitwise shift operations are useful in various scenarios, such as manipulating binary flags, performing efficient multiplication or division by powers of 2, or packing/unpacking data in specific formats. They can be used to optimize certain calculations or perform low-level bit manipulations.

Integral operands include: int, unsigned int, short, unsigned short, long, unsigned long long, etc.

