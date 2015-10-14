#include "MyVector.h"

MyVector::~MyVector() { }

MyVector2D::MyVector2D(float x, float y) :
	MyPoint2D(x, y)
{
}

MyVector2D::~MyVector2D()
{
}

MyVector3D::MyVector3D(float x, float y, float z) :
	MyPoint3D(x, y, z)
{
}

MyVector3D::~MyVector3D()
{
}