#include "MyApplication.h"

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include "windows.h"
#include "glew.h"
#include <GL/gl.h>
#include <glut.h>
#include "soil.h"
#include <wglew.h>
#endif

#include "MyStringUtil.h"

MyApplication::MyApplication(char * name)
{
	applicationName = MyStringUtil::CopyString(name);
	windowWidth = 0;
	windowHeight = 0;
	windowID = 0;
	inputManager = new MyInputManager();

	colorShader = new MyShaderProgram();
}

MyApplication::~MyApplication()
{
	if (windowID != 0)
	{
		glutDestroyWindow(windowID);
	}
	MyDeleteArray(applicationName);
	MyDelete(inputManager);
	MyDelete(colorShader);
}

void MyApplication::Initialize(int *argc, char **argv)
{
	glutInit(argc, argv);
	windowWidth = (int)(0.75f * (float)glutGet(GLUT_SCREEN_WIDTH));
	windowHeight = (int)((float)windowWidth / ((float)ASPECT_RATIO_X / (float)ASPECT_RATIO_Y));
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((int)((float)(glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2.0f),
		(int)((float)(glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 4.0f));
	windowID = glutCreateWindow(applicationName);
	if (GLenum err = glewInit() != GLEW_OK)
	{
		throw glewGetErrorString(err);
	}
	colorShader->InitializeShaderProgram("Shader Files\\Color.vert", "Shader Files\\Color.frag");
	glUseProgram(colorShader->GetShaderProgram());
}

void MyApplication::LoadContent()
{
}

void MyApplication::Update()
{
}

void MyApplication::Draw()
{
}

void MyApplication::Run()
{
	glutMainLoop();
}

char * MyApplication::GetName()
{
	return MyStringUtil::CopyString(applicationName);
}

int MyApplication::GetWindowWidth()
{
	return windowWidth;
}

int MyApplication::GetWindowHeight()
{
	return windowHeight;
}

void MyApplication::RegisterReshapeFunc(void(*callback)(int width, int height))
{
	glutReshapeFunc(callback);
}

void MyApplication::RegisterDisplayFunc(void(*callback)())
{
	glutDisplayFunc(callback);
}

void MyApplication::RegisterKeyboardFunc(void(*callback)(unsigned char key, int x, int y))
{
	glutKeyboardFunc(callback);
}

void MyApplication::RegisterKeyboardUpFunc(void(*callback)(unsigned char key, int x, int y))
{
	glutKeyboardUpFunc(callback);
}

void MyApplication::RegisterMouseFunc(void(*callback)(int button, int state, int x, int y))
{
	glutMouseFunc(callback);
}

void MyApplication::RegisterMouseMoveFunc(void(*callback)(int x, int y))
{
	glutMotionFunc(callback);
}

void MyApplication::RegisterMouseMovePassiveFunc(void(*callback)(int x, int y))
{
	glutPassiveMotionFunc(callback);
}

void MyApplication::ReshapeFunc(int width, int height)
{
	windowWidth = width;
	windowHeight = height;

	// use the full view port
	glViewport(0, 0, windowWidth, windowHeight);

	// use 2D  orthographic parallel projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
}

void MyApplication::DisplayFunc()
{
	int x = 0, y = 0;
	float r = 100.0f / 255.0f;
	float g = 149.0f / 255.0f;
	float b = 237.0f / 255.0f;
	float a = 1.0f;

	// clear the window
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);

	/*
	MyVertex3D v;
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	GLuint positionLoc = glGetAttribLocation(shaderProgram, "vtxPos");
	glEnableVertexAttribArray(positionLoc);
	int attAddress = (char *)&v.v - (char *)&v;
	glVertexAttribPointer(positionLoc, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex3D), (void *)attAddress);
	GLuint colorLoc = glGetAttribLocation(shaderProgram, "vtxColor");
	glEnableVertexAttribArray(colorLoc);
	attAddress = (char *)&v.c - (char *)&v;
	glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, sizeof(MyVertex3D), (void *)attAddress);
	GLuint loc = glGetUniformLocation(shaderProgram, "useColourAtt");
	glUniform1i(loc, 1);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(positionLoc);
	glDisableVertexAttribArray(colorLoc);
	*/

	glutSwapBuffers();

	glutPostRedisplay();
}

void MyApplication::KeyboardFunc(unsigned char key, int x, int y)
{
	if (inputManager->Keys[key] == GLUT_UP)
	{
		// UNREACHABLE
		if (key == 27)
		{
			// exit
		}
	}
	if (inputManager != 0)
	{
		inputManager->Keys[key] = GLUT_DOWN;
	}
}

void MyApplication::KeyboardUpFunc(unsigned char key, int x, int y)
{
	inputManager->Keys[key] = GLUT_UP;
}

void MyApplication::MouseFunc(int button, int state, int x, int y)
{
	int winWidth = glutGet(GLUT_WINDOW_WIDTH);
	int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int glX = x;
	int glY = winHeight - y;

	// mouse press event
	if (inputManager->Mouse[button] == GLUT_UP && state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{

		}
		if (button == GLUT_MIDDLE_BUTTON)
		{

		}
		if (button == GLUT_RIGHT_BUTTON)
		{

		}
	}

	// mouse release event
	if (inputManager->Mouse[button] == GLUT_DOWN && state == GLUT_UP)
	{
		if (button == GLUT_LEFT_BUTTON)
		{

		}
		if (button == GLUT_MIDDLE_BUTTON)
		{

		}
		if (button == GLUT_RIGHT_BUTTON)
		{

		}
	}

	inputManager->Mouse[button] = state;
	inputManager->MouseLocation.SetX((float)glX);
	inputManager->MouseLocation.SetY((float)glY);
}

void MyApplication::MouseMoveFunc(int x, int y)
{
	int winWidth = glutGet(GLUT_WINDOW_WIDTH);
	int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int glX = x;
	int glY = winHeight - y;

	if (inputManager->Mouse[GLUT_LEFT_BUTTON] == GLUT_DOWN)
	{

	}
	if (inputManager->Mouse[GLUT_MIDDLE_BUTTON] == GLUT_DOWN)
	{

	}
	if (inputManager->Mouse[GLUT_RIGHT_BUTTON] == GLUT_DOWN)
	{

	}
	inputManager->MouseLocation.SetX((float)glX);
	inputManager->MouseLocation.SetY((float)glY);
}

void MyApplication::MouseMovePassiveFunc(int x, int y)
{
	int winWidth = glutGet(GLUT_WINDOW_WIDTH);
	int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int glX = x;
	int glY = winHeight - y;
	inputManager->MouseLocation.SetX((float)glX);
	inputManager->MouseLocation.SetY((float)glY);
}