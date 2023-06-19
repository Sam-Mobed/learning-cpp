#include <string>

//inheritance
class Child: public Human {
    public:
        string headwear = "Hat";
        void whine(){
            cout << "I want ice cream!";
        }

};