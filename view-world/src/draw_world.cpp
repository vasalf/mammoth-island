#include "draw_world.h"
#include "world.h"
#include "render.h"
#include "polyhedron.h"

using namespace std;

static Polyhedron cube(int x, int y, int z)
{
    return Polyhedron({
        {vect(x, y, z), vect(x, y + 1, z), vect(x + 1, y + 1, z), vect(x + 1, y, z)},
        {vect(x, y, z), vect(x, y + 1, z), vect(x, y + 1, z + 1), vect(x, y, z + 1)},
        {vect(x, y, z), vect(x, y, z + 1), vect(x + 1, y, z + 1), vect(x + 1, y, z)},
        {vect(x + 1, y, z), vect(x + 1, y, z + 1), vect(x + 1, y + 1, z + 1), vect(x + 1, y + 1, z)},
        {vect(x, y + 1, z), vect(x, y + 1, z + 1), vect(x + 1, y + 1, z + 1), vect(x + 1, y + 1, z)},
        {vect(x, y, z + 1), vect(x + 1, y, z + 1), vect(x + 1, y + 1, z + 1), vect(x, y + 1, z + 1)}
    });
}

void DrawWorld(World w)
{
    for (int x = 0; x < w.width; x++)
    {
        for (int y = 0; y < w.height; y++)
        {
            for (int z = 0; z < w.depth; z++)
            {
                if (w.GetField(x, y, z) == FIELDTYPE_STONE)
                {
                    Polyhedron p(cube(x, y, z));
                    p.GetMover().SetPosition(vect(0, 0, 5));
                //    if ((x + y) % 2)
                //        p[5].color = vect(0, 1, 0);
                    p[1].color = vect(1, 0, 1);
                    p[2].color = vect(1, 1, 0);
                    p[3].color = vect(0, 1, 1);
                    p[4].color = vect(0, 0, 1);
                    p[5].color = vect(0, 1, 0);
                    AlivePolyhedrons.push_back(p);
                }
            }
        }
    }
}
