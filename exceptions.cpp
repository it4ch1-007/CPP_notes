#include <iostream>
#include <string>

class B {
	B() {

	}
};
class Foo {

};
struct A :public B {
	A() try : B(), foo(1){
		//This is a special type of constructor that initializes the object foo of class Foo and first calls the constructor of the B class from its own constructor and then does initialization and throws error if any found.

	}
	//This is a destructor for the given class 
	~A() noexcept(false) try {
		noexcept keyword is the keyword which specifies in runtime of the expression inside it is gonna throw error or not during runtime.
		/*The destructor will throw error once there is a problem when the object is being destroyed.

		However we cannot throw any error during stack unwinding that is when the objects are being destroyed then we cannot throw error as it may call std::terminate

		STACK UNWINDING is the process of destructing the objects that are made inside the try catch block in the order reverse of their creation.
		This happens for all the automatic objects.
*/

	}
	catch ()
	{

	}
private:
	Foo foo;
};
int main() {
	try {
		throw new std::runtime_error("Error!");//This error occurs inside the heap and makes us to manage the memory on our own.
		throw std::runtime_error("Error on the stack!");
	}
	catch(const std::runtime_error& e) {
		std::cout << e.what() << std::endl;//this tells us what type of error has occured
	}

	std::string str("foo");
	try {
		str.reserve(2);
		/*The reserve keyword is to specify atleast how many elements are gonna be there inside a vector
		*///It reduces the time and complexity of the program as it is better than the case where we will push the elements inside the vector and donot know the actual size of the vector.
		str.at(10); //This will throw error due to the out_of_range element access.
	}
	//The catch clauses are all executed in order
	catch (const std::length_error& e) {
		std::cout << e.what()<<std::endl;
		//This error will occur due to the reserve keyword reserving less space than the space the vector in initialised with.

	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		//This condition will make sure that the program prints the error even when we donot know what the error is
		std::cout << e.what() << std::endl;
	}

	try {
		throw std::runtime_error("hello");
	}
	//Only one Whole exception is printed due to the runtime_error also coming in the category of exception but not declared after this.
	
	catch (const std::exception& e) {
		std::cout << "Whole exception";
	}
	//If declared before then this will be executed
	catch (const std::runtime_error& e) {
		std::cout << "runtime_error";
	}
	
}