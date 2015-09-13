#include <random>
#include "world.h"

using namespace std;

void World::Generate()
{
    random_device rd;
    mt19937 rand(rd());
    for (int x = 0; x < width; x++)
        for (int z = 0; z < depth; z++)
        {
            int y = rand() % height;
            for (int _y = 0; _y <= y; _y++)
                SetField(x, _y, z, FIELDTYPE_STONE);
            for (int _y = y + 1; _y < height; _y++)
                SetField(x, _y, z, FIELDTYPE_AIR);
        }
}
