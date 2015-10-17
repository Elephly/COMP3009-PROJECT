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

}

void MyCamera::Rotate(float const & x, float const & y, float const & z, bool isDegree)
{
	MyObject3D::Rotate(x, y, z, isDegree);
}

void MyCamera::Rotate(MyVector3D const & vector, bool isDegree)
{
	MyObject3D::Rotate(vector, isDegree);
}

void MyCamera::Rotate(MyVector4D const & vector, bool isDegree)
{
	MyObject3D::Rotate(vector, isDegree);
}

void MyCamera::Scale(float const & x, float const & y, float const & z)
{
	MyObject3D::Scale(x, y, z);
}

void MyCamera::Scale(MyVector3D const & vector)
{
	MyObject3D::Scale(vector);
}

void MyCamera::Scale(MyVector4D const & vector)
{
	MyObject3D::Scale(vector);
}

void MyCamera::Translate(float const & x, float const & y, float const & z)
{
	MyObject3D::Translate(x, y, z);
	lookAt += MyVector3D(x, y, z);
}

void MyCamera::Translate(MyVector3D const & vector)
{
	MyObject3D::Translate(vector);
	lookAt += vector;
}

void MyCamera::Translate(MyVector4D const & vector)
{
	MyObject3D::Translate(vector);
	lookAt += MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyCamera::Roll(float const & angle, bool isDegree)
{
	MyObject3D::Roll(angle, isDegree);
}

void MyCamera::Pitch(float const & angle, bool isDegree)
{
	MyObject3D::Pitch(angle, isDegree);
}

void MyCamera::Yaw(float const & angle, bool isDegree)
{
	MyObject3D::Yaw(isDegree);
}

MyVector3D MyCamera::GetDirection() const
{
	return (lookAt - position).GetNormalized();
}

const MyVector3D & MyCamera::GetLookAt() const
{
	return lookAt;
}

MyVector3D MyCamera::GetRightVector() const
{
	return GetDirection().Cross(up);
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
