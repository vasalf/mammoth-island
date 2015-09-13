#include "world.h"

static int get_distance(int x, int y)
{
    return x + y;
}

void World::Generate()
{
    for (int x = 0; x < width; x++)
        for (int z = 0; z < depth; z++)
        {
            int y = get_distance(x, z);
            for (int _y = 0; _y <= y && _y < height; _y++)
                SetField(x, _y, z, FIELDTYPE_STONE);
            for (int _y = y + 1; _y < height; _y++)
                SetField(x, _y, z, FIELDTYPE_AIR);
        }
}
