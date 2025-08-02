
// Person → Student, Teacher
#include <iostream>          // For input-output stream
using namespace std;

// Base class Person 
class Person {
    protected:
        // Protected member accessible to derived classes 
        string name;
        int age;

    public:
       // Parameterized constructor to initialize name and age
       Person(string n, int a) : name(n), age(a) {}

       // Virtual function to runtime polymorphism
       virtual void display() const {
        cout << "Person: " << name << ", Age: " << age << endl;

       }
};

// Derived class Student inherits publicly from Person
class Student: public Person {
    private:
        string college;                 // Extra data member Specific to Student

    public:
        // Constructor initializes base class and derived class members
        Student(string n, int a, string c) : Person(n, a), college(c) {}
        
        // Overriding display() function of Person class
        void display() const override {
            cout << "Student: " << name << ", Age: " << age << ", College: " << college << endl;

        }
};

// Derived class Teacher inherits publicly from Person
class Teacher: public Person {
    private:
       string subject;                 // Extra data member specific to Teacher

    public:
       // Constructor initializes base class and derived class members
       Teacher(string n, int a, string s): Person(n, a), subject(s) {}
       
       // Overriding display() function of person class
       void display() const override {
        cout << "Teacher: " << name << ", Age: " << age << ", Subject: " << subject << endl;

       }
};

int main() {
    // Polymorphism: base class pointer pointing to derived class object
    Person* p1 = new Student("Ravi", 20, "IIT");
    Person* p2 = new Student("Meena", 35, "Physics");

    // Because display() is virtual, correct derived class is called
    p1->display();                  // calls Student::display()
    p2->display();                  // calls Teacher::display()
    
    // Free dynamically allocated memory
    delete p1;
    delete p2;

    return 0;

}