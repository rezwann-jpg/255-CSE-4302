#include "Matrix.h"

Matrix::Matrix() : incrementStep(1) {
    mat.resize(3, std::vector<double>(3, 0.0));
}

Matrix::~Matrix() { }

double Matrix::det() const {
    double determinant;

    for(int i = 0; i < 3; i++)
		determinant += (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));

    return determinant;
}

Matrix Matrix::getMatrix() const {
    return *this;
}

Matrix Matrix::inverse() const {
    Matrix invertedMat;
    double determinant = det();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            invertedMat.mat[i][j] = ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant;
        
    }

    return invertedMat;
}

void Matrix::setIncrement(int val) {
    incrementStep = val > 0 ? val : incrementStep;
}

void Matrix::increment() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] += incrementStep;
        }
    }
}

Matrix Matrix::operator+(Matrix &mat2)
{
    return Matrix();
}

Matrix Matrix::operator-(Matrix &mat2)
{
    return Matrix();
}

Matrix Matrix::operator*(Matrix &mat2)
{
    return Matrix();
}
