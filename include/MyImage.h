#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <glew.h>
#include "SOIL.h"

class MyImage
{
public:
	MyImage();
	MyImage(GLubyte *buffer, GLint w, GLint h, GLint ch);
	MyImage(GLchar *src);
	MyImage(MyImage &other);
	~MyImage();

	GLint GetImageWidth();
	GLint GetImageHeight();
	GLint GetImageChannels();
	GLubyte *GetImageBuffer();
	GLubyte *GetPixelAt(GLint x, GLint y);

	void SetImage(GLubyte *buffer, GLint w, GLint h, GLint ch);
	void SetImage(MyImage * image);
	void SetImageFile(GLchar *src);
	void SetPixelAt(GLint x, GLint y, GLubyte *value, GLint nChannels);

	void FlipHorizontal();
	void FlipVertical();

	void Negative();

private:
	GLint width;
	GLint height;
	GLint channels;
	GLubyte *image;
};

#endif // MYIMAGE_H