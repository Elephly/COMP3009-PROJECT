#ifndef MYOBJECT3D_H
#define MYOBJECT3D_H

#include "MyMatrix.h"

class MyObject3D
{
public:
	MyObject3D();
	virtual ~MyObject3D() = 0;

	virtual void Update();

	// Getters
	virtual const MyMatrix4 &GetModelMatrix();
	virtual const MyMatrix4 &GetTransformMatrix();

protected:
	MyMatrix4 modelMatrix;
	MyMatrix4 transformMatrix;
};

#endif // MYOBJECT3D_H
