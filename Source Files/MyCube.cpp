#include "MyCube.h"

MyCube::MyCube(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyColorRGBA & color1, MyColorRGBA & color2, MyColorRGBA & color3, MyColorRGBA & color4, MyColorRGBA & color5, MyColorRGBA & color6) :
	MyGraphicsObject3D(position, scale, rotation)
{
	/*
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), color1, color1, color1, color1));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), color2, color2, color2, color2));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), color3, color3, color3, color3));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), color4, color4, color4, color4));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), color5, color5, color5, color5));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), color6, color6, color6, color6));
	*/
	MyVertex4D v01 = MyVertex4D(-0.5f, -0.5f, 0.5f, 1.0f, color1);
	MyVertex4D v02 = MyVertex4D(0.5f, -0.5f, 0.5f, 1.0f, color1);
	MyVertex4D v03 = MyVertex4D(0.5f, 0.5f, 0.5f, 1.0f, color1);
	MyVertex4D v04 = MyVertex4D(-0.5f, 0.5f, 0.5f, 1.0f, color1);
	MyVertex4D v05 = MyVertex4D(0.5f, -0.5f, -0.5f, 1.0f, color2);
	MyVertex4D v06 = MyVertex4D(-0.5f, -0.5f, -0.5f, 1.0f, color2);
	MyVertex4D v07 = MyVertex4D(-0.5f, 0.5f, -0.5f, 1.0f, color2);
	MyVertex4D v08 = MyVertex4D(0.5f, 0.5f, -0.5f, 1.0f, color2);
	MyVertex4D v09 = MyVertex4D(-0.5f, -0.5f, -0.5f, 1.0f, color3);
	MyVertex4D v10 = MyVertex4D(-0.5f, -0.5f, 0.5f, 1.0f, color3);
	MyVertex4D v11 = MyVertex4D(-0.5f, 0.5f, 0.5f, 1.0f, color3);
	MyVertex4D v12 = MyVertex4D(-0.5f, 0.5f, -0.5f, 1.0f, color3);
	MyVertex4D v13 = MyVertex4D(0.5f, -0.5f, 0.5f, 1.0f, color4);
	MyVertex4D v14 = MyVertex4D(0.5f, -0.5f, -0.5f, 1.0f, color4);
	MyVertex4D v15 = MyVertex4D(0.5f, 0.5f, -0.5f, 1.0f, color4);
	MyVertex4D v16 = MyVertex4D(0.5f, 0.5f, 0.5f, 1.0f, color4);
	MyVertex4D v17 = MyVertex4D(-0.5f, 0.5f, 0.5f, 1.0f, color5);
	MyVertex4D v18 = MyVertex4D(0.5f, 0.5f, 0.5f, 1.0f, color5);
	MyVertex4D v19 = MyVertex4D(0.5f, 0.5f, -0.5f, 1.0f, color5);
	MyVertex4D v20 = MyVertex4D(-0.5f, 0.5f, -0.5f, 1.0f, color5);
	MyVertex4D v21 = MyVertex4D(-0.5f, -0.5f, -0.5f, 1.0f, color6);
	MyVertex4D v22 = MyVertex4D(0.5f, -0.5f, -0.5f, 1.0f, color6);
	MyVertex4D v23 = MyVertex4D(0.5f, -0.5f, 0.5f, 1.0f, color6);
	MyVertex4D v24 = MyVertex4D(-0.5f, -0.5f, 0.5f, 1.0f, color6);

	myVertices[0] = v01;
	myVertices[1] = v02;
	myVertices[2] = v03;
	myVertices[3] = v01;
	myVertices[4] = v03;
	myVertices[5] = v04;
	myVertices[6] = v05;
	myVertices[7] = v06;
	myVertices[8] = v07;
	myVertices[9] = v05;
	myVertices[10] = v07;
	myVertices[11] = v08;
	myVertices[12] = v09;
	myVertices[13] = v10;
	myVertices[14] = v11;
	myVertices[15] = v09;
	myVertices[16] = v11;
	myVertices[17] = v12;
	myVertices[18] = v13;
	myVertices[19] = v14;
	myVertices[20] = v15;
	myVertices[21] = v13;
	myVertices[22] = v15;
	myVertices[23] = v16;
	myVertices[24] = v17;
	myVertices[25] = v18;
	myVertices[26] = v19;
	myVertices[27] = v17;
	myVertices[28] = v19;
	myVertices[29] = v20;
	myVertices[30] = v21;
	myVertices[31] = v22;
	myVertices[32] = v23;
	myVertices[33] = v21;
	myVertices[34] = v23;
	myVertices[35] = v24;
	vertices = (MyVertex4D **)&myVertices;
	numVertices = 36;
}

