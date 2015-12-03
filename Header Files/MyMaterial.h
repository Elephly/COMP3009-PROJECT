#ifndef MYMATERIAL_H
#define MYMATERIAL_H

#include "MyGraphics.h"
#include "MyTexture2D.h"

class MyMaterial
{
public:
	MyMaterial(MyTexture2D * texture = 0, MyColorRGBA const & ambient = MyColorRGBA(), MyColorRGBA const & diffuse = MyColorRGBA(1.0f, 1.0f, 1.0f),
		MyColorRGBA const & specular = MyColorRGBA(1.0f, 1.0f, 1.0f), float const & shine = 1.0f, bool const & toon = false);
	~MyMaterial();

	MyTexture2D * GetTexture() const;
	const MyColorRGBA & GetAmbient() const;
	const MyColorRGBA & GetDiffuse() const;
	const MyColorRGBA & GetSpecular() const;
	const float & GetShine() const;
	const bool & GetToon() const;

	bool HasTexture() const;

	void SetTexture(MyTexture2D * texture);
	void SetAmbient(float const & red, float const & green, float const & blue, float const & alpha);
	void SetAmbient(MyColorRGBA const & ambient);
	void SetDiffuse(float const & red, float const & green, float const & blue, float const & alpha);
	void SetDiffuse(MyColorRGBA const & diffuse);
	void SetSpecular(float const & red, float const & green, float const & blue, float const & alpha);
	void SetSpecular(MyColorRGBA const & specular);
	void SetShine(float const & shine);
	void SetToon(bool const & toon);
	
private:
	MyTexture2D *tex;
	MyColorRGBA a;
	MyColorRGBA d;
	MyColorRGBA s;
	float sh;
	bool t;

};

#endif // MYMATERIAL_H