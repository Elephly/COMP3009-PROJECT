#ifndef MYDEFINES_H
#define MYDEFINES_H

#ifndef MY_DEBUG
#define MY_DEBUG 1
#endif // MY_DEBUG

#ifndef PROJECT_NAME
#define PROJECT_NAME "COMP3009-PROJECT"
#endif

#ifndef TIMER_UPDATE_OPERATION
#define TIMER_UPDATE_OPERATION 0
#endif // TIMER_UPDATE_OPERATION

#ifndef FRAME_TIME
#define FRAME_TIME 30
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

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef ASPECT_RATIO_X
#define ASPECT_RATIO_X 16
#endif

#ifndef ASPECT_RATIO_Y
#define ASPECT_RATIO_Y 9
#endif

#endif // MYDEFINES_H