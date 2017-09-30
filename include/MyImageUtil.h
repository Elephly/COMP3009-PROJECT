#ifndef MYIMAGEUTIL_H
#define MYIMAGEUTIL_H

#include "MyImage.h"
#include "MyGeometry.h"

enum RBGA_CHANNEL { RBGA_CHANNEL_RED, RBGA_CHANNEL_GREEN, RBGA_CHANNEL_BLUE, RBGA_CHANNEL_ALPHA};
enum SEPARATION_TYPE { SEPARATION_LIGHT, SEPARATION_DARK };
enum GRAYSCALE_TYPE { GRAYSCALE_MIN, GRAYSCALE_MED, GRAYSCALE_MAX, GRAYSCALE_LIGHTNESS, GRAYSCALE_AVG, GRAYSCALE_LUMINOSITY };
enum CHANNEL_COMPLEMENT { COMPLEMENT_OFF, COMPLEMENT_ON };
enum GAMMA_FUNCTION { GAMMA_FUNCTION_BLACKHOLE, GAMMA_FUNCTION_EXPAND };

class MyImageUtil
{
public:
	/* Image distortion effects */
	static void BlackHoleEffect(MyImage *src, MyCircle areaOfEffect);
	static void ExpandEffect(MyImage *src, MyCircle areaOfEffect);
	static void SwirlEffect(MyImage *src, MyCircle areaOfEffect, int nTwists);

	/* Copy and paste */
	static void CopyFromImage(MyImage *src, MyImage **dest, MyRectangle selection);
	static void PasteToImage(MyImage *src, MyImage *dest, int x, int y);

	/* Image filters */
	static void GrayscaleImage(MyImage *src, MyImage *dest, GRAYSCALE_TYPE type);
	static void SeparateChannel(MyImage *src, MyImage *dest, RBGA_CHANNEL channel, SEPARATION_TYPE type);
	static void SubtractChannel(MyImage *src, MyImage *dest, RBGA_CHANNEL channel, SEPARATION_TYPE type);

	/* Pixel functions */
	static GLubyte *LerpPixels(GLubyte *a, GLubyte *b, double t, int channels);
	static GLubyte *BilerpPixels(MyImage *image, double x, double y);
};

#endif // MYIMAGEUTIL_H