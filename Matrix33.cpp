#include "Matrix33.hpp"
#include <iostream>
using namespace std;

Matrix33::Matrix33() {
    matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3]{0};
    }
}

Matrix33::Matrix33(double input[3][3]) {
    matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3];
        for (int j = 0; j < 3; ++j)
            matrix[i][j] = input[i][j];
    }
}

Matrix33::Matrix33(const Matrix33& other) {
    matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3];
        for (int j = 0; j < 3; ++j)
            matrix[i][j] = other.matrix[i][j];
    }
}

Matrix33::Matrix33(Matrix33&& other) noexcept {
    matrix = other.matrix;
    other.matrix = nullptr;
}

Matrix33& Matrix33::operator=(const Matrix33& other) {
    if (this == &other) return *this;
    for (int i = 0; i < 3; ++i) delete[] matrix[i];
    delete[] matrix;
    matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3];
        for (int j = 0; j < 3; ++j)
            matrix[i][j] = other.matrix[i][j];
    }
    return *this;
}

Matrix33& Matrix33::operator=(Matrix33&& other) noexcept {
    if (this == &other) return *this;
    for (int i = 0; i < 3; ++i) delete[] matrix[i];
    delete[] matrix;
    matrix = other.matrix;
    other.matrix = nullptr;
    return *this;
}

Matrix33::~Matrix33() {
    if (matrix) {
        for (int i = 0; i < 3; ++i) delete[] matrix[i];
        delete[] matrix;
    }
}

double& Matrix33::operator()(int row, int col) {
    return matrix[row][col];
}

Matrix33 Matrix33::operator*(const Matrix33& other) const {
    Matrix33 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
    return result;
}

Matrix33 Matrix33::operator*(double scalar) const {
    Matrix33 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.matrix[i][j] = matrix[i][j] * scalar;
    return result;
}

Matrix33 Matrix33::operator+(const Matrix33& other) const {
    Matrix33 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
    return result;
}

double Matrix33::determinant() const {
    return matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1])
         - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0])
         + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);
}

ostream& operator<<(ostream& os, const Matrix33& m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            os << m.matrix[i][j] << " ";
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix33& m) {
    cout << "Enter 9 values for the 3x3 matrix:\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            is >> m.matrix[i][j];
    return is;
}