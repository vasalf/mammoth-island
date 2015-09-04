#ifndef RENDER_H_
#define RENDER_H_

#include <vector>
#include "glinclude.h"
#include "polyhedron.h"

extern std::vector<Polyhedron> AlivePolyhedrons;

void render_scene();

#endif //RENDER_H_
