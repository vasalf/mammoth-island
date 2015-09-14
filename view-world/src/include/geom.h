#ifndef GEOM_H_
#define GEOM_H_

struct vect
{
    float x, y, z;
    vect(float _x = 0, float _y = 0, float _z = 0);
    vect operator+(const vect& other) const;
    vect& operator+=(const vect& other);
};

vect operator*(const float& f, const vect& v);
vect operator*(const vect& v, const float& f);

#endif //GEOM_H_
