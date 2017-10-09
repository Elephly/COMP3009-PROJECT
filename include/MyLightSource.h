#ifndef MYLIGHTSOURCE_H
#define MYLIGHTSOURCE_H

#include "MyVector.h"

enum LIGHT_SOURCE_TYPE
{
	LIGHT_SOURCE_POINT,
	LIGHT_SOURCE_SPOT,
};

class MyLightSource : public MyVector4D
{
public:
	MyLightSource(float x = 0.0f, float y = 0.0f, float z = 0.0f, MyColorRGBA const & color = MyColorRGBA(1.0f, 1.0f, 1.0f), LIGHT_SOURCE_TYPE type = LIGHT_SOURCE_POINT);
	MyLightSource(MyVector3D const & position, MyColorRGBA const & color = MyColorRGBA(1.0f, 1.0f, 1.0f), LIGHT_SOURCE_TYPE type = LIGHT_SOURCE_POINT);
	MyLightSource(MyVector4D const & position, MyColorRGBA const & color = MyColorRGBA(1.0f, 1.0f, 1.0f), LIGHT_SOURCE_TYPE type = LIGHT_SOURCE_POINT);
	~MyLightSource();

	const MyColorRGBA &GetColor() const;
	const LIGHT_SOURCE_TYPE &GetLightSourceType() const;

	void SetColor(float const & red, float const & green, float const & blue, float const & alpha);
	void SetColor(MyColorRGBA const & color);
	void SetLightSourceType(LIGHT_SOURCE_TYPE const & type);

private:
	MyColorRGBA c;
	LIGHT_SOURCE_TYPE t;

};

#endif // MYLIGHTSOURCE_H