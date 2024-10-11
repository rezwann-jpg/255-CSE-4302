#ifndef MATRIX_H
#define MATRIX_H

#pragma once

#include <vector>

class Matrix {
public:
    Matrix();
    ~Matrix();

    double det() const;
    Matrix getMatrix() const;
    Matrix inverse() const;
    void setIncrement(int val);
    void increment();

    Matrix operator +(Matrix &mat2);
    Matrix operator -(Matrix &mat2);
    Matrix operator *(Matrix &mat2);

private:
    std::vector<std::vector<double>> mat;
    int incrementStep;
};

#endif