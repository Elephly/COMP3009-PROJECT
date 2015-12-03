#include "MyQuad.h"

MyQuad::MyQuad(MyIndexedVertexArray *vertexArray, MyVector3D & position, MyVector3D & scale, MyVector3D & rotation) :
	MyGraphicsObject3D(vertexArray, position, scale, rotation)
{
}

MyQuad::~MyQuad()
{
}
