#include "MyCube.h"

MyCube::MyCube(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyColorRGBA & color1, MyColorRGBA & color2, MyColorRGBA & color3, MyColorRGBA & color4, MyColorRGBA & color5, MyColorRGBA & color6) :
	MyGraphicsObject3D(position, scale, rotation)
{
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, 1.0f), color1),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, 1.0f), color1),
		MyVertex4D(MyVector4D(1.0f, 1.0f, 1.0f), color1),
		MyVertex4D(MyVector4D(1.0f, -1.0f, 1.0f), color1)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, -1.0f), color2),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, -1.0f), color2),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, 1.0f), color2),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, 1.0f), color2)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, -1.0f, -1.0f), color3),
		MyVertex4D(MyVector4D(1.0f, 1.0f, -1.0f), color3),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, -1.0f), color3),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, -1.0f), color3)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, -1.0f, 1.0f), color4),
		MyVertex4D(MyVector4D(1.0f, 1.0f, 1.0f), color4),
		MyVertex4D(MyVector4D(1.0f, 1.0f, -1.0f), color4),
		MyVertex4D(MyVector4D(1.0f, -1.0f, -1.0f), color4)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, -1.0f, 1.0f), color5),
		MyVertex4D(MyVector4D(1.0f, -1.0f, -1.0f), color5),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, -1.0f), color5),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, 1.0f), color5)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, 1.0f, -1.0f), color6),
		MyVertex4D(MyVector4D(1.0f, 1.0f, 1.0f), color6),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, 1.0f), color6),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, -1.0f), color6)));
}

MyCube::MyCube(bool solidColor, MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyColorRGBA & color) :
	MyGraphicsObject3D(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D())
{
	MyColorRGBA c1, c2, c3, c4, c5, c6;
	c1 = c2 = c3 = c4 = c5 = c6 = (solidColor ? color : MyColorRGBA());
	c1 = color;

	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, 1.0f), c1),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, 1.0f), c1),
		MyVertex4D(MyVector4D(1.0f, 1.0f, 1.0f), c1),
		MyVertex4D(MyVector4D(1.0f, -1.0f, 1.0f), c1)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, -1.0f), c2),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, -1.0f), c2),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, 1.0f), c2),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, 1.0f), c2)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, -1.0f, -1.0f), c3),
		MyVertex4D(MyVector4D(1.0f, 1.0f, -1.0f), c3),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, -1.0f), c3),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, -1.0f), c3)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, -1.0f, 1.0f), c4),
		MyVertex4D(MyVector4D(1.0f, 1.0f, 1.0f), c4),
		MyVertex4D(MyVector4D(1.0f, 1.0f, -1.0f), c4),
		MyVertex4D(MyVector4D(1.0f, -1.0f, -1.0f), c4)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, -1.0f, 1.0f), c5),
		MyVertex4D(MyVector4D(1.0f, -1.0f, -1.0f), c5),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, -1.0f), c5),
		MyVertex4D(MyVector4D(-1.0f, -1.0f, 1.0f), c5)));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(MyVector4D(1.0f, 1.0f, -1.0f), c6),
		MyVertex4D(MyVector4D(1.0f, 1.0f, 1.0f), c6),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, 1.0f), c6),
		MyVertex4D(MyVector4D(-1.0f, 1.0f, -1.0f), c6)));
}