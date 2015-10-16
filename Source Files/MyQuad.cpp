#include "MyQuad.h"

MyQuad::MyQuad(MyVector3D & position, MyVector3D & scale, MyVector3D & rotation, MyVertex4D & vertex1, MyVertex4D & vertex2, MyVertex4D & vertex3, MyVertex4D & vertex4)
{
	t1 = new MyTriangle(position, scale, rotation, vertex1, vertex2, vertex4);
	t2 = new MyTriangle(position, scale, rotation, vertex2, vertex3, vertex4);
}

MyQuad::~MyQuad()
{
	MyDelete(t1);
	MyDelete(t2);
}

void MyQuad::Initialize(MyShaderProgram * shader)
{
	t1->Initialize(shader);
	t2->Initialize(shader);
}

void MyQuad::Update()
{
	t1->Update();
	t2->Update();
}

void MyQuad::Draw()
{
	t1->Draw();
	t2->Draw();
}
