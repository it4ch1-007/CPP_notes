#include <iostream>

#define N 10+2 //This will be compiled in compile time and evaluated then and there only but it will appear as (10+2) in the program assembly or decompilation
#ifdef N
std::cout << "Yes,Defined" << std::endl;
#endif



struct Example {
	void func() {
		std::cout << "Not a constant" << std::endl;
	}
	void func() const {
		std::cout << "A constant function" << std::endl;
	}
};

void const_incorrect_function(Example& one, Example* two) {
	one.func();
	two->func();
}

void const_correct_function(const Example& one, const Example* two) {
	one.func();
	two->func();
}
//int getx() const { return 0; } //This is a constant function that will return a constant and cannot modify the instance.
int main() {
	const int var1 = 5; //This declares a variables whose value cannot be changed
	const int& ref = var1; //This declares a reference to the value of the variables var1
	//A constant reference to a constant variable but it is not necessary
	const int* ptr = &var1; //A pointer to a const value 
	//The pointer may made to point anything else but the value at the given referenced data value can never change
	//int* const ptr2 = &var1; //This is the const pointer to a non const value
	//The pointer will point to the same value irrespective of the data value however the data at the same address can change
	const int* const ptr3 = &var1; //Neither the pointer can point to another address and neither the data value at that address can change
	

	Example a, b;
	const_incorrect_function(a, &b); 
	const_correct_function(a, &b);
	//If we have a	constant function then it will try to find the constant returning function too and will execute the function that returns a constant value

	constexpr int N = 10 + 2; //This will be evaluated first in compile time as 12 and then will appear in the program code in the decompilation.
	//The return value of the absolute function is a runtime value and it appears in at runtime and thus it cannot be used as a size descriptor of an array as it should be a constant value described at compile time.
	
	if constexpr(N==12)
}