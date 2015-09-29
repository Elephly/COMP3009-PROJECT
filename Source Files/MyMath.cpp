#include "MyMath.h"

double Lerp(double a, double b, double t)
{
	if (t > 1 || t < 0)
	{
		t -= floor(t);
	}

	return ((1 - t) * a) + (t * b);
}