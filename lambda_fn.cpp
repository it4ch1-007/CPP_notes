#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
	std::vector<string> vec = { "hello","my","world" };
	std::for_each(vec.begin(), vec.end(), [](const auto &s) {
		if (s % 2 == 0) {

		}
		})
}