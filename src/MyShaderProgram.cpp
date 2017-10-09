#include "MyShaderProgram.h"

#include "MyFileIO.h"
#include "MyIncludes.h"

#include <GL/glew.h>

MyShaderProgram::MyShaderProgram(const char * vertShaderFileName, const char * fragShaderFileName)
{
	if (vertShaderFileName != 0)
	{
		int sl = strlen(vertShaderFileName);
		vertexShaderFileName = new char[sl + 1];
		strcpy(vertexShaderFileName, vertShaderFileName);
	}
	else
	{
		vertexShaderFileName = 0;
	}
	if (fragShaderFileName != 0)
	{
		int sl = strlen(fragShaderFileName);
		fragmentShaderFileName = new char[sl + 1];
		strcpy(fragmentShaderFileName, fragShaderFileName);
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

void MyShaderProgram::InitializeShaderProgram(const char * vertShaderFileName, const char * fragShaderFileName)
{
	if (vertShaderFileName != 0)
	{
		int sl = strlen(vertShaderFileName);
		MyDeleteArray(vertexShaderFileName);
		vertexShaderFileName = new char[sl + 1];
		strcpy(vertexShaderFileName, vertShaderFileName);
	}
	if (fragShaderFileName != 0)
	{
		int sl = strlen(fragShaderFileName);
		MyDeleteArray(fragmentShaderFileName);
		fragmentShaderFileName = new char[sl + 1];
		strcpy(fragmentShaderFileName, fragShaderFileName);
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
		sprintf(errLog, "Error creating vertex shader - %s\n", log);
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
		sprintf(errLog, "Error creating fragment shader - %s\n", log);
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
		sprintf(errLog, "Error linking shader program (id=%d) - %s\n", shaderProgram, log);
		throw errLog;
	}

	glDetachShader(shaderProgram, vtxShader);
	glDeleteShader(vtxShader);
	glDetachShader(shaderProgram, frgShader);
	glDeleteShader(frgShader);
}

unsigned int MyShaderProgram::GetShaderProgram()
{
	return shaderProgram;
}

int MyShaderProgram::BindUniformMatrix(MyMatrix4 const & matrix, const char * uniformName)
{
	glUseProgram(shaderProgram);
	MyMatrix4 m = matrix;
	int location = glGetUniformLocation(shaderProgram, uniformName);
	//assert(location != -1);
	if (location == -1)
		return location;
	glUniformMatrix4fv(location, 1, true, m.GetEntries());
	return 0;
}

int MyShaderProgram::BindUniformVector(MyVector2D const & vector, const char * uniformName)
{
	glUseProgram(shaderProgram);
	float v[2] = { vector.GetX(), vector.GetY() };
	int location = glGetUniformLocation(shaderProgram, uniformName);
	//assert(location != -1);
	if (location == -1)
		return location;
	glUniform2fv(location, 1, v);
	return 0;
}

int MyShaderProgram::BindUniformVector(MyVector3D const & vector, const char * uniformName)
{
	glUseProgram(shaderProgram);
	float v[3] = { vector.GetX(), vector.GetY(), vector.GetZ() };
	int location = glGetUniformLocation(shaderProgram, uniformName);
	//assert(location != -1);
	if (location == -1)
		return location;
	glUniform3fv(location, 1, v);
	return 0;
}

int MyShaderProgram::BindUniformVector(MyVector4D const & vector, const char * uniformName)
{
	glUseProgram(shaderProgram);
	float v[4] = { vector.GetX(), vector.GetY(), vector.GetZ(), vector.GetW() };
	int location = glGetUniformLocation(shaderProgram, uniformName);
	//assert(location != -1);
	if (location == -1)
		return location;
	glUniform4fv(location, 1, v);
	return 0;
}

int MyShaderProgram::BindUniformFloat(float const & f, const char * uniformName)
{
	glUseProgram(shaderProgram);
	int location = glGetUniformLocation(shaderProgram, uniformName);
	//assert(location != -1);
	if (location == -1)
		return location;
	glUniform1f(location, f);
	return 0;
}

int MyShaderProgram::BindUniformInt(int const & i, const char * uniformName)
{
	glUseProgram(shaderProgram);
	int location = glGetUniformLocation(shaderProgram, uniformName);
	//assert(location != -1);
	if (location == -1)
		return location;
	glUniform1i(location, i);
	return 0;
}
