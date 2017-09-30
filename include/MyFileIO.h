#ifndef MYFILEIO_H
#define MYFILEIO_H

class MyFileIO
{
public:
	static int ReadFile(char *fileName, char **buffer, int *bufferSize);
};

#endif // MYFILEIO_H