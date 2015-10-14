#include "MyVertex.h"

MyVertex::MyVertex(MyColorRGBA & color)
{
	c = color;
}

MyVertex::~MyVertex() { }

MyColorRGBA & MyVertex::GetColor()
{
	return c;
}

void MyVertex::SetColor(float red, float green, float blue, float alpha)
{
	c = MyColorRGBA(red, green, blue, alpha);
}

void MyVertex::SetColor(MyColorRGBA & color)
{
	c = color;
}

MyVertex2D::MyVertex2D(float x, float y, MyColorRGBA & color) :
	MyVertex(color)
{
	v = MyVector2D(x, y);
}

MyVertex2D::MyVertex2D(MyVector2D &vector, MyColorRGBA &color) :
	MyVertex(color)
{
	v = vector;
}

MyVertex2D::~MyVertex2D()
{
}

MyVector2D & MyVertex2D::GetVector()
{
	return v;
}

void MyVertex2D::SetVector(float x, float y)
{
	v = MyVector2D(x, y);
}

void MyVertex2D::SetVector(MyVector2D & vector)
{
	v = vector;
}

MyVertex3D::MyVertex3D(float x, float y, float z, MyColorRGBA &color) :
	MyVertex(color)
{
	v = MyVector3D(x, y, z);
}

MyVertex3D::MyVertex3D(MyVector3D &vector, MyColorRGBA &color) :
	MyVertex(color)
{
	v = vector;
}

MyVertex3D::~MyVertex3D()
{
}

MyVector3D & MyVertex3D::GetVector()
{
	return v;
}

void MyVertex3D::SetVector(float x, float y, float z)
{
	v = MyVector3D(x, y, z);
}

void MyVertex3D::SetVector(MyVector3D & vector)
{
	v = vector;
}
