#include "MyIndexedVertexArray.h"

#include "MyDefines.h"

MyIndexedVertexArray::MyIndexedVertexArray(MyVertex4D * v, int const & numVertices) :
	vertices(v), vertexCount(numVertices)
{
}

MyIndexedVertexArray::~MyIndexedVertexArray()
{
	MyDeleteArray(vertices);
}

MyVertex4D ** MyIndexedVertexArray::GetVertices()
{
	return &vertices;
}

int MyIndexedVertexArray::GetVertexCount() const
{
	return vertexCount;
}

void MyIndexedVertexArray::SetVertices(MyVertex4D * v, int const & numVertices)
{
	vertices = v;
	vertexCount = numVertices;
}
