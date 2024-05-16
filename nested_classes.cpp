#include <iostream>


//NESTED CLASSES
struct Outer {
	struct Inner {

	};
	Inner in; //an object of the Inner struct 

};
int main(int argc, char* argv[]) {

	Outer obj;
	Outer::Inner i = obj.in; //Inner classes are accessed using the scope resolution operator

}