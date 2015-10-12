#ifndef MYSHADERPROGRAM_H
#define MYSHADERPROGRAM_H

class MyShaderProgram
{
public:
	MyShaderProgram(char *vertShaderFileName = 0, char *fragShaderFileName = 0);
	~MyShaderProgram();

	void InitializeShaderProgram(char *vertShaderFileName = 0, char *fragShaderFileName = 0);

	// Getters
	int GetShaderProgram();

private:
	char *vertexShaderFileName;
	char *fragmentShaderFileName;
	int shaderProgram;
};

#endif // MYSHADERPROGRAM_H
