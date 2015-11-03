#include "MyTriangle.h"

#include <glew.h>

MyTriangle::MyTriangle(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyVertex4D & vertex1, MyVertex4D & vertex2, MyVertex4D & vertex3) :
	MyGraphicsObject3D(position, scale, rotation)
{
	currentVertex = 0;
	vertices[0] = vertex1;
	vertices[1] = vertex3;
	vertices[2] = vertex2;
	vertexArrayObject = 0;
}

MyTriangle::~MyTriangle()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void MyTriangle::Initialize(MyShaderProgram *shader)
{
	MyGraphicsObject3D::Initialize(shader);

	GLuint vbo;
	MyVertex4D v;

	unsigned int *addr_ver = (unsigned int *)&v;
	unsigned int *addr_vec = (unsigned int *)&v.GetVector().GetXAddr();
	unsigned int *addr_col = (unsigned int *)&v.GetColor().GetRedAddr();

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex4D) * 3, vertices, GL_STATIC_DRAW);

	GLuint positionLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxPos");
	glEnableVertexAttribArray(positionLoc);
	unsigned int attAddress = (unsigned int)addr_vec - (unsigned int)addr_ver;
	glVertexAttribPointer(positionLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);
	GLuint colorLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxColor");
	glEnableVertexAttribArray(colorLoc);
	attAddress = (unsigned int)addr_col - (unsigned int)addr_ver;
	glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	glDeleteBuffers(1, &vbo);
}

void MyTriangle::Update()
{
}

void MyTriangle::Draw()
{
	MyGraphicsObject3D::Draw();
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

MyVertex4D & MyTriangle::GetCurrentVertex()
{
	return vertices[currentVertex];
}

MyVertex4D & MyTriangle::GetNextVertex()
{
	int i = currentVertex;
	currentVertex = (currentVertex + 1) % 3;
	return vertices[i];
}

void MyTriangle::SetCurrentVertex(MyVertex4D & vertex)
{
	vertices[currentVertex] = vertex;
}

void MyTriangle::SetNextVertex(MyVertex4D & vertex)
{
	SetCurrentVertex(vertex);
	currentVertex = (currentVertex + 1) % 3;
}

void MyTriangle::SetCurrentVertex(float x, float y, float z, float w, MyColorRGBA & color)
{
	vertices[currentVertex] = MyVertex4D(x, y, z, w, color);
}

void MyTriangle::SetNextVertex(float x, float y, float z, float w, MyColorRGBA & color)
{
	SetCurrentVertex(x, y, z, w, color);
	currentVertex = (currentVertex + 1) % 3;
}
