#include "geom.h"
#include <cmath>

using namespace std;

vect::vect(float _x, float _y, float _z)
{
    x = _x; y = _y; z = _z;
}

vect vect::operator+(const vect& other) const
{
    return vect(x + other.x, y + other.y, z + other.z);
}

vect vect::operator-(const vect& other) const
{
    return vect(x - other.x, y - other.y, z - other.z);
}

vect& vect::operator+=(const vect& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

vect& vect::operator-=(const vect& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

vect operator*(const float& f, const vect& v)
{
    return vect(f * v.x, f * v.y, f * v.z);
}

vect operator*(const vect& v, const float& f)
{
    return vect(f * v.x, f * v.y, f * v.z);
}

vect CrossProduct(vect u, vect v)
{
    return vect(v.y * u.z - v.z * u.y, v.z * u.x - v.x * u.z, v.x * u.y - v.y * u.x);
}

vect Normalized(vect u)
{
    return u * (1 / sqrtf(u.x * u.x + u.y * u.y + u.z * u.z));
}
