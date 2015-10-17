#ifndef MYQUAD_H
#define MYQUAD_H

#include "MyDefines.h"
#include "MyTriangle.h"

class MyQuad : MyGraphicsObject3D
{
public:
	MyQuad(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		MyVertex4D &vertex1 = MyVertex4D(MyVector4D(-1.0f, -1.0f)),
		MyVertex4D &vertex2 = MyVertex4D(MyVector4D(-1.0f, 1.0f)),
		MyVertex4D &vertex3 = MyVertex4D(MyVector4D(1.0f, 1.0f)),
		MyVertex4D &vertex4 = MyVertex4D(MyVector4D(1.0f, -1.0f)));
	~MyQuad();

	virtual void Initialize(MyShaderProgram *shader);
	virtual void Update();
	virtual void Draw();

	// Setters
	virtual void SetShader(MyShaderProgram *shader);

private:
	MyTriangle *t1;
	MyTriangle *t2;
};

#endif // MYQUAD_H
