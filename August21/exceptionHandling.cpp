#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero error");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return 0;
}

/*
Use exceptions for error handling: Do not use return codes for errors, use exceptions instead.
Throw by value, catch by reference: Always throw exceptions by value and catch them by reference to avoid object slicing and unnecessary copies.
Prefer standard exceptions: Use standard exceptions (std::runtime_error, std::invalid_argument, etc.) where possible instead of creating custom exceptions.
Use try-catch blocks appropriately: Only use try-catch blocks where you can handle the exception or log it; do not catch exceptions just to silence them.
*/