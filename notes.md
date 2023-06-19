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

## Operator Overloading

Similar to function overloading. The number of parameters stay the same though, same for how the parameters are passed to the operators.

If we want to overload the + operator, we do: operator+
for equals, it's: operator==

When overloading operators in classes, we need to think about where our operators go. some of them must be implmented aasa member functions (methods), such as the assignment operator (=) and the index operator ([]). Otherwise, insertion and extraction operators cannot be methods, they must be implemented outside of the class, this is because the left argument for them are the stream classes, and we can't modify them. 

The rest of them can be done either way.


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

## Functions 

C++ functions don't need to belong to a class (aka be methods).

In general, functions that only operate on their parameters should probably not be methods.

Order of functions declared matters to the compiler. The purpose of the include keyword was to put the declarations inside iostream header file in our program. 

Provide a brief comment that explains the purpose of the function when you declare its prototype.

```cpp
//using function prototypes at the top of the file is the preferred approach
double computeTax(double subTotal);
//second approach is to reorder where the functions are written, and those who don't call other funcs are written near the top of the file

//similar to other languages, constants are in all caps and the words are separated by underscores
const double SALES_TAX = 0.15;
```
Function parrameters are passed by value, by default. This means that the data is copied from the caller into the local parameter and any changes won't be reflected in the original. However, C++ provides an option for passing by reference.

To pass by reference, use the & symbol between the type and the name of the variable: int& param.

This way, you pass the reference of the variable to the function, and all changes will be directly done on the original.

to avoid editing variables that shouldn't be modified:
int myFunc(const string& inputParam)

Another cool feature is that C++ allows us to specify default values for a parameter:
double computeTax(double subTotal, double taxRate = 0.0.75);

Important note, default arguments are always the last ones in the function declation (from right to left). 
Also, only specify the default value once (usually in the prototype). You'll get an error if you put the default on the prototype and header of the full function definiton.

```cpp
void computeTax(double subTotal, double& tax, double& total, double taxRate){
    tax = subTotal * taxRate;
    total = subTotal + tax;
}
```

## Arrays

Array declarations in C++ are somewhat similar to java's, but the differences are important. 
```cpp
//here are the declarations of static arrays
int score[10];
double price[NUM_ITEMS];
//the size must be specified
//array size cannot be changed for static arrays
```
C++ have no bounds checking, they don't know how big they are. Buffer overflows are a threat to consider, as you can access elements that are outside your array if you don't pay attention.

In C++, arrays are not initialized for us. 
You can initial arrays like so:
```cpp
//initializing is the one exception to leaving [] empty
char vowels[] = {'a','e','u','i','o'};
int values[10] = {1,2,3,4};
//if our initialized array is smaller than the size, then the rest of it is filled with 0's.

//you can use this to initialize large arrays just by providing an initial value
int counters[100] = {1};
//the other 99 will all be 0.
```

arrays as parameters:
void processArray(int numItems, int arr[]);
Here we don't need to specify the size, as long as it contains integers. Here the numItems is essential, as we can't tell the size of the array inside the function.

We can also pass multi-dimensional arrays like so:
void process3D(int numPerRow, double[][10][10]);
Here we need to specify the size of every dimension but the first one. 

## Strings

Two types of strings: traditional strings from C (called C-strings), and the C++ library string class. 
In general, it's best to avoid using C-strings whenever possible, the string class is more flexible, easier to use and not prone to buffer overflow problems.

Sometimes we have to use c-strings, like the arguments passed from the command-line to the main function (argv). However, it is easy to turn a c-string into a string class object. The string class offers a method that lets us get the C-string version of any string class object.

A cool C library that's available in C++ and is useful no matter the type of the string is <cctype>
The functions in it operate on characters and can be very useful. the functions in it take in characters as argument.

### C-strings

Just an array of characters where the string ends with a null character \0.

So if you're working with c-strings, you must have room in your array for \0.
Except at declaration, = operator won't work to assign the value of a c-string to another variable.

== doesn't work, neither does <=.>=, < or >

However, you can still use C string libraries that are available in C++.

## the string Class

You can use the benefits of operator overloading, so operators like <,>,==,etc. can be used on string objects.
```cpp
//you can use these on string objects
if (name == "Ann"){...}

if (name[0] <= 'M'){...}

major = preferredMajor;
```

Many operations offered by <string>:
- += or append
- insert, erase, replace
- length/size
- clear
- empty (like isEmpty)
- indexing with [] or at
- iterators
- find
- substr
- compare
- c_str (turn string object into a c-string)

