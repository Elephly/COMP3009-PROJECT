#include "MyInputManager.h"

#include <GL/glut.h>

MyInputManager::MyInputManager()
{
	for (int i = 0; i < 256; i++)
	{
		Keys[i] = GLUT_UP;
	}
	for (int i = 0; i < 256; i++)
	{
		SpecialKeys[i] = GLUT_UP;
	}
	for (int i = 0; i < 3; i++)
	{
		Mouse[i] = GLUT_UP;
	}
	MouseLocation = MyPoint2D();
}

MyInputManager::~MyInputManager()
{
}