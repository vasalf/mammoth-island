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
                    p.GetMover().SetScale(1.0f / (float)max(w.width, w.height));
                    p.GetMover().SetPosition(vect(-0.5, -0.5, -0.5));
                    AlivePolyhedrons.push_back(p);
                }
            }
        }
    }
}
