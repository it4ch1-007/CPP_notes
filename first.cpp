#include <iostream>
#include <memory> //to use various types of pointers

using namespace std; //namespace is a alias name defined for the standard c++ library
namespace A {
   struct Z { };
   namespace I { void g(Z); }
   using namespace I;

   struct X { struct Y { }; friend void f(Y) { } };
   void f(X p) { }
//    void f(std::shared_ptr<X> p) { }
}
int add(int a,int b=10){ //the default args must be placed after all the non-default args as 
// int add(a=10,b) is not right as b is non-default and placed after a , a default argument
    cout<<a+b<<endl;
}

template<int base,int exponent>
struct power
{
    static const int exponentabs = abs(exponent);
    static const int halfvalue = power<base,exponentabs/2>::value;
    static const int valueabs = halfvalue*halfvalue* power<base,exponentabs%2>::value;
    constexpr static double value = exponent<0?(1.0/valueabs):(valueabs);
};

template<int base>
struct power<base,0>
{
    // static const int val/ue = 1;
    constexpr static double value = 1;
    static_assert(base!=0, "both cannot be 0");
};

template<int base>
struct  power<base,1>
{
    constexpr static double value = base;
};

class Rectangle{
private:
    int length;
    int breadth;
public:
    int area(){
        return length*breadth;
    }
    Rectangle(int l,int b){
        length = l;
        breadth = b;
    }
};
int main(int argc,char* argv[]){
    std::cout<<"Hello"<<std::endl; //the scope resolution operator is used to import the fns or methods from a namespace.
    /*This is a multiline 
    comment
    */
   add(2,5);
    alignas(1) int i;
    cout<<sizeof(i)<<endl;
    //alignof(var) gives the size of the variable
    f(A::X());

    std::cout<<power<5,-3>::value<<std::endl;


    int arrayOfInts[5] = {10,20}; // means 10, 20, 0, 0, 0
    int *a = new int[6]; //directly allocating a ptr to the first element of the array allocated.
    delete[] a; //deleting the memory allocated to the array data 

    //Else we can create smart pointers that are deleted on their own once they go out of scope or mainly once the main fn is destructed.
    //Smart pointers implementation
    //ways are weak_ptr, unique_ptr,shared_ptr,auto_ptr

    //Auto pointers are the ones where if the first pointer is pointing to some resource and then the another pointer demands its ownership then the ownership shifts by itself to the second pointer.
    //Shared pointers are the pointers that may share the same resource to which they are pointing 

    shared_ptr<Rectangle> P1(new Rectangle(10,5)); //the statement after the declaration of the P1 pointer defines the value of the P1 pointer

    std::cout<<P1->area()<<std::endl;

    shared_ptr<Rectangle> P2;
    P2=P1;
    std::cout<<P2->area()<<" "<<P1->area()<<std::endl; //here the pointers are sharing the same resource.


    //Unique pointers : the resource must be transferred in order to be pointed by another pointer
    unique_ptr<Rectangle> P3(new Rectangle(5,4));

    std::cout<<P3->area()<<std::endl;

    unique_ptr<Rectangle> P4;
    P4 = move(P3);
    std::cout<<P4->area()<<std::endl;
    // std::cout<<P3->area()<<std::endl; 
    //this will give memory leak and the program will crash as it is not pointing to anything and is now acting as a dangling pointer


    //Weak pointers: they are similar to the shared pointers but they donot calculate the reference count of the resources that 
    // they have to point.Also a weak pointer can only be made deriving from a shared pointer as it then act as the weak pointer 
    // for that shared ptr only

    shared_ptr<Rectangle> P5(new Rectangle(6,4));
    weak_ptr<Rectangle> P6(P5);

    std::cout<<P5->area()<<std::endl;
    // std::cout<<P6->area()<<std::endl;


    return EXIT_SUCCESS; //main fn that has the return type integer can also return these macros
} 