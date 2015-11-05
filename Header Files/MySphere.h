#ifndef MYSPHERE_H
#define MYSPHERE_H

#include "MyGraphicsObject3D.h"

class MySphere : MyGraphicsObject3D
{
public:
	MySphere(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		int latitudeSamples = 32, int longitudeSamples = 32, MyColorRGBA &color1 = MyColorRGBA());
};

#endif // MYSPHERE_H