MyCube::MyCube(bool solidColor, MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyColorRGBA & color) :
	MyGraphicsObject3D(position, scale, rotation)
{
	MyColorRGBA c1, c2, c3, c4, c5, c6;
	c1 = c2 = c3 = c4 = c5 = c6 = (solidColor ? color : MyColorRGBA());
	c1 = color;

	/*
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), c1, c1, c1, c1));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), c2, c2, c2, c2));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), c3, c3, c3, c3));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), c4, c4, c4, c4));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), c5, c5, c5, c5));
	children->push_back(new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(), c6, c6, c6, c6));
	*/

	MyVertex4D v01 = MyVertex4D(-0.5f, -0.5f, 0.5f, 1.0f, c1);
	MyVertex4D v02 = MyVertex4D(0.5f, -0.5f, 0.5f, 1.0f, c1);
	MyVertex4D v03 = MyVertex4D(0.5f, 0.5f, 0.5f, 1.0f, c1);
	MyVertex4D v04 = MyVertex4D(-0.5f, 0.5f, 0.5f, 1.0f, c1);
	MyVertex4D v05 = MyVertex4D(0.5f, -0.5f, -0.5f, 1.0f, c2);
	MyVertex4D v06 = MyVertex4D(-0.5f, -0.5f, -0.5f, 1.0f, c2);
	MyVertex4D v07 = MyVertex4D(-0.5f, 0.5f, -0.5f, 1.0f, c2);
	MyVertex4D v08 = MyVertex4D(0.5f, 0.5f, -0.5f, 1.0f, c2);
	MyVertex4D v09 = MyVertex4D(-0.5f, -0.5f, -0.5f, 1.0f, c3);
	MyVertex4D v10 = MyVertex4D(-0.5f, -0.5f, 0.5f, 1.0f, c3);
	MyVertex4D v11 = MyVertex4D(-0.5f, 0.5f, 0.5f, 1.0f, c3);
	MyVertex4D v12 = MyVertex4D(-0.5f, 0.5f, -0.5f, 1.0f, c3);
	MyVertex4D v13 = MyVertex4D(0.5f, -0.5f, 0.5f, 1.0f, c4);
	MyVertex4D v14 = MyVertex4D(0.5f, -0.5f, -0.5f, 1.0f, c4);
	MyVertex4D v15 = MyVertex4D(0.5f, 0.5f, -0.5f, 1.0f, c4);
	MyVertex4D v16 = MyVertex4D(0.5f, 0.5f, 0.5f, 1.0f, c4);
	MyVertex4D v17 = MyVertex4D(-0.5f, 0.5f, 0.5f, 1.0f, c5);
	MyVertex4D v18 = MyVertex4D(0.5f, 0.5f, 0.5f, 1.0f, c5);
	MyVertex4D v19 = MyVertex4D(0.5f, 0.5f, -0.5f, 1.0f, c5);
	MyVertex4D v20 = MyVertex4D(-0.5f, 0.5f, -0.5f, 1.0f, c5);
	MyVertex4D v21 = MyVertex4D(-0.5f, -0.5f, -0.5f, 1.0f, c6);
	MyVertex4D v22 = MyVertex4D(0.5f, -0.5f, -0.5f, 1.0f, c6);
	MyVertex4D v23 = MyVertex4D(0.5f, -0.5f, 0.5f, 1.0f, c6);
	MyVertex4D v24 = MyVertex4D(-0.5f, -0.5f, 0.5f, 1.0f, c6);

	myVertices[0] = v01;
	myVertices[1] = v02;
	myVertices[2] = v03;
	myVertices[3] = v01;
	myVertices[4] = v03;
	myVertices[5] = v04;
	myVertices[6] = v05;
	myVertices[7] = v06;
	myVertices[8] = v07;
	myVertices[9] = v05;
	myVertices[10] = v07;
	myVertices[11] = v08;
	myVertices[12] = v09;
	myVertices[13] = v10;
	myVertices[14] = v11;
	myVertices[15] = v09;
	myVertices[16] = v11;
	myVertices[17] = v12;
	myVertices[18] = v13;
	myVertices[19] = v14;
	myVertices[20] = v15;
	myVertices[21] = v13;
	myVertices[22] = v15;
	myVertices[23] = v16;
	myVertices[24] = v17;
	myVertices[25] = v18;
	myVertices[26] = v19;
	myVertices[27] = v17;
	myVertices[28] = v19;
	myVertices[29] = v20;
	myVertices[30] = v21;
	myVertices[31] = v22;
	myVertices[32] = v23;
	myVertices[33] = v21;
	myVertices[34] = v23;
	myVertices[35] = v24;
	vertices = (MyVertex4D **)&myVertices;
	numVertices = 36;
}