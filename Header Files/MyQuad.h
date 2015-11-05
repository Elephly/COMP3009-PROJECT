#ifndef MYQUAD_H
#define MYQUAD_H

#include "MyDefines.h"
#include "MyTriangle.h"

class MyQuad : public MyGraphicsObject3D
{
public:

	MyQuad(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		MyColorRGBA &color1 = MyColorRGBA(),
		MyColorRGBA &color2 = MyColorRGBA(),
		MyColorRGBA &color3 = MyColorRGBA(),
		MyColorRGBA &color4 = MyColorRGBA());

private:
	MyVertex4D myVertices[6];
};

#endif // MYQUAD_H
