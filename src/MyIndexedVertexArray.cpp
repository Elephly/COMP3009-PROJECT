#include "MyIndexedVertexArray.h"

#include "MyDefines.h"
#include <GL/glew.h>
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

		unsigned char *addr_ver = (unsigned char *)&v;
		unsigned char *addr_pos = (unsigned char *)&v.GetPosition().GetXAddr();
		unsigned char *addr_nor = (unsigned char *)&v.GetNormal().GetXAddr();
		unsigned char *addr_col = (unsigned char *)&v.GetColor().GetRedAddr();
		unsigned char *addr_tex = (unsigned char *)&v.GetTextureCoord().GetXAddr();

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex4D) * vertexCount, vertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glEnableVertexAttribArray(positionLoc);
		long int attAddress = addr_pos - addr_ver;
		glVertexAttribPointer(positionLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)(intptr_t)attAddress);
		//glVertexAttribDivisor(positionLoc, 0);

		glEnableVertexAttribArray(normalLoc);
		attAddress = addr_nor - addr_ver;
		glVertexAttribPointer(normalLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)(intptr_t)attAddress);
		//glVertexAttribDivisor(normalLoc, 0);

		glEnableVertexAttribArray(colorLoc);
		attAddress = addr_col - addr_ver;
		glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)(intptr_t)attAddress);
		//glVertexAttribDivisor(colorLoc, 0);

		glEnableVertexAttribArray(textureCoordLoc);
		attAddress = addr_tex - addr_ver;
		glVertexAttribPointer(textureCoordLoc, 2, GL_FLOAT, GL_FALSE, sizeof(MyVertex4D), (void *)(intptr_t)attAddress);
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
