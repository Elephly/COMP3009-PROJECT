#ifndef MYINDEXEDVERTEXARRAY_H
#define MYINDEXEDVERTEXARRAY_H

#include "MyVertex.h"

class MyIndexedVertexArray
{
public:
	MyIndexedVertexArray(MyVertex4D *vertexArray = 0, int const & numVertices = 0);
	~MyIndexedVertexArray();

	virtual void Initialize(MyVertex4D *vertexArray = 0, int const & numVertices = 0);

	// Getters
	virtual MyVertex4D **GetVertices();
	virtual int GetVertexCount() const;
	virtual unsigned int GetVertexArrayObject();

	// Setters
	virtual void SetVertices(MyVertex4D *vertexArray, int const & numVertices);

private:
	MyVertex4D *vertices;
	int vertexCount;
	unsigned int vbo;
	unsigned int vao;

};

#endif // MYINDEXEDVERTEXARRAY_H
