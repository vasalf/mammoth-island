#include "polyhedron.h"
#include "glvars.h"
#include "glheader.h"

Polygon::Polygon() {}

Polygon::Polygon(std::vector<vect> _poly, Mover* _mover)
{
    poly = _poly;
    mvr = _mover;
    vect a[poly.size()];
    for (int i = 0; i < (int)poly.size(); i++)
        a[i] = poly[i];
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(a), a, GL_STATIC_DRAW);
}

void Polygon::__draw() const
{
    Matrix position = mvr->GetMatrix();
    glUniformMatrix4fv(glWorldLocation, 1, GL_TRUE, &position.m[0][0]);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glDrawArrays(GL_TRIANGLES, 0, poly.size());

    glDisableVertexAttribArray(0);
}

Polyhedron::Polyhedron(std::vector<std::vector<vect> > pts)
{
    surfaces.resize(pts.size());
    for (int i = 0; i < (int)surfaces.size(); i++)
        surfaces[i] = *(new Polygon(pts[i], &mvr)); 
}

const Polygon& Polyhedron::operator[](const int& i) const
{
    return surfaces[i]; 
}

Polygon& Polyhedron::operator[](const int& i)
{
    return surfaces[i];
}

void Polyhedron::Draw() const
{
    for (int i = 0; i < (int)surfaces.size(); i++)
        surfaces[i].__draw();
}
