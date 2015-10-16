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

void MyCamera::Translate(float const & x, float const & y, float const & z)
{
	MyObject3D::Translate(-x, -y, -z);
}

void MyCamera::Translate(MyVector3D const & vector)
{
	MyVector3D v = vector;
	MyObject3D::Translate(-v);
}

void MyCamera::Translate(MyVector4D const & vector)
{
	MyVector4D v = vector;
	MyObject3D::Translate(-v);
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
