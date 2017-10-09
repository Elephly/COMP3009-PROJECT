#ifndef MYTEXTURE2D_H
#define MYTEXTURE2D_H

class MyTexture2D
{
public:
	MyTexture2D(const char *texFileName = 0, unsigned int texUnit = 0);
	~MyTexture2D();

	virtual void InitializeTexture(const char *texFileName = 0, unsigned int texUnit = 0);

	// Getters
	virtual unsigned int GetTextureID();
	virtual unsigned int GetTextureUnit();

private:
	char *textureFileName;
	unsigned int textureID;
	unsigned int textureUnit;

};

#endif // MYTEXTURE2D_H
