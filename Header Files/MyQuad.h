#ifndef MYQUAD_H
#define MYQUAD_H

#include "MyDefines.h"
#include "MyTriangle.h"

class MyQuad : public MyGraphicsObject3D
{
public:
	MyQuad(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		MyVertex4D &vertex1 = MyVertex4D(MyVector4D(-1.0f, -1.0f)),
		MyVertex4D &vertex2 = MyVertex4D(MyVector4D(-1.0f, 1.0f)),
		MyVertex4D &vertex3 = MyVertex4D(MyVector4D(1.0f, 1.0f)),
		MyVertex4D &vertex4 = MyVertex4D(MyVector4D(1.0f, -1.0f)));
};

#endif // MYQUAD_H
