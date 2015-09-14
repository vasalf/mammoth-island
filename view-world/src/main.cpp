#include "glheader.h"
#include "polyhedron.h"
#include "render.h"
#include "world.h"
#include "draw_world.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    World w(argv[1]);
    cout << w.height << " " << w.width << " " << w.depth << endl;
    for (int x = 0; x < w.width; x++)
    {
        for (int z = 0; z < w.depth; z++)
        {
            int mx = 0;
            while ( mx < w.height && w.GetField(x, mx, z) == FIELDTYPE_STONE) mx++;
            cout << mx << " ";
        }
        cout << endl;
    }
    init_gl(&argc, argv);
    glClearColor(0, 0, 0, 0);
    compile_shaders("./shaders/vertex-shader.vsh", "./shaders/fragment-shader.fsh"); 

    //Polyhedron p({{vect(0, 0, 0), vect(1, 0, 0), vect(0, 1, 0)}});
    //AlivePolyhedrons.push_back(p);
    
    DrawWorld(w);

    glutMainLoop();
    return 0;
}
