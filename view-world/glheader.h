#ifndef GLHEADER_H_
#define GLHEADER_H_

#include "glinclude.h"
#include <string>
#include <vector>
#include "polyhedron.h"

void init_gl(int argc, char** argv);
void compile_shaders(std::string vsh_filename, std::string fsh_filename);

void render_scene();

#endif //GLHEADER_H_
