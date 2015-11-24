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
	cameraMoveSpeed = 4.0f;
	cameraRotateSpeed = 60.0f;
	renderWireFrame = false;

	applicationName = MyStringUtil::CopyString(name);
	windowWidth = 0;
	windowHeight = 0;
	windowID = 0;
	totalElapsedTime = 0;
	elapsedTime = 0;
	inputManager = new MyInputManager();

	colorShader = new MyShaderProgram();
	gouraudShader = new MyShaderProgram();
	phongShader = new MyShaderProgram();

	shinyMaterial = new MyMaterial(MyColorRGBA(0.25f, 0.25f, 0.25f), MyColorRGBA(0.75f, 0.75f, 0.75f), MyColorRGBA(0.5f, 0.5f, 0.5f), 128.0f);

	primaryLightSource = MyLightSource(100.0f, 100.0f, 100.0f);

	MyVector3D cameraPosition(0.0f, 0.0f, 0.0f);
	MyVector3D cameraLookAt(0.0f, 0.0f, -1.0f);
	MyVector3D cameraUpVector(0.0f, 1.0f, 0.0f);
	MyMatrix4 projectionMatrix = MyMatrix4::SymmetricPerspectiveProjectionMatrix(30.0f, (float)ASPECT_RATIO_X / (float)ASPECT_RATIO_Y, 0.1f, 1000.0f);
	camera = new MyCamera(cameraPosition, cameraLookAt, cameraUpVector, projectionMatrix, true);

	testManikin = new MyManikin();
}

MyApplication::~MyApplication()
{
	MyDelete(testManikin);

	MyDelete(camera);

	MyDelete(shinyMaterial);

	MyDelete(colorShader);
	MyDelete(gouraudShader);
	MyDelete(phongShader);

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
	totalElapsedTime = glutGet(GLUT_ELAPSED_TIME);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	if (GLenum err = glewInit() != GLEW_OK)
	{
		throw glewGetErrorString(err);
	}

	colorShader->InitializeShaderProgram("Shader Files\\ColorVert.glsl", "Shader Files\\ColorFrag.glsl");
	gouraudShader->InitializeShaderProgram("Shader Files\\GouraudVert.glsl", "Shader Files\\GouraudFrag.glsl");
	phongShader->InitializeShaderProgram("Shader Files\\PhongVert.glsl", "Shader Files\\PhongFrag.glsl");

	camera->Translate(0.0f, 0.0f, 10.0f);

	testManikin->Initialize(phongShader, shinyMaterial);
	testManikin->Yaw(-90.0f);

	ShadersUpdateLightSource();
	ShadersUpdateCameraMatrix();
	ShadersUpdateProjectionMatrix();
}

void MyApplication::LoadContent()
{
}

