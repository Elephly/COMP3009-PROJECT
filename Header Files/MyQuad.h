#ifndef MYQUAD_H
#define MYQUAD_H

#include "MyDefines.h"
#include "MyGraphicsObject3D.h"

class MyQuad : public MyGraphicsObject3D
{
public:
	MyQuad(MyIndexedVertexArray *vertexArray = 0, MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D());
	~MyQuad();

};

#endif // MYQUAD_H
