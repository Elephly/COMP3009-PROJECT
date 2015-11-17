#ifndef MYMATERIAL_H
#define MYMATERIAL_H

#include "MyGraphics.h"

class MyMaterial
{
public:
	MyMaterial(MyColorRGBA const & ambient = MyColorRGBA(), MyColorRGBA const & diffuse = MyColorRGBA(0.75f, 0.75f, 0.75f),
		MyColorRGBA const & specular = MyColorRGBA(1.0f, 1.0f, 1.0f), float shine = 1.0f);
	~MyMaterial();

	const MyColorRGBA & GetAmbient() const;
	const MyColorRGBA & GetDiffuse() const;
	const MyColorRGBA & GetSpecular() const;
	const float & GetShine() const;

	void SetAmbient(float const & red, float const & green, float const & blue, float const & alpha);
	void SetAmbient(MyColorRGBA const & ambient);
	void SetDiffuse(float const & red, float const & green, float const & blue, float const & alpha);
	void SetDiffuse(MyColorRGBA const & diffuse);
	void SetSpecular(float const & red, float const & green, float const & blue, float const & alpha);
	void SetSpecular(MyColorRGBA const & specular);
	void SetShine(float const & shine);
	
private:
	MyColorRGBA a;
	MyColorRGBA d;
	MyColorRGBA s;
	float sh;

};

#endif // MYMATERIAL_H