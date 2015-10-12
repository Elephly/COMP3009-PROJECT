#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#include "MyGeometry.h"

class MyTriangle
{
public:
	MyTriangle(MyVertex3D &vertex1 = MyVertex3D(), MyVertex3D &vertex2 = MyVertex3D(), MyVertex3D &vertex3 = MyVertex3D());
	~MyTriangle();

	void Draw();

private:
	MyVertex3D vertices[3];
};

#endif // MYTRIANGLE_H
