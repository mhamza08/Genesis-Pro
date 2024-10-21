#include <iostream>
#include "project.h"
#include "utils.h"

// Define the function declared in project.h
void printProjectInfo() {
    std::cout << "Project: MyProject" << std::endl;
    std::cout << "Default Value: " << DEFAULT_VALUE << std::endl;
}

int main() {
    // Print project info
    printProjectInfo();

    // Use utility functions
    int a = 5, b = 3;
    std::cout << "Addition of " << a << " and " << b << " is: " << add(a, b) << std::endl;
    std::cout << "Multiplication of " << a << " and " << b << " is: " << multiply(a, b) << std::endl;

    return 0;
}
