#include "glheader.h"
#include "polyhedron.h"
#include "render.h"

int main(int argc, char** argv)
{
    init_gl(&argc, argv);
    glClearColor(0, 0, 0, 0);
    compile_shaders("./shaders/vertex-shader.vsh", "./shaders/fragment-shader.fsh"); 

    Polyhedron p({{vect(0, 0, 0), vect(1, 0, 0), vect(0, 1, 0)}});
    AlivePolyhedrons.push_back(p);
    glutMainLoop();
    return 0;
}
