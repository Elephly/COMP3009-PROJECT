#include "MyApplication.h"
#include <time.h>

using namespace std;

void MainReshapeFunc(int width, int height);
void MainTimerFunc(int operation);
void MainDisplayFunc();
void MainKeyboardFunc(unsigned char key, int x, int y);
void MainKeyboardUpFunc(unsigned char key, int x, int y);
void MainMouseEntryFunc(int state);
void MainMouseFunc(int button, int state, int x, int y);
void MainMouseMoveFunc(int x, int y);
void MainMouseMovePassiveFunc(int x, int y);
void MainSpecialFunc(int key, int x, int y);
void MainSpecialUpFunc(int key, int x, int y);

MyApplication *myApplication;

int main(int argc, char *argv[])
{
	try
	{
		srand(time(0));
		myApplication = new MyApplication(PROJECT_NAME);
		myApplication->Initialize(&argc, argv);
		myApplication->RegisterReshapeFunc(MainReshapeFunc);
		myApplication->RegisterTimerFunc(MainTimerFunc);
		myApplication->RegisterDisplayFunc(MainDisplayFunc);
		myApplication->RegisterKeyboardFunc(MainKeyboardFunc);
		myApplication->RegisterKeyboardUpFunc(MainKeyboardUpFunc);
		myApplication->RegisterMouseEntryFunc(MainMouseEntryFunc);
		myApplication->RegisterMouseFunc(MainMouseFunc);
		myApplication->RegisterMouseMoveFunc(MainMouseMoveFunc);
		myApplication->RegisterMouseMovePassiveFunc(MainMouseMovePassiveFunc);
		myApplication->RegisterSpecialFunc(MainSpecialFunc);
		myApplication->RegisterSpecialUpFunc(MainSpecialUpFunc);
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

void MainMouseEntryFunc(int state)
{
	if (myApplication != 0)
	{
		myApplication->MouseEntryFunc(state);
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

void MainSpecialFunc(int key, int x, int y)
{
	if (myApplication != 0)
	{
		myApplication->SpecialFunc(key, x, y);
	}
}

void MainSpecialUpFunc(int key, int x, int y)
{
	if (myApplication != 0)
	{
		myApplication->SpecialUpFunc(key, x, y);
	}
}