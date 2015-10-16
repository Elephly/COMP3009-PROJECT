#include "MyGeometry.h"

#include <cstdio>

MyRectangle::MyRectangle(int x, int y, int width, int height) : x_(x), y_(y), width_(width), height_(height) { }

MyRectangle::~MyRectangle() { }

bool MyRectangle::IsZeroDimensional()
{
	return (x_ == 0 && y_ == 0 && width_ == 0 && height_ == 0);
}

int MyRectangle::GetX1()
{
	return x_;
}

int MyRectangle::GetY1()
{
	return y_;
}

int MyRectangle::GetX2()
{
	return x_ + width_;
}

int MyRectangle::GetY2()
{
	return y_ + height_;
}

int MyRectangle::GetWidth()
{
	return width_;
}

int MyRectangle::GetHeight()
{
	return height_;
}

void MyRectangle::SetX1(int x)
{
	x_ = x;
}

void MyRectangle::SetY1(int y)
{
	y_ = y;
}

void MyRectangle::SetX2(int x)
{
	width_ = x - x_;
}

void MyRectangle::SetY2(int y)
{
	height_ = y - y_;
}

void MyRectangle::SetWidth(int width)
{
	width_ = width;
}

void MyRectangle::SetHeight(int height)
{
	height_ = height;
}

char *MyRectangle::ToString()
{
	sprintf_s(stringRectangle, "Rectangle:\n\tx1:\t%5d\n\ty1:\t%5d\n\tx2:\t%5d\n\ty2:\t%5d\n\twidth:\t%5d\n\theight:\t%5d\n",
		x_, y_, GetX2(), GetY2(), width_, height_);
		
	return stringRectangle;
}
MyCircle::MyCircle(int x, int y, double radius) : x_(x), y_(y), radius_(radius) { }

MyCircle::~MyCircle() { }

bool MyCircle::IsZeroDimensional()
{
	return (x_ == 0 && y_ == 0 && radius_ == 0.0);
}
int MyCircle::GetCenterX()
{
	return x_;
}
int MyCircle::GetCenterY()
{
	return y_;
}
double MyCircle::GetRadius()
{
	return radius_;
}
double MyCircle::GetDiameter()
{
	return radius_ * 2.0;
}
void MyCircle::SetCenterX(int x)
{
	x_ = x;
}
void MyCircle::SetCenterY(int y)
{
	y_ = y;
}
void MyCircle::SetRadius(double radius)
{
	radius_ = radius;
}
void MyCircle::SetDiameter(double diameter)
{
	radius_ = diameter / 2.0;
}
char * MyCircle::ToString()
{
	sprintf_s(stringCircle, "Circle:\n\tCenter x1:\t%8d\n\tCenter y1:\t%8d\n\tradius:/t%8f\n",
		x_, y_, radius_);

	return stringCircle;
}

MyPoint2D::MyPoint2D(float x, float y)
{
	x_ = x;
	y_ = y;
}

MyPoint2D::~MyPoint2D()
{
}

float MyPoint2D::GetX() const
{
	return x_;
}

float MyPoint2D::GetY() const
{
	return y_;
}

const float & MyPoint2D::GetXAddr() const
{
	return x_;
}

const float & MyPoint2D::GetYAddr() const
{
	return y_;
}

void MyPoint2D::SetX(float const & x)
{
	x_ = x;
}

void MyPoint2D::SetY(float const & y)
{
	y_ = y;
}

MyPoint3D::MyPoint3D(float x, float y, float z)
{
	x_ = x;
	y_ = y;
	z_ = z;
}

MyPoint3D::~MyPoint3D()
{
}

float MyPoint3D::GetX() const
{
	return x_;
}

float MyPoint3D::GetY() const
{
	return y_;
}

float MyPoint3D::GetZ() const
{
	return z_;
}

const float & MyPoint3D::GetXAddr() const
{
	return x_;
}

const float & MyPoint3D::GetYAddr() const
{
	return y_;
}

const float & MyPoint3D::GetZAddr() const
{
	return z_;
}

void MyPoint3D::SetX(float const & x)
{
	x_ = x;
}

void MyPoint3D::SetY(float const & y)
{
	y_ = y;
}

void MyPoint3D::SetZ(float const & z)
{
	z_ = z;
}

MyPoint4D::MyPoint4D(float x, float y, float z, float w)
{
	x_ = x;
	y_ = y;
	z_ = z;
	w_ = w;
}

MyPoint4D::~MyPoint4D()
{
}

float MyPoint4D::GetX() const
{
	return x_;
}

float MyPoint4D::GetY() const
{
	return y_;
}

float MyPoint4D::GetZ() const
{
	return z_;
}

float MyPoint4D::GetW() const
{
	return w_;
}

const float & MyPoint4D::GetXAddr() const
{
	return x_;
}

const float & MyPoint4D::GetYAddr() const
{
	return y_;
}

const float & MyPoint4D::GetZAddr() const
{
	return z_;
}

const float & MyPoint4D::GetWAddr() const
{
	return w_;
}

void MyPoint4D::SetX(float const & x)
{
	x_ = x;
}

void MyPoint4D::SetY(float const & y)
{
	y_ = y;
}

void MyPoint4D::SetZ(float const & z)
{
	z_ = z;
}

void MyPoint4D::SetW(float const & w)
{
	w_ = w;
}