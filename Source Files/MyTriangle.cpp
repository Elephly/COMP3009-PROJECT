#include "MyTriangle.h"

MyTriangle::MyTriangle(MyVertex3D &vertex1, MyVertex3D &vertex2, MyVertex3D &vertex3)
{
	vertices[0] = vertex1;
	vertices[1] = vertex2;
	vertices[2] = vertex3;
}

MyTriangle::~MyTriangle()
{
}

void MyTriangle::Draw()
{
}
