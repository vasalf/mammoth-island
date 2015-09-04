#include "geom.h"

vect::vect(float _x, float _y, float _z)
{
    x = _x; y = _y; z = _z;
}

vect vect::operator+(const vect& other) const
{
    return vect(x + other.x, y + other.y, z + other.z);
}

vect& vect::operator+=(const vect& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}
