#include "MySphere.h"

#include "MyIncludes.h"

MySphere::MySphere(MyIndexedVertexArray *vertexArray, MyVector3D & position, MyVector3D & scale, MyVector3D & rotation) :
	MyGraphicsObject3D(vertexArray, position, scale, rotation)
{
}

MySphere::~MySphere()
{
}
