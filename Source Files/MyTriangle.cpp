#include "MyTriangle.h"

#include <cstdio> // temp

#include <glew.h>

MyTriangle::MyTriangle(MyVertex3D &vertex1, MyVertex3D &vertex2, MyVertex3D &vertex3)
{
	currentVertex = 0;
	vertices[0] = vertex1;
	vertices[1] = vertex2;
	vertices[2] = vertex3;
	shaderProgram = 0;
	vertexArrayObject = 0;
}

MyTriangle::~MyTriangle()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void MyTriangle::Initialize(MyShaderProgram *shader)
{
	shaderProgram = shader;

	GLuint vbo;
	MyVertex3D v;

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex3D) * 3, vertices, GL_STATIC_DRAW);

	GLuint positionLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxPos");
	glEnableVertexAttribArray(positionLoc);
	unsigned int attAddress = (unsigned int *)&v.GetVector() - (unsigned int *)&v;
	glVertexAttribPointer(positionLoc, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex3D), (void *)attAddress);
	GLuint colorLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxColor");
	glEnableVertexAttribArray(colorLoc);
	attAddress += sizeof(MyVector3D);
	glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex3D), (void *)attAddress);

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	glDeleteBuffers(1, &vbo);
}

void MyTriangle::Draw()
{
	glUseProgram(shaderProgram->GetShaderProgram());
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

MyVertex3D & MyTriangle::GetNextVertex()
{
	int i = currentVertex;
	currentVertex = (currentVertex + 1) % 3;
	return vertices[i];
}

void MyTriangle::SetShader(MyShaderProgram *shader)
{
	shaderProgram = shader;
}

void MyTriangle::SetVertex(MyVertex3D & vertex)
{
	vertices[currentVertex] = vertex;
	currentVertex = (currentVertex + 1) % 3;
}

void MyTriangle::SetVertex(float x, float y, float z, MyColorRGBA & color)
{
	vertices[currentVertex] = MyVertex3D(x, y, z, color);
	currentVertex = (currentVertex + 1) % 3;
}
