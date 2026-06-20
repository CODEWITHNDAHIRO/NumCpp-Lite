#include "../include/matrix.h"
#include <iostream>

int main() {
    
    Matrix A(2, 3);
    A.set(0, 0, 1.0); A.set(0, 1, 2.0); A.set(0, 2, 3.0);
    A.set(1, 0, 4.0); A.set(1, 1, 5.0); A.set(1, 2, 6.0);

    Matrix B(3, 2);
    B.set(0, 0, 7.0);  B.set(0, 1, 8.0);
    B.set(1, 0, 9.0);  B.set(1, 1, 10.0);
    B.set(2, 0, 11.0); B.set(2, 1, 12.0);

    std::cout << "--- Matrix A (2x3) ---\n";
    A.print();
    std::cout << "\n--- Matrix B (3x2) ---\n";
    B.print();

    try{
        Matrix C = A * B; 
        std::cout << "\n--- Result of A * B (2x2) ---\n";
        C.print();
    } catch (const std::exception& e) {
        std::cerr << "Multiplication Error: " << e.what() << '\n';
    }

    try{
        Matrix D = A + A;
        std::cout << "\n--- Result of A + A (2x3) ---\n";
        D.print();
    } catch (const std::exception& e) {
        std::cerr << "Addition Error: " << e.what() << '\n';
    }

    
    std::cout << "\n--- Testing Deep Copy ---\n";
    Matrix E = A; // Invokes Copy Constructor
    E.set(0, 0, 99.0); 
    
    std::cout << "Matrix E (Modified Copy, Top-Left should be 99):\n";
    E.print();
    std::cout << "Matrix A (Original, Top-Left should still be 1):\n";
    A.print();

    return 0;
}