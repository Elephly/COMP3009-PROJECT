#ifndef MYKEYFRAME_H
#define MYKEYFRAME_H

#include "MyVector.h"

class MyKeyframe
{
public:
	MyKeyframe(MyVector3D &position = MyVector3D(), MyVector3D &scale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &rotation = MyVector3D());
	~MyKeyframe();

	// Getters
	virtual const MyVector3D &GetPosition() const;
	virtual const MyVector3D &GetRotation() const;
	virtual const MyVector3D &GetScale() const;
	virtual const bool IsRecursiveScale() const;

	// Setters
	virtual void SetPosition(float const & x, float const & y, float const & z);
	virtual void SetPosition(MyVector3D const & vector);
	virtual void SetPosition(MyVector4D const & vector);
	virtual void SetRotation(float const & x, float const & y, float const & z);
	virtual void SetRotation(MyVector3D const & vector);
	virtual void SetRotation(MyVector4D const & vector);
	virtual void SetScale(float const & x, float const & y, float const & z);
	virtual void SetScale(MyVector3D const & vector);
	virtual void SetScale(MyVector4D const & vector);
	virtual void SetRecursiveScale(bool const & recursive);

private:
	MyVector3D position;
	MyVector3D rotation;
	MyVector3D scale;
	bool recursiveScale;

};

#endif // MYKEYFRAME_H
