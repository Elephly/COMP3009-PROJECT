#include "MyGraphicsObject3D.h"

#include <glew.h>

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
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Initialize(shader);
	}
	shaderProgram = shader;
}

void MyGraphicsObject3D::Draw(MyMatrix4 const & parentTransformation)
{
	// ISROT
	MyMatrix4 transformation = (parentTransformation *
		(MyMatrix4::TranslationMatrix(position) *
		(MyMatrix4::RollPitchYawRotationMatrix(rotation.GetZ(), rotation.GetX(), rotation.GetY()) *
		(MyMatrix4::ScaleMatrix(scale.GetX(), scale.GetY(), scale.GetZ()) *
		MyMatrix4::IdentityMatrix()))));

	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Draw(transformation);
	}

	if (shaderProgram != 0)
	{
		glUseProgram(shaderProgram->GetShaderProgram());

		shaderProgram->BindUniformMatrix(transformation, "transform");
	}
}

MyShaderProgram * MyGraphicsObject3D::GetShader()
{
	return shaderProgram;
}

void MyGraphicsObject3D::SetShader(MyShaderProgram * shader)
{
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->SetShader(shader);
	}
	shaderProgram = shader;
}
