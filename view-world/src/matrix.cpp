#include "matrix.h"
#include <cmath>

using namespace std;

Matrix::Matrix()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] = 0;
    for (int i = 0; i < 4; i++)
        m[i][i] = 1;
}

float* Matrix::operator[](const int& i)
{
    return m[i];
}

Matrix operator*(const Matrix& a, const Matrix& b)
{
    Matrix ans;
    for (int i = 0; i < 4; i++)
        ans[i][i] = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                ans[i][j] += a.m[i][k] * b.m[k][j];
    return ans;
}

Matrix ScaleMatrix(float scale)
{
    Matrix res;
    for (int i = 0; i < 3; i++)
        res[i][i] = scale;
    return res;
}

Matrix XAngleMatrix(float ang)
{
    Matrix res;
    res[1][1] = cosf(ang);
    res[1][2] = -sinf(ang);
    res[2][1] = sinf(ang);
    res[2][2] = cosf(ang);
    return res;
}

Matrix YAngleMatrix(float ang)
{
    Matrix res;
    res[0][0] = cosf(ang);
    res[0][2] = -sinf(ang);
    res[2][0] = sinf(ang);
    res[2][2] = cosf(ang);
    return res;
}

Matrix ZAngleMatrix(float ang)
{
    Matrix res;
    res[0][0] = cosf(ang);
    res[0][1] = -sinf(ang);
    res[1][0] = sinf(ang);
    res[1][1] = cosf(ang);
    return res;
}

Matrix PositionMatrix(vect v)
{
    Matrix res;
    res[0][3] = v.x;
    res[1][3] = v.y;
    res[2][3] = v.z;
    return res;
}
