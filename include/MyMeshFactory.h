#ifndef MYMESHFACTORY_H
#define MYMESHFACTORY_H

#include "MyIndexedVertexArray.h"
#include "MyGraphics.h"
#include <map>

class MyMeshFactory
{
public:
	static MyIndexedVertexArray *CreateQuad(char *meshName, MyColorRGBA &color1 = MyColorRGBA(), MyColorRGBA &color2 = MyColorRGBA(), MyColorRGBA &color3 = MyColorRGBA(), MyColorRGBA &color4 = MyColorRGBA());

	static MyIndexedVertexArray *CreateSphere(char *meshName, int latitudeSamples = 32, int longitudeSamples = 64, MyColorRGBA &color1 = MyColorRGBA(), MyColorRGBA &color2 = MyColorRGBA());
	static MyIndexedVertexArray *CreateSphere(char *meshName, MyColorRGBA &solidColor, int latitudeSamples = 32, int longitudeSamples = 64);

	static MyIndexedVertexArray *GetMesh(char *meshName);

	static void Cleanup();

private:
	static std::map<char *, MyIndexedVertexArray *> *meshes;
	
};

#endif // MYMESHFACTORY_H
