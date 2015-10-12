#include "MyApplication.h"

void MainReshapeFunc(int width, int height);
void MainDisplayFunc();
void MainKeyboardFunc(unsigned char key, int x, int y);
void MainKeyboardUpFunc(unsigned char key, int x, int y);
void MainMouseFunc(int button, int state, int x, int y);
void MainMouseMoveFunc(int x, int y);
void MainMouseMovePassiveFunc(int x, int y);
void test()
{
	char t[32];
	sprintf_s(t, "uh oh");
	throw t;
}

MyApplication *myApplication;

int main(int argc, char *argv[])
{
	try
	{
		myApplication = new MyApplication("COMP3009-PROJECT");
		myApplication->Initialize(&argc, argv);
		myApplication->RegisterReshapeFunc(MainReshapeFunc);
		myApplication->RegisterDisplayFunc(MainDisplayFunc);
		myApplication->RegisterKeyboardFunc(MainKeyboardFunc);
		myApplication->RegisterKeyboardUpFunc(MainKeyboardUpFunc);
		myApplication->RegisterMouseFunc(MainMouseFunc);
		myApplication->RegisterMouseMoveFunc(MainMouseMoveFunc);
		myApplication->RegisterMouseMovePassiveFunc(MainMouseMovePassiveFunc);
		myApplication->LoadContent();
		myApplication->Run();
	}
	catch (char *err)
	{
		fprintf(stderr, "Exception: %s\n\nPress enter to exit.", err);
		getchar();
	}

	MyDelete(myApplication);

	//initGeom();

	return 0;
}

void MainReshapeFunc(int width, int height)
{
	myApplication->ReshapeFunc(width, height);
}

void MainDisplayFunc()
{
	myApplication->DisplayFunc();
}

void MainKeyboardFunc(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		MyDelete(myApplication);
#ifdef _CRTDBG_MAP_ALLOC
		_CrtDumpMemoryLeaks();
#endif
	}
	else
	{
		myApplication->KeyboardFunc(key, x, y);
	}
}

void MainKeyboardUpFunc(unsigned char key, int x, int y)
{
	myApplication->KeyboardUpFunc(key, x, y);
}

void MainMouseFunc(int button, int state, int x, int y)
{
	myApplication->MouseFunc(button, state, x, y);
}
void MainMouseMoveFunc(int x, int y)
{
	myApplication->MouseMoveFunc(x, y);
}
void MainMouseMovePassiveFunc(int x, int y)
{
	myApplication->MouseMovePassiveFunc(x, y);
}

/*
void initGeom()
{
	MyVertex3D tri[3];
	tri[0].v.x = -1.0; tri[0].v.y = -1.0; tri[0].v.z = 0.0;
	tri[1].v.x = 0.0; tri[1].v.y = 1.0; tri[1].v.z = 0.0;
	tri[2].v.x = 1.0; tri[2].v.y = -1.0; tri[2].v.z = 0.0;

	tri[0].c.r = 1.0; tri[0].c.g = 0.0; tri[0].c.b = 0.0; tri[0].c.a = 1.0;
	tri[1].c.r = 0.0; tri[1].c.g = 1.0; tri[1].c.b = 0.0; tri[1].c.a = 1.0;
	tri[2].c.r = 0.0; tri[2].c.g = 0.0; tri[2].c.b = 1.0; tri[2].c.a = 1.0;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri), tri, GL_STATIC_DRAW);
}
*/