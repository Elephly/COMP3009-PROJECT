#include "MyGraphics.h"

const MyColorRGBA MyColors::CornflowerBlue = MyColorRGBA(100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f, 1.0f);

MyColorRGBA::MyColorRGBA(float red, float green, float blue, float alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}

MyColorRGBA::~MyColorRGBA()
{
}

const float &MyColorRGBA::GetRed()
{
	return r;
}

const float &MyColorRGBA::GetGreen()
{
	return g;
}

const float &MyColorRGBA::GetBlue()
{
	return b;
}

const float &MyColorRGBA::GetAlpha()
{
	return a;
}

void MyColorRGBA::SetRed(float &red)
{
	r = red;
}

void MyColorRGBA::SetGreen(float &green)
{
	g = green;
}

void MyColorRGBA::SetBlue(float &blue)
{
	b = blue;
}

void MyColorRGBA::SetAlpha(float &alpha)
{
	a = alpha;
}
