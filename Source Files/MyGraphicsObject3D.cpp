#include "MyGraphicsObject3D.h"

#include <glew.h>

MyGraphicsObject3D::MyGraphicsObject3D(MyIndexedVertexArray *vertexArray, MyVector3D & position, MyVector3D & scale, MyVector3D & rotation) :
	MyObject3D(position, scale, rotation), vertices(vertexArray)
{
	shaderProgram = 0;
	objectMaterial = 0;
}

MyGraphicsObject3D::~MyGraphicsObject3D()
{
}

void MyGraphicsObject3D::Initialize(MyShaderProgram * shader, MyMaterial * material, bool recursive, MyIndexedVertexArray *vertexArray, bool recursiveVAO)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			if (recursiveVAO)
				((MyGraphicsObject3D *)(*it))->Initialize(shader, material, recursive, vertexArray, recursiveVAO);
			else
				((MyGraphicsObject3D *)(*it))->Initialize(shader, material, recursive);
		}
	}
	shaderProgram = shader;
	objectMaterial = material;
	if (vertexArray != 0) vertices = vertexArray;
}

void MyGraphicsObject3D::Draw(MyMatrix4 const & parentTransformation)
{
	MyObject3D::Draw(parentTransformation);

	if (shaderProgram != 0)
	{
		glUseProgram(shaderProgram->GetShaderProgram());

		shaderProgram->BindUniformMatrix(transformation, "transform");
		shaderProgram->BindUniformVector(MyVector4D(objectMaterial->GetAmbient()), "ambient");
		shaderProgram->BindUniformVector(MyVector4D(objectMaterial->GetDiffuse()), "diffuse");
		shaderProgram->BindUniformVector(MyVector4D(objectMaterial->GetSpecular()), "specular");
		shaderProgram->BindUniformFloat(objectMaterial->GetShine(), "shine");
	}

	if (vertices != 0 && vertices->GetVertexArrayObject() != 0)
	{
		glBindVertexArray(vertices->GetVertexArrayObject());
		//glDrawArraysInstancedARB(GL_TRIANGLES, 0, vertices->GetVertexCount(), 1);
		glDrawArrays(GL_TRIANGLES, 0, vertices->GetVertexCount());
		glBindVertexArray(0);
	}
}

MyShaderProgram * MyGraphicsObject3D::GetShader()
{
	return shaderProgram;
}

MyMaterial * MyGraphicsObject3D::GetMaterial()
{
	return objectMaterial;
}

MyIndexedVertexArray * MyGraphicsObject3D::GetIndexedVertexArray()
{
	return vertices;
}

void MyGraphicsObject3D::SetShader(MyShaderProgram * shader, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			((MyGraphicsObject3D *)(*it))->SetShader(shader, recursive);
		}
	}
	shaderProgram = shader;
}

void MyGraphicsObject3D::SetMaterial(MyMaterial * material, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			((MyGraphicsObject3D *)(*it))->SetMaterial(material, recursive);
		}
	}
	objectMaterial = material;
}

void MyGraphicsObject3D::SetIndexedVertexArray(MyIndexedVertexArray * vertexArray)
{
	vertices = vertexArray;
}
