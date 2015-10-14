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
	void SetColor(float red, float green, float blue, float alpha);
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
	void SetVector(float x, float y);
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
	void SetVector(float x, float y, float z);
	void SetVector(MyVector3D &vector);

private:
	MyVector3D v;
};

#endif // MYVERTEX_H