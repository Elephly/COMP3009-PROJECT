#ifndef MYGRAPHICSOBJECT3D_H
#define MYGRAPHICSOBJECT3D_H

#include "MyObject3D.h"
#include "MyShaderProgram.h"
#include "MyMaterial.h"
#include "MyVertex.h"

class MyGraphicsObject3D : public MyObject3D
{
public:
	MyGraphicsObject3D(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D());
	virtual ~MyGraphicsObject3D() = 0;

	virtual void Initialize(MyShaderProgram *shader, MyMaterial *material, bool recursive = false);
	virtual void Draw(MyMatrix4 const & parentTransformation = MyMatrix4::IdentityMatrix());

	// Getters
	virtual MyShaderProgram *GetShader();
	virtual MyMaterial *GetMaterial();

	// Setters
	virtual void SetShader(MyShaderProgram *shader, bool recursive = false);
	virtual void SetMaterial(MyMaterial *shader, bool recursive = false);

protected:
	MyShaderProgram *shaderProgram;
	MyMaterial *objectMaterial;
	unsigned int vertexArrayObject;
	MyVertex4D **vertices;
	int numVertices;
	bool isDynamicArray;
};

#endif // !MYGRAPHICSOBJECT3D_H
