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

vect Mover::GetPosition() const
{
    return position;
}

float Mover::GetXAngle() const
{
    return xang;
}

float Mover::GetYAngle() const
{
    return yang;
}

float Mover::GetZAngle() const
{
    return zang;
}

float Mover::GetScale() const
{
    return scale;
}

Matrix Mover::GetMatrix() const
{
   return ScaleMatrix(scale) * XAngleMatrix(xang) * YAngleMatrix(yang) * ZAngleMatrix(zang) * PositionMatrix(position); 
}
