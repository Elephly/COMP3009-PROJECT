#include "MySphere.h"

#include "MyIncludes.h"

MySphere::MySphere(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, int latitudeSamples, int longitudeSamples, MyColorRGBA & color1, MyColorRGBA & color2) :
	MyGraphicsObject3D(position, scale, rotation)
{
	MyVertex4D *v = new MyVertex4D[latitudeSamples * longitudeSamples]();
	myVertices = new MyVertex4D[6 * (latitudeSamples * longitudeSamples)]();

	float theta, phi;
	int k = 0;
	for (int i = 0; i < longitudeSamples; i++)
	{
		theta = (2 * MyMath::MY_PI_F) * i / (longitudeSamples - 1);
		for (int j = 0; j < latitudeSamples; j++)
		{
			phi = MyMath::MY_PI_F * j / (latitudeSamples - 1);
			MyVector4D normal = MyVector4D(cos(theta) * sin(phi), sin(theta) * sin(phi), -cos(phi));

			float t = (float)j / latitudeSamples;
			MyColorRGBA color = MyColorRGBA(LerpF(color1.GetRed(), color2.GetRed(), t), LerpF(color1.GetGreen(), color2.GetGreen(), t),
				LerpF(color1.GetBlue(), color2.GetBlue(), t), LerpF(color1.GetAlpha(), color2.GetAlpha(), t));

			//float s = abs(((float)i / ((float)longitudeSamples / 2.0f)) - 1);
			//MyColorRGBA color = MyColorRGBA(LerpF(color1.GetRed(), color2.GetRed(), s), LerpF(color1.GetGreen(), color2.GetGreen(), s),
			//	LerpF(color1.GetBlue(), color2.GetBlue(), s), LerpF(color1.GetAlpha(), color2.GetAlpha(), s));

			MyVector4D position = normal * 0.5f;
			position.SetW(1.0f);
			
			v[k++] = MyVertex4D(position, color);
		}
	}

	k = 0;
	for (int i = 0; i < longitudeSamples; i++)
	{
		for (int j = 0; j < (latitudeSamples - 1); j++)
		{
			myVertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + j];
			myVertices[k++] = v[i * latitudeSamples + (j + 1)];
			myVertices[k++] = v[i * latitudeSamples + j];

			myVertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + j];
			myVertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + (j + 1)];
			myVertices[k++] = v[i * latitudeSamples + (j + 1)];
		}
	}

	vertices = &myVertices;
	numVertices = 6 * (latitudeSamples * longitudeSamples);
	isDynamicArray = true;

	MyDeleteArray(v);
}

MySphere::~MySphere()
{
	MyDeleteArray(myVertices);
}
