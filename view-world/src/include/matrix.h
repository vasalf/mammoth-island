#ifndef MATRIX_H_
#define MATRIX_H_

#include "geom.h"

struct Matrix
{
    float m[4][4];
    Matrix();
    float* operator[](const int& i);
};

Matrix operator*(const Matrix& a, const Matrix& b);

Matrix ScaleMatrix(float scale);

Matrix XAngleMatrix(float ang);
Matrix YAngleMatrix(float ang);
Matrix ZAngleMatrix(float ang);

Matrix PositionMatrix(vect v);

Matrix Transpose(Matrix x);

#endif //MATRIX_H_
