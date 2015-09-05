#include "render.h"
#include "glvars.h"
#include <iostream>

using namespace std;

vector<Polyhedron> AlivePolyhedrons;

void render_scene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (Polyhedron& p : AlivePolyhedrons)
        p.Draw();
    glutSwapBuffers();
}
