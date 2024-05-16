#include <iostream>

using namespace std;
class Foo {
public:
	//default constructor
	Foo(int data) {
		this->data = data;
	}
	//destructor
	~Foo(){}
	//Assignment operator
	Foo& operator=(const Foo& rhs)
	{
		std::cout << "Assigning" << std::endl;
		data = rhs.data;
		return *this;
	}
	//Copy constructor
	Foo(const Foo& rhs) {
		std::cout << "Copying" << std::endl;
		data = rhs.data;
	}
	int data;
	//The diff between copy and assignment are that in copy we need niot initialize the object while during assginment we have to first initialize the object instance and then assign any value to it .

};
//class MyClass {
//public:
//
//
//	//Copy constructors
//	//The volatile variables are those which cannot be changes or modified by the compiler itself or any user appplication cannot modify it and it can only be modified by the code outside ths scope of the current variable.
//
//	MyClass(const MyClass& other);
//	MyClass(MyClass& other);
//	MyClass(volatile const MyClass& other);
//	MyClass(volatile MyClass& other);
//
//	//Assignment Operators
//	//These replace the data between the objects.
//	MyClass& operator = (const MyClass& rhs);
//	MyClass& operator = (MyClass& rhs);
//	MyClass& operator = (MyClass rhs);
//	const MyClass& operator = (const MyClass& rhs);
//	const MyClass& operator = (MyClass& rhs);
//	const MyClass& operator = (MyClass rhs);
//	MyClass operator = (const MyClass& rhs);
//	MyClass operator = (MyClass& rhs);
//	MyClass operator = (MyClass rhs);
//
//
//};
int main() {

	Foo foo(2);
	Foo foo2(50); // using an assignment operator
	Foo foo3 = foo; //using a copy constructor
	foo2 = foo;
	std::cout << foo2.data << std::endl;
	std::cout << foo3.data << std::endl;


	Foo obj1(0);
	Foo obj2(1);
	obj2 = obj1;
	std::cout << obj2.data << std::endl;

	Foo obj3 = obj1; //copying is done at the time of initialisation
	//obj3 = obj1;
	std::cout << obj3.data << std::endl;


	//IF DONE WITH INITIALIZATION THEN IT IS ASSIGNMENT , AND IF DONE WITHOUT ASSIGNMENT THEN IT IS COPYING THE DATA.

}