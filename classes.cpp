#include <iostream>

class Animal {
public:		
	virtual void makesound() {
		std::cout << "The sound is default" << std::endl;
	}
};

class Dog : public Animal {
public:
	void makesound() {
		std::cout << "The sound is the bark" << std::endl;
	}
};

class Cat : public Animal {
public:
	void makesound() {
		std::cout << "The sound is of the meow" << std::endl;
	}
};

struct Plus2Base {
	int value() noexcept { return  calculateValue() + 2; }
protected:
	virtual int calculateValue() noexcept = 0; //virtual function that can be used as the function in other classes 
	//noexcept is the feature the ensures that the function specified will not throw any exception even if any error occurs in the execution of the function

};

class test {
public: 
	static void bar() { std::cout << "Accessed!!" << std::endl; }
};


//Final classes and structs
//These types of classes cannot be derived again by any other classes or structs



class final_test final{

};

//class deriving_class :final_test {

//};

//This gives error as it cannot inherit from a final class 

class deriving_class final : public Plus2Base {

};

//This final class inherits from a struct but cannot be inherited further by any other class or struct.




//Friend Functions
//It basically allows us to write a method of the class just outside the class having access to all privte and protected variables and methods of the class.
class friend_test {
private:
	int secret;
public:
	friend void secret_printing(friend_test ftest);
	friend class printer;
};

//A friend function setting the private variable of the given specific class
void secret_printing(friend_test ftest) {
	ftest.secret = 1;
	std::cout << ftest.secret << std::endl;
}
class printer {
public:
	void print(const friend_test& ftest) {
		std::cout << ftest.secret << std::endl;
	}
};



//Typedefs inside the classes or structs

struct IntTypeDef {
	typedef int MyTypeDef; 
};

struct TemplateTypeDef {
	//template<typename T>;
	//using MyTemplate = std::vector<T>;
	//This will now make the vector of any type wherever the class is accessed by the program.

};

class A {
public:
	void func(){
	std::cout << "The first func!" << std::endl;
	}
};
class B {
public:
	void func(){
		std::cout << "The second func!" << std::endl;
	}
};

class C : public A, public B {

};
int main(int argc, char* argv[])
{

	Dog dog;
	Cat cat;

	Animal* animal1 = &dog;
	Animal* animal2 = &cat;

	animal1->makesound();
	animal2->makesound();

	test::bar(); //calling the static members of the classes or structs

	friend_test ftest;
	secret_printing(ftest);
	printer p;
	p.print(ftest);

	//IntTypeDef::MyTypeDef i = 5; //this will define i as an integer
	//TemplateTypeDef::MyTemplate<int> vec; 
	//TemplateTypeDef::MyTemplate<char> vec2;
	//This can define vectors of different types in the same syntax form



	//Multiple inheritance
	C c;
	c.A::func();
	c.B::func();
	//using scope operator to use the functions of the parent classes
	return 0;



}


// WHY *p.a is not used and p->a is used ?
// *p.a tries to access the member a of p and as p is a pointer there is no member of a.
// *(p.a) is equivalent to *p.a here and also this dereferences a which may be a variable that cannot be dereferenced.
// thus p->a is used to be equivalent to (*p).a 

//The :: operator is also used for the same reason as the static functions or instances are not actual members of the classes.



//If a struct is derived from a class then it should be private by default while if a class is derived from a struct then it should be public by default


//Levels of inheritance

//Public inheritance
//public->public
//protected->protected
//Only private is inaccessible
//public inherits as in the parent class

//Private Inheritance 
//public -> private
//protected -> private
//private is still inaccessible
//private converts evrythin to private

//Protected Inheritance
//public -> protected
//protected -> protected
//private is inaccessible
//protected converts everything into protected


//Multiple Inheritance problem
//When a class inherits more than one class then this can lead to ambiguity as there may be two or more functions with the same name inside the classes. 
//But this ambiguity is prevented by using scope reasolution operator