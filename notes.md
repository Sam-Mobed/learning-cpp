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

## Input/Output

Standard input stream is **cin**
Standard output stream is **cout**

Insertion operator is **<<** to write to an output stream.
Extraction operator **>>** which reads in data. The right-hand side is going to be the variable where we will store the data.

A good way to remember which is which: the left-hand side is always cin or cout, so the arrows show which direction the data is moving from. 

### '\n' vs endl 
(endl for endline), this is an alternative to \n, and we use it in some instances. when we transfer data in and out of a program, it doesn't work character by character or word by word. The chunk of data that is transfered depends on the specifics of the computer achitecture, but usually half a kilobyte(512 bytes). 

Input and output are expensive, we don't write data directly to the screen or a file, instead the data goes to an output buffer (or conversely, an input buffer). This buffer can be thought of as an array of data.

When you write/read what's inside the buffer is called **flushing the buffer**.

What `endl` does is that it forces the flush of the buffer, so whether you're done or out, it clears the buffer and outputs the data to the output stream. `\n` does not flush the buffer. 

In many cases we don't want to flush the buffer, cause it will be less efficient. But sometimes we do.

Example: if our program is crashing and we want to add print statements to help us figure out where the problem is, we need to use `endl` at the end of those print statements to make sure our debugging output actually gets to the screen or file before our program crashes, or we might think the crash happens at the wrong time. (since the print statements will go to the output buffer, and the crash might happen before the buffer gets flushed.)

```cpp
int age;
cout << "What is your age?";
cin >> age;
cout << "Your age is " << age << endl;
```
Here, when the user enters the input, the `cin` object attempts to parse it as an integer (based on the type of the `age` variable), expecting the input to match the type. If the input cannot be parsed, there might be an error or unexpected behavior. 

## basic types

Mostly similar to C and Java. 
short and long are type modifiers in C++, as opposed to separate types.
(you can use short alone in a declaration, but technically the type is `short int`, same goes for long)
There's quite a lot of combinations, and variations based on the architecture. So you have to take this into account when writing code.

**sizeof** operator can be used to determine the size of any type including an int. 

Another difference in C++ is that integers and char can be signed or unsigned. They are signed by default. To changed that: `unsigned int` or `unsigned char`. This is used in places where we know that we won't need the support of negative numbers, and we would like bigger positive numbers.

for a 4-byte int:
Signed: -2,147,483,648 to 2,147,483,647
Unsigned: 0 to 4,294,967,295

Another type is that char type is only 1 byte, so it covers ASCII only.
However, there is wchar_t for wider character types (such as Unicode).
In C++, similar to C, a char is treated like another kind of int.

**bool** and **void** are two other types in C++, self explanatory. void is mostly used in relation to pointer variables.

Boolean expressions don't need to be of type bool: 0 is false, **everything else is true**.

```cpp
if (3 < a < 8) //always true
//it will do 3<a, and whether a is smaller or bigger than 3(0 for false, 1 for true), the result will always be smaller than 8
if (a=9)//always true
if (c=0)//always false.
```

## constants

Use keyword const to declare constant values. Must set the value when the constant is declared.
## compilation and execution

Similar to C, you compile your code using gcc or another compiler and run it by doing `./a.out`.

To give a custom name to the executable file, do
`gcc -o app app.cpp`

