#include <iostream>
#include <vector>
#include <sstream>



//Functors are the instances when the structs are called as functions instead of simple structs

struct Person {
	std::string name;
	unsigned int age;
};

struct FindPersonByName {
	FindPersonByName(const std::string &name) : _name(name) {} //This is the definition of the default constructor that sets the value of the variables name here 


	//Now we are going to overload the default constructor of the struct to set its behaviour when it is called as a simple function and thus called functors.
	bool operator()(const Person& person) const {
		return person.name == _name;
	}
private:
	std::string _name;
};
void globalFn() {
	std::cout << "Called the Global Function: \n" << std::endl;
}
class Random {
	void localFunction(int data) {
		std::cout << data << std::endl;
	}
	static void staticFunction(int data, std::string s) {
		std::ostringstream ss;
		ss << s << data;
		std::cout << ss.str() << std::endl;
	}
};
int main(int argc, char* argv[]) {

	std::vector<Person> v; //A vector containing the objects of the Person class
	std::vector<Person>::iterator iFind = std::find_if(v.begin(), v.end(), FindPersonByName("Rajveer"));
	//Here the "Rajveer" is passed as an argument and thus first the _name will be set to the "Rajveer" and then as the Person object is being compared thus the overloaded function will be called and then 


}