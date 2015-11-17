#include "MyVertex.h"

MyVertex::MyVertex(MyColorRGBA const & color) :
	c(color), t(MyVector2D())
{
}

MyVertex::~MyVertex() { }

const MyColorRGBA & MyVertex::GetColor() const
{
	return c;
}

const MyVector2D & MyVertex::GetTextureCoord() const
{
	return t;
}

void MyVertex::SetColor(float const & red, float const & green, float const & blue, float const & alpha)
{
	c = MyColorRGBA(red, green, blue, alpha);
}

void MyVertex::SetColor(MyColorRGBA const & color)
{
	c = color;
}

void MyVertex::SetTextureCoord(float const & x, float const & y)
{
	t = MyVector2D(x, y);
}

void MyVertex::SetTextureCoord(MyVector2D const & textureCoord)
{
	t = textureCoord;
}

MyVertex2D::MyVertex2D(float x, float y, MyColorRGBA const & color) :
	p(MyVector2D(x, y)), MyVertex(color)
{
}

MyVertex2D::MyVertex2D(MyVector2D & position, MyColorRGBA const & color) :
	p(position), MyVertex(color)
{
}

MyVertex2D::~MyVertex2D()
{
}

const MyVector2D & MyVertex2D::GetPosition() const
{
	return p;
}

void MyVertex2D::SetPosition(float const & x, float const & y)
{
	p = MyVector2D(x, y);
}

void MyVertex2D::SetPosition(MyVector2D const & position)
{
	p = position;
}

MyVertex3D::MyVertex3D(float x, float y, float z, MyColorRGBA const & color) :
	p(MyVector3D(x, y, z)), n(MyVector3D()), MyVertex(color)
{
}

MyVertex3D::MyVertex3D(MyVector3D const & position, MyColorRGBA const & color) :
	p(position), n(MyVector3D()), MyVertex(color)
{
}

MyVertex3D::~MyVertex3D()
{
}

const MyVector3D & MyVertex3D::GetPosition() const
{
	return p;
}

const MyVector3D & MyVertex3D::GetNormal() const
{
	return n;
}

void MyVertex3D::SetPosition(float const & x, float const & y, float const & z)
{
	p = MyVector3D(x, y, z);
}

void MyVertex3D::SetPosition(MyVector2D const & position, float const & z)
{
	p = MyVector3D(position, z);
}

void MyVertex3D::SetPosition(MyVector3D const & position)
{
	p = position;
}

void MyVertex3D::SetNormal(float const & x, float const & y, float const & z)
{
	n = MyVector3D(x, y, z);
}

void MyVertex3D::SetNormal(MyVector2D const & normal, float const & z)
{
	n = MyVector3D(normal, z);
}

void MyVertex3D::SetNormal(MyVector3D const & normal)
{
	n = normal;
}

MyVertex4D::MyVertex4D(float x, float y, float z, float w, MyColorRGBA const & color) :
	p(MyVector4D(x, y, z, w)), n(MyVector4D()), MyVertex(color)
{
}

MyVertex4D::MyVertex4D(MyVector4D const & position, MyColorRGBA const & color) :
	p(position), n(MyVector4D()), MyVertex(color)
{
}

MyVertex4D::~MyVertex4D()
{
}

const MyVector4D & MyVertex4D::GetPosition() const
{
	return p;
}

const MyVector4D & MyVertex4D::GetNormal() const
{
	return n;
}

void MyVertex4D::SetPosition(float const & x, float const & y, float const & z, float const & w)
{
	p = MyVector4D(x, y, z, w);
}

void MyVertex4D::SetPosition(MyVector2D const & position, float const & z, float const & w)
{
	p = MyVector4D(position, z, w);
}

void MyVertex4D::SetPosition(MyVector3D const & position, float const & w)
{
	p = MyVector4D(position, w);
}

void MyVertex4D::SetPosition(MyVector4D const & position)
{
	p = position;
}

void MyVertex4D::SetNormal(float const & x, float const & y, float const & z, float const & w)
{
	n = MyVector4D(x, y, z, w);
}

void MyVertex4D::SetNormal(MyVector2D const & normal, float const & z, float const & w)
{
	n = MyVector4D(normal, z, w);
}

void MyVertex4D::SetNormal(MyVector3D const & normal, float const & w)
{
	n = MyVector4D(normal, w);
}

void MyVertex4D::SetNormal(MyVector4D const & normal)
{
	n = normal;
}
