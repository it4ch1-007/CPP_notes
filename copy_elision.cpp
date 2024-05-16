#include <iostream>


class GFG {
public:
	GFG() { std::cout << "only constructed"; }
	GFG(const GFG&) //This is a copy constructor that takes the object of the type of GFG class and then copies it to the desired object of the same class.
	{
		std::cout << "Copy constructor called";
	}
};

GFG func() {
	return GFG();
}

int main() {
	//When we call a copy constructor then it does'nt only directly copuies the contents into an object but it does way more than that. 
	//It first makes a temporary object that has the contents and then it  copies the contents into that desired object and then destructs the temporary object created.

	//Copy elision is the way to skip this waste creation of an object to increase performance.
	//Here the content is directly copied to the desired object.

	std::string str = std::string("foo"); 
	//Here copy elision occurs due to the same type of the lvalue and the rvalue
	//This is the case of initializing a variable with copy elision
	//Without copy elision, the compiler first makes 2 calls for copy constructors but with copy elision just a move constructor is called and the initialization is done.


	GFG G = func();
	return 0;
}