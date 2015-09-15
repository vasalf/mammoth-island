#ifndef GLHEADER_H_
#define GLHEADER_H_

#include "glinclude.h"
#include <string>
#include <vector>
#include "polyhedron.h"
#include "matrix.h"

void init_gl(int* argc, char** argv);
void compile_shaders(std::string vsh_filename, std::string fsh_filename);

Matrix PerspectiveMatrix();

void render_scene();

#endif //GLHEADER_H_
