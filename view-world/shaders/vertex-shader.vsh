attribute vec3 Position;

uniform mat4 glWorld;
uniform mat4 glProj;

void main()
{
    gl_Position = glProj * glWorld * vec4(Position, 1.0);
}
