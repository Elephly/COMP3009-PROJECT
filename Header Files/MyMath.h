#ifndef MYMATH_H
#define MYMATH_H

#include <cmath>

#ifndef DegreeToRadian
#define DegreeToRadian(x) (float)(((x) * M_PI / 180.0f))
#endif // DegreeToRadian

#ifndef RadianToDegree
#define RadianToDegree(x) (float)(((x) * 180.0f / M_PI))
#endif // RadianToDegree

double Lerp(double a, double b, double t);

#endif // MYMATH_H
