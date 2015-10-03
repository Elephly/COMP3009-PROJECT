#ifndef MYDEFINES_H
#define MYDEFINES_H

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

#endif // MYDEFINES_H