#ifndef MYQUAD_H
#define MYQUAD_H

#include "MyDefines.h"
#include "MyTriangle.h"

class MyQuad
{
public:
	MyQuad(MyVertex4D &vertex1 = MyVertex4D(), MyVertex4D &vertex2 = MyVertex4D(), MyVertex4D &vertex3 = MyVertex4D(), MyVertex4D &vertex4 = MyVertex4D());
	~MyQuad();

	void Initialize(MyShaderProgram *shader);
	void Draw();

private:
	MyTriangle *t1;
	MyTriangle *t2;
};

#endif // MYQUAD_H
