#include "MyMath.h"

const long double MyMath::MY_PI_LD = 3.141592653589793238L;
const double MyMath::MY_PI_D = 3.141592653589793;
const float MyMath::MY_PI_F = 3.1415927f;

float LerpF(float a, float b, float t)
{
	if (t > 1 || t < 0)
	{
		t -= floor(t);
	}

	return ((1 - t) * a) + (t * b);
}

double LerpD(double a, double b, double t)
{
	if (t > 1 || t < 0)
	{
		t -= floor(t);
	}

	return ((1 - t) * a) + (t * b);
}