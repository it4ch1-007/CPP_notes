#include <iostream>


//STACK UNWINDING
void f1()  throw(int) { //The throw here makes the function able to throw an error in the form of an integer 
	std::cout << "f1 called()" << std::endl;
	throw 100;
}
void f2() throw(int) {
	f1();
	std::cout << "f2 called" << std::endl; //This function does not contain any excpetion handling block and thus it will not be called but due to stack unwinding it will be removed from the function call stack

}
void f3() {
	f2();
	//the exception handling block that makes the f3() function to handle the exception raised by f1() function and thus this function is called next in the function call stack.
	/*try {
		
	}
	catch (int i) {
		std::cout << "Exception called" << std::endl;
	}*/
	std::cout << "f3 called" << std::endl;
}
int main() {
	f3();
	getchar(); //To wait the program to finish all the function calls

	//Here the f2() function will not be called
	return 0;

}