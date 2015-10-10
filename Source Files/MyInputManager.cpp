#include "MyInputManager.h"

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif

MyInputManager::MyInputManager()
{
	for (int i = 0; i < 256; i++)
	{
		Keys[i] = GLUT_UP;
	}
	for (int i = 0; i < 3; i++)
	{
		Mouse[i] = GLUT_UP;
	}
	MouseLocation.x = 0;
	MouseLocation.y = 0;
}

MyInputManager::~MyInputManager()
{
}