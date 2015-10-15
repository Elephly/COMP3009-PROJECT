#ifndef MYMATRIX_H
#define MYMATRIX_H

#include "MyVector.h"

class MyMatrix
{
public:
	virtual ~MyMatrix() = 0;
};

class MyMatrix4 : MyMatrix
{
public :
	static MyMatrix4 NullMatrix();
	static MyMatrix4 IdentityMatrix();
	static MyMatrix4 RotateMatrix();
	static MyMatrix4 ScaleMatrix();
	static MyMatrix4 TranslationMatrix();

	MyMatrix4(MyVector4D vector1 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), MyVector4D vector2 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), 
		MyVector4D vector3 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), MyVector4D vector4 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f));
	~MyMatrix4();

	// Getters
	float *GetEntries();
	MyMatrix4 GetTranspose();

	// Setters
	MyMatrix4 &SetNull();

	MyMatrix4 &Transpose();

	// Operators
	MyMatrix4 operator+(const MyMatrix4 &other) const;
	MyMatrix4 operator-(const MyMatrix4 &other) const;
	MyMatrix4 operator*(const MyMatrix4 &other) const;
	MyMatrix4 operator*(const float &multiplier) const;
	MyVector3D operator*(const MyVector3D &other) const;
	MyVector4D operator*(const MyVector4D &vector) const;
	MyMatrix4 &operator+=(const MyMatrix4 &other);
	MyMatrix4 &operator-=(const MyMatrix4 &other);
	MyMatrix4 &operator*=(const MyMatrix4 &other);
	MyMatrix4 &operator*=(const float &multiplier);
	friend MyMatrix4 operator*(const float &multiplier, MyMatrix4 &matrix);
	friend std::ostream &operator<<(std::ostream &os, const MyMatrix4 &matrix);

private:
	float entries[4][4];
};

#endif // MYMATRIX_H
