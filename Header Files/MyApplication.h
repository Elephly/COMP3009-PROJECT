#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include "MyIncludes.h"
#include "MyInputManager.h"
#include "MyShaderProgram.h"
#include "MyMaterial.h"
#include "MyLightSource.h"
#include "MyCamera.h"
#include "MyTriangle.h"
#include "MyQuad.h"
#include "MyCube.h"
#include "MySphere.h"
#include "MyManikin.h"

class MyApplication
{
public:
	MyApplication(char *name = "My Application");
	~MyApplication();

	void Initialize(int *argc, char **argv);
	void LoadContent();
	void Update(float const & deltaTime);
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
	void RegisterMouseEntryFunc(void(*callback)(int state));
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
	void MouseEntryFunc(int state);
	void MouseFunc(int button, int state, int x, int y);
	void MouseMoveFunc(int x, int y);
	void MouseMovePassiveFunc(int x, int y);
	void SpecialFunc(int key, int x, int);
	void SpecialUpFunc(int key, int x, int);

private:
	// Application Specific Information
	char *applicationName;
	int windowWidth;
	int windowHeight;
	int windowID;
	int totalElapsedTime;
	int elapsedTime;

	// Input Manager
	MyInputManager *inputManager;

	// Shaders
	MyShaderProgram *colorShader;
	MyShaderProgram *gouraudShader;
	MyShaderProgram *phongShader;

	// Materials
	MyMaterial *shinyMaterial;

	// Lights
	MyLightSource primaryLightSource;

	// Camera
	MyCamera *camera;

	// Objects
	MySphere *testSphere;
	MyManikin *testManikin;

	// Private Functions
	void ShadersUpdateLightSource();
	void ShadersUpdateCameraMatrix();
	void ShadersUpdateProjectionMatrix();

	// Arbitrary Values
	float cameraMoveSpeed;
	float cameraRotateSpeed;
};

#endif // MYAPPLICATION_H
