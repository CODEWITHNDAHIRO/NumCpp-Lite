#include "../include/matrix.h"
#include <iostream>
#include <stdexcept> 
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

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = other.data[i]; 
    }
}


Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this; 

    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}


Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        result.data[i] = this->data[i] + other.data[i];
    }
    return result;
}


Matrix Matrix::operator*(const Matrix& other) const {
    
    if (this->cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions incompatible for multiplication.");
    }

    Matrix result(this->rows, other.cols);


    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < this->cols; ++k) {
                sum += this->get(i, k) * other.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}