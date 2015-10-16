#include "MyApplication.h"

using namespace std;

void MainReshapeFunc(int width, int height);
void MainTimerFunc(int operation);
void MainDisplayFunc();
void MainKeyboardFunc(unsigned char key, int x, int y);
void MainKeyboardUpFunc(unsigned char key, int x, int y);
void MainMouseFunc(int button, int state, int x, int y);
void MainMouseMoveFunc(int x, int y);
void MainMouseMovePassiveFunc(int x, int y);

MyApplication *myApplication;

int main(int argc, char *argv[])
{
	try
	{
		myApplication = new MyApplication(PROJECT_NAME);
		myApplication->Initialize(&argc, argv);
		myApplication->RegisterReshapeFunc(MainReshapeFunc);
		myApplication->RegisterTimerFunc(MainTimerFunc);
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

	return 0;
}

void MainReshapeFunc(int width, int height)
{
	if (myApplication != 0)
	{
		myApplication->ReshapeFunc(width, height);
	}
}

void MainTimerFunc(int operation)
{
	if (myApplication != 0)
	{
		myApplication->RegisterTimerFunc(MainTimerFunc);
		myApplication->TimerFunc(operation);
	}
}

void MainDisplayFunc()
{
	if (myApplication != 0)
	{
		myApplication->DisplayFunc();
	}
}

void MainKeyboardFunc(unsigned char key, int x, int y)
{
	if (myApplication != 0)
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
}

void MainKeyboardUpFunc(unsigned char key, int x, int y)
{
	if (myApplication != 0)
	{
		myApplication->KeyboardUpFunc(key, x, y);
	}
}

void MainMouseFunc(int button, int state, int x, int y)
{
	if (myApplication != 0)
	{
		myApplication->MouseFunc(button, state, x, y);
	}
}
void MainMouseMoveFunc(int x, int y)
{
	if (myApplication != 0)
	{
		myApplication->MouseMoveFunc(x, y);
	}
}
void MainMouseMovePassiveFunc(int x, int y)
{
	if (myApplication != 0)
	{
		myApplication->MouseMovePassiveFunc(x, y);
	}
}