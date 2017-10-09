#include "MyFileIO.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>

int MyFileIO::ReadFile(char * fileName, char ** buffer, int * bufferSize)
{
	int length = 0;
	FILE *fp = 0;
	fp = fopen(fileName, "r");
	if (fp == 0)
	{
		return -1;
	}
	// find the length of code
	fseek(fp, 0L, SEEK_END);
	length = ftell(fp);
	rewind(fp); // could use fseek(fp, 0L, SEEK_SET)
	if (length > 0) {
		// allocate space for buffer and check for errors
		*buffer = new char[length + 1]; // add a space for the '\0'
		if (*buffer == 0)
		{
			return -2;
		}
		memset((void *)*buffer, 0, length + 1);
		fread(*buffer, sizeof(char), length, fp);
		(*buffer)[length] = 0;
	}
	if (fp != 0)
	{
		fclose(fp);
	}
	if (bufferSize != 0)
	{
		*bufferSize = length;
	}

	return 0;
}
