#include <iostream>
//to handle input/output
#include <string>

using namespace std;

//code starts executing from the main func
int main(){
    //use standard character output 
    // << is the  bitwise shift left operator
    std::cout << "Welcome to C++!";
    
    //got rid of std by using a namespace

    //strings can be an array of characters
    char mystr[] = "this is a string.";

    string newstr = "this is another string";

    Human Sam; //instanciate class i made
    //constructor can take parameters optionally

    //when it comes to memory, we can manage everything manually
    Human* myPtr = new Human;

    delete myPtr; //deallocate memory

    //however tools like unique pointers can 
    //get the job done easier and safer
    unique_ptr<Human> ptrSam(new Human);
    //this ensures that only one object can be allocated 
    //to memory
    cout << ptrJeff->foo;

    return 0;
}

/*
bitwise shift left/shift right operators (<< >>)



*/