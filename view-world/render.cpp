#include "render.h"
#include "glvars.h"

std::vector<Polyhedron> AlivePolyhedrons;

void render_scene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (Polyhedron& p : AlivePolyhedrons)
        p.Draw();
    AlivePolyhedrons[0].GetMover().ZRotate(0.01);
    glutSwapBuffers();
}
