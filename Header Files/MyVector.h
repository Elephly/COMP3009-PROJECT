#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "MyGeometry.h"

class MyVector
{
public:
	virtual ~MyVector() = 0;
};

class MyVector2D : public MyPoint2D, public MyVector
{
public:
	MyVector2D(float x = 0.0f, float y = 0.0f);
	~MyVector2D();
};

class MyVector3D : public MyPoint3D, public MyVector
{
public:
	MyVector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	~MyVector3D();
};

#endif // MYVECTOR_H
