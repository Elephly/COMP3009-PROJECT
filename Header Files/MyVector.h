#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include "MyGeometry.h"

class MyVector;
class MyVector2D;
class MyVector3D;
class MyVector4D;

class MyVector
{
public:
	virtual ~MyVector() = 0;

	virtual float GetLength() const = 0;

	virtual void Normalize() = 0;
};

class MyVector2D : public MyPoint2D, public MyVector
{
public:
	MyVector2D(MyVector3D &vector);
	MyVector2D(MyVector4D &vector);
	MyVector2D(float x = 0.0f, float y = 0.0f);
	~MyVector2D();

	virtual float GetLength() const;
	MyVector2D GetNormalized();

	float Dot(const MyVector2D &other) const;
	virtual void Normalize();

	// Operators
	MyVector2D operator-();
	MyVector2D operator+(const MyVector2D &other) const;
	MyVector2D operator-(const MyVector2D &other) const;
	MyVector2D operator*(const MyVector2D &other) const;
	MyVector2D operator*(const float &multiplier) const;
	MyVector2D operator/(const float &divisor) const;
	MyVector2D &operator+=(const MyVector2D &other);
	MyVector2D &operator-=(const MyVector2D &other);
	MyVector2D &operator*=(const float &multiplier);
	MyVector2D &operator/=(const float &divisor);
	friend MyVector2D operator*(const float &multiplier, MyVector2D &vector);
	friend std::ostream &operator<<(std::ostream &os, const MyVector2D &vector);
};

class MyVector3D : public MyPoint3D, public MyVector
{
public:
	MyVector3D(MyVector2D &vector, float z = 0.0f);
	MyVector3D(MyVector4D &vector);
	MyVector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	~MyVector3D();

	virtual float GetLength() const;
	virtual MyVector3D GetNormalized() const;

	MyVector3D Cross(const MyVector3D &other) const;
	float Dot(const MyVector3D &other) const;
	virtual void Normalize();

	// Operators
	MyVector3D operator-();
	MyVector3D operator+(const MyVector3D &other) const;
	MyVector3D operator-(const MyVector3D &other) const;
	MyVector3D operator*(const MyVector3D &other) const;
	MyVector3D operator*(const float &multiplier) const;
	MyVector3D operator/(const float &divisor) const;
	MyVector3D &operator+=(const MyVector3D &other);
	MyVector3D &operator-=(const MyVector3D &other);
	MyVector3D &operator*=(const float &multiplier);
	MyVector3D &operator/=(const float &divisor);
	friend MyVector3D operator*(const float &multiplier, MyVector3D &vector);
	friend std::ostream &operator<<(std::ostream &os, const MyVector3D &vector);
};

class MyVector4D : public MyPoint4D, public MyVector
{
public:
	MyVector4D(MyVector2D &vector, float z = 0.0f, float w = 1.0f);
	MyVector4D(MyVector3D &vector, float w = 1.0f);
	MyVector4D(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);
	~MyVector4D();

	virtual float GetLength() const;
	virtual MyVector4D GetNormalized();

	MyVector4D Cross(const MyVector4D &other) const;
	float Dot(const MyVector4D &other) const;
	float Dot3(const MyVector4D &other) const;
	virtual void Normalize();

	// Operators
	MyVector4D operator-();
	MyVector4D operator+(const MyVector4D &other) const;
	MyVector4D operator-(const MyVector4D &other) const;
	MyVector4D operator*(const MyVector4D &other) const;
	MyVector4D operator*(const float &multiplier) const;
	MyVector4D operator/(const float &divisor) const;
	MyVector4D &operator+=(const MyVector4D &other);
	MyVector4D &operator-=(const MyVector4D &other);
	MyVector4D &operator*=(const float &multiplier);
	MyVector4D &operator/=(const float &divisor);
	friend MyVector4D operator*(const float &multiplier, MyVector4D &vector);
	friend std::ostream &operator<<(std::ostream &os, const MyVector4D &vector);
};

#endif // MYVECTOR_H
