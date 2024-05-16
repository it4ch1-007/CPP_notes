#include <iostream>
#include <thread>


void add(int a,int b,int *result){
    for(int i=a;i<=b;i++){
        result += i;
    }
}
//This fn adds up all the integers included and between and writes it to the shared region as required
int main(int argc,char* argv[]){
    //Atomic Types
    //They are used to access and read or write in the shared regions

    int shared = 0;

    
    //A thread that will run parallel to the main thread
    std::thread parallelThread(add,1,100,&shared); 
    //This takes up all theargs of the fn inside the thread and all the regions where the read ans write operations should be done by the thread

    while(!parallelThread.joinable()){ //checks if the thread created is finished or we can say it is made joinable
        
        std::cout<<shared<<std::endl; //The main thread tries to read the same shared region simultaneously and tries to print it 

    }
    
    //When the thread has become joinable then the program code should wait until the thread execution has finished
    parallelThread.join();
    std::cout << "hello" << std::endl;

    return EXIT_SUCCESS;

}