#include "MyIndexedVertexArray.h"

#include "MyDefines.h"
#include <glew.h>
#include "MyShaderManager.h"

MyIndexedVertexArray::MyIndexedVertexArray(MyVertex4D * vertexArray, int const & numVertices) :
	vertices(vertexArray), vertexCount(numVertices), vao(0), vbo(0)
{
}

MyIndexedVertexArray::~MyIndexedVertexArray()
{
	MyDeleteArray(vertices);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void MyIndexedVertexArray::Initialize(MyVertex4D * vertexArray, int const & numVertices)
{
	if (vertexArray != 0) vertices = vertexArray;
	if (numVertices != 0) vertexCount = numVertices;

	if (vertices != 0 && vertexCount > 0)
	{
		MyVertex4D v;

		GLuint positionLoc = 0; // glGetAttribLocation((*it)->GetShaderProgram(), "vtxPosition");
		GLuint normalLoc = 1; // glGetAttribLocation((*it)->GetShaderProgram(), "vtxNormal");
		GLuint colorLoc = 2; // glGetAttribLocation((*it)->GetShaderProgram(), "vtxColor");
		GLuint textureCoordLoc = 3; // glGetAttribLocation((*it)->GetShaderProgram(), "vtxTextureCoord");

		unsigned int *addr_ver = (unsigned int *)&v;
		unsigned int *addr_pos = (unsigned int *)&v.GetPosition().GetXAddr();
		unsigned int *addr_nor = (unsigned int *)&v.GetNormal().GetXAddr();
		unsigned int *addr_col = (unsigned int *)&v.GetColor().GetRedAddr();
		unsigned int *addr_tex = (unsigned int *)&v.GetTextureCoord().GetXAddr();

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex4D) * vertexCount, vertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glEnableVertexAttribArray(positionLoc);
		unsigned int attAddress = (unsigned int)addr_pos - (unsigned int)addr_ver;
		glVertexAttribPointer(positionLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);
		//glVertexAttribDivisor(positionLoc, 0);

		glEnableVertexAttribArray(normalLoc);
		attAddress = (unsigned int)addr_nor - (unsigned int)addr_ver;
		glVertexAttribPointer(normalLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);
		//glVertexAttribDivisor(normalLoc, 0);

		glEnableVertexAttribArray(colorLoc);
		attAddress = (unsigned int)addr_col - (unsigned int)addr_ver;
		glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);
		//glVertexAttribDivisor(colorLoc, 0);

		glEnableVertexAttribArray(textureCoordLoc);
		attAddress = (unsigned int)addr_tex - (unsigned int)addr_ver;
		glVertexAttribPointer(textureCoordLoc, 2, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)attAddress);
		//glVertexAttribDivisor(textureCoordLoc, 0);

		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
	}
}

MyVertex4D ** MyIndexedVertexArray::GetVertices()
{
	return &vertices;
}

int MyIndexedVertexArray::GetVertexCount() const
{
	return vertexCount;
}

unsigned int MyIndexedVertexArray::GetVertexArrayObject()
{
	return vao;
}

void MyIndexedVertexArray::SetVertices(MyVertex4D * vertexArray, int const & numVertices)
{
	vertices = vertexArray;
	vertexCount = numVertices;
}
