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
    

    /*vector<vect> pts = {vect(-1, -1, 0.5773f), vect(0, -1, -1.15475), vect(1, -1, 0.5773), vect(0, 1, 0)};

    AlivePolyhedrons.push_back(Polyhedron({{pts[0], pts[3], pts[1]}, {pts[1], pts[3], pts[2]}, {pts[2], pts[3], pts[0]}, {pts[0], pts[2], pts[1]}}));

    AlivePolyhedrons[0].GetMover().SetPosition(vect(0, 0, 5));*/

    /*vector<vector<vect> > vv = {{vect(0, 0, 0), vect(1, 0, 0), vect(1, 1, 0), vect(0, 1, 0)},
    {vect(0, 0, 0), vect(0, 0, 1), vect(0, 1, 1), vect(0, 1, 0)},
    {vect(0, 0, 0), vect(1, 0, 0), vect(1, 0, 1), vect(0, 0, 1)},
    {vect(1, 1, 1), vect(1, 1, 0), vect(0, 1, 0), vect(0, 1, 1)},
    {vect(1, 1, 1), vect(1, 0, 1), vect(1, 0, 0), vect(1, 1, 0)},
    {vect(1, 1, 1), vect(1, 0, 1), vect(0, 0, 1), vect(0, 1, 1)}};
    for (int i = 0; i < 6; i++)
        for (vect& v : vv[i])
        {
            v.x -= 0.5;
            v.y -= 0.5;
            v.z -= 0.5;
        }
    AlivePolyhedrons.push_back(Polyhedron(vv));
    //AlivePolyhedrons[0][5].color = vect(0, 1, 0);
    //AlivePolyhedrons[0].GetMover().SetScale(0.5);
    AlivePolyhedrons[0].GetMover().SetPosition(vect(0, 0, 3));
    AlivePolyhedrons[0][1].color = vect(1, 0, 1);
    AlivePolyhedrons[0][2].color = vect(1, 1, 0);
    AlivePolyhedrons[0][3].color = vect(0, 1, 1);
    AlivePolyhedrons[0][4].color = vect(0, 0, 1);
    AlivePolyhedrons[0][5].color = vect(0, 1, 0);*/

    DrawWorld(w);
    
    glutMainLoop();
    
    return 0;
}
