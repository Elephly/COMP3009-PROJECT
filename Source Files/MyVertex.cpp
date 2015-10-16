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

void MyVertex::SetColor(float const & red, float const & green, float const & blue, float const & alpha)
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

void MyVertex2D::SetVector(float const & x, float const & y)
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

void MyVertex3D::SetVector(float const & x, float const & y, float const & z)
{
	v = MyVector3D(x, y, z);
}

void MyVertex3D::SetVector(MyVector2D & vector, float const & z)
{
	v = MyVector3D(vector, z);
}

void MyVertex3D::SetVector(MyVector3D & vector)
{
	v = vector;
}

MyVertex4D::MyVertex4D(float x, float y, float z, float w, MyColorRGBA &color) :
	MyVertex(color)
{
	v = MyVector4D(x, y, z, w);
}

MyVertex4D::MyVertex4D(MyVector4D &vector, MyColorRGBA &color) :
	MyVertex(color)
{
	v = vector;
}

MyVertex4D::~MyVertex4D()
{
}

MyVector4D & MyVertex4D::GetVector()
{
	return v;
}

void MyVertex4D::SetVector(float const & x, float const & y, float const & z, float const & w)
{
	v = MyVector4D(x, y, z, w);
}

void MyVertex4D::SetVector(MyVector2D & vector, float const & z, float const & w)
{
	v = MyVector4D(vector, z, w);
}

void MyVertex4D::SetVector(MyVector3D & vector, float const & w)
{
	v = MyVector4D(vector, w);
}

void MyVertex4D::SetVector(MyVector4D & vector)
{
	v = vector;
}
