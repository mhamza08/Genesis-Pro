#include <iostream>

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "Max of 3 and 7: " << max(3, 7) << std::endl;
    std::cout << "Max of 3.5 and 2.1: " << max(3.5, 2.1) << std::endl;
    return 0;
}

/*
Use templates for generic programming: Templates should be used to create functions and classes that work with any data type.
Be aware of code bloat: Since templates generate code for each type they are used with, avoid excessive use that could lead to large binary sizes.
Provide meaningful error messages: When writing templates, make sure to provide clear error messages for misuse, which can be complex.
Prefer type traits and SFINAE for type checking: Use C++ type traits and SFINAE (Substitution Failure Is Not An Error) to ensure that templates only compile for valid types.
*/