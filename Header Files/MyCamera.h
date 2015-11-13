#ifndef MYCAMERA_H
#define MYCAMERA_H

#include "MyObject3D.h"

class MyCamera : public MyObject3D
{
public:
	MyCamera(MyVector3D &position = MyVector3D(), MyVector3D &lookAtVector = MyVector3D(0.0f, 0.0f, -1.0f), MyVector3D upVector = MyVector3D(0.0f, 1.0f, 0.0f),
		MyMatrix4 &projection = MyMatrix4::IdentityMatrix(), bool yawLocked = false);
	virtual ~MyCamera();

	// Transformations
	virtual void Rotate(float const & x, float const & y, float const & z, bool isDegree = true);
	virtual void Rotate(MyVector3D const & vector, bool isDegree = true);
	virtual void Rotate(MyVector4D const & vector, bool isDegree = true);
	virtual void Scale(float const & x, float const & y, float const & z);
	virtual void Scale(MyVector3D const & vector);
	virtual void Scale(MyVector4D const & vector);
	virtual void Translate(float const & x, float const & y, float const & z);
	virtual void Translate(MyVector3D const & vector);
	virtual void Translate(MyVector4D const & vector);

	// Special Rotations
	virtual void Roll(float const & angle, bool isDegree = true);
	virtual void Pitch(float const & angle, bool isDegree = true);
	virtual void Yaw(float const & angle, bool isDegree = true);

	// Getters
	MyVector3D GetDirection() const;
	const MyVector3D &GetLookAt() const;
	MyVector3D GetRightVector() const;
	const MyVector3D &GetUpVector() const;
	const MyMatrix4 GetViewMatrix() const;
	const MyMatrix4 &GetProjectionMatrix() const;

private:
	MyVector3D lookAt;
	MyVector3D up;
	MyMatrix4 projectionMatrix;
	bool yawLock;
};

#endif // MYCAMERA_H