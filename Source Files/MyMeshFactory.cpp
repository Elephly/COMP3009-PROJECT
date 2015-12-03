#include "MyMeshFactory.h"

#include "MyIncludes.h"
#include "MyShaderManager.h"
#include <glew.h>
#include <vector>

std::map<char *, MyIndexedVertexArray *> *MyMeshFactory::meshes = new std::map<char *, MyIndexedVertexArray *>();

MyIndexedVertexArray * MyMeshFactory::CreateQuad(char * meshName, MyColorRGBA & color1, MyColorRGBA & color2, MyColorRGBA & color3, MyColorRGBA & color4)
{
	if (meshes->find(meshName) != meshes->end())
	{
		return 0;
	}
	MyVertex4D *vertices = new MyVertex4D[6]();

	MyVector3D normal = MyVector3D(0.0f, 0.0f, 1.0f);
	MyVertex4D v1 = MyVertex4D(-0.5f, -0.5f, 0.0f, 1.0f, color1);
	MyVertex4D v2 = MyVertex4D(0.5f, -0.5f, 0.0f, 1.0f, color2);
	MyVertex4D v3 = MyVertex4D(0.5f, 0.5f, 0.0f, 1.0f, color3);
	MyVertex4D v4 = MyVertex4D(-0.5f, 0.5f, 0.0f, 1.0f, color4);
	v1.SetNormal(normal);
	v2.SetNormal(normal);
	v3.SetNormal(normal);
	v4.SetNormal(normal);
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
	vertices[3] = v1;
	vertices[4] = v3;
	vertices[5] = v4;

	(*meshes)[meshName] = new MyIndexedVertexArray(vertices, 6);
	(*meshes)[meshName]->Initialize();

	return (*meshes)[meshName];
}

MyIndexedVertexArray * MyMeshFactory::CreateSphere(char *meshName, int latitudeSamples, int longitudeSamples, MyColorRGBA & color1, MyColorRGBA & color2)
{
	if (meshes->find(meshName) != meshes->end())
	{
		return 0;
	}
	MyVertex4D *v = new MyVertex4D[latitudeSamples * longitudeSamples]();
	MyVertex4D *vertices = new MyVertex4D[6 * (latitudeSamples * longitudeSamples)]();

	float theta, phi;
	int k = 0;
	for (int i = 0; i < longitudeSamples; i++)
	{
		theta = (2 * MyMath::MY_PI_F) * i / (longitudeSamples - 1);
		for (int j = 0; j < latitudeSamples; j++)
		{
			phi = MyMath::MY_PI_F * j / (latitudeSamples - 1);
			MyVector3D normal = MyVector3D(-sin(theta) * sin(phi), cos(phi), cos(theta) * sin(phi));

			float t = (float)j / latitudeSamples;
			MyColorRGBA color = MyColorRGBA(LerpF(color1.GetRed(), color2.GetRed(), t), LerpF(color1.GetGreen(), color2.GetGreen(), t),
				LerpF(color1.GetBlue(), color2.GetBlue(), t), LerpF(color1.GetAlpha(), color2.GetAlpha(), t));

			MyVector4D position = normal * 0.5f;

			MyVertex4D vertex = MyVertex4D(position, color);
			vertex.SetNormal(normal);
			vertex.SetTextureCoord(1.0f - ((float)i / (float)longitudeSamples), (float)j / (float)latitudeSamples);

			v[k++] = vertex;
		}
	}

	k = 0;
	for (int i = 0; i < longitudeSamples; i++)
	{
		for (int j = 0; j < (latitudeSamples - 1); j++)
		{
			vertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + j];
			vertices[k++] = v[i * latitudeSamples + (j + 1)];
			vertices[k++] = v[i * latitudeSamples + j];

			vertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + j];
			vertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + (j + 1)];
			vertices[k++] = v[i * latitudeSamples + (j + 1)];
		}
	}

	(*meshes)[meshName] = new MyIndexedVertexArray(vertices, 6 * (latitudeSamples * longitudeSamples));
	(*meshes)[meshName]->Initialize();

	MyDeleteArray(v);

	return (*meshes)[meshName];
}

MyIndexedVertexArray * MyMeshFactory::CreateSphere(char *meshName, MyColorRGBA & solidColor, int latitudeSamples, int longitudeSamples)
{
	if (meshes->find(meshName) != meshes->end())
	{
		return 0;
	}
	MyVertex4D *v = new MyVertex4D[latitudeSamples * longitudeSamples]();
	MyVertex4D *vertices = new MyVertex4D[6 * (latitudeSamples * longitudeSamples)]();

	float theta, phi;
	int k = 0;
	for (int i = 0; i < longitudeSamples; i++)
	{
		theta = (2 * MyMath::MY_PI_F) * i / (longitudeSamples - 1);
		for (int j = 0; j < latitudeSamples; j++)
		{
			phi = MyMath::MY_PI_F * j / (latitudeSamples - 1);
			MyVector3D normal = MyVector3D(-sin(theta) * sin(phi), cos(phi), cos(theta) * sin(phi));

			MyVector4D position = normal * 0.5f;

			MyVertex4D vertex = MyVertex4D(position, solidColor);
			vertex.SetNormal(normal);
			vertex.SetTextureCoord(1.0f - ((float)i / (float)longitudeSamples), (float)j / (float)latitudeSamples);

			v[k++] = vertex;
		}
	}

	k = 0;
	for (int i = 0; i < longitudeSamples; i++)
	{
		for (int j = 0; j < (latitudeSamples - 1); j++)
		{
			vertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + j];
			vertices[k++] = v[i * latitudeSamples + (j + 1)];
			vertices[k++] = v[i * latitudeSamples + j];

			vertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + j];
			vertices[k++] = v[((i + 1) % longitudeSamples) * latitudeSamples + (j + 1)];
			vertices[k++] = v[i * latitudeSamples + (j + 1)];
		}
	}

	(*meshes)[meshName] = new MyIndexedVertexArray(vertices, 6 * (latitudeSamples * longitudeSamples));
	(*meshes)[meshName]->Initialize();

	MyDeleteArray(v);

	return (*meshes)[meshName];
}

MyIndexedVertexArray * MyMeshFactory::GetMesh(char * meshName)
{
	if (meshes->find(meshName) != meshes->end())
	{
		return (*meshes)[meshName];
	}
	return nullptr;
}

void MyMeshFactory::Cleanup()
{
	for (std::map<char *, MyIndexedVertexArray *>::iterator it = meshes->begin(); it != meshes->end(); ++it)
	{
		MyDelete(it->second);
	}
	meshes->clear();
	MyDelete(meshes);
}
