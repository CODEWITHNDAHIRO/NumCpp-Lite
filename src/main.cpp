#include "../include/matrix.h"
#include <iostream>

int main() {
    try {
        std::cout << "Attempting to load data.csv...\n";
        
        // 1. Parse the CSV file into a Matrix object
        Matrix dataset = Matrix::from_csv("data.csv");
        
        std::cout << "Successfully loaded dataset!\n";
        std::cout << "Dimensions: " << dataset.getRows() << " rows x " << dataset.getCols() << " cols\n\n";
        
        std::cout << "Dataset Content:\n";
        dataset.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}