void MyApplication::Update(float const & deltaTime)
{
	bool cameraTransformed = false;
	if (inputManager != 0)
	{
		MyVector3D direction = camera->GetDirection();
		MyVector3D right = camera->GetRightVector();
		MyVector3D up = camera->GetUpVector();
		if (inputManager->Keys['W'] == GLUT_DOWN || inputManager->Keys['w'] == GLUT_DOWN)
		{
			camera->Translate(direction * cameraMoveSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->Keys['A'] == GLUT_DOWN || inputManager->Keys['a'] == GLUT_DOWN)
		{
			camera->Translate(-right * cameraMoveSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->Keys['S'] == GLUT_DOWN || inputManager->Keys['s'] == GLUT_DOWN)
		{
			camera->Translate(-direction * cameraMoveSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->Keys['D'] == GLUT_DOWN || inputManager->Keys['d'] == GLUT_DOWN)
		{
			camera->Translate(right * cameraMoveSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->Keys['Q'] == GLUT_DOWN || inputManager->Keys['q'] == GLUT_DOWN)
		{
			camera->Translate(up * cameraMoveSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->Keys['C'] == GLUT_DOWN || inputManager->Keys['c'] == GLUT_DOWN)
		{
			camera->Translate(-up * cameraMoveSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_UP] == GLUT_DOWN)
		{
			camera->Pitch(cameraRotateSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_LEFT] == GLUT_DOWN)
		{
			camera->Yaw(cameraRotateSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_DOWN] == GLUT_DOWN)
		{
			camera->Pitch(-cameraRotateSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->SpecialKeys[GLUT_KEY_RIGHT] == GLUT_DOWN)
		{
			camera->Yaw(-cameraRotateSpeed * deltaTime);
			cameraTransformed = true;
		}
		if (inputManager->Keys['i'] == GLUT_DOWN)
		{
			testManikin->Translate(testManikin->GetDirection() * cameraMoveSpeed * deltaTime);
		}
		if (inputManager->Keys['j'] == GLUT_DOWN)
		{
			testManikin->Yaw(cameraRotateSpeed * deltaTime);
		}
		if (inputManager->Keys['k'] == GLUT_DOWN)
		{
			testManikin->Translate(-(MyVector3D)testManikin->GetDirection() * cameraMoveSpeed * deltaTime);
		}
		if (inputManager->Keys['l'] == GLUT_DOWN)
		{
			testManikin->Yaw(-cameraRotateSpeed * deltaTime);
		}
	}
	camera->Update(deltaTime);
	if (cameraTransformed)
	{
		ShadersUpdateCameraMatrix();
	}

	testManikin->Update(deltaTime);
}

void MyApplication::Draw()
{
	MyColorRGBA c = MyColors::CornflowerBlue;
	glClearColor(c.GetRed(), c.GetGreen(), c.GetBlue(), c.GetAlpha());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (renderWireFrame)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	testManikin->Draw();

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

void MyApplication::RegisterMouseEntryFunc(void(*callback)(int state))
{
	glutEntryFunc(callback);
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
	int previousTime = totalElapsedTime;
	totalElapsedTime = glutGet(GLUT_ELAPSED_TIME);
	elapsedTime = totalElapsedTime - previousTime;
	switch (operation)
	{
	case TIMER_UPDATE_OPERATION:
		Update((float)elapsedTime / 1000.0f);
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
		if (inputManager->Keys[key] == GLUT_DOWN)
		{
			if (key == ' ')
			{
				testManikin->TogglePlay();
			}
			if (key == 'L')
			{
				testManikin->ToggleLooping();
			}
			if (key == 13)
			{
				testManikin->Stop();
			}
			if (key == '+')
			{
				testManikin->ChangeSpeed(1.0f / 0.9f);
			}
			if (key == '-')
			{
				testManikin->ChangeSpeed(0.9f);
			}
			if (key == 'f')
			{
				renderWireFrame = !renderWireFrame;
			}
		}
		else
		{

		}
		inputManager->Keys[key] = GLUT_UP;
	}
}

void MyApplication::MouseEntryFunc(int state)
{
	switch (state)
	{
	case GLUT_ENTERED:
		break;
	case GLUT_LEFT:
		break;
	default:
		break;
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

void MyApplication::ShadersUpdateLightSource()
{
	colorShader->BindUniformVector(primaryLightSource, "lightPosition");
	colorShader->BindUniformVector(MyVector4D(primaryLightSource.GetColor()), "lightColor");
	gouraudShader->BindUniformVector(primaryLightSource, "lightPosition");
	gouraudShader->BindUniformVector(MyVector4D(primaryLightSource.GetColor()), "lightColor");
	phongShader->BindUniformVector(primaryLightSource, "lightPosition");
	phongShader->BindUniformVector(MyVector4D(primaryLightSource.GetColor()), "lightColor");
}

void MyApplication::ShadersUpdateCameraMatrix()
{
	colorShader->BindUniformMatrix(camera->GetViewMatrix(), "view");
	gouraudShader->BindUniformMatrix(camera->GetViewMatrix(), "view");
	phongShader->BindUniformMatrix(camera->GetViewMatrix(), "view");
}

void MyApplication::ShadersUpdateProjectionMatrix()
{
	colorShader->BindUniformMatrix(camera->GetProjectionMatrix(), "projection");
	gouraudShader->BindUniformMatrix(camera->GetProjectionMatrix(), "projection");
	phongShader->BindUniformMatrix(camera->GetProjectionMatrix(), "projection");
}
