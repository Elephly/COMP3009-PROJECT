#include "MyImageUtil.h"

#include <algorithm>

#include "MyIncludes.h"

void MyImageUtil::BlackHoleEffect(MyImage * src, MyCircle areaOfEffect)
{
	double x = areaOfEffect.GetCenterX();
	double y = areaOfEffect.GetCenterY();
	double r = areaOfEffect.GetRadius();
	int x1 = std::max(areaOfEffect.GetCenterX() - (int)areaOfEffect.GetRadius(), 0);
	int y1 = std::max(areaOfEffect.GetCenterY() - (int)areaOfEffect.GetRadius(), 0);
	int x2 = std::min(areaOfEffect.GetCenterX() + (int)areaOfEffect.GetRadius(), src->GetImageWidth() - 1);
	int y2 = std::min(areaOfEffect.GetCenterY() + (int)areaOfEffect.GetRadius(), src->GetImageHeight() - 1);

	MyImage *temp = new MyImage(*src);
	int channels = temp->GetImageChannels();

	GLubyte *tempPixel = 0;
	GLubyte *pixel = 0;

	bool **pixelSet = new bool*[src->GetImageHeight()]();
	for (int i = 0; i < src->GetImageHeight(); i++)
	{
		pixelSet[i] = new bool[src->GetImageWidth()]();
		for (int j = 0; j < src->GetImageWidth(); j++)
		{
			pixelSet[i][j] = false;
		}
	}

	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			double dX = j - x;
			double dY = i - y;
			double distance = sqrt((dX * dX) + (dY * dY));
			if (distance <= r)
			{
				double dXPrime = dX / (r / distance);
				double dYPrime = dY / (r / distance);
				double xPrime = x + dXPrime;
				int xPrimeFloor = (int)floor(xPrime);
				int xPrimeCeiling = (int)ceil(xPrime);
				double xPrimeRemainder = xPrime - xPrimeFloor;
				double yPrime = y + dYPrime;
				int yPrimeFloor = (int)floor(yPrime);
				int yPrimeCeiling = (int)ceil(yPrime);
				double yPrimeRemainder = yPrime - yPrimeFloor;

				pixel = temp->GetPixelAt(j, i);
				src->SetPixelAt((int)xPrime, (int)yPrime, pixel, channels);
				pixelSet[(int)yPrime][(int)xPrime] = true;

				MyDeleteArray(pixel);
			}
		}
	}

	GLubyte *colorChannels[4];
	for (int i = 0; i < 4; i++)
	{
		colorChannels[i] = new GLubyte[channels]();
	}

	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			double dX = j - x;
			double dY = i - y;
			double distance = sqrt((dX * dX) + (dY * dY));
			if (distance <= r)
			{
				int nLerps = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < channels; j++)
					{
						colorChannels[i][j] = 0;
					}
				}
				if (pixelSet[i][j] == false)
				{
					if (i < (y2 - 1) && pixelSet[i + 1][j] == true)
					{
						tempPixel = src->GetPixelAt(j, i + 1);
						for (int i = 0; i < channels; i++)
						{
							colorChannels[0][i] = tempPixel[i];
						}
						nLerps++;
						MyDeleteArray(tempPixel);
					}
					if (i > x1 && pixelSet[i - 1][j] == true)
					{
						tempPixel = src->GetPixelAt(j, i - 1);
						for (int i = 0; i < channels; i++)
						{
							colorChannels[1][i] = tempPixel[i];
						}
						nLerps++;
						MyDeleteArray(tempPixel);
					}
					if (j < (x2 - 1) && pixelSet[i][j + 1] == true)
					{
						tempPixel = src->GetPixelAt(j + 1, i);
						for (int i = 0; i < channels; i++)
						{
							colorChannels[2][i] = tempPixel[i];
						}
						nLerps++;
						MyDeleteArray(tempPixel);
					}
					if (j > x1 && pixelSet[i][j - 1] == true)
					{
						tempPixel = src->GetPixelAt(j - 1, i);
						for (int i = 0; i < channels; i++)
						{
							colorChannels[3][i] = tempPixel[i];
						}
						nLerps++;
						MyDeleteArray(tempPixel);
					}

					pixel = new GLubyte[channels];
					for (int i = 0; i < channels; i++)
					{
						GLubyte avg = (GLubyte)(((float)colorChannels[0][i] + (float)colorChannels[1][i] +
							(float)colorChannels[2][i] + (float)colorChannels[3][i]) / (float)nLerps);
						pixel[i] = avg;
					}
					src->SetPixelAt(j, i, pixel, channels);
					MyDeleteArray(pixel);
					pixelSet[i][j] = true;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		MyDeleteArray(colorChannels[i]);
	}
	for (int i = 0; i < src->GetImageHeight(); i++)
	{
		MyDeleteArray(pixelSet[i]);
	}
	MyDeleteArray(pixelSet);

	MyDelete(temp);
}

