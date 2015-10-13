#ifndef MYGEOMETRY_H
#define MYGEOMETRY_H

#include "MyGraphics.h"

class MyPoint2D
{
public:
	MyPoint2D(float x = 0.0f, float y = 0.0f);
	~MyPoint2D();

	// Getters
	float GetX();
	float GetY();

	// Setters
	void SetX(float x);
	void SetY(float y);

private:
	float x_;
	float y_;
};

class MyPoint3D
{
public:
	MyPoint3D(float x = 0.0f, float y = 0.0f, float z  = 0.0f);
	~MyPoint3D();

	// Getters
	float GetX();
	float GetY();
	float GetZ();

	// Setters
	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);

private:
	float x_;
	float y_;
	float z_;
};

class MyVector2D : MyPoint2D
{
public:
	MyVector2D(float x = 0.0f, float y = 0.0f);
	~MyVector2D();
};

class MyVector3D : MyPoint3D
{
public:
	MyVector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	~MyVector3D();
};

class MyVertex2D
{
public:
	MyVertex2D(float x = 0.0f, float y = 0.0f, MyColorRGBA &color = MyColorRGBA());
	MyVertex2D(MyVector2D &vector, MyColorRGBA &color = MyColorRGBA());
	~MyVertex2D();

	// Getters
	MyVector2D &GetVector();
	MyColorRGBA &GetColor();

	// Setters
	void SetVector(float x, float y);
	void SetVector(MyVector2D &vector);
	void SetColor(float red, float green, float blue, float alpha);
	void SetColor(MyColorRGBA &color);

private:
	MyVector2D v;
	MyColorRGBA c;

};

class MyVertex3D
{
public:
	MyVertex3D(float x = 0.0f, float y = 0.0f, float z = 0.0f, MyColorRGBA &color = MyColorRGBA());
	MyVertex3D(MyVector3D &vector, MyColorRGBA &color = MyColorRGBA());
	~MyVertex3D();

	// Getters
	MyVector3D &GetVector();
	MyColorRGBA &GetColor();

	// Setters
	void SetVector(float x, float y, float z);
	void SetVector(MyVector3D &vector);
	void SetColor(float red, float green, float blue, float alpha);
	void SetColor(MyColorRGBA &color);

private:
	MyVector3D v;
	MyColorRGBA c;
};

class MyRectangle
{
public:
	MyRectangle(int x = 0, int y = 0, int width = 0, int height = 0);
	~MyRectangle();
		
	bool IsZeroDimensional();

	int GetX1(), GetY1(), GetX2(), GetY2(), GetWidth(), GetHeight();
	void SetX1(int x), SetY1(int y), SetX2(int x), SetY2(int y), SetWidth(int width), SetHeight(int height);

	char *ToString();

private:
	int x_, y_, width_, height_;
	char stringRectangle[64];
};

class MyCircle
{
public:
	MyCircle(int x = 0, int y = 0, double radius = 0.0);
	~MyCircle();

	bool IsZeroDimensional();

	int GetCenterX(), GetCenterY();
	double GetRadius(), GetDiameter();
	void  SetCenterX(int x), SetCenterY(int y), SetRadius(double radius), SetDiameter(double diameter);

	char *ToString();

private:
	int x_, y_;
	double radius_;
	char stringCircle[64];
};

#endif // MYGEOMETRY_H