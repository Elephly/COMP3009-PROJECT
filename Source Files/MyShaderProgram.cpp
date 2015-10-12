#include "MyShaderProgram.h"

#include "MyDefines.h"
#include <cstdio>
#include <cstring>
#include "glew.h"
#include "MyFileIO.h"

MyShaderProgram::MyShaderProgram(char * vertShaderFileName, char * fragShaderFileName)
{
	if (vertShaderFileName != 0)
	{
		int sl = strlen(vertShaderFileName);
		vertexShaderFileName = new char[sl + 1];
		strcpy_s(vertexShaderFileName, sl + 1, vertShaderFileName);
	}
	else
	{
		vertexShaderFileName = 0;
	}
	if (fragShaderFileName != 0)
	{
		int sl = strlen(fragShaderFileName);
		fragmentShaderFileName = new char[sl + 1];
		strcpy_s(fragmentShaderFileName, sl + 1, fragShaderFileName);
	}
	else
	{
		fragmentShaderFileName = 0;
	}
	shaderProgram = 0;
}

MyShaderProgram::~MyShaderProgram()
{
	glDeleteProgram(shaderProgram);
	MyDeleteArray(vertexShaderFileName);
	MyDeleteArray(fragmentShaderFileName);
}

void MyShaderProgram::InitializeShaderProgram(char * vertShaderFileName, char * fragShaderFileName)
{
	if (vertShaderFileName != 0)
	{
		int sl = strlen(vertShaderFileName);
		MyDeleteArray(vertexShaderFileName);
		vertexShaderFileName = new char[sl + 1];
		strcpy_s(vertexShaderFileName, sl + 1, vertShaderFileName);
	}
	if (fragShaderFileName != 0)
	{
		int sl = strlen(fragShaderFileName);
		MyDeleteArray(fragmentShaderFileName);
		fragmentShaderFileName = new char[sl + 1];
		strcpy_s(fragmentShaderFileName, sl + 1, fragShaderFileName);
	}
	int rc;
	int srcLength;
	char *shaderSrc[1];

	rc = MyFileIO::ReadFile(vertexShaderFileName, shaderSrc, &srcLength);
	GLuint vtxShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vtxShader, 1, shaderSrc, 0);
	glCompileShader(vtxShader);
	glGetShaderiv(vtxShader, GL_COMPILE_STATUS, &rc);
	if (rc != GL_TRUE)
	{
		char log[2048];
		glGetShaderInfoLog(vtxShader, sizeof(log), NULL, log);
		char errLog[2048];
		sprintf_s(errLog, "Error creating vertex shader - %s\n", log);
		throw errLog;
	}
	MyDeleteArray(shaderSrc[0]);

	rc = MyFileIO::ReadFile(fragmentShaderFileName, shaderSrc, &srcLength);
	GLuint frgShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frgShader, 1, shaderSrc, 0);
	glCompileShader(frgShader);
	glGetShaderiv(frgShader, GL_COMPILE_STATUS, &rc);
	if (rc != GL_TRUE)
	{
		char log[2048];
		glGetShaderInfoLog(frgShader, sizeof(log), NULL, log);
		char errLog[2048];
		sprintf_s(errLog, "Error creating fragment shader - %s\n", log);
		throw errLog;
	}
	MyDeleteArray(shaderSrc[0]);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vtxShader);
	glAttachShader(shaderProgram, frgShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &rc);
	if (rc != GL_TRUE)
	{
		char log[2048];
		glGetProgramInfoLog(shaderProgram, sizeof(log), NULL, log);
		char errLog[2048];
		sprintf_s(errLog, "Error linking shader program (id=%d) - %s\n", shaderProgram, log);
		throw errLog;
	}

	glDetachShader(shaderProgram, vtxShader);
	glDeleteShader(vtxShader);
	glDetachShader(shaderProgram, frgShader);
	glDeleteShader(frgShader);
}

int MyShaderProgram::GetShaderProgram()
{
	return shaderProgram;
}
