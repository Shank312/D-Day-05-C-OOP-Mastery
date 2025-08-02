
#include <iostream>
using namespace std;

// Base class with virtual function 
class Base {
    public:
       // Virtual function: enables runtime polymorphism
       virtual void display() {
        cout<<"Base\n";

       }
};

// Derived class overrides Base::display()
class Derived : public Base {
    public:
       // Override keyword(C++11 and above): ensures you are overriding a virtual function
       void display() override {
        cout<<"Derived\n";
       }
};

// Function that takes a Base class pointer 
void show (Base* b) {
    // Because 'display()' is virtual, the function of the actual object type (Base or Derived) will be called
    b->display(); // If 'b' points to the Derived object, this will call Derived::display()
}

int main() {
    Base baseObj;
    Derived derivedObj;

    // Base class pointer to base object
    show(&baseObj);                      // Output: Base

    // Base class pointer to derived object - polymorphism in the action
    show(&derivedObj);                   // Output: Derived

    return 0;
}
