#ifndef MYDEFINES_H
#define MYDEFINES_H

#ifndef MY_DEBUG
#define MY_DEBUG 1
#endif // MY_DEBUG

#ifndef PROJECT_NAME
#define PROJECT_NAME "N3DIL"
#endif

#ifndef TIMER_UPDATE_OPERATION
#define TIMER_UPDATE_OPERATION 0
#endif // TIMER_UPDATE_OPERATION

#ifndef MAXIMUM_FRAME_RATE // frames per second (value as double)
#define MAXIMUM_FRAME_RATE 256.0
#endif // FRAME_RATE

#ifndef FRAME_TIME
#define FRAME_TIME (unsigned int)(1000.0 * (1.0 / MAXIMUM_FRAME_RATE))
#endif // FRAME_TIME

#ifndef _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC
#endif // _CRTDBG_MAP_ALLOC

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // _USE_MATH_DEFINES

#ifndef MyDelete
#define MyDelete(x) if(x!=0){delete x;x=0;}
#endif

#ifndef MyDeleteArray
#define MyDeleteArray(x) if(x!=0){delete[] x;x=0;}
#endif

#ifndef MAX
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#endif // MAX

#ifndef MIN
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#endif // MIN

#ifndef ASPECT_RATIO_X
#define ASPECT_RATIO_X 16
#endif

#ifndef ASPECT_RATIO_Y
#define ASPECT_RATIO_Y 9
#endif

#endif // MYDEFINES_H
