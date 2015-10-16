#version 150

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

attribute vec4 vtxPos;
attribute vec4 vtxColor;

varying vec4 vColor;

void main(void)

{
	gl_Position = projection * view * transform * vtxPos;
	vColor = vtxColor;
}