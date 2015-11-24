#include "MyGraphicsObject3D.h"

#include <glew.h>

MyGraphicsObject3D::MyGraphicsObject3D(MyIndexedVertexArray *vertexArray, MyVector3D & position, MyVector3D & scale, MyVector3D & rotation) :
	MyObject3D(position, scale, rotation), vertices(vertexArray)
{
	shaderProgram = 0;
	objectMaterial = 0;
	vertexArrayObject = 0;
}

MyGraphicsObject3D::~MyGraphicsObject3D()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void MyGraphicsObject3D::Initialize(MyShaderProgram * shader, MyMaterial * material, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			((MyGraphicsObject3D *)(*it))->Initialize(shader, material, recursive);
		}
	}
	shaderProgram = shader;
	objectMaterial = material;

	int numVertices;

	if (vertices != 0 && (numVertices = vertices->GetVertexCount()) > 0)
	{
		GLuint vbo;
		MyVertex4D v;

		unsigned int *addr_ver = (unsigned int *)&v;
		unsigned int *addr_pos = (unsigned int *)&v.GetPosition().GetXAddr();
		unsigned int *addr_nor = (unsigned int *)&v.GetNormal().GetXAddr();
		unsigned int *addr_col = (unsigned int *)&v.GetColor().GetRedAddr();
		unsigned int *addr_tex = (unsigned int *)&v.GetTextureCoord().GetXAddr();

		glGenVertexArrays(1, &vertexArrayObject);
		glBindVertexArray(vertexArrayObject);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex4D) * numVertices, *(vertices->GetVertices()), GL_STATIC_DRAW);

		GLuint positionLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxPosition");
		glEnableVertexAttribArray(positionLoc);
		unsigned int attAddress = (unsigned int)addr_pos - (unsigned int)addr_ver;
		glVertexAttribPointer(positionLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);

		GLuint normalLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxNormal");
		glEnableVertexAttribArray(normalLoc);
		attAddress = (unsigned int)addr_nor - (unsigned int)addr_ver;
		glVertexAttribPointer(normalLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);

		GLuint colorLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxColor");
		glEnableVertexAttribArray(colorLoc);
		attAddress = (unsigned int)addr_col - (unsigned int)addr_ver;
		glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);

		GLuint textureCoordLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxTextureCoord");
		glEnableVertexAttribArray(textureCoordLoc);
		attAddress = (unsigned int)addr_tex - (unsigned int)addr_ver;
		glVertexAttribPointer(textureCoordLoc, 2, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);

		glEnableVertexAttribArray(0);
		glBindVertexArray(0);

		glDeleteBuffers(1, &vbo);
	}
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

	if (vertexArrayObject != 0)
	{
		glBindVertexArray(vertexArrayObject);
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
