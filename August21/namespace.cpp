#include <iostream>

namespace MathOperations {
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }
}

int main() {
    std::cout << "Addition: " << MathOperations::add(10, 5) << std::endl;
    std::cout << "Subtraction: " << MathOperations::subtract(10, 5) << std::endl;
    return 0;
}

/*
Use namespaces to avoid name collisions: Wrap your code in namespaces to prevent naming conflicts in larger projects.
Use concise and meaningful names: Choose namespace names that clearly indicate the purpose or domain of the code.
Avoid global namespace pollution: Do not put functions, classes, or variables in the global namespace unless necessary.
Use nested namespaces sparingly: While nesting can help organize large projects, it should be used judiciously to avoid overly complicated code.
*/