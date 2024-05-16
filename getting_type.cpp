#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	std::vector<int>::iterator iter1; //This is how to make iterator of the vector
	decltype(vec)::iterator iter2; //this decltype(vec) basically returns the type of the inside expressions defined inside the brackets.

	decltype(vec.begin()) iter3; //This will give the type of the begin() that is an iterator inside the vector named vec but will not assign any value to the iter variables.
	int a;
	decltype(a) b; //This decalres the b variable with the same type as variable a
	b = 5;
}