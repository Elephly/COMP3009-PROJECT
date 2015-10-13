#include "MyQuad.h"

MyQuad::MyQuad(MyVertex3D &vertex1, MyVertex3D &vertex2, MyVertex3D &vertex3, MyVertex3D &vertex4)
{
	t1 = new MyTriangle(vertex1, vertex2, vertex4);
	t2 = new MyTriangle(vertex2, vertex3, vertex4);
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

void MyQuad::Draw()
{
	t1->Draw();
	t2->Draw();
}
