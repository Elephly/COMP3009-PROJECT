#ifndef MYVERTEX_H
#define MYVERTEX_H

#include "MyGraphics.h"
#include "MyVector.h"

class MyVertex
{
public:
	MyVertex(MyColorRGBA &color = MyColorRGBA());
	virtual ~MyVertex() = 0;

	// Getters
	MyColorRGBA &GetColor();

	// Setters
	void SetColor(float const & red, float const & green, float const & blue, float const & alpha);
	void SetColor(MyColorRGBA &color);

private:
	MyColorRGBA c;
};

class MyVertex2D : public MyVertex
{
public:
	MyVertex2D(float x = 0.0f, float y = 0.0f, MyColorRGBA &color = MyColorRGBA());
	MyVertex2D(MyVector2D &vector, MyColorRGBA &color = MyColorRGBA());
	~MyVertex2D();

	// Getters
	MyVector2D &GetVector();

	// Setters
	void SetVector(float const & x, float const & y);
	void SetVector(MyVector2D &vector);

private:
	MyVector2D v;
};

class MyVertex3D : public MyVertex
{
public:
	MyVertex3D(float x = 0.0f, float y = 0.0f, float z = 0.0f, MyColorRGBA &color = MyColorRGBA());
	MyVertex3D(MyVector3D &vector, MyColorRGBA &color = MyColorRGBA());
	~MyVertex3D();

	// Getters
	MyVector3D &GetVector();

	// Setters
	void SetVector(float const & x, float const & y, float const & z);
	void SetVector(MyVector2D &vector, float const & z);
	void SetVector(MyVector3D &vector);

private:
	MyVector3D v;
};

class MyVertex4D : public MyVertex
{
public:
	MyVertex4D(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f, MyColorRGBA &color = MyColorRGBA());
	MyVertex4D(MyVector4D &vector, MyColorRGBA &color = MyColorRGBA());
	~MyVertex4D();

	// Getters
	MyVector4D &GetVector();

	// Setters
	void SetVector(float const & x, float const & y, float const & z, float const & w);
	void SetVector(MyVector2D &vector, float const & z, float const & w);
	void SetVector(MyVector3D &vector, float const & w);
	void SetVector(MyVector4D &vector);

private:
	MyVector4D v;
};

#endif // MYVERTEX_H