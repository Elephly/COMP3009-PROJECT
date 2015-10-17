#ifndef MYOBJECT3D_H
#define MYOBJECT3D_H

#include "MyMatrix.h"
#include "MyShaderProgram.h"
#include <vector>

class MyObject3D
{
public:
	MyObject3D(MyVector3D &initialPosition = MyVector3D(), MyVector3D &initialScale = MyVector3D(1.0f, 1.0f, 1.0f), MyVector3D &initialRotation = MyVector3D());
	virtual ~MyObject3D() = 0;

	// Transformations
	virtual void Rotate(float const & x, float const & y, float const & z, bool isDegree = true);
	virtual void Rotate(MyVector3D const & vector, bool isDegree = true);
	virtual void Rotate(MyVector4D const & vector, bool isDegree = true);
	virtual void Scale(float const & x, float const & y, float const & z);
	virtual void Scale(MyVector3D const & vector);
	virtual void Scale(MyVector4D const & vector);
	virtual void Translate(float const & x, float const & y, float const & z);
	virtual void Translate(MyVector3D const & vector);
	virtual void Translate(MyVector4D const & vector);

	// Special Rotations
	/* TODO */
	virtual void Roll(float const & angle, bool isDegree = true);
	/* TODO */
	virtual void Pitch(float const & angle, bool isDegree = true);
	/* TODO */
	virtual void Yaw(float const & angle, bool isDegree = true);

	// Getters
	virtual const MyVector3D &GetPosition() const;
	virtual const MyVector3D &GetRotation() const;
	virtual const MyVector3D &GetScale() const;

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

protected:
	MyVector3D position;
	MyVector3D rotation;
	MyVector3D scale;
	std::vector<MyObject3D *> children;
};

#endif // MYOBJECT3D_H
