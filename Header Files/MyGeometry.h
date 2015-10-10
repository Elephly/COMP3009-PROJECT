#ifndef MYGEOMETRY_H
#define MYGEOMETRY_H

#include "MyGraphics.h"

typedef struct
{
	int x;
	int y;
} MyPoint2D;

typedef struct
{
	int x;
	int y;
	int z;
} MyPoint3D;

typedef struct
{
	float x;
	float y;
} MyVector2D;

typedef struct
{
	float x;
	float y;
	float z;
} MyVector3D;

typedef struct
{
	MyVector2D v;
	MyColorRGBA c;

} MyVertex2D;

typedef struct
{
	MyVector3D v;
	MyColorRGBA c;
} MyVertex3D;

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