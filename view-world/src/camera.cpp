#include "camera.h"
#include "glinclude.h"
#include <cmath>

using namespace std;

CameraMover camera;

CameraMover::CameraMover() {}

CameraMover::CameraMover(int width, int height)
{
    w = width;
    h = height;
    xvect = vect(1, 0, 0);
    yvect = vect(0, 1, 0);
    zvect = vect(0, 0, 1);
    horizontal_angle = 0;
    vertical_angle = 0;
    mouse.x = width / 2;
    mouse.y = height / 2;
    glutWarpPointer(mouse.x, mouse.y);
}

Matrix CameraMover::GetMatrix()
{
    Matrix res;
    res[0][0] = xvect.x; res[0][1] = xvect.y; res[0][2] = xvect.z;
    res[1][0] = yvect.x; res[1][1] = yvect.y; res[1][2] = yvect.z;
    res[2][0] = zvect.x; res[2][1] = zvect.y; res[2][2] = zvect.z;
    return res * PositionMatrix(position); 
}

static const float step_size = 0.1;

void SpecialKeyHandler(int key, int x, int y)
{
    x += y; //just to make the compiler not worrying
    switch(key)
    {
      case GLUT_KEY_UP:
        camera.position -= camera.zvect * step_size;
        break;
      case GLUT_KEY_DOWN:
        camera.position += camera.zvect * step_size;
        break;
      case GLUT_KEY_LEFT:
        camera.position += camera.xvect * step_size;
        break;
      case GLUT_KEY_RIGHT:
        camera.position -= camera.xvect * step_size;
        break;
      default:
        break;
    }
}

static const float angle_step_size = 0.003;
static const int margin = 20;

void MouseHandler(int x, int y)
{
    float dx = x - camera.mouse.x;
    float dy = y - camera.mouse.y;
    camera.mouse.x = x;
    camera.mouse.y = y;
    camera.horizontal_angle -= angle_step_size * dx;
    camera.vertical_angle += angle_step_size * dy;
    camera.update();
}

void CameraMover::OnRender()
{
    bool should_update = true;
    if (mouse.x >= w - margin)
        horizontal_angle -= angle_step_size;
    else if (mouse.x <= margin)
        horizontal_angle += angle_step_size;
    else if (mouse.y >= h - margin)
        vertical_angle += angle_step_size;
    else if (mouse.y <= margin)
        vertical_angle -= angle_step_size;
    else
        should_update = false;
    if (should_update)
        update();
}

struct quaternion
{
    float x, y, z, w;
    quaternion(float _x, float _y, float _z, float _w)
    {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }
};

quaternion operator*(const quaternion& q, const quaternion& r)
{
    return quaternion(q.x * r.w + q.w * r.x + q.y * r.z - q.z * r.y,
                      q.y * r.w + q.w * r.y + q.z * r.x - q.x * r.z,
                      q.z * r.w + q.w * r.z + q.x * r.y - q.y * r.x,
                      q.w * r.w - q.x * r.x - q.y * r.y - q.z * r.z);
}

quaternion operator*(const quaternion& q, const vect& v)
{
    return quaternion(q.w * v.x + q.y * v.z - q.z * v.y,
                      q.w * v.y + q.z * v.x - q.x * v.z,
                      q.w * v.z + q.x * v.y - q.y * v.x,
                      q.x * v.x - q.y * v.y - q.z * v.z);
}

static quaternion conjugate(quaternion q)
{
    return quaternion(-q.x, -q.y, -q.z, q.w);
}

static vect rotate(vect v, float angle, vect u)
{
    float sinhalf = sinf(angle / 2);
    quaternion r(u.x * sinhalf, u.y * sinhalf, u.z * sinhalf, cosf(angle / 2));
    quaternion w = r * v * conjugate(r);
    return vect(w.x, w.y, w.z);
}

void CameraMover::update()
{
   zvect = Normalized(rotate(vect(1, 0, 0), horizontal_angle, vect(0, 1, 0)));
   xvect = Normalized(CrossProduct(vect(0, 1, 0), zvect));
   zvect = Normalized(rotate(zvect, vertical_angle, xvect));
   yvect = Normalized(CrossProduct(xvect, zvect));
}

