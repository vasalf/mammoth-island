attribute vec3 Position;

uniform mat4 glWorld;

void main()
{
    gl_Position = glWorld * vec4(Position, 1.0);
}
