
// Shape → Rectangle, Circle

#include <iostream>           // For input/output operations
#include <cmath>              // For M_PI constant (value of pi)
using namespace std;

// Base class Shape with virtual area() function
class Shape {
    public: 
       // Virtual function allows dynamic (runtime) polymorphism
       virtual double area() const {
        cout << "Shape::area()\n";                // just for demonstration
        return 0.0;                               // Default implementation

       }
};

// Derived class Rectangle inherits from Shape
class Rectangle : public Shape {
    private:
       double length, width;                     // Private members to hold dimensions
    public:
       // Constructor to initialize length and width
       Rectangle(double l, double w) : length(l), width(w) {}

       // Override the base class's virtual area() function
       double area() const override {
        return length*width;                    // Area of rectangle: length*width
       }
};

// Derived class Circle inherits from Shape
class Circle: public Shape {
    private:
       double radius;                           // Private member to hold radius
    public:
       // Constructor to initialize radius 
       Circle(double r) : radius (r) {}

       // Overrides the base class's virtual area function 
       double area() const override {
        return M_PI*radius*radius;              // Area of circle: Pi*r*r

       }
};

int main() {
    // Create a Rectangle object and assign it to a Shape pointer
    Shape* s1 = new Rectangle(5, 10);           // Rectangle with length 10 and width 5

    // Create a circle object and assign it to a Shape pointer
    Shape* s2 = new Circle(7);                  // Circle with radius 7

    // Since area() is virtual, the correct derived class derived version is called
    cout << "Rectangle Area: " << s1-> area()<< endl;
    cout << "Circle Area: " << s2->area()<< endl;

    // Clean up dynamically allocated memory
    delete s1;
    delete s2;

    return 0;

}