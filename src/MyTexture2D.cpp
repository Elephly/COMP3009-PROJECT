#include "MyTexture2D.h"

#include <GL/glew.h>

#include "MyIncludes.h"
#include "SOIL.h"

MyTexture2D::MyTexture2D(const char * texFileName, unsigned int texUnit) :
	textureID(0), textureUnit((texUnit < GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS) ? texUnit : 0)
{
	if (texFileName != 0)
	{
		int sl = strlen(texFileName);
		textureFileName = new char[sl + 1];
		strcpy_s(textureFileName, sl + 1, texFileName);
	}
	else
	{
		textureFileName = 0;
	}
}

MyTexture2D::~MyTexture2D()
{
	MyDeleteArray(textureFileName);
	glDeleteTextures(1, &textureID);
}

void MyTexture2D::InitializeTexture(const char * texFileName, unsigned int texUnit)
{
	if (texFileName != 0)
	{
		int sl = strlen(texFileName);
		MyDeleteArray(textureFileName);
		textureFileName = new char[sl + 1];
		strcpy_s(textureFileName, sl + 1, texFileName);
	}
	if (texUnit != 0)
	{
		textureUnit = (texUnit < GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS) ? texUnit : textureUnit;
	}

	int width, height;
	unsigned char* image = NULL;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	image = SOIL_load_image(textureFileName, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	image = NULL;
	// set the repeat behaviour
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	// set the sampling behaviour
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

unsigned int MyTexture2D::GetTextureID()
{
	return textureID;
}

unsigned int MyTexture2D::GetTextureUnit()
{
	return textureUnit;
}
