#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#include "MyMath.h"
#include "MyGraphicsObject3D.h"
#include "MyVertex.h"
#include "MyShaderProgram.h"

class MyTriangle : public MyGraphicsObject3D
{
public:
	MyTriangle(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D(),
		MyVertex4D &vertex1 = MyVertex4D(MyVector4D(0.0f, sin(DegreeToRadian(60.0f)) / 2.0f)),
		MyVertex4D &vertex2 = MyVertex4D(MyVector4D(cos(DegreeToRadian(60.0f)), -sin(DegreeToRadian(60.0f)) / 2.0f)),
		MyVertex4D &vertex3 = MyVertex4D(MyVector4D(-cos(DegreeToRadian(60.0f)), -sin(DegreeToRadian(60.0f)) / 2.0f)));
	virtual ~MyTriangle();

	virtual void Initialize(MyShaderProgram *shader);
	virtual void Update();
	virtual void Draw(MyMatrix4 const & parentTransformation = MyMatrix4::IdentityMatrix());

	// Getters
	MyVertex4D &GetCurrentVertex();
	MyVertex4D &GetNextVertex();

	// Setters
	void SetCurrentVertex(MyVertex4D &vertex);
	void SetNextVertex(MyVertex4D &vertex);
	void SetCurrentVertex(float x, float y, float z, float w, MyColorRGBA &color = MyColorRGBA());
	void SetNextVertex(float x, float y, float z, float w, MyColorRGBA &color = MyColorRGBA());

private:
	int currentVertex;
	MyVertex4D vertices[3];
	unsigned int vertexArrayObject;
};

#endif // MYTRIANGLE_H
