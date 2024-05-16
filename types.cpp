#include <iostream>
#include <bitset>
#include <string>

using namespace std;
//Removing the rightmost set bit inside a binary number
template<typename T> //include this and use this template to make sure that the function can be used for any type defined
T rightmostSetBitRemoval(T n) {
	return n & n - 1;
	//static_assert(condition,error{if condition is not fulfilled})
}
//This removes the 1 in the given number to the right most position


//Templates can only be declared in global or namespace scope

int main(int argc, char* argv[]) {
	const char zero = '0';
	const char one = zero + 1;
	std::cout << one << std::endl;

	const float  pi = 3.14592f; //denotes a float integer
	//signed integer range = -32767 to +32767,
	//long integer range = 2**31 - 1 and long long datatype doubles this range


	//wchar_t is the longest wide character set that is stored in the code.

	//Bitset program
	//std::bitset<5> num(std::string("00100")); //<> includes the number of bits that will be used to represent the number in bits
	//num.set(0, true);  // num is now 00101
	//num.set(2, false); // num is now 00001

	//Bit manipulation program to check if a number is the multiple of 2
	int n;
	std::cout << "Enter the number to check: ";
	std::cin >> n;
	bool check = n && !(n & (n - 1));
	std::cout << (check ? "True" : "False") << std::endl;

	//the xth bit of the number can be determined by (n>>x) && 1 that will return the rightmost bit of the number that is obtained 

	std:bitset<4> num(std::string("0010"));
	std::cout << num.test(1) << std::endl;


	//reset and set

	std::bitset<5> num2(std::string("01010"));
	num.reset(1); //makes the bit at the nth position 0
	num.set(3, false); //makes or sets the bit equal to value of true or false
	//the position of the bit starts from the right 


	std::cout << num << std::endl;


	

	std::bitset<12> num4;
	num4.set(); //this sets all the bits to 1
	num4.set(2, false); //setting the bit specifically
	num4.reset(3); //setting the bit to 0
	num4.flip(5); //this is to flip or change the set value of the bit
	std::cout << num4 << std::endl;


	//A trick to swap two variables
	int a = 42;
	int b = 65;

	a = a ^ b;
	b = b ^ a;
	a = a ^ b;

	std::cout << a << " " << b << std::endl;


	//static_cast is also used for explicit type casting but it also provides compiler time check for the type conversion

	unsigned char d = 215;
	unsigned char e = ~a;
	std::cout << "d= " << static_cast<int>(d) << " " << "e= " << static_cast<int>(e) << std::endl;



}