void MyImageUtil::ExpandEffect(MyImage * src, MyCircle areaOfEffect)
{
	double x = areaOfEffect.GetCenterX();
	double y = areaOfEffect.GetCenterY();
	double r = areaOfEffect.GetRadius();
	int x1 = std::max(areaOfEffect.GetCenterX() - (int)areaOfEffect.GetRadius(), 0);
	int y1 = std::max(areaOfEffect.GetCenterY() - (int)areaOfEffect.GetRadius(), 0);
	int x2 = std::min(areaOfEffect.GetCenterX() + (int)areaOfEffect.GetRadius(), src->GetImageWidth() - 1);
	int y2 = std::min(areaOfEffect.GetCenterY() + (int)areaOfEffect.GetRadius(), src->GetImageHeight() - 1);

	MyImage *temp = new MyImage(*src);
	int channels = temp->GetImageChannels();

	GLubyte *pixel = 0;

	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			double dX = j - x;
			double dY = i - y;
			double distance = sqrt((dX * dX) + (dY * dY));
			if (distance <= r)
			{
				double dXPrime = dX / (r / distance);
				double dYPrime = dY / (r / distance);
				double xPrime = x + dXPrime;
				double yPrime = y + dYPrime;

				pixel = BilerpPixels(temp, xPrime, yPrime);
				src->SetPixelAt(j, i, pixel, channels);
				MyDeleteArray(pixel);
			}
		}
	}

	MyDelete(temp);
}

void MyImageUtil::SwirlEffect(MyImage * src, MyCircle areaOfEffect, int nTwists)
{
	double x = areaOfEffect.GetCenterX();
	double y = areaOfEffect.GetCenterY();
	double r = areaOfEffect.GetRadius();
	int x1 = std::max(areaOfEffect.GetCenterX() - (int)areaOfEffect.GetRadius(), 0);
	int y1 = std::max(areaOfEffect.GetCenterY() - (int)areaOfEffect.GetRadius(), 0);
	int x2 = std::min(areaOfEffect.GetCenterX() + (int)areaOfEffect.GetRadius(), src->GetImageWidth() - 1);
	int y2 = std::min(areaOfEffect.GetCenterY() + (int)areaOfEffect.GetRadius(), src->GetImageHeight() - 1);
	double angle = (nTwists * (2 * MyMath::MY_PI_D)) / r;

	MyImage *temp = new MyImage(*src);
	int channels = temp->GetImageChannels();

	GLubyte *pixel = 0;

	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			double dX = j - x;
			double dY = i - y;
			double distance = sqrt((dX * dX) + (dY * dY));
			if (distance <= r)
			{
				double a = angle * distance;
				double theta = atan2(dY, dX);;
				theta += a;

				int dXPrime = (int)(cos(theta) * distance);
				int dYPrime = (int)(sin(theta) * distance);

				int xPrime = (int)x + dXPrime;
				int yPrime = (int)y + dYPrime;

				if (xPrime >= x2 || xPrime < x1 || yPrime >= y2 || yPrime < y1)
				{
					pixel = new GLubyte[channels]();
					for (int k = 0; k < channels; k++)
					{
						pixel[k] = 0;
					}
				}
				else
				{
					// Bilinear interpolation doesn't really seem to help smooth out this effect
					// pixel = BilerpPixels(temp, xPrime, yPrime);
					pixel = temp->GetPixelAt(xPrime, yPrime);
				}
				src->SetPixelAt(j, i, pixel, channels);
				MyDeleteArray(pixel);
			}
		}
	}

	MyDelete(temp);
}

