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

float MyColorRGBA::GetRed() const
{
	return r;
}

float MyColorRGBA::GetGreen() const
{
	return g;
}

float MyColorRGBA::GetBlue() const
{
	return b;
}

float MyColorRGBA::GetAlpha() const
{
	return a;
}

const float & MyColorRGBA::GetRedAddr() const
{
	return r;
}

const float & MyColorRGBA::GetGreenAddr() const
{
	return g;
}

const float & MyColorRGBA::GetBlueAddr() const
{
	return b;
}

const float & MyColorRGBA::GetAlphaAddr() const
{
	return a;
}

void MyColorRGBA::SetRed(float const & red)
{
	r = red;
}

void MyColorRGBA::SetGreen(float const & green)
{
	g = green;
}

void MyColorRGBA::SetBlue(float const & blue)
{
	b = blue;
}

void MyColorRGBA::SetAlpha(float const & alpha)
{
	a = alpha;
}
