#include "MyStringUtil.h"

#include <cstring>

char * MyStringUtil::CopyString(const char * string)
{
	char *out = new char[strlen(string) + 1]();
	strcpy_s(out, strlen(string) + 1, string);
	return out;
}
