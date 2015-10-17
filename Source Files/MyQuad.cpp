#include "MyQuad.h"

MyQuad::MyQuad(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyVertex4D & vertex1, MyVertex4D & vertex2, MyVertex4D & vertex3, MyVertex4D & vertex4) :
	MyGraphicsObject3D(position, scale, rotation)
{
	children->push_back(new MyTriangle(position, scale, rotation, vertex1, vertex2, vertex4));
	children->push_back(new MyTriangle(position, scale, rotation, vertex2, vertex3, vertex4));
}

MyQuad::~MyQuad()
{
}