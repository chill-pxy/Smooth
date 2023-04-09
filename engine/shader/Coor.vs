#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

smooth out vec3 ex_originalPosition;

void main()
{
    gl_Position=projection * view * model * vec4(aPos, 1.0);
    ex_originalPosition = vec3(aPos.xyz);
}