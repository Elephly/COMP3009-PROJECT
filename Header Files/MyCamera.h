#ifndef MYCAMERA_H
#define MYCAMERA_H

#include "MyObject3D.h"

class MyCamera : public MyObject3D
{
public:
	MyCamera(MyVector3D &position = MyVector3D(), MyVector3D &lookAtVector = MyVector3D(), MyVector3D upVector = MyVector3D(0.0f, 1.0f, 0.0f),
		MyMatrix4 &projection = MyMatrix4::IdentityMatrix());
	virtual ~MyCamera();

	virtual void Update();

	// Getters
	const MyVector3D &GetLookAt() const;
	const MyVector3D &GetUpVector() const;
	const MyMatrix4 GetViewMatrix() const;
	const MyMatrix4 &GetProjectionMatrix() const;

private:
	MyVector3D lookAt;
	MyVector3D up;
	MyMatrix4 projectionMatrix;
};

#endif // MYCAMERA_H