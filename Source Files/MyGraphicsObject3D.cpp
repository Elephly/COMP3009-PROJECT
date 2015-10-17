#include "MyGraphicsObject3D.h"

MyGraphicsObject3D::MyGraphicsObject3D(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation) :
	MyObject3D(position, scale, rotation)
{
	shaderProgram = 0;
}

MyGraphicsObject3D::~MyGraphicsObject3D()
{
}

void MyGraphicsObject3D::Initialize(MyShaderProgram * shader)
{
	shaderProgram = shader;
}

void MyGraphicsObject3D::Draw()
{
	// ISROT
	if (shaderProgram != 0)
	{
		MyMatrix4 transformation = MyMatrix4::TranslationMatrix(position) *
			MyMatrix4::RollPitchYawRotationMatrix(rotation.GetZ(), rotation.GetX(), rotation.GetY()) *
			MyMatrix4::ScaleMatrix(scale.GetX(), scale.GetY(), scale.GetZ()) *
			MyMatrix4::IdentityMatrix();

		shaderProgram->BindUniformMatrix(transformation, "transform");
	}
}

MyShaderProgram * MyGraphicsObject3D::GetShader()
{
	return shaderProgram;
}

void MyGraphicsObject3D::SetShader(MyShaderProgram * shader)
{
	shaderProgram = shader;
}
