#ifndef MATRIXNM_HPP
#define MATRIXNM_HPP
#include <vector>
#include <iostream>

class MatrixNM {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    MatrixNM(int n, int m);
    double& operator()(int i, int j);
    void print() const;
};

#endif