#ifndef POLYHEDRON_H_
#define POLYHEDRON_H_

#include <vector>
#include "mover.h"
#include "geom.h"
#include "glheader.h"

/* This is a helper class to Polyhedron.
 * Please, do not construct it directly or use it's shadowed with "__" methods
 * (e.g. __draw), only using interface provided by Polyhedron to access it.
*/

class Polygon
{
    std::vector<vect> poly;
    Mover* mvr;
    GLuint VBO;
  public:
    Polygon();
    Polygon(std::vector<vect> _poly, Mover* _mover);
    void __draw() const;
};

class Polyhedron
{
    std::vector<Polygon> surfaces;
    Mover mvr;
  public:
    Polyhedron(std::vector<std::vector<vect> > pts);
    Mover& GetMover();
    const Polygon& operator[](const int& i) const;
    Polygon& operator[](const int& i);
    void Draw() const;
};

#endif //POLYHEDRON_H_
