#include <iostream>
#include <cctype>

#include "Triangle.hpp"

int main() {
    double x = 0, y = 0, z = 0;

    while (true) {
        std::cout << "Enter 3 values: ";
        std::cin >> x >> y >> z;

        if (x <= 0 || y <= 0 || z <= 0) {
            std::cout << "Invalid input. Sides of a triangle must be greater than zero. Please try again.\n";
            continue;
        }

        Triangle t(x, y, z);
        std::cout << "Is it a triangle? " << (t.isTriangle() ? "Yes" : "No") << std::endl;
        std::cout << "Is it a right angle triangle? " << (t.isRightAngle() ? "Yes" : "No") << std::endl;

        char answer = ' ';
        std::cout << "Do you want to repeat (y or n)? ";
        std::cin >> answer;
        answer = std::tolower(answer);
        if (answer != 'y') {
            break; // Exit the loop
        }
    }

    return 0;
}
