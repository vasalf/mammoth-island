#include "mover.h"

Mover::Mover()
{
    xang = 0;
    yang = 0;
    zang = 0;
    scale = 1;
}

void Mover::SetPosition(vect _position)
{
    position = _position;
}

void Mover::SetXAngle(float _xang)
{
    xang = _xang;
}

void Mover::SetYAngle(float _yang)
{
    yang = _yang;
}

void Mover::SetZAngle(float _zang)
{
    zang = _zang;
}

void Mover::SetScale(float _scale)
{
    scale = _scale;
}

void Mover::Move(vect v)
{
    position += v;
}

void Mover::XRotate(float ang)
{
    xang += ang;
}

void Mover::YRotate(float ang)
{
    yang += ang;
}

void Mover::ZRotate(float ang)
{
    zang += ang;
}

void Mover::Scale(float sc)
{
    scale *= sc;
}

vect Mover::GetPosition()
{
    return position;
}

float Mover::GetXAngle()
{
    return xang;
}

float Mover::GetYAngle()
{
    return yang;
}

float Mover::GetZAngle()
{
    return zang;
}

float Mover::GetScale()
{
    return scale;
}

Matrix Mover::GetMatrix()
{
   return ScaleMatrix(scale) * XAngleMatrix(xang) * YAngleMatrix(yang) * ZAngleMatrix(xang) * PositionMatrix(position); 
}
