#include <iostream>
#include "Matrix33.hpp"
#include "vector3.hpp"
using namespace std;

Vector3 multiplyMatrixVector(Matrix33& A, Vector3& x) {
    return Vector3(
        A(0, 0) * x(0) + A(0, 1) * x(1) + A(0, 2) * x(2),
        A(1, 0) * x(0) + A(1, 1) * x(1) + A(1, 2) * x(2),
        A(2, 0) * x(0) + A(2, 1) * x(1) + A(2, 2) * x(2)
    );
}

int main() {
    Matrix33 A;
    Vector3 x;
    cin >> A;
    cin >> x;
    Vector3 b = multiplyMatrixVector(A, x);
    cout << "Result (Ax = b): " << b << endl;
    return 0;
}