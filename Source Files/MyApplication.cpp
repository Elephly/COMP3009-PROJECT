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
#include "MyMatrix.h"

#if (MY_DEBUG == 1)
#include <iostream>
#endif // MY_DEBUG

using namespace std;

MyApplication::MyApplication(char * name)
{
	applicationName = MyStringUtil::CopyString(name);
	windowWidth = 0;
	windowHeight = 0;
	windowID = 0;
	inputManager = new MyInputManager();

	colorShader = new MyShaderProgram();

	MyVector3D cameraPosition(0.0f, 0.0f, 5.0f);
	MyVector3D cameraLookAt(0.0f, 0.0f, -1.0f);
	MyVector3D cameraUpVector(0.0f, 1.0f, 0.0f);
	MyMatrix4 projectionMatrix = MyMatrix4::SymmetricPerspectiveProjectionMatrix(30.0f, (float)ASPECT_RATIO_X / (float)ASPECT_RATIO_Y, 0.1f, 1000.0f);
	camera = new MyCamera(cameraPosition, cameraLookAt, cameraUpVector, projectionMatrix);

	testTriangleFront = new MyTriangle();
	testTriangleBack = new MyTriangle();

	testQuadFront = new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(-0.5f, -0.5f, 0.0f, 1.0f, MyColorRGBA(0.0f, 1.0f, 0.0f, 1.0f)),
		MyVertex4D(-0.5f, 0.5f, 0.0f, 1.0f, MyColorRGBA(0.0f, 1.0f)),
		MyVertex4D(0.5f, 0.5f, 0.0f, 1.0f, MyColorRGBA(1.0f, 1.0f)),
		MyVertex4D(0.5f, -0.5f, 0.0f, 1.0f, MyColorRGBA(1.0f, 1.0f)));
	testQuadBack = new MyQuad(MyVector3D(), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyVertex4D(-0.5f, -0.5f, 0.0f, 1.0f, MyColorRGBA(0.0f, 1.0f, 0.0f, 1.0f)),
		MyVertex4D(-0.5f, 0.5f, 0.0f, 1.0f, MyColorRGBA(0.0f, 1.0f)),
		MyVertex4D(0.5f, 0.5f, 0.0f, 1.0f, MyColorRGBA(1.0f, 1.0f)),
		MyVertex4D(0.5f, -0.5f, 0.0f, 1.0f, MyColorRGBA(1.0f, 1.0f)));

	testCube = new MyCube(MyVector3D(-1.0f, 1.0f, -1.0f), MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D(),
		MyColorRGBA(1.0f), MyColorRGBA(0.0f, 1.0f), MyColorRGBA(0.0f, 0.0f, 1.0f),
		MyColorRGBA(1.0f, 1.0f), MyColorRGBA(1.0f, 0.0f, 1.0f), MyColorRGBA(0.0f, 1.0f, 1.0f));
}

MyApplication::~MyApplication()
{
	MyDelete(testTriangleFront);
	MyDelete(testTriangleBack);
	MyDelete(testQuadFront);
	MyDelete(testQuadBack);
	MyDelete(testCube);
	MyDelete(camera);
	MyDelete(colorShader);
	if (windowID != 0)
	{
		glutDestroyWindow(windowID);
	}
	MyDelete(inputManager);
	MyDeleteArray(applicationName);
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
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	if (GLenum err = glewInit() != GLEW_OK)
	{
		throw glewGetErrorString(err);
	}
	colorShader->InitializeShaderProgram("Shader Files\\Color.vert", "Shader Files\\Color.frag");
	glUseProgram(colorShader->GetShaderProgram());

	testTriangleFront->Initialize(colorShader);
	testTriangleBack->Initialize(colorShader);
	testTriangleBack->Yaw(180.0f);
	testTriangleFront->Translate(MyVector3D(-0.5f, 0.0f, 0.5f));
	testTriangleBack->Translate(MyVector3D(-0.5f, 0.0f, 0.5f));
	testQuadFront->Initialize(colorShader);
	testQuadBack->Initialize(colorShader);
	testQuadBack->Yaw(180.0f);
	testQuadFront->Translate(MyVector3D(0.5f, 0.0f, -0.5f));
	testQuadBack->Translate(MyVector3D(0.5f, 0.0f, -0.5f));
	testCube->Initialize(colorShader);

	ShadersUpdateCameraMatrix();
	ShadersUpdateProjectionMatrix();
}

void MyApplication::LoadContent()
{
}

