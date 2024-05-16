#include <iostream>

class MyClass {
public:
    // constexpr constructor
    constexpr MyClass(int x, int y) : a(x), b(y) {}

    // constexpr member function
    constexpr int sum() const {
        return a + b;
    }

private:
    int a;
    int b;
};

int main() {
    // constexpr object creation
    constexpr MyClass obj(10, 20);

    // Using constexpr function at compile time
    constexpr int result = obj.sum();

    // Displaying the result at compile time
    std::cout << "Result at compile time: " << result << std::endl;

    // Creating a non-constexpr object at runtime
    MyClass nonConstObj(30, 40);

    // Using the function at runtime
    int runtimeResult = nonConstObj.sum();

    // Displaying the result at runtime
    std::cout << "Result at runtime: " << runtimeResult << std::endl;

    return 0;
}
