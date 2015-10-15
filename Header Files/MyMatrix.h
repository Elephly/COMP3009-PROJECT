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
	static MyMatrix4 ScaleMatrix(float const& x, float const& y, float const& z);
	static MyMatrix4 TranslationMatrix(float const& x, float const& y, float const& z);
	static MyMatrix4 TranslationMatrix(MyVector3D &vector);
	static MyMatrix4 TranslationMatrix(MyVector4D &vector);
	static MyMatrix4 CameraMatrix(MyVector3D &position, MyVector3D &lookAt, MyVector3D &upVector);
	static MyMatrix4 CameraMatrix(MyVector4D &position, MyVector4D &lookAt, MyVector4D &upVector);
	static MyMatrix4 FrustrumProjetionMatrix(float const& xMin, float const& yMin, float const& xMax, float const& yMax, float const& nearPlane, float const& farPlane);
	static MyMatrix4 SymmetricPerspectiveProjectionMatrix(float const& fieldOfView, float const& aspectRatio, float const& nearPlane, float const& farPlane);

	MyMatrix4(MyVector4D vector1 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), MyVector4D vector2 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), 
		MyVector4D vector3 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), MyVector4D vector4 = MyVector4D(0.0f, 0.0f, 0.0f, 0.0f));
	~MyMatrix4();

	// Getters
	float *GetEntries();
	MyMatrix4 GetTranspose() const;

	// Setters
	MyMatrix4 &SetNull();

	MyMatrix4 &Transpose();

	// Operators
	MyMatrix4 operator+(const MyMatrix4 &other) const;
	MyMatrix4 operator-(const MyMatrix4 &other) const;
	MyMatrix4 operator*(const MyMatrix4 &other) const;
	MyMatrix4 operator*(const float &multiplier) const;
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
