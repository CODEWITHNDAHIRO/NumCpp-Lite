#include "../include/matrix.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector> 
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
Matrix Matrix::from_csv(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filepath);
    }

    std::vector<std::vector<double>> temporary_data;
    std::string line;

    // Read file line by line
    while (std::getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;

        std::vector<double> row_values;
        std::stringstream ss(line);
        std::string value_str;

        // Split line by commas
        while (std::getline(ss, value_str, ',')) {
            try {
                row_values.push_back(std::stod(value_str)); // Convert string to double
            } catch (const std::invalid_argument&) {
                // If parsing fails (e.g., text headers), skip or handle
                continue; 
            }
        }

        if (!row_values.empty()) {
            temporary_data.push_back(row_values);
        }
    }
    file.close();

    // Check if we actually read anything
    if (temporary_data.empty()) {
        throw std::runtime_error("File is empty or contains no valid numeric data.");
    }

    int parsed_rows = temporary_data.size();
    int parsed_cols = temporary_data[0].size();

    // Allocate our optimized Matrix memory block and fill it
    Matrix result(parsed_rows, parsed_cols);
    for (int r = 0; r < parsed_rows; ++r) {
        for (int c = 0; c < parsed_cols; ++c) {
            result.set(r, c, temporary_data[r][c]);
        }
    }

    return result;
}