#ifndef WORLD_H_
#define WORLD_H_

#include <string>

#define FIELDTYPE_FRESHWATER 0
#define FIELDTYPE_SHALLOWWATER 1
#define FIELDTYPE_MEDIUMWATER 2
#define FIELDTYPE_DEEPWATER 3

#define FIELDTYPE_STONE 4
#define FIELDTYPE_GROUND 5
#define FIELDTYPE_SAND 6
#define FIELDTYPE_AIR 7

class World
{
    char* data;
    int height, width, depth;
  public:
    World(std::string filename);
    char GetField(int x, int y, int z);
};

#endif //WORLD_H_
