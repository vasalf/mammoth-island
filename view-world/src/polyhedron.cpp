#include "polyhedron.h"
#include "glvars.h"
#include "glheader.h"

Polygon::Polygon() {}

Polygon::Polygon(std::vector<vect> _poly, Mover* _mover)
{
    color = vect(1, 0, 0);
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
    glUniform4f(glInputColorLocation, color.x, color.y, color.z, 1);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glDrawArrays(GL_POLYGON, 0, poly.size());

    glDisableVertexAttribArray(0);
}

std::vector<vect> Polygon::__get_poly() const
{
    return poly;
}

Polyhedron::Polyhedron(std::vector<std::vector<vect> > pts)
{
    surfaces.resize(pts.size());
    for (int i = 0; i < (int)surfaces.size(); i++)
        surfaces[i] = Polygon(pts[i], &mvr); 
}

Polyhedron::Polyhedron(const Polyhedron& other)
{
    mvr = other.mvr;
    surfaces.resize(other.surfaces.size());
    for (int i = 0; i < (int)surfaces.size(); i++)
    {
        surfaces[i] = Polygon(other.surfaces[i].__get_poly(), &mvr);
        surfaces[i].color = other.surfaces[i].color;
    }
}

const Polygon& Polyhedron::operator[](const int& i) const
{
    return surfaces[i]; 
}

Polygon& Polyhedron::operator[](const int& i)
{
    return surfaces[i];
}

Mover& Polyhedron::GetMover()
{
    return mvr;
}

void Polyhedron::Draw() const
{
    for (int i = 0; i < (int)surfaces.size(); i++)
        surfaces[i].__draw();
}
