#include "MyKeyframe.h"

MyKeyframe::MyKeyframe(MyVector3D p, MyVector3D s, MyVector3D r) :
	position(p), scale(s), rotation(r)
{
}

MyKeyframe::~MyKeyframe()
{
}

const MyVector3D & MyKeyframe::GetPosition() const
{
	return position;
}

const MyVector3D & MyKeyframe::GetRotation() const
{
	return rotation;
}

const MyVector3D & MyKeyframe::GetScale() const
{
	return scale;
}

const bool MyKeyframe::IsRecursiveScale() const
{
	return recursiveScale;
}

void MyKeyframe::SetPosition(float const & x, float const & y, float const & z)
{
	position = MyVector3D(x, y, z);
}

void MyKeyframe::SetPosition(MyVector3D const & vector)
{
	position = vector;
}

void MyKeyframe::SetPosition(MyVector4D const & vector)
{
	position = MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyKeyframe::SetRotation(float const & x, float const & y, float const & z)
{
	rotation = (x, y, z);
}

void MyKeyframe::SetRotation(MyVector3D const & vector)
{
	rotation = vector;
}

void MyKeyframe::SetRotation(MyVector4D const & vector)
{
	rotation = MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyKeyframe::SetScale(float const & x, float const & y, float const & z)
{
	scale = MyVector3D(x, y, z);
}

void MyKeyframe::SetScale(MyVector3D const & vector)
{
	scale = vector;
}

void MyKeyframe::SetScale(MyVector4D const & vector)
{
	scale = MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyKeyframe::SetRecursiveScale(bool const & recursive)
{
	recursiveScale = recursive;
}
