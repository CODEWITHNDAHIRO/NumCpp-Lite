#include "../include/matrix.h"
#include <iostream>

int main() {
    Matrix mat(2, 3);
    mat.set(0, 0, 1.0); mat.set(0, 1, 2.0); mat.set(0, 2, 3.0);
    mat.set(1, 0, 4.0); mat.set(1, 1, 5.0); mat.set(1, 2, 6.0);

    std::cout << "Structured Matrix:\n";
    mat.print();

    return 0;
}