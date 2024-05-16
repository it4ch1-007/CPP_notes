#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream> //to use ostringstream


int main(int argc, char* argv[]) {
	int* p(NULL); //initializing a null pointer
	//std::istream_iterator represents the end of the stream given by default
	//std::istream_iterator<int> ifs(std::cin);
	//std::vector<int> v;
	//std::copy(std::istream_iterator<int>(ifs), std::istream_iterator<int>(),std::back_inserter(v)); 
	//for (auto i : v) {
		//std::cout << i << std::endl;
	//}


	//`>>` operator reads the input while it encounters a whitespace symbol




	//ostream_iterator
	std::cout << std::setprecision(3); //this sets the float datatype to have 3 digits after the decimal
	std::fixed(std::cout); //this sets the output datatype as float
	
	std::vector<int> vec = { 0,1,2,3,4,5 };
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout," ! ")); //to copy the whole vector from begin to end to the ostream iterator and output it as cout stream with the separator !

	std::ifstream ifs("to_read.txt"); //this reads the string until a whitespace character is encountered
	std::string s;
	//while (ifs >> s) { //this takes different strings inside the file and give it one by one to the string s 
		//std::cout << s << std::endl;
	//}
	//IF WE USE ISTREAM TO INPUT THE TEXT OF A TEXT FILE INSIDE ANY STRING OR BUFFER USING STREAMS THEN IT GETS STORED INTO IT AND WE CANNOT USE THE SAME STREAM ITERATOR TO STORE THE TEXT INTO ANY VARIABLE
	std::string s2;
	s2.resize(200);
	//while (std::getline(ifs, s2)) {
	//std::cout << s2 << std::endl;
	std::string s3;
	//std::copy(std::istreambuf_iterator<char>(), std::istreambuf_iterator<char>(ifs), std::back_inserter(s3)); //this ensures the strings are added from back of the string like appneding in the list
	//This will not work as the iterator cannot be traced back to the middle or anywhere at the stream buffer pointer

	//std::cout << s3 << std::endl;

	
	//std::copy(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), s2.begin());
	//std::cout << s2 << std::endl;

	//OUTPUTTING FILES

	std::ofstream ofs("to_output.txt");
	std::copy(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), std::ostream_iterator<char> (ofs));
	ofs.close(); //closing the file after use


	//STORING THE  DATA IN SPECIFIC FORMATS
	std::ostringstream ss; //creating an object of the given class ostrinstream
	ss << "The answer to everything is " << 42;
	/*const std::string result = ss.str();*/
	std::cout << ss.str() << std::endl; //converting the whole as a string
	//This syntax will convert eveything into string instead of containing any integers or numbers or any other datatypes


}

//https://riptutorial.com/cplusplus/example/32525/cplusplus-containers-flowchart
// Safe stack is the concept in which the compiler provied two different stacks -> 
// one for the critical data like return addresses and other local variables that should be
// handled carefully and the second for the other provided data inside the program code
// It can be enabled by using `-fsantize = safe-stack` flag when compiling the program code 
// They are used to prevent any stack overflow attacks or the code injection vulnberabilities

//https://clang.llvm.org/extra/clang-tidy/
//clang-tidy is a tool that is used to check the integrity and the quality of the code.
