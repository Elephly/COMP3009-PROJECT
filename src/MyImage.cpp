#include "MyImage.h"

#include <algorithm>

#include "MyIncludes.h"

MyImage::MyImage() : width(0), height(0), channels(0), image(nullptr) { }

MyImage::MyImage(GLubyte * buffer, GLint w, GLint h, GLint ch) : width(w), height(h), channels(ch)
{
	image = new GLubyte[width * height * channels];
	for (int i = 0; i < width * height * channels; i++)
	{
		image[i] = buffer[i];
	}
}

MyImage::MyImage(GLchar * src) : width(0), height(0), channels(0), image(nullptr)
{
	SetImageFile(src);
}

MyImage::MyImage(MyImage & other)
{
	width = other.width;
	height = other.height;
	channels = other.channels;
	image = new GLubyte[width * height * channels];
	for (int i = 0; i < width * height * channels; i++)
	{
		image[i] = other.image[i];
	}
}

MyImage::~MyImage()
{
	MyDeleteArray(image);
}

GLint MyImage::GetImageWidth()
{
	return width;
}

GLint MyImage::GetImageHeight()
{
	return height;
}

GLint MyImage::GetImageChannels()
{
	return channels;
}

GLubyte * MyImage::GetImageBuffer()
{
	GLubyte *buffer = new GLubyte[width * height * channels]();

	for (int i = 0; i < width * height * channels; i++)
	{
		buffer[i] = image[i];
	}

	return buffer;
}

GLubyte * MyImage::GetPixelAt(GLint x, GLint y)
{
	GLubyte *pixel = new GLubyte[channels];
	GLint pixelOffset = (y * width * channels) + (x * channels);

	for (int i = 0; i < channels; i++)
	{
		pixel[i] = image[pixelOffset + i];
	}

	return pixel;
}

void MyImage::SetImage(GLubyte * buffer, GLint w, GLint h, GLint ch)
{
	width = w;
	height = h;
	channels = ch;
	MyDeleteArray(image);

	image = new GLubyte[w * h * ch]();
	for (int i = 0; i < w * h * ch; i++)
	{
		image[i] = buffer[i];
	}
}

void MyImage::SetImage(MyImage *image)
{
	GLint width = image->GetImageWidth();
	GLint height = image->GetImageHeight();
	GLint channels = image->GetImageChannels();
	GLubyte *buffer = image->GetImageBuffer();

	SetImage(buffer, width, height, channels);

	MyDeleteArray(buffer);
}

void MyImage::SetImageFile(GLchar * src)
{
	MyDeleteArray(image);
	image = SOIL_load_image(src, &width, &height, &channels, SOIL_LOAD_RGBA);
}

void MyImage::SetPixelAt(GLint x, GLint y, GLubyte * value, GLint nChannels)
{
	GLint pixelOffset = (y * width * channels) + (x * channels);

	for (int i = 0; i < std::min(channels, nChannels); i++)
	{
		image[pixelOffset + i] = value[i];
	}
}

void MyImage::FlipHorizontal()
{
	GLubyte byteBuffer;

	int c = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width / 2; j++)
		{
			for (int k = 0; k < channels; k++)
			{
				byteBuffer = image[(i * width * channels) + (j * channels) + k];
				image[(i * width * channels) + (j * channels) + k] = image[(i * width * channels) + (((width - 1) - j) * channels) + k];
				image[(i * width * channels) + (((width - 1) - j) * channels) + k] = byteBuffer;
			}
		}
	}
}

void MyImage::FlipVertical()
{
	GLubyte byteBuffer;

	int c = 0;
	for (int i = 0; i < height / 2; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < channels; k++)
			{
				byteBuffer = image[(i * width * channels) + (j * channels) + k];
				image[(i * width * channels) + (j * channels) + k] = image[(((height - 1) - i) * width * channels) + (j * channels) + k];
				image[(((height - 1) - i) * width * channels) + (j * channels) + k] = byteBuffer;
			}
		}
	}
}

void MyImage::Negative()
{
	for (int i = 0; i < width * height * channels; i++)
	{
		image[i] = 255 - image[i];
	}
}
