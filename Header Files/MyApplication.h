#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include "MyIncludes.h"
#include "MyInputManager.h"
#include "MyShaderProgram.h"
#include "MyCamera.h"
#include "MyTriangle.h"
#include "MyQuad.h"
#include "MyCube.h"

class MyApplication
{
public:
	MyApplication(char *name = "My Application");
	~MyApplication();

	void Initialize(int *argc, char **argv);
	void LoadContent();
	void Update();
	void Draw();

	void Run();

	// Getters
	char *GetName();
	int GetWindowWidth();
	int GetWindowHeight();

	// Callback Function Registers
	void RegisterReshapeFunc(void(*callback)(int width, int height));
	void RegisterTimerFunc(void(*callback)(int operation));
	void RegisterDisplayFunc(void(*callback)());
	void RegisterKeyboardFunc(void(*callback)(unsigned char key, int x, int y));
	void RegisterKeyboardUpFunc(void(*callback)(unsigned char key, int x, int y));
	void RegisterMouseFunc(void(*callback)(int button, int state, int x, int y));
	void RegisterMouseMoveFunc(void(*callback)(int x, int y));
	void RegisterMouseMovePassiveFunc(void(*callback)(int x, int y));
	void RegisterSpecialFunc(void(*callback)(int key, int x, int y));
	void RegisterSpecialUpFunc(void(*callback)(int key, int x, int y));

	// Callback Functions
	void ReshapeFunc(int width, int height);
	void TimerFunc(int operation);
	void DisplayFunc();
	void KeyboardFunc(unsigned char key, int x, int y);
	void KeyboardUpFunc(unsigned char key, int x, int y);
	void MouseFunc(int button, int state, int x, int y);
	void MouseMoveFunc(int x, int y);
	void MouseMovePassiveFunc(int x, int y);
	void SpecialFunc(int key, int x, int);
	void SpecialUpFunc(int key, int x, int);

private:
	char *applicationName;
	int windowWidth;
	int windowHeight;
	int windowID;
	MyInputManager *inputManager;

	// Shaders
	MyShaderProgram *colorShader;

	// Camera
	MyCamera *camera;

	// Objects
	MyTriangle *testTriangleFront;
	MyTriangle *testTriangleBack;
	MyQuad *testQuadFront;
	MyQuad *testQuadBack;
	MyCube *testCube;

	// Private Functions
	void ShadersUpdateCameraMatrix();
	void ShadersUpdateProjectionMatrix();
};

#endif // MYAPPLICATION_H
