#include "MyLightSource.h"

MyLightSource::MyLightSource(float x, float y, float z, MyColorRGBA const & color, LIGHT_SOURCE_TYPE type) :
	c(color), t(type), MyVector4D(x, y, z)
{
}

MyLightSource::MyLightSource(MyVector3D const & position, MyColorRGBA const & color, LIGHT_SOURCE_TYPE type) :
	c(color), t(type), MyVector4D(position)
{
}

MyLightSource::MyLightSource(MyVector4D const & position, MyColorRGBA const & color, LIGHT_SOURCE_TYPE type) :
	c(color), t(type), MyVector4D(position)
{
}

MyLightSource::~MyLightSource()
{
}

const MyColorRGBA & MyLightSource::GetColor() const
{
	return c;
}

const LIGHT_SOURCE_TYPE & MyLightSource::GetLightSourceType() const
{
	return t;
}

void MyLightSource::SetColor(float const & red, float const & green, float const & blue, float const & alpha)
{
	c = MyColorRGBA(red, green, blue, alpha);
}

void MyLightSource::SetColor(MyColorRGBA const & color)
{
	c = color;
}

void MyLightSource::SetLightSourceType(LIGHT_SOURCE_TYPE const & type)
{
	t = type;
}
