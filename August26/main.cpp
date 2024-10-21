#include <iostream>
#include "mylib.h"

int main() {
    int a = 5, b = 3;
    
    std::cout << "Addition of " << a << " and " << b << " is: " << add(a, b) << std::endl;
    std::cout << "Subtraction of " << b << " from " << a << " is: " << subtract(a, b) << std::endl;

    return 0;
}
