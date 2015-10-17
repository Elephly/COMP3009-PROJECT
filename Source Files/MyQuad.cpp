#include "MyQuad.h"

MyQuad::MyQuad(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyVertex4D & vertex1, MyVertex4D & vertex2, MyVertex4D & vertex3, MyVertex4D & vertex4) :
	MyGraphicsObject3D(position, scale, rotation)
{
	children->push_back(new MyTriangle(position, scale, rotation, vertex1, vertex2, vertex4));
	children->push_back(new MyTriangle(position, scale, rotation, vertex2, vertex3, vertex4));
}

MyQuad::~MyQuad()
{
}

void MyQuad::Initialize(MyShaderProgram * shader)
{
	MyGraphicsObject3D::Initialize(shader);
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Initialize(shader);
	}
}

void MyQuad::Update()
{
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Update();
	}
}

void MyQuad::Draw()
{
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		((MyGraphicsObject3D *)(*it))->Draw();
	}
}