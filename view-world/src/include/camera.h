#ifndef CAMERA_H_
#define CAMERA_H_

#include "matrix.h"
#include "geom.h"

struct CameraMover
{
    vect xvect;
    vect yvect;
    vect zvect;
    vect position;
    vect mouse;
    int w, h;
    float vertical_angle;
    float horizontal_angle;
    void update();
    void OnRender();
    CameraMover();
    CameraMover(int width, int height);
    Matrix GetMatrix();
};

extern CameraMover camera;

void SpecialKeyHandler(int key, int x, int y);
void MouseHandler(int x, int y);
void KeyboardHandler(unsigned char key, int x, int y);

#endif //CAMERA_H_
