#version 150

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

attribute vec4 vtxPosition;
attribute vec4 vtxColor;

varying vec4 vColor;

void main(void)

{
	gl_Position = projection * view * transform * vtxPosition;
	vColor = vec4(1.0, 1.0, 1.0, 1.0);
}