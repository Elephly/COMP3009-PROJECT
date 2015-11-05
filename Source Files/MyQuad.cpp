#include "MyQuad.h"

MyQuad::MyQuad(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyColorRGBA & color1, MyColorRGBA & color2, MyColorRGBA & color3, MyColorRGBA & color4)
{
	MyVertex4D v1 = MyVertex4D(-0.5f, -0.5f, 0.0f, 1.0f, color1);
	MyVertex4D v2 = MyVertex4D(0.5f, -0.5f, 0.0f, 1.0f, color2);
	MyVertex4D v3 = MyVertex4D(0.5f, 0.5f, 0.0f, 1.0f, color3);
	MyVertex4D v4 = MyVertex4D(-0.5f, 0.5f, 0.0f, 1.0f, color4);
	myVertices[0] = v1;
	myVertices[1] = v2;
	myVertices[2] = v3;
	myVertices[3] = v1;
	myVertices[4] = v3;
	myVertices[5] = v4;
	vertices = (MyVertex4D **)&myVertices;
	numVertices = 6;
}