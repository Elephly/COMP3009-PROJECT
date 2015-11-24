#ifndef MYGRAPHICSOBJECT3D_H
#define MYGRAPHICSOBJECT3D_H

#include "MyObject3D.h"
#include "MyShaderProgram.h"
#include "MyMaterial.h"
#include "MyVertex.h"
#include "MyIndexedVertexArray.h"

class MyGraphicsObject3D : public MyObject3D
{
public:
	MyGraphicsObject3D(MyIndexedVertexArray *vertexArray = 0, MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D());
	virtual ~MyGraphicsObject3D();

	virtual void Initialize(MyShaderProgram *shader, MyMaterial *material, bool recursive = false);
	virtual void Draw(MyMatrix4 const & parentTransformation = MyMatrix4::IdentityMatrix());

	// Getters
	virtual MyShaderProgram *GetShader();
	virtual MyMaterial *GetMaterial();
	virtual MyIndexedVertexArray *GetIndexedVertexArray();

	// Setters
	virtual void SetShader(MyShaderProgram *shader, bool recursive = false);
	virtual void SetMaterial(MyMaterial *shader, bool recursive = false);
	virtual void SetIndexedVertexArray(MyIndexedVertexArray *vertexArray);

protected:
	MyShaderProgram *shaderProgram;
	MyMaterial *objectMaterial;
	unsigned int vertexArrayObject;
	MyIndexedVertexArray *vertices;
};

#endif // !MYGRAPHICSOBJECT3D_H
