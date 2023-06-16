#include <iostream>
#include <string>

//using namespace std;

class Human{
    //attributes are private by default
    float dna;

    public:
        string face;
        void walk() {
            cout << "I'm taking a walk";
        }

    //c++ also supports method overloading
    Human() {
        // constructor
    }

    ~Human() {
        //destructor
    }
};

//its also possible to define methods outside the
//class using the double colon method

//not sure if this is good practice though
void Human::run() {
    cout << "Now I'm running!";
}