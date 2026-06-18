#include "../include/matrix.h"
#include <iostream>
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = 0.0;
    }
}

Matrix::~Matrix() {
    delete[] data;
}

void Matrix::set(int r, int c, double value) {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        data[r * cols + c] = value;
    }
}

double Matrix::get(int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        return data[r * cols + c];
    }
    return 0.0;
}

void Matrix::print() const {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout << get(r, c) << " ";
        }
        std::cout << "\n";
    }
}