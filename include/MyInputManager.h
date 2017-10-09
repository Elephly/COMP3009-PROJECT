#ifndef MYINPUTMANAGER_H
#define MYINPUTMANAGER_H

#include "MyGeometry.h"

class MyInputManager
{
public:
	MyInputManager();
	~MyInputManager();

	char Keys[256];
	int SpecialKeys[256];
	char Mouse[3];
	MyPoint2D MouseLocation;
};

#endif // MYINPUTMANAGER_H