void MyImageUtil::CopyFromImage(MyImage * src, MyImage ** dest, MyRectangle selection)
{
	MyDelete(*dest);
	int x = std::min(selection.GetX1(), selection.GetX2());
	int y = std::min(selection.GetY1(), selection.GetY2());
	int width = abs(selection.GetWidth());
	int height = abs(selection.GetHeight());
	int channels = src->GetImageChannels();
	GLubyte *buffer = new GLubyte[width * height * channels]();

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			GLubyte *pixel = src->GetPixelAt(x + j, y + i);
			for (int k = 0; k < channels; k++)
			{
				buffer[(i * width * channels) + (j * channels) + k] = pixel[k];
			}
			MyDeleteArray(pixel);
		}
	}

	*dest = new MyImage(buffer, width, height, channels);

	MyDeleteArray(buffer);
}

void MyImageUtil::PasteToImage(MyImage * src, MyImage * dest, int x, int y)
{
	int x2 = x + src->GetImageWidth();
	int y2 = y + src->GetImageHeight();
	int width = std::min(src->GetImageWidth() - (x2 - dest->GetImageWidth()), src->GetImageWidth());
	int height = std::min(src->GetImageHeight() - (y2 - dest->GetImageHeight()), src->GetImageHeight());
	int channels = src->GetImageChannels();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			GLubyte *pixel = src->GetPixelAt(j, i);
			dest->SetPixelAt(x + j, i + y, pixel, channels);
			MyDeleteArray(pixel);
		}
	}
}

void MyImageUtil::GrayscaleImage(MyImage *src, MyImage *dest, GRAYSCALE_TYPE type)
{
	GLint width = src->GetImageWidth();
	GLint height = src->GetImageHeight();
	GLint channels = src->GetImageChannels();
	GLubyte *buffer = src->GetImageBuffer();

	GLubyte grayVal;

	for (int i = 0; i < width * height * channels; i += channels)
	{
		GLubyte maxVal = std::max(buffer[i], std::max(buffer[i + 1], buffer[i + 2]));
		GLubyte minVal = std::min(buffer[i], std::min(buffer[i + 1], buffer[i + 2]));

		switch (type)
		{
		case GRAYSCALE_MIN:
			grayVal = minVal;
			break;
		case GRAYSCALE_MED:
			grayVal = ((buffer[i] != maxVal && buffer[i] != minVal) ? buffer[i] :
				((buffer[i + 1] != maxVal && buffer[i + 1] != minVal) ? buffer[i + 1] :
					((buffer[i + 2] != maxVal && buffer[i + 2] != minVal) ? buffer[i + 2] : buffer[i])));
			break;
		case GRAYSCALE_MAX:
			grayVal = maxVal;
			break;
		case GRAYSCALE_LIGHTNESS:
			grayVal = (maxVal + minVal) / 2;
			break;
		case GRAYSCALE_AVG:
			grayVal = (buffer[i] + buffer[i + 1] + buffer[i + 2]) / 3;
			break;
		case GRAYSCALE_LUMINOSITY:
			grayVal = (GLubyte)(0.21 * buffer[i]) + (GLubyte)(0.72 * buffer[i + 1]) + (GLubyte)(0.07 * buffer[i + 2]);
			break;
		default:
			grayVal = 255 / 2;
			break;
		}

		buffer[i] = grayVal;
		buffer[i + 1] = grayVal;
		buffer[i + 2] = grayVal;
	}

	dest->SetImage(buffer, width, height, channels);
	MyDeleteArray(buffer);
}

