#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor;

void main()
{
	gl_Position = model*vec4(aPos, 1.0f);
	ourColor=vec3(aPos.x,aPos.y,aPos.z);
}