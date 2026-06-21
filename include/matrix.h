#ifndef MATRIX_H
#define MATRIX_H
#include <string>
class Matrix {
private:
    int rows;
    int cols;
    double* data;

public:
    Matrix(int r, int c);
    ~Matrix();
    void set(int r, int c, double value);
    double get(int r, int c) const;
    void print() const;
    Matrix(const Matrix& other);                // Copy Constructor
    Matrix& operator=(const Matrix& other);     // Copy Assignment
    Matrix operator+(const Matrix& other) const; // Matrix Addition
    Matrix operator*(const Matrix& other) const; // Matrix Multiplication
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    
    static Matrix from_csv(const std::string& filepath);
};

#endif
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int rows;
    int cols;
    double* data;

public:
    Matrix(int r, int c);
    ~Matrix();
    void set(int r, int c, double value);
    double get(int r, int c) const;
    void print() const;
};

#endif