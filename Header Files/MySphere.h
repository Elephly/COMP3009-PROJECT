#ifndef MYSPHERE_H
#define MYSPHERE_H

#include "MyGraphicsObject3D.h"

class MySphere : public MyGraphicsObject3D
{
public:
	MySphere(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		int latitudeSamples = 32, int longitudeSamples = 64, MyColorRGBA &color1 = MyColorRGBA(), MyColorRGBA &color2 = MyColorRGBA());
	MySphere(MyColorRGBA &solidColor, MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f),
		MyVector3D &rotation = MyVector3D(), int latitudeSamples = 32, int longitudeSamples = 64);
	virtual ~MySphere();

private:
	MyVertex4D *myVertices;
};

#endif // MYSPHERE_H
