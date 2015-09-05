#include <fstream>
#include <cstring>
#include <cassert>
#include <iostream>
#include "glheader.h"
#include "glvars.h"

using namespace std;

GLuint glWorldLocation;

static void init_glut_cb()
{
    glutDisplayFunc(render_scene); 
    glutIdleFunc(render_scene);
}

void init_gl(int* argc, char** argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("View world");

    init_glut_cb();
    assert(glewInit() == GLEW_OK);
}

static string read_file(string filename)
{
    ifstream fin(filename);
    assert(fin);
    string s;

    fin.seekg(0, ios::end);
    s.reserve(fin.tellg());
    fin.seekg(0, ios::beg);

    s.assign(istreambuf_iterator<char>(fin), istreambuf_iterator<char>());
    fin.close();
    return s;
}

static void add_shader(GLuint program, const char* text, GLenum type)
{
    GLuint sobj = glCreateShader(type);
    const GLchar* p[1];
    p[0] = text;
    GLint lens[1];
    lens[0] = strlen(text);
    glShaderSource(sobj, 1, p, lens);
    glCompileShader(sobj);
    GLint success;
    glGetShaderiv(sobj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        cerr << "Shader compilation error" << endl;
        GLchar log[1024];
        glGetShaderInfoLog(sobj, 1024, NULL, log);
        cerr << log << endl;
    }
    assert(success);
    glAttachShader(program, sobj);
}

void compile_shaders(string vsh_filename, string fsh_filename)
{
    GLuint sprog = glCreateProgram();
    assert(sprog);
    add_shader(sprog, read_file(vsh_filename).c_str(), GL_VERTEX_SHADER);
    add_shader(sprog, read_file(fsh_filename).c_str(), GL_FRAGMENT_SHADER);

    GLint success = 0;

    glLinkProgram(sprog);
    glGetProgramiv(sprog, GL_LINK_STATUS, &success);
    assert(success);

    glValidateProgram(sprog);
    glGetProgramiv(sprog, GL_VALIDATE_STATUS, &success);
    assert(success);

    glUseProgram(sprog);

    glWorldLocation = glGetUniformLocation(sprog, "glWorld");
    assert(glWorldLocation != 0xffffffff);
}