void MyApplication::Update()
{
	bool cameraTransformed = false;
	if (inputManager != 0)
	{
		MyVector3D direction = camera->GetDirection();
		MyVector3D right = camera->GetRightVector();
		MyVector3D up = camera->GetUpVector();
		if (inputManager->Keys['W'] == GLUT_DOWN || inputManager->Keys['w'] == GLUT_DOWN)
		{
			camera->Translate(direction * 0.1f);
			cameraTransformed = true;
		}
		if (inputManager->Keys['A'] == GLUT_DOWN || inputManager->Keys['a'] == GLUT_DOWN)
		{
			camera->Translate(-right * 0.1f);
			cameraTransformed = true;
		}
		if (inputManager->Keys['S'] == GLUT_DOWN || inputManager->Keys['s'] == GLUT_DOWN)
		{
			camera->Translate(-direction * 0.1f);
			cameraTransformed = true;
		}
		if (inputManager->Keys['D'] == GLUT_DOWN || inputManager->Keys['d'] == GLUT_DOWN)
		{
			camera->Translate(right * 0.1f);
			cameraTransformed = true;
		}
		if (inputManager->Keys['Q'] == GLUT_DOWN || inputManager->Keys['q'] == GLUT_DOWN)
		{
			camera->Translate(up * 0.1f);
			cameraTransformed = true;
		}
		if (inputManager->Keys['C'] == GLUT_DOWN || inputManager->Keys['c'] == GLUT_DOWN)
		{
			camera->Translate(-up * 0.1f);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_UP] == GLUT_DOWN)
		{
			camera->Pitch(2.0f);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_LEFT] == GLUT_DOWN)
		{
			camera->Yaw(2.0f);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_DOWN] == GLUT_DOWN)
		{
			camera->Pitch(-2.0f);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_RIGHT] == GLUT_DOWN)
		{
			camera->Yaw(-2.0f);
			cameraTransformed = true;
		}
	}
	camera->Update();
	if (cameraTransformed)
	{
		ShadersUpdateCameraMatrix();
	}

	testCube->Yaw(2.0f);
	testTriangleFront->Update();
	testTriangleBack->Update();
	testQuadFront->Update();
	testQuadBack->Update();
	testCube->Update();
}

void MyApplication::Draw()
{
	MyColorRGBA c = MyColors::CornflowerBlue;
	glClearColor(c.GetRed(), c.GetGreen(), c.GetBlue(), c.GetAlpha());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	testTriangleFront->Draw();
	testTriangleBack->Draw();
	testQuadFront->Draw();
	testQuadBack->Draw();
	testCube->Draw();

	glutSwapBuffers();

	glutPostRedisplay();
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

void MyApplication::RegisterTimerFunc(void(*callback)(int operation))
{
	glutTimerFunc(FRAME_TIME, callback, TIMER_UPDATE_OPERATION);
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

void MyApplication::RegisterSpecialFunc(void(*callback)(int key, int x, int y))
{
	glutSpecialFunc(callback);
}

void MyApplication::RegisterSpecialUpFunc(void(*callback)(int key, int x, int y))
{
	glutSpecialUpFunc(callback);
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

void MyApplication::TimerFunc(int operation)
{
	switch (operation)
	{
	case TIMER_UPDATE_OPERATION:
		Update();
		break;
	default:
		break;
	}
}

void MyApplication::DisplayFunc()
{
	Draw();
}

void MyApplication::KeyboardFunc(unsigned char key, int x, int y)
{
	if (inputManager != 0)
	{
		if (inputManager->Keys[key] == GLUT_UP)
		{

		}
		else
		{

		}
		inputManager->Keys[key] = GLUT_DOWN;
	}
}

void MyApplication::KeyboardUpFunc(unsigned char key, int x, int y)
{
	if (inputManager != 0)
	{
		inputManager->Keys[key] = GLUT_UP;
	}
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
	inputManager->MouseLocation.SetX((float &)glX);
	inputManager->MouseLocation.SetY((float &)glY);
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
	inputManager->MouseLocation.SetX((float &)glX);
	inputManager->MouseLocation.SetY((float &)glY);
}

void MyApplication::MouseMovePassiveFunc(int x, int y)
{
	int winWidth = glutGet(GLUT_WINDOW_WIDTH);
	int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
	int glX = x;
	int glY = winHeight - y;
	inputManager->MouseLocation.SetX((float &)glX);
	inputManager->MouseLocation.SetY((float &)glY);
}

void MyApplication::SpecialFunc(int key, int x, int)
{
	if (inputManager != 0)
	{
		if (inputManager->SpecialKeys[key] == GLUT_UP)
		{

		}
		else
		{

		}
		inputManager->SpecialKeys[key] = GLUT_DOWN;
	}
}

void MyApplication::SpecialUpFunc(int key, int x, int)
{
	if (inputManager != 0)
	{
		inputManager->SpecialKeys[key] = GLUT_UP;
	}
}

void MyApplication::ShadersUpdateCameraMatrix()
{
	colorShader->BindUniformMatrix(camera->GetViewMatrix(), "view");
}

void MyApplication::ShadersUpdateProjectionMatrix()
{
	colorShader->BindUniformMatrix(camera->GetProjectionMatrix(), "projection");
}
