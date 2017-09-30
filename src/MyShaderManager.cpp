#include "MyShaderManager.h"

#include "MyDefines.h"

std::map<char *, MyShaderProgram *> *MyShaderManager::shaders = new std::map<char *, MyShaderProgram *>();

MyShaderProgram * MyShaderManager::CreateShader(char *shaderName, char * vertShaderFileName, char * fragShaderFileName)
{
	if (shaders->find(shaderName) != shaders->end())
	{
		return nullptr;
	}

	MyShaderProgram *shader = new MyShaderProgram();
	shader->InitializeShaderProgram(vertShaderFileName, fragShaderFileName);

	(*shaders)[shaderName] = shader;

	return shader;
}

MyShaderProgram * MyShaderManager::GetShader(char * shaderName)
{
	if (shaders->find(shaderName) != shaders->end())
	{
		return (*shaders)[shaderName];
	}
	return nullptr;
}

std::vector<MyShaderProgram*>* MyShaderManager::GetShaderList()
{
	std::vector<MyShaderProgram *> *shaderList = new std::vector<MyShaderProgram *>();

	for (std::map<char *, MyShaderProgram *>::iterator it = shaders->begin(); it != shaders->end(); ++it)
	{
		shaderList->push_back(it->second);
	}

	return shaderList;
}

void MyShaderManager::Cleanup()
{
	for (std::map<char *, MyShaderProgram *>::iterator it = shaders->begin(); it != shaders->end(); ++it)
	{
		MyDelete(it->second);
	}
	shaders->clear();
	MyDelete(shaders);
}
