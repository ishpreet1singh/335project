#ifndef MATRIX33_HPP
#define MATRIX33_HPP
#include <iostream>

class Matrix33 {
private:
    double** matrix;

public:
    Matrix33();
    Matrix33(double input[3][3]);
    Matrix33(const Matrix33& other); // copy constructor
    Matrix33(Matrix33&& other) noexcept; // move constructor
    Matrix33& operator=(const Matrix33& other); // copy assignment
    Matrix33& operator=(Matrix33&& other) noexcept; // move assignment
    ~Matrix33();

    double& operator()(int row, int col);

    Matrix33 operator*(const Matrix33& other) const;
    Matrix33 operator*(double scalar) const;
    Matrix33 operator+(const Matrix33& other) const;

    double determinant() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix33& m);
    friend std::istream& operator>>(std::istream& is, Matrix33& m);
};

#endif