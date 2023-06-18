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

## Bitwise Shift Operations

Bitwise shift operations on integral operands involve manipulating the individual bits of integer values. These operations allow you to shift the bits either to the left or to the right.

When you perform a left shift (`<<`) operation on an integer, you move the bits towards the left. This effectively multiplies the integer value by a power of 2, depending on the number of positions shifted. Each bit is shifted by the specified number of positions, and the empty bit positions on the right are filled with zeros.

For example, if you have the binary representation `00001010` (decimal 10) and perform a left shift by 2 positions, you get `00101000` (decimal 40).

Conversely, when you perform a right shift (`>>`) operation on an integer, you move the bits towards the right. This effectively divides the integer value by a power of 2, depending on the number of positions shifted. Each bit is shifted by the specified number of positions, and the empty bit positions on the left are filled based on the sign (for signed types) or with zeros (for unsigned types).

Bitwise shift operations are useful in various scenarios, such as manipulating binary flags, performing efficient multiplication or division by powers of 2, or packing/unpacking data in specific formats. They can be used to optimize certain calculations or perform low-level bit manipulations.

Integral operands include: int, unsigned int, short, unsigned short, long, unsigned long long, etc.