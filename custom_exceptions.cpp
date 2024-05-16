#include <iostream>
#include <exception>


//overriding the Except class in the standard library
class Except : virtual public std::exception {
protected:
	int error_num;
	int error_offset;
	std::string error_message;

public:
	//making a constructor that will initialize all the basic details of the error like its number and the id details and the message it should display as default.
	explicit
	Except(const std::string& msg,int err_num,int err_off):
		error_num(err_num),
		error_offset(err_off),
		error_message(msg)
	{}
	//explicit is used to not allow the compiler to change its type on its own and not confuse between the types.

	virtual ~Except() throw(){} //this is a virtual destructor if any of the derived class define its own destructor then it will be called instead of this destructor.


	//overloading the what() method to make sure that when what() is called then the error will do what we want
	virtual const char* what() const throw() {
		return error_message.c_str();
	}


	//This we will also overload to make sure that when we call getErrorNumber then we will be able to get what we want
	virtual int getErrorNumber() const throw() {
		return error_num;
	}

	//Also overload the getErrorOffset method
	virtual int getErrorOffset() const throw() {
		return error_offset;
	}
};


//throw keyword is simply used to throw any error based on its arguments are the type of error , the message to show and the ids and the offset of the error type.


int main() {
	//For creating custom exceptions we will simply overkload the what() operator and the Except class to define new results imported from the standard exception class 

	try {
		throw(Except("This is a custom error created", 12, 34));
	}
	catch (const Except& e) {
		std::cout << e.what() << " " << e.getErrorNumber() << " " << e.getErrorOffset() << std::endl;
	}


}