non-member functions that work with string objects:
- + (concatenate)
- relational operators (<,>,<=,etc.)
- swap
- << and >>
- getline (from stream into string)

Reading and writing:
you generally write into strings with <<. You can read word by word inside a string wwith >>.
You can read line by line with getline (and you can specify another delimiter than the newline).

characters:
- get
- put
- peek (won't remove the character)
- putback
- ignore

## Pointers

C++ doesn't distinguish between variable types. any kind of variable can live on the stack. Any kind of variable can have a reference, and a pointer.
Pointers are similar to references, the value of a pointer is a memory address. Pointers are what we get in C++ when we dynamically allocate memory using new.

Pointers are different from references. We can see and manipulate the memory address in a pointer, we must explicitely dereference a pointer to get what it is pointing at.

```cpp
//declaring pointers
int *p, *q;
char *str;
Student *stuPtr;
```
Pointer values typically not initialized for you, and the size of a pointer depends on the machine architecture as it is a memory address.

Dereferencing pointers:
int myVal = *ptr;
now myVal will hold the value that ptr was pointing to.
Make sure that the ptr is pointing to a legitimate value(null ptr exception), and make sure it's pointing to an address that is allowed, otherwise you get a segmentation fault.

nullptr for address 000000000.

```cpp
int scoreArray[10];
int *scorePtr = scoreArray;
*scorePtr = 10;
//the first element of scoreArray is now 10
scoreArray[1]=12;
scorePtr[2]=11;
*(scoreArray+3) = 40;
//scoreArray: 10,12,11,40,...

```
Pointer arithmetic:
adding 1 to a pointer changes the memoory address by the size of the target type
for any array: arr[i] == *(arr+i)

### The address operator (&)

It allows us to determine the address of an item in memory.
int v, *ptr;
ptr = &v;

## Dynamic Memory Management in C++

the new operator: it allocates space for a data item in the heap. It then returns a pointer to that item. new can be used with any type.

```cpp
int *myPtr = new int;
string *myStrPtr = new String("Sally");
//new can also be used to create dynamic arrays
int* scores = new int[10];
string *nameArray = new string[24];
//can initialize it too
int *scores = new int[10]{4,5,10,12};
//you can leave out the 10.
```
One big difference between static arrays and dynamic arrays is that dynamic arrays are initialized by default.

Managing dynamic arrays: you need a pointer to the data, the capacity of the array, and the number of items.

Cleaning up:
this isn't an issue for statically allocated variables, as they're cleared from the stack. For dynamically allocated objects, we need to clean up ourselves, as C++ doesn't have a garbage collector. thus, we must free the memory using the **delete** operator.
```cpp
delete myPtr;
delete [] scores;
```
delete doesn't change the value of the pointer or the value of the target. It only tells the system that this memory is no longer in use and may be re-allocated.
```cpp
int *intPtr = new int;
*intPtr = 5;
intPtr = new int;
*intPtr = 10;
/*
Here we have an example of a memory leak. the value of 5 is still on the heap, but we can't access it anymore.
*/
```
When memory leaks accumulate, the program gets more and more slower; I imagine that it's because it gets slowly harder to find free space each time we need to allocate memory for a new item. 

Dangling Pointers: the opposite of the previous situation, having pointers pointing to memory that has already been freed.
One common example is copying the value of a pointer like so: ptr1=ptr2, and then freeing one of them, and then trying to access the other one.

Here we see an example of dynamically increasing the size of an array and assigning new items to it:
```cpp
//three of the arguments are passed by reference
void addItem(int newItem, int*& scores, int& numItems, int& capacity){
    if (numItems == capacity){
        capacity = capacity * 2;
        int* temp = new int[capacity];
        for (int i=0; i< numItems; i++){
            temp[i]=scores[i];
        }
        delete [] scores;
        scores = temp;
    }
    scores[numItems] = newItem;
    numItems++;
}
```

## classes

Class declarations, which typically declare all of the variables and methods for the class. However, we don't actually implement most methods inside the class declaration. Instead, we provide function prototypes and we write the actual methods outside the declaration. Those we do write inside the declaration tend to be very short. 

Class declaration typically goes inside a .h file, while method implementations will go inside of a .cpp file.

So, classes are typically written in a pair of files.

important note: the class declaration must end with a semi-colon ;

We need to associate method implementation with the class that they belong to, which is done by adding the class name and two colons before the method name (class::method).

Other terminology:
Instance variables aand class variables are referred to as data members.
Methods are known asa member functions.

inside constructors, C++ allows aa thing called initializtion list.

functions that we implement inside the class declaration are called inline functions. functions that are 1-2 lines (and don't make lots of function calls), like getters and setters should be inline. Longer functions and those who have other function calls inside of them should me implemented outside.

Separate compilation:
why we separate our code into multiple files. A design pattern. it facilitates reuse of code, instead of extracting a small piece of a file, we take an entire file. Less error-prone. Easier to debug. Keeps us from haaving multiple copies of the same code in a file. New changes become easier to implement.

->
This is the arrow operator, similar to the one in C. When you reference a part of an object that you have a pointer to, use this operator: stuPtr->getMajor();

We need it becaause the . operator has a higher precedence than the dereference operator, so *stuPtr.getMajor() produces an error.
(*stuPtr).getMajor(); this works but everyone uses arrows.

Class varriables/methods:
To declare them, use the static keyword. Class variables are declared similarly, but must be defined outside the class as well, in the .cpp file for the class.

```cpp
//header file date.h

//by default, things inside this class are private.
#include <string>
using namespace std;

class Date{
    private:
        int month;
        int day;
        int year;
        //but we also need to give it some space and initial value
        static int dateCounter;

    public:
        //two constructors here:
        Date();
        //you could also just define it here
        //Date():month(1),day(1),year(2020) {}
        //or use the other constructor we defined:
        //Date(): Date(1,1,2020);

        Date(int thisMonth, int thisDay, int thisYear): month(thisMonth), day(thisDay), year(thisYear) {dateCounter++;}

        //the const is to show the compiler that this method won't change the item
        int getMonth() const {return month;}

        string getShortDate() const;

        void setDay(int day) { this->day = day;}

        static int getNumDates() {return dateCounter;}

        //== takes two arguments, but since this is a method the first argument is represented as the `this` keyword.
        bool operator==(const Date& rhs);

//insertion and extraction operators return a reference to a stream
//thats how we can chain them.
ostream& operator<<(ostream& outStream, const Date& dateToPrint);
};

//and this is the code for date.cpp
//small note, when we include our own .h files, we use double quotes and not <>. The "" tells the precompiler that it should look in the current directory for the file. Whereas the <> tell it to go to the C++ library.
#include "date.h"

//we only need to implement the default constructor and getShortDate()
//Date:: tells us that this constructor/method belongs to the date class
Date::Date(){
    month=1;
    day=1;
    year=2020;
}

int Date::dateCounter = 0;

//still need to add const here as well, if we don't the compiler will complain and think that this is a different function, and we don't have an implementation for the method with const yet.
string Date::getShortDate() const {
    return to_string(day)+"-"+to_string(month)+"-"+to_string(year);
}

bool Date::operator==(const Date& rhs){
    return this->year == rhs.year;
}

ostream& operator<<(ostream& outStream, const Date& dateToPrint){
    return (outStream << dateToPrint.getShortDate());
}

//and inside main.cpp
#include "date.h"

int main(){
    Date defaultDate; //no need for () when instanciating with default constructor in C++

    //the previous one lives on the stack, but you can create them dynamically as well
    //Date* defaultDate = new Date;
    //Date* schoolStart = new Date(8,17,2020);
    //defaultDate->getShortDate();

    Date schoolStart(8,17,2020);
    cout << defaultDate.getShortDate() << "\n";

    //after overloading the << operator
    cout << defaultDate << "\n";

    defaultDate.setDay(20);

    //to use a static method/variable, we need to use the class name
    cout << Date::getNumDates() << endl;
    return 0;
}
```
### the scope operator

in java we have . as the scope operator (myVar.find()), in C++ the scope operator is ::, so:
myVar::find()

### Friends

The class says who its friends are. Friends can access what is private or protected. Controversial feature as some argue that it breaks encapsulation.

## Dynamic Classes

Using dynamic memory comes with memory leaks and dangling memory. With classes, we need to write three methods to make sure that the memory is cleaned up properly: the destructor, the copy constructor, the assignment operator. C++ actually offers default versions of these, but they only work well when we don't have dynamic memory to manage.
Destructor: called when the object is destroyed. (out of scope or someone called delete on it.)

## compilation and execution

Similar to C, you compile your code using gcc or another compiler and run it by doing `./a.out`.

To give a custom name to the executable file, do
`gcc -o app app.cpp`

If you have multiple .cpp files, then you have to compile them all. Good practice is to have a `makefile` file that will run a series of commands and compile everything for you. 

You do not compile .h files.


## Useful sites

cplusplus.com

