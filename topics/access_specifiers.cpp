
#include <iostream>
using namespace std;

// Base class A
class A {
    public:
        int pub = 1;                 // public member - accessible anywhere (inside and outside class)
    protected:
        int prot = 2;                // protected member - only accessible inside the class and its derived classes
    private:
        int priv = 3;                // private member - accessible only in the class A

};

// Derived class B inherits publicly from A
class B : public A {
    public:
      void show() {
        // This function is a member of derived class B
        // So let's see what it can access from class A:

        cout<<pub<<endl;         // Allowed: public member of A  remains public in B
        cout<<prot<<endl;        // Allowed: protected members of A become protected in B
                                 // And since we're inside class B, we can access protected members
    //  cout<<priv<<endl;        // Error: private members of A are not inherited at all
                                 // They are not accessible in B, not even inside member functions     

    }
};

int main() {
    B obj;
    obj.show();
    return 0;
}