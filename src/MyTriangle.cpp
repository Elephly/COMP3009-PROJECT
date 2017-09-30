#include "MyTriangle.h"

#include <glew.h>

MyTriangle::MyTriangle(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyVertex4D & vertex1, MyVertex4D & vertex2, MyVertex4D & vertex3) :
	MyGraphicsObject3D(position, scale, rotation)
{
	currentVertex = 0;
	myVertices[0] = vertex1;
	myVertices[1] = vertex2;
	myVertices[2] = vertex3;
	vertices = (MyVertex4D **)&myVertices;
	numVertices = 3;
}

MyVertex4D & MyTriangle::GetCurrentVertex()
{
	return myVertices[currentVertex];
}

MyVertex4D & MyTriangle::GetNextVertex()
{
	int i = currentVertex;
	currentVertex = (currentVertex + 1) % 3;
	return myVertices[i];
}

void MyTriangle::SetCurrentVertex(MyVertex4D & vertex)
{
	myVertices[currentVertex] = vertex;
}

void MyTriangle::SetNextVertex(MyVertex4D & vertex)
{
	SetCurrentVertex(vertex);
	currentVertex = (currentVertex + 1) % 3;
}

void MyTriangle::SetCurrentVertex(float x, float y, float z, float w, MyColorRGBA & color)
{
	myVertices[currentVertex] = MyVertex4D(x, y, z, w, color);
}

void MyTriangle::SetNextVertex(float x, float y, float z, float w, MyColorRGBA & color)
{
	SetCurrentVertex(x, y, z, w, color);
	currentVertex = (currentVertex + 1) % 3;
}
