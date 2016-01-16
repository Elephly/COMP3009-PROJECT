#ifndef MYOBJECTSMANAGER_H
#define MYOBJECTSMANAGER_H

#include <map>
#include <vector>

#include "MyDefines.h"

template<typename T>
class MyObjectManager
{
public:
	static void Add(char * objectName, T * object);
	static void Erase(char * objectName);
	static T * Get(char * objectName);
	static std::vector<T *> * GetAll();
	static T *  Remove(char * objectName);
	static T *  Remove(T * object);
	static void Set(char * objectName);

	static void Cleanup();

private:
	static std::map<char *, T *> * objects;

};

template<typename T>
std::map<char *, T *> * MyObjectManager<T>::objects = new std::map<char *, T *>();

template<typename T>
void MyObjectManager<T>::Add(char * objectName, T * object)
{
	if (objects->find(objectName) != objects->end())
	{
		return;
	}
	(*objects)[objectName] = object;
}

template<typename T>
T * MyObjectManager<T>::Get(char * objectName)
{
	if (objects->find(objectName) != objects->end())
	{
		return (*objects)[objectName];
	}
	return nullptr;
}

template<typename T>
std::vector<T *> * MyObjectManager<T>::GetAll()
{
	std::vector<T *> * objectList = new std::vector<T *>();

	for (std::map<char *, T *>::iterator it = objects->begin(); it != objects->end(); ++it)
	{
		objectList->push_back(it->second);
	}

	return objectList;
}

template<typename T>
void MyObjectManager<T>::Cleanup()
{
	for (std::map<char *, T *>::iterator it = objects->begin(); it != objects->end(); ++it)
	{
		MyDelete(it->second);
	}
	objects->clear();
	MyDelete(objects);
}

#endif // MYOBJECTMANAGER_H