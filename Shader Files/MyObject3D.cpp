#include "MyObject3D.h"

MyObject3D::MyObject3D()
{
}

MyObject3D::~MyObject3D()
{
}

void MyObject3D::Update()
{
	modelMatrix *= transformMatrix;
}

const MyMatrix4 & MyObject3D::GetModelMatrix()
{
	return modelMatrix;
}

const MyMatrix4 & MyObject3D::GetTransformMatrix()
{
	return transformMatrix;
}
