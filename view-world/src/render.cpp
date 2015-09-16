#include "render.h"
#include "glvars.h"
#include "camera.h"
#include <cmath>

std::vector<Polyhedron> AlivePolyhedrons;

static float f = 0;

void render_scene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    camera.OnRender();
    for (Polyhedron& p : AlivePolyhedrons)
        p.Draw();
    f += 0.01;
    AlivePolyhedrons[0].GetMover().SetXAngle(sinf(f));
    AlivePolyhedrons[0].GetMover().SetYAngle(sinf(f));
    AlivePolyhedrons[0].GetMover().SetZAngle(sinf(f));
    glutSwapBuffers();
}
