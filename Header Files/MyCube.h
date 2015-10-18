#ifndef MYCUBE_H
#define MYCUBE_H

#include "MyGraphicsObject3D.h"
#include "MyQuad.h"

class MyCube : public MyGraphicsObject3D
{
public:
	MyCube(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		MyColorRGBA &color1 = MyColorRGBA(), MyColorRGBA &color2 = MyColorRGBA(), MyColorRGBA &color3 = MyColorRGBA(),
		MyColorRGBA &color4 = MyColorRGBA(), MyColorRGBA &color5 = MyColorRGBA(), MyColorRGBA &color6 = MyColorRGBA());
	MyCube(bool solidColor, MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		MyColorRGBA &color = MyColorRGBA());
};

#endif // MYCUBE_H