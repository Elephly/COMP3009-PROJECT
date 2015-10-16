#include "MyCamera.h"

MyCamera::MyCamera(MyVector3D & position, MyVector3D & lookAtVector, MyVector3D upVector, MyMatrix4 & projection) : lookAt(lookAtVector),
	up(upVector), projectionMatrix(projection),	MyObject3D(position)
{
}

MyCamera::~MyCamera()
{
}

void MyCamera::Update()
{
	MyObject3D::Update();
}

const MyVector3D & MyCamera::GetLookAt() const
{
	return lookAt;
}

const MyVector3D & MyCamera::GetUpVector() const
{
	return up;
}

const MyMatrix4 MyCamera::GetViewMatrix() const
{
	return MyMatrix4::CameraMatrix(position, lookAt, up);
}

const MyMatrix4 & MyCamera::GetProjectionMatrix() const
{
	return projectionMatrix;
}
