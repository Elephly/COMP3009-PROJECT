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
	/*
	In this matrix implementation, the Zero Matrix is not to be mistaken with the Null Matrix.
	The Null Matrix is a matrix with 0 for the value of every entry.
	The Zero Matrix features a value of 1 in the entry at the last row by the last column.
	Ex. entry (m, n) where m = numRows and n = numColumns.
	*/
	static MyMatrix4 ZeroMatrix();
	static MyMatrix4 IdentityMatrix();
	/*
	Creates a matrix like this:
	       1       0       0       0
	       0  cos(a) -sin(a)       0
	       0  sin(a)  cos(a)       0
	       0       0       0       1
	where a = angle.
	*/
	static MyMatrix4 RotationAboutXMatrix(float const & angle, bool isDegree = true);
	/*
	Creates a matrix like this:
	  cos(a)       0  sin(a)       0
	       0       1       0       0
	 -sin(a)       0  cos(a)       0
	       0       0       0       1
	where a = angle.
	*/
	static MyMatrix4 RotationAboutYMatrix(float const & angle, bool isDegree = true);
	/*
	Creates a matrix like this:
	  cos(a) -sin(a)       0       0
	  sin(a)  cos(a)       0       0
	       0       0       1       0
	       0       0       0       1
	where a = angle.
	*/
	static MyMatrix4 RotationAboutZMatrix(float const & angle, bool isDegree = true);
	static MyMatrix4 RollPitchYawRotationMatrix(float const & roll, float const & pitch, float const & yaw, bool isDegree = true);
	static MyMatrix4 RotationAboutVectorAxisMatrix(MyVector3D const & vector, float const & angle, bool isDegree = true);
	static MyMatrix4 RotationAboutVectorAxisMatrix(MyVector4D const & vector, float const & angle, bool isDegree = true);
	static MyMatrix4 ScaleMatrix(float const & x, float const & y, float const & z);
	static MyMatrix4 TranslationMatrix(float const & x, float const & y, float const & z);
	static MyMatrix4 TranslationMatrix(MyVector3D const & vector);
	static MyMatrix4 TranslationMatrix(MyVector4D const & vector);
	static MyMatrix4 CameraMatrix(MyVector3D const& position, MyVector3D const& lookAt, MyVector3D const& upVector);
	static MyMatrix4 CameraMatrix(MyVector4D const& position, MyVector4D const& lookAt, MyVector4D const& upVector);
	static MyMatrix4 FrustrumProjetionMatrix(float const & xMin, float const & yMin, float const & xMax, float const & yMax, float const & nearPlane, float const & farPlane);
	static MyMatrix4 SymmetricPerspectiveProjectionMatrix(float const & fieldOfView, float const & aspectRatio, float const & nearPlane, float const & farPlane);

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
