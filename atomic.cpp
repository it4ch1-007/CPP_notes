#include <iostream>
#include <thread>
#include <atomic>


void add(int a, int b, std::atomic<int>* result) {
	for (int i = a; i <= b; i++) {
		result ->fetch_add(i);
	}
} 
int main(int argc, char* argv[])
{
	std::atomic<int> shared = 0; //As this variable is created before spawning the thread thus it will be shared by both threads main as well as the spawned one.

	std::thread parallelThread(add, 1, 100, &shared); //the sum is being stored inside the shared variable

	while (!parallelThread.joinable()) {
		std::cout << shared.load() << std::endl;
	}

	parallelThread.join();



}

//Sequential Consistency: 
// It is the ordering of all the memory operations after the atomic operations as this helps it to prevent data race conditions and help to improve the performance of the system.
// But it degrades the compiler optmizations as then the compiler cannot do reordering of the operations inside the program
//In this all the threads will see the operations of the program code in the same order as all the other threads

//Relaxed Ordering
//It makes the operations restrictions less.


//Fencing
//There are two types of fences: release fence and acquire fence
// Acquire Fence if is present before the release fence then the memory operations before the acquire fence are visible to the operations after the release fence 


//Releasing
//It is to ensure that the previous operations donot replace the current operation

//Acquiring 
//It is to ensure that the current operation is not replaced by the subsequent operations

