#ifndef MOVER_H_
#define MOVER_H_

#include "geom.h"
#include "matrix.h"

class Mover
{
    vect position;
    float xang, yang, zang;
    float scale;
  public:
    Mover();
    void SetPosition(vect _position);
    void SetXAngle(float _xang);
    void SetYAngle(float _yang);
    void SetZAngle(float _zang);
    void SetScale(float _scale);

    void Move(vect v);
    void XRotate(float ang);
    void YRotate(float ang);
    void ZRotate(float ang);
    void Scale(float sc);

    vect GetPosition() const;
    float GetXAngle() const;
    float GetYAngle() const;
    float GetZAngle() const;
    float GetScale() const;

    Matrix GetMatrix() const;
};

#endif //MOVER_H_
