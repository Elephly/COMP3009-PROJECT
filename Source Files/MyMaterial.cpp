#include "MyMaterial.h"

#include "MyDefines.h"

MyMaterial::MyMaterial(MyColorRGBA const & ambient, MyColorRGBA const & diffuse, MyColorRGBA const & specular, float const & shine, bool const & toon) :
	a(ambient), d(diffuse), s(specular), sh(shine), t(toon)
{
}

MyMaterial::~MyMaterial()
{
}

const MyColorRGBA & MyMaterial::GetAmbient() const
{
	return a;
}

const MyColorRGBA & MyMaterial::GetDiffuse() const
{
	return d;
}

const MyColorRGBA & MyMaterial::GetSpecular() const
{
	return s;
}

const float & MyMaterial::GetShine() const
{
	return sh;
}

const bool & MyMaterial::GetToon() const
{
	return t;
}

void MyMaterial::SetAmbient(float const & red, float const & green, float const & blue, float const & alpha)
{
	a = MyColorRGBA(red, green, blue, alpha);
}

void MyMaterial::SetAmbient(MyColorRGBA const & ambient)
{
	a = ambient;
}

void MyMaterial::SetDiffuse(float const & red, float const & green, float const & blue, float const & alpha)
{
	d = MyColorRGBA(red, green, blue, alpha);
}

void MyMaterial::SetDiffuse(MyColorRGBA const & diffuse)
{
	d = diffuse;
}

void MyMaterial::SetSpecular(float const & red, float const & green, float const & blue, float const & alpha)
{
	s = MyColorRGBA(red, green, blue, alpha);
}

void MyMaterial::SetSpecular(MyColorRGBA const & specular)
{
	s = specular;
}

void MyMaterial::SetShine(float const & shine)
{
	sh = max(shine, 0.0f);
}

void MyMaterial::SetToon(bool const & toon)
{
	t = toon;
}
