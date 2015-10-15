#version 150

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

attribute vec3 vtxPos;
attribute vec4 vtxColor;

varying vec4 vColor;

void main(void)

{
	//gl_Position = vec4(vtxPos, 1.0);
	//gl_Position = projection * view * model * vtxPos;
	gl_Position = projection * view * vec4(vtxPos, 1.0);
	vColor = vtxColor;
}