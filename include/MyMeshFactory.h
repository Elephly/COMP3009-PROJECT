#ifndef MYMESHFACTORY_H
#define MYMESHFACTORY_H

#include "MyGraphics.h"
#include "MyIndexedVertexArray.h"

#include <map>

class MyMeshFactory
{
public:
	static MyIndexedVertexArray *CreateQuad(const char *meshName, MyColorRGBA color1 = MyColorRGBA(), MyColorRGBA color2 = MyColorRGBA(), MyColorRGBA color3 = MyColorRGBA(), MyColorRGBA color4 = MyColorRGBA());

	static MyIndexedVertexArray *CreateSphere(const char *meshName, int latitudeSamples = 32, int longitudeSamples = 64, MyColorRGBA color1 = MyColorRGBA(), MyColorRGBA color2 = MyColorRGBA());
	static MyIndexedVertexArray *CreateSphere(const char *meshName, MyColorRGBA solidColor, int latitudeSamples = 32, int longitudeSamples = 64);

	static MyIndexedVertexArray *GetMesh(const char *meshName);

	static void Cleanup();

private:
	static std::map<const char *, MyIndexedVertexArray *> *meshes;

};

#endif // MYMESHFACTORY_H
