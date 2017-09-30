#ifndef MYSPHERE_H
#define MYSPHERE_H

#include "MyGraphicsObject3D.h"
#include "MyMeshFactory.h"

class MySphere : public MyGraphicsObject3D
{
public:
	MySphere(MyIndexedVertexArray *vertexArray = MyMeshFactory::CreateSphere("Sphere"), MyVector3D &position = MyVector3D(),
		MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D());
	virtual ~MySphere();

};

#endif // MYSPHERE_H
