#include "MatrixNM.hpp"
#include <iostream>
using namespace std;

MatrixNM::MatrixNM(int n, int m) : rows(n), cols(m), data(n, vector<double>(m, 0)) {}

double& MatrixNM::operator()(int i, int j) {
    return data[i][j];
}

void MatrixNM::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}