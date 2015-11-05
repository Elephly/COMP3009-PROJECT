#ifndef MYMATH_H
#define MYMATH_H

#include <cmath>

class MyMath
{
public:
	static const long double MY_PI_LD;
	static const double MY_PI_D;
	static const float MY_PI_F;
};

#ifndef DegreeToRadian
#define DegreeToRadian(x) (float)(((x) * MyMath::MY_PI_F / 180.0f))
#endif // DegreeToRadian

#ifndef RadianToDegree
#define RadianToDegree(x) (float)(((x) * 180.0f / MyMath::MY_PI_F))
#endif // RadianToDegree

float LerpF(float a, float b, float t);
double LerpD(double a, double b, double t);

#endif // MYMATH_H
