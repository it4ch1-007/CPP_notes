#include <iostream>
#include <vector>
#include <chrono>



#pragma omp parallel for 
//This creates a parallel for loop that can work multithreading easily
//this works faster but very slightly
//Data paralleliztion is when we have different threads working on different subsets of data and this increases the speed of the program
//std::cout << "begin" << std::endl;

 


int main() {
	//std::vector<int> element;
	//auto start = std::chrono::high_resolution_clock::now();
	////To integrate Open MP we will have to use -fopenmp or /openmp tags while compilation
	//
	//for (size_t i = 0; i < 10000000; i++) {
	//	element.push_back(i);
	//	//if (i % 100 == 0)
	//		//std::cout << i << std::endl;
	//}
	///*for (size_t i = 0; i < 1000; i++) {
	//	element[i] = i;
	//}*/
	//auto end = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<double> duration = end - start;
	//std::cout << duration.count() << std::endl;
	int x = 1;
	std::cout << "begin" << std::endl;
	for (int i = 0; i < 1000; i++) {
#pragma omp parallel sections
		{
#pragma omp section
			{
#pragma omp critical //This creates a critical code section that ensures that no race condition occurs between the sections 
				std::cout << x<<std::endl;
			}
#pragma omp section
			{
				x = x * 5;
			}
#pragma omp section
			{
				x = x + 2;
			}
		}
	}
	std::cout << "\nend" << std::endl;


}