void MyImageUtil::SeparateChannel(MyImage *src, MyImage *dest, RBGA_CHANNEL channel, SEPARATION_TYPE type)
{
	GLint width = src->GetImageWidth();
	GLint height = src->GetImageHeight();
	GLint channels = src->GetImageChannels();
	GLubyte *buffer = src->GetImageBuffer();

	unsigned char emptyVal = (type == SEPARATION_LIGHT ? 255 : 0);

	for (int i = 0; i < width * height * channels; i += channels)
	{
		if (channel != RBGA_CHANNEL_RED && channels > 0)
			buffer[i] = emptyVal;
		if (channel != RBGA_CHANNEL_GREEN && channels > 1)
			buffer[i + 1] = emptyVal;
		if (channel != RBGA_CHANNEL_BLUE && channels > 2)
			buffer[i + 2] = emptyVal;
		if (channel != RBGA_CHANNEL_ALPHA && channels > 3)
			buffer[i + 3] = emptyVal;
	}

	dest->SetImage(buffer, width, height, channels);
	MyDeleteArray(buffer);
}

void MyImageUtil::SubtractChannel(MyImage *src, MyImage *dest, RBGA_CHANNEL channel, SEPARATION_TYPE type)
{
	GLint width = src->GetImageWidth();
	GLint height = src->GetImageHeight();
	GLint channels = src->GetImageChannels();
	GLubyte *buffer = src->GetImageBuffer();

	unsigned char emptyVal = (type == SEPARATION_LIGHT ? 255 : 0);

	for (int i = 0; i < width * height * channels; i += channels)
	{
		if (channel == RBGA_CHANNEL_RED && channels > 0)
			buffer[i] = emptyVal;
		if (channel == RBGA_CHANNEL_GREEN && channels > 1)
			buffer[i + 1] = emptyVal;
		if (channel == RBGA_CHANNEL_BLUE && channels > 2)
			buffer[i + 2] = emptyVal;
		if (channel == RBGA_CHANNEL_ALPHA && channels > 3)
			buffer[i + 3] = emptyVal;
	}

	dest->SetImage(buffer, width, height, channels);
	MyDeleteArray(buffer);
}

GLubyte * MyImageUtil::LerpPixels(GLubyte * a, GLubyte * b, double t, int channels)
{
	GLubyte *lerp = new GLubyte[channels]();
	for (int i = 0; i < channels; i++)
	{
		lerp[i] = (int)LerpD((double)a[i], (double)b[i], t);
	}
	return lerp;
}

GLubyte * MyImageUtil::BilerpPixels(MyImage * image, double x, double y)
{
	GLubyte *bottomLeft = 0;
	GLubyte *bottomRight = 0;
	GLubyte *topLeft = 0;
	GLubyte *topRight = 0;
	GLubyte *lerpBottom = 0;
	GLubyte *lerpTop = 0;
	GLubyte *pixel = 0;

	int xFloor = (int)floor(x);
	int xCeiling = (int)ceil(x);
	double xRemainder = x - xFloor;
	int yFloor = (int)floor(y);
	int yCeiling = (int)ceil(y);
	double yRemainder = y - yFloor;
	int channels = image->GetImageChannels();

	if (x != xFloor)
	{
		bottomLeft = image->GetPixelAt(xFloor, yFloor);
		bottomRight = image->GetPixelAt(xCeiling, yFloor);
		lerpBottom = LerpPixels(bottomLeft, bottomRight, xRemainder, channels);
		if (y != yFloor)
		{
			topLeft = image->GetPixelAt(xFloor, yCeiling);
			topRight = image->GetPixelAt(xCeiling, yCeiling);
			lerpTop = LerpPixels(topLeft, topRight, xRemainder, channels);
		}
	}
	else
	{
		lerpBottom = image->GetPixelAt(xFloor, yFloor);
		if (y != yFloor)
		{
			lerpTop = image->GetPixelAt(xFloor, yCeiling);
		}
	}
	if (y != yFloor)
	{
		pixel = LerpPixels(lerpBottom, lerpTop, yRemainder, channels);
	}
	else
	{
		pixel = lerpBottom;
		lerpBottom = 0;
	}

	MyDeleteArray(lerpBottom);
	if (x != xFloor)
	{
		MyDeleteArray(bottomLeft);
		MyDeleteArray(bottomRight);
		if (y != yFloor)
		{
			MyDeleteArray(topLeft);
			MyDeleteArray(topRight);
		}
	}
	if (y != yFloor)
	{
		MyDeleteArray(lerpTop);
	}
	return pixel;
}
