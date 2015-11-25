#ifndef MYSHADERMANAGER_H
#define MYSHADERMANAGER_H

#include <map>
#include <vector>
#include "MyShaderProgram.h"

class MyShaderManager
{
public:
	static MyShaderProgram *CreateShader(char *shaderName, char *vertShaderFileName, char *fragShaderFileName);

	static MyShaderProgram *GetShader(char *shaderName);
	static std::vector<MyShaderProgram *> *GetShaderList();

	static void Cleanup();

private:
	static std::map<char *, MyShaderProgram *> *shaders;

};

#endif // MYSHADERMANAGER_H
