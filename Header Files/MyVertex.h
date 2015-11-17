#ifndef MYVERTEX_H
#define MYVERTEX_H

#include "MyGraphics.h"
#include "MyVector.h"

class MyVertex
{
public:
	MyVertex(MyColorRGBA const & color = MyColorRGBA());
	virtual ~MyVertex() = 0;

	// Getters
	const MyColorRGBA &GetColor() const;
	const MyVector2D &GetTextureCoord() const;

	// Setters
	void SetColor(float const & red, float const & green, float const & blue, float const & alpha);
	void SetColor(MyColorRGBA const & color);
	void SetTextureCoord(float const & x, float const & y);
	void SetTextureCoord(MyVector2D const & textureCoord);

private:
	MyColorRGBA c;
	MyVector2D t;
};

class MyVertex2D : public MyVertex
{
public:
	MyVertex2D(float x = 0.0f, float y = 0.0f, MyColorRGBA const & color = MyColorRGBA());
	MyVertex2D(MyVector2D & position, MyColorRGBA const & color = MyColorRGBA());
	~MyVertex2D();

	// Getters
	const MyVector2D &GetPosition() const;

	// Setters
	void SetPosition(float const & x, float const & y);
	void SetPosition(MyVector2D const & position);

private:
	MyVector2D p;
};

class MyVertex3D : public MyVertex
{
public:
	MyVertex3D(float x = 0.0f, float y = 0.0f, float z = 0.0f, MyColorRGBA const & color = MyColorRGBA());
	MyVertex3D(MyVector3D const & position, MyColorRGBA const & color = MyColorRGBA());
	~MyVertex3D();

	// Getters
	const MyVector3D &GetPosition() const;
	const MyVector3D &GetNormal() const;

	// Setters
	void SetPosition(float const & x, float const & y, float const & z);
	void SetPosition(MyVector2D const & position, float const & z);
	void SetPosition(MyVector3D const & position);
	void SetNormal(float const & x, float const & y, float const & z);
	void SetNormal(MyVector2D const & normal, float const & z);
	void SetNormal(MyVector3D const & normal);

private:
	MyVector3D p;
	MyVector3D n;
};

class MyVertex4D : public MyVertex
{
public:
	MyVertex4D(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f, MyColorRGBA const & color = MyColorRGBA());
	MyVertex4D(MyVector4D const & position, MyColorRGBA const & color = MyColorRGBA());
	~MyVertex4D();

	// Getters
	const MyVector4D &GetPosition() const;
	const MyVector4D &GetNormal() const;

	// Setters
	void SetPosition(float const & x, float const & y, float const & z, float const & w);
	void SetPosition(MyVector2D const & position, float const & z, float const & w);
	void SetPosition(MyVector3D const & position, float const & w);
	void SetPosition(MyVector4D const & position);
	void SetNormal(float const & x, float const & y, float const & z, float const & w);
	void SetNormal(MyVector2D const & normal, float const & z, float const & w);
	void SetNormal(MyVector3D const & normal, float const & w);
	void SetNormal(MyVector4D const & normal);

private:
	MyVector4D p;
	MyVector4D n;
};

#endif // MYVERTEX_H