#include <bits/stdc++.h>
#include <iostream>

// Forward declaration of class NoDefault
// class NoDefault;

class NoDefault {
public:
    // Constructor that takes an int
    //custom constructor
    NoDefault(int value) : data(value) {
        std::cout << "NoDefault constructor called with value: " << value << std::endl;
    }

    // Other member functions of class NoDefault, if needed

private:
    int data;
};

// Definition of class C
class C {
public:
    // Default constructor for C
    C() : noDefaultMember(42) {}  // Initialize NoDefault member with an int

    // Other member functions of class C, if needed

private:
    NoDefault noDefaultMember;  // Member of type NoDefault
};

// Definition of class NoDefault


int main() {
    // Create an object of class C
    C cObject;

    // Output: NoDefault constructor called with value: 42
    // This confirms that the NoDefault member of class C is properly initialized.
    
    return 0;
}
