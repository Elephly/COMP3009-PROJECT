#include "MyObject3D.h"

MyObject3D::MyObject3D(MyVector3D & initialPosition, MyVector3D & initialScale, MyVector3D & initialRotation) :
	position(initialPosition), scale(initialScale), rotation(initialRotation)
{
}

MyObject3D::~MyObject3D()
{
}

void MyObject3D::Update()
{
	//modelMatrix *= transformMatrix;
	//transformMatrix = MyMatrix4::IdentityMatrix();
}

void MyObject3D::Rotate(float const & x, float const & y, float const & z, bool isDegree)
{
}

void MyObject3D::Rotate(MyVector3D const & vector, bool isDegree)
{
}

void MyObject3D::Rotate(MyVector4D const & vector, bool isDegree)
{
}

void MyObject3D::Scale(float const & x, float const & y, float const & z)
{
}

void MyObject3D::Scale(MyVector3D const & vector)
{
}

void MyObject3D::Scale(MyVector4D const & vector)
{
}

void MyObject3D::Translate(float const & x, float const & y, float const & z)
{
	//transformMatrix *= MyMatrix4::TranslationMatrix(x, y, z);
}

void MyObject3D::Translate(MyVector3D const & vector)
{
	//transformMatrix *= MyMatrix4::TranslationMatrix(vector);
}

void MyObject3D::Translate(MyVector4D const & vector)
{
	//transformMatrix *= MyMatrix4::TranslationMatrix(vector);
}

const MyVector3D & MyObject3D::GetPosition() const
{
	return position;
}

const MyVector3D & MyObject3D::GetRotation() const
{
	return rotation;
}

const MyVector3D & MyObject3D::GetScale() const
{
	return scale;
}

void MyObject3D::SetPosition(float const & x, float const & y, float const & z)
{
}

void MyObject3D::SetPosition(MyVector3D const & vector)
{
}

void MyObject3D::SetPosition(MyVector4D const & vector)
{
}

void MyObject3D::SetRotation(float const & x, float const & y, float const & z)
{
}

void MyObject3D::SetRotation(MyVector3D const & vector)
{
}

void MyObject3D::SetRotation(MyVector4D const & vector)
{
}

void MyObject3D::SetScale(float const & x, float const & y, float const & z)
{
}

void MyObject3D::SetScale(MyVector3D const & vector)
{
}

void MyObject3D::SetScale(MyVector4D const & vector)
{
}
