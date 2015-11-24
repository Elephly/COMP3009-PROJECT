#ifndef MYINDEXEDVERTEXARRAY_H
#define MYINDEXEDVERTEXARRAY_H

#include "MyVertex.h"

class MyIndexedVertexArray
{
public:
	MyIndexedVertexArray(MyVertex4D *v = 0, int const & numVertices = 0);
	~MyIndexedVertexArray();

	// Getters
	virtual MyVertex4D **GetVertices();
	virtual int GetVertexCount() const;

	// Setters
	virtual void SetVertices(MyVertex4D *v, int const & numVertices);

private:
	MyVertex4D *vertices;
	int vertexCount;

};

#endif // MYINDEXEDVERTEXARRAY_H
