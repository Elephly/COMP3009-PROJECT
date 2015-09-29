#ifndef MYDEFINE_H
#define MYDEFINE_H


#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>

#include "MyMath.h"

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#endif // MYDEFINE_H