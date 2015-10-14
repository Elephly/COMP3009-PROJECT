#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#include "MyVertex.h"
#include "MyShaderProgram.h"

class MyTriangle
{
public:
	MyTriangle(MyVertex3D &vertex1 = MyVertex3D(), MyVertex3D &vertex2 = MyVertex3D(), MyVertex3D &vertex3 = MyVertex3D());
	~MyTriangle();

	void Initialize(MyShaderProgram *shader);
	void Draw();

	// Getters
	MyVertex3D &GetCurrentVertex();
	MyVertex3D &GetNextVertex();

	// Setters
	void SetShader(MyShaderProgram *shader);
	void SetCurrentVertex(MyVertex3D &vertex);
	void SetNextVertex(MyVertex3D &vertex);
	void SetCurrentVertex(float x, float y, float z, MyColorRGBA &color = MyColorRGBA());
	void SetNextVertex(float x, float y, float z, MyColorRGBA &color = MyColorRGBA());

private:
	int currentVertex;
	MyVertex3D vertices[3];
	MyShaderProgram *shaderProgram;
	unsigned int vertexArrayObject;
};

#endif // MYTRIANGLE_H
