#include "MyCamera.h"

#include "MyIncludes.h"

MyCamera::MyCamera(MyVector3D position, MyVector3D lookAtVector, MyVector3D upVector, MyMatrix4 projection, bool yawLocked) : lookAt(lookAtVector),
	up(upVector), projectionMatrix(projection),	MyObject3D(position), yawLock(yawLocked)
{
}

MyCamera::~MyCamera()
{
}

void MyCamera::Rotate(float const & x, float const & y, float const & z, bool isDegree)
{
	MyObject3D::Rotate(x, y, z, isDegree);
	lookAt = (MyMatrix4::RotationAboutVectorAxisMatrix(up, y, isDegree) * MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), x, isDegree) *
		MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), z, isDegree) * MyVector4D(lookAt - position)) + position;
	if (!yawLock)
	{
		up = MyMatrix4::RotationAboutVectorAxisMatrix(up, y, isDegree) * MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), x, isDegree) *
			MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), z, isDegree) * up;
	}
}

void MyCamera::Rotate(MyVector3D const & vector, bool isDegree)
{
	MyObject3D::Rotate(vector, isDegree);
	lookAt = (MyMatrix4::RotationAboutVectorAxisMatrix(up, vector.GetY(), isDegree) * MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), vector.GetX(), isDegree) *
		MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), vector.GetZ(), isDegree) * MyVector4D(lookAt - position)) + position;
	if (!yawLock)
	{
		up = MyMatrix4::RotationAboutVectorAxisMatrix(up, vector.GetY(), isDegree) * MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), vector.GetX(), isDegree) *
			MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), vector.GetZ(), isDegree) * up;
	}
}

void MyCamera::Rotate(MyVector4D const & vector, bool isDegree)
{
	MyObject3D::Rotate(vector, isDegree);
	lookAt = (MyMatrix4::RotationAboutVectorAxisMatrix(up, vector.GetY(), isDegree) * MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), vector.GetX(), isDegree) *
		MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), vector.GetZ(), isDegree) * MyVector4D(lookAt - position)) + position;
	if (!yawLock)
	{
		up = MyMatrix4::RotationAboutVectorAxisMatrix(up, vector.GetY(), isDegree) * MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), vector.GetX(), isDegree) *
			MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), vector.GetZ(), isDegree) * up;
	}
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
	lookAt = (MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), angle, isDegree) * MyVector4D(lookAt - position)) + position;
	if (!yawLock)
	{
		up = MyMatrix4::RotationAboutVectorAxisMatrix(GetDirection(), angle, isDegree) * up;
	}
}

void MyCamera::Pitch(float const & angle, bool isDegree)
{
	float angleBetweenUpAndDir = acos(up.Dot(GetDirection() /* / (up.GetLength() / GetDirection().GetLengt())*/));
	float a = abs(isDegree ? DegreeToRadian(angle) : angle);
	if (!yawLock || ((angle > 0 && angleBetweenUpAndDir > (a * 2.0f)) ||
		(angle < 0 && angleBetweenUpAndDir < (MyMath::MY_PI_F - (a * 2.0f)))))
	{
		MyObject3D::Pitch(angle, isDegree);
		lookAt = (MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), angle, isDegree) * MyVector4D(lookAt - position)) + position;
		if (!yawLock)
		{
			up = MyMatrix4::RotationAboutVectorAxisMatrix(GetRightVector(), angle, isDegree) * up;
		}
	}
}

void MyCamera::Yaw(float const & angle, bool isDegree)
{
	MyObject3D::Yaw(isDegree);
	lookAt = (MyMatrix4::RotationAboutVectorAxisMatrix(up, angle, isDegree) * MyVector4D(lookAt - position)) + position;
	if (!yawLock)
	{
		up = MyMatrix4::RotationAboutVectorAxisMatrix(up, angle, isDegree) * up;
	}
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
	return GetDirection().Cross(up).GetNormalized();
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
