#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char* argv[]) {
	std::vector<string> vec1 = { "hello","my","world" };
	for (auto i : vec1) {
		if (i == "my") {
			std::cout << i.append(" appended")<<std::endl; //this only takes the value or can be understood as a copy of the value taken from the given vector
		}
	}
	for (auto i : vec1) {
		std::cout << i << std::endl;
	}
	std::vector<string> vec2 = { "hey","not","my","world" };
	for (auto& i : vec2) { //using the reference to change the value itself inside the given array or vector
		if (i == "my") {
			i.append(" appended");
		}
	}
	for (auto i : vec2) {
		std::cout << i << std::endl;
	}
	return 0;
}