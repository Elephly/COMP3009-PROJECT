#include "MyGraphicsObject3D.h"

#include <glew.h>

MyGraphicsObject3D::MyGraphicsObject3D(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation) :
	MyObject3D(position, scale, rotation)
{
	shaderProgram = 0;
	vertexArrayObject = 0;
	vertices = 0;
	numVertices = 0;
	hasVAO = 0;
}

MyGraphicsObject3D::~MyGraphicsObject3D()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}

void MyGraphicsObject3D::Initialize(MyShaderProgram * shader)
{
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Initialize(shader);
	}
	shaderProgram = shader;

	if (numVertices > 0)
	{
		GLuint vbo;
		MyVertex4D v;

		unsigned int *addr_ver = (unsigned int *)&v;
		unsigned int *addr_vec = (unsigned int *)&v.GetVector().GetXAddr();
		unsigned int *addr_col = (unsigned int *)&v.GetColor().GetRedAddr();

		glGenVertexArrays(1, &vertexArrayObject);
		glBindVertexArray(vertexArrayObject);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex4D) * numVertices, vertices, GL_STATIC_DRAW);

		GLuint positionLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxPos");
		glEnableVertexAttribArray(positionLoc);
		unsigned int attAddress = (unsigned int)addr_vec - (unsigned int)addr_ver;
		glVertexAttribPointer(positionLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);
		GLuint colorLoc = glGetAttribLocation(shaderProgram->GetShaderProgram(), "vtxColor");
		glEnableVertexAttribArray(colorLoc);
		attAddress = (unsigned int)addr_col - (unsigned int)addr_ver;
		glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);

		glEnableVertexAttribArray(0);
		glBindVertexArray(0);

		glDeleteBuffers(1, &vbo);

		hasVAO = true;
	}
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

	if (hasVAO)
	{
		glBindVertexArray(vertexArrayObject);
		glDrawArrays(GL_TRIANGLES, 0, numVertices);
		glBindVertexArray(0);
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
