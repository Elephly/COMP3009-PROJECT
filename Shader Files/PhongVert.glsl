#version 400

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;
uniform vec4 lightPosition;

attribute vec4 vtxPosition;
attribute vec4 vtxNormal;
attribute vec4 vtxColor;
attribute vec2 vtxTextureCoord;

varying vec3 vPosition;
varying vec3 vNormal;
varying vec4 vColor;
varying vec2 vTextureCoord;
varying vec3 light;

void main(void)
{
	gl_Position = projection * view * transform * vtxPosition;
	vPosition = vec3(view * transform * vtxPosition);
	vNormal = vec3(transpose(inverse(view * transform)) * vtxNormal);
	vColor = vtxColor;
	vTextureCoord = vtxTextureCoord;
	light = vec3(view * lightPosition);
}