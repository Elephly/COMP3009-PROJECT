#include "MyStringUtil.h"

#include "MyDefines.h"

#include <cstdarg>
#include <cstring>

char * MyStringUtil::CopyString(const char * string)
{
	char *out = new char[strlen(string) + 1]();
	strcpy(out, string);
	return out;
}

char * MyStringUtil::SystemPath(int length, ...)
{
	char *path = new char[1]();

	va_list args;
	va_start(args, length);

	for (int i = 0; i < length; ++i)
	{
		const char *p = va_arg(args, const char *);

		char *tmp_path = path;
		path = new char[strlen(tmp_path) + strlen(p) + 1](); // Plus 2 for the delimiter and the string terminator
		strcpy(path, tmp_path);
		MyDeleteArray(tmp_path);

		if (i > 0)
		{
			strcat(path, SYSTEM_DELIM);
		}

		strcat(path, p);
	}

	va_end(args);

	return path;
}
