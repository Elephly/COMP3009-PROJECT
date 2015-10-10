#include "MyApplication.h"

void MainReshapeFunc(int width, int height);
void MainDisplayFunc();
void MainKeyboardFunc(unsigned char key, int x, int y);
void MainKeyboardUpFunc(unsigned char key, int x, int y);
void MainMouseFunc(int button, int state, int x, int y);
void MainMouseMoveFunc(int x, int y);
void MainMouseMovePassiveFunc(int x, int y);

MyApplication *myApplication;

int main(int argc, char *argv[])
{
	try
	{
		myApplication = new MyApplication("COMP3009-PROJECT");
		myApplication->Initialize(&argc, argv);
		myApplication->RegisterReshapeFunc(MainReshapeFunc);
		myApplication->RegisterDisplayFunc(MainDisplayFunc);
		myApplication->RegisterKeyboardFunc(MainKeyboardFunc);
		myApplication->RegisterKeyboardUpFunc(MainKeyboardUpFunc);
		myApplication->RegisterMouseFunc(MainMouseFunc);
		myApplication->RegisterMouseMoveFunc(MainMouseMoveFunc);
		myApplication->RegisterMouseMovePassiveFunc(MainMouseMovePassiveFunc);
		myApplication->LoadContent();
		myApplication->Run();
	}
	catch (char *err)
	{
		printf("%s\n\nPress enter to exit.", err);
		getchar();
	}

	MyDelete(myApplication);

	//initMaterials();

	//initGeom();

	return 0;
}

void MainReshapeFunc(int width, int height)
{
	myApplication->ReshapeFunc(width, height);
}

void MainDisplayFunc()
{
	myApplication->DisplayFunc();
}

void MainKeyboardFunc(unsigned char key, int x, int y)
{
	myApplication->KeyboardFunc(key, x, y);
}

void MainKeyboardUpFunc(unsigned char key, int x, int y)
{
	myApplication->KeyboardUpFunc(key, x, y);
}

void MainMouseFunc(int button, int state, int x, int y)
{
	myApplication->MouseFunc(button, state, x, y);
}
void MainMouseMoveFunc(int x, int y)
{
	myApplication->MouseMoveFunc(x, y);
}
void MainMouseMovePassiveFunc(int x, int y)
{
	myApplication->MouseMovePassiveFunc(x, y);
}

//GLuint vbo; // vertex buffer object
//GLuint shaderProgram;

/*
void initGeom()
{
	MyVertex3D tri[3];
	tri[0].v.x = -1.0; tri[0].v.y = -1.0; tri[0].v.z = 0.0;
	tri[1].v.x = 0.0; tri[1].v.y = 1.0; tri[1].v.z = 0.0;
	tri[2].v.x = 1.0; tri[2].v.y = -1.0; tri[2].v.z = 0.0;

	tri[0].c.r = 1.0; tri[0].c.g = 0.0; tri[0].c.b = 0.0; tri[0].c.a = 1.0;
	tri[1].c.r = 0.0; tri[1].c.g = 1.0; tri[1].c.b = 0.0; tri[1].c.a = 1.0;
	tri[2].c.r = 0.0; tri[2].c.g = 0.0; tri[2].c.b = 1.0; tri[2].c.a = 1.0;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri), tri, GL_STATIC_DRAW);
}

int readCode(char * fileName, char **shaderCode, int *codeLength)
{
	int length = 0;
	FILE *fp = NULL;
	// check for error in file name
	fopen_s(&fp, fileName, "r"); // open file and check for errors
	if (fp == NULL) { return -1; }
	// find the length of code
	fseek(fp, 0L, SEEK_END);
	length = ftell(fp);
	rewind(fp); // could use fseek(fp, 0L, SEEK_SET)
	if (length > 0) {
		// allocated space for code and check for errors
		*shaderCode = (char *)malloc(length + 1); // add a space for the '\0'
		if (*shaderCode == NULL) return(-2);
		memset((void *)*shaderCode, 0, length + 1);
		fread((void *)*shaderCode, sizeof(char), length, fp);
		(*shaderCode)[length] = 0;
	}
	if (fp != NULL) fclose(fp);
	if (codeLength != NULL) *codeLength = length;

	return 0;
}

void initMaterials()
{
	int rc;
	int codeLength;
	char *shaderSrc[1];
	
	rc = readCode("Material Files\\tri.vert", shaderSrc, &codeLength);
	GLuint vtxShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vtxShader, 1, shaderSrc, 0);
	glCompileShader(vtxShader);
	glGetShaderiv(vtxShader, GL_COMPILE_STATUS, &rc);
	if (rc != GL_TRUE)
	{
		char log[2048];
		glGetShaderInfoLog(vtxShader, sizeof(log), NULL, log);
		fprintf(stderr, "Error creating vertex shader - %s\n", log);
	}
	MyDeleteArray(shaderSrc[0]);

	rc = readCode("Material Files\\tri.frag", shaderSrc, &codeLength);
	GLuint frgShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frgShader, 1, shaderSrc, 0);
	glCompileShader(frgShader);
	glGetShaderiv(frgShader, GL_COMPILE_STATUS, &rc);
	if (rc != GL_TRUE)
	{
		char log[2048];
		glGetShaderInfoLog(frgShader, sizeof(log), NULL, log);
		fprintf(stderr, "Error creating fragment shader - %s\n", log);
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
		fprintf(stderr, "Error linking shader program (id=%d) - %s\n", shaderProgram, log);
	}

	glDetachShader(shaderProgram, vtxShader);
	glDeleteShader(vtxShader);
	glDetachShader(shaderProgram, frgShader);
	glDeleteShader(frgShader);

	glUseProgram(shaderProgram);
}
*/