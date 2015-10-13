#ifndef MYQUAD_H
#define MYQUAD_H

#include "MyDefines.h"
#include "MyTriangle.h"

class MyQuad
{
public:
	MyQuad(MyVertex3D &vertex1 = MyVertex3D(), MyVertex3D &vertex2 = MyVertex3D(), MyVertex3D &vertex3 = MyVertex3D(), MyVertex3D &vertex4 = MyVertex3D());
	~MyQuad();

	void Initialize(MyShaderProgram *shader);
	void Draw();

private:
	MyTriangle *t1;
	MyTriangle *t2;
};

#endif // MYQUAD_H
