#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#include "MyVertex.h"
#include "MyShaderProgram.h"

class MyTriangle
{
public:
	MyTriangle(MyVertex4D &vertex1 = MyVertex4D(), MyVertex4D &vertex2 = MyVertex4D(), MyVertex4D &vertex3 = MyVertex4D());
	~MyTriangle();

	void Initialize(MyShaderProgram *shader);
	void Draw();

	// Getters
	MyVertex4D &GetCurrentVertex();
	MyVertex4D &GetNextVertex();

	// Setters
	void SetShader(MyShaderProgram *shader);
	void SetCurrentVertex(MyVertex4D &vertex);
	void SetNextVertex(MyVertex4D &vertex);
	void SetCurrentVertex(float x, float y, float z, float w, MyColorRGBA &color = MyColorRGBA());
	void SetNextVertex(float x, float y, float z, float w, MyColorRGBA &color = MyColorRGBA());

private:
	int currentVertex;
	MyVertex4D vertices[3];
	MyShaderProgram *shaderProgram;
	unsigned int vertexArrayObject;
};

#endif // MYTRIANGLE_H
