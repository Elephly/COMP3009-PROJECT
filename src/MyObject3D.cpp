#include "MyObject3D.h"

#include <algorithm>

#include "MyDefines.h"
#include "MyMath.h"

MyObject3D::MyObject3D(MyVector3D initialPosition, MyVector3D initialScale, MyVector3D initialRotation) :
	position(initialPosition), scale(initialScale), rotation(initialRotation)
{
	children = new std::vector<MyObject3D *>();
}

MyObject3D::~MyObject3D()
{
	if (children != 0)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			MyDelete(*it);
		}
		children->clear();
		delete children;
		children = 0;
	}
}

void MyObject3D::Update(float const & deltaTime)
{
	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		(*it)->Update(deltaTime);
	}
}

void MyObject3D::Draw(MyMatrix4 const & parentTransformation)
{
	// Scale is not passed onto children
	transformation =
		parentTransformation *
		MyMatrix4::TranslationMatrix(position) *
		MyMatrix4::RollPitchYawRotationMatrix(rotation.GetZ(), rotation.GetX(), rotation.GetY());

	for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
	{
		(*it)->Draw(transformation);
	}

	//transformation =
	//	parentTransformation *
	//	MyMatrix4::TranslationMatrix(position) *
	//	MyMatrix4::RollPitchYawRotationMatrix(rotation.GetZ(), rotation.GetX(), rotation.GetY()) *
	//	MyMatrix4::ScaleMatrix(scale.GetX(), scale.GetY(), scale.GetZ());
    transformation *= MyMatrix4::ScaleMatrix(scale.GetX(), scale.GetY(), scale.GetZ());
}

void MyObject3D::Rotate(float const & x, float const & y, float const & z, bool isDegree)
{
	rotation += MyVector3D((!isDegree ? RadianToDegree(x) : x),
		(!isDegree ? RadianToDegree(y) : y),
		(!isDegree ? RadianToDegree(z) : z));
}

void MyObject3D::Rotate(MyVector3D const & vector, bool isDegree)
{
	rotation += MyVector3D((!isDegree ? RadianToDegree(vector.GetX()) : vector.GetX()),
		(!isDegree ? RadianToDegree(vector.GetY()) : vector.GetY()),
		(!isDegree ? RadianToDegree(vector.GetZ()) : vector.GetZ()));
}

void MyObject3D::Rotate(MyVector4D const & vector, bool isDegree)
{
	rotation += MyVector3D((!isDegree ? RadianToDegree(vector.GetX()) : vector.GetX()),
		(!isDegree ? RadianToDegree(vector.GetY()) : vector.GetY()),
		(!isDegree ? RadianToDegree(vector.GetZ()) : vector.GetZ()));
}

void MyObject3D::Scale(float const & x, float const & y, float const & z, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			(*it)->Scale(x, y, z, recursive);
		}
	}
	scale = MyVector3D(scale.GetX() * x, scale.GetY() * y, scale.GetZ() * z);
}

void MyObject3D::Scale(MyVector3D const & vector, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			(*it)->Scale(vector, recursive);
		}
	}
	scale = MyVector3D(scale.GetX() * vector.GetX(), scale.GetY() * vector.GetY(), scale.GetZ() * vector.GetZ());
}

void MyObject3D::Scale(MyVector4D const & vector, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			(*it)->Scale(vector, recursive);
		}
	}
	scale = MyVector3D(scale.GetX() * vector.GetX(), scale.GetY() * vector.GetY(), scale.GetZ() * vector.GetZ());
}

void MyObject3D::Translate(float const & x, float const & y, float const & z)
{
	position += MyVector3D(x, y, z);
}

void MyObject3D::Translate(MyVector3D const & vector)
{
	position += vector;
}

void MyObject3D::Translate(MyVector4D const & vector)
{
	position += MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyObject3D::Roll(float const & angle, bool isDegree)
{
	rotation += MyVector3D(0.0f, 0.0f, (!isDegree ? RadianToDegree(angle) : angle));
}

void MyObject3D::Pitch(float const & angle, bool isDegree)
{
	rotation += MyVector3D((!isDegree ? RadianToDegree(angle) : angle), 0.0f, 0.0f);
}

void MyObject3D::Yaw(float const & angle, bool isDegree)
{
	rotation += MyVector3D(0.0f, (!isDegree ? RadianToDegree(angle) : angle), 0.0f);
}

const MyVector3D & MyObject3D::GetPosition() const
{
	return position;
}

const MyVector3D & MyObject3D::GetRotation() const
{
	return rotation;
}

const MyVector3D & MyObject3D::GetScale() const
{
	return scale;
}

std::vector<MyObject3D*>* MyObject3D::GetChildren() const
{
	return children;
}

void MyObject3D::SetPosition(float const & x, float const & y, float const & z)
{
	position = MyVector3D(x, y, z);
}

void MyObject3D::SetPosition(MyVector3D const & vector)
{
	position = vector;
}

void MyObject3D::SetPosition(MyVector4D const & vector)
{
	position = MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyObject3D::SetRotation(float const & x, float const & y, float const & z)
{
	rotation = (x, y, z);
}

void MyObject3D::SetRotation(MyVector3D const & vector)
{
	rotation = vector;
}

void MyObject3D::SetRotation(MyVector4D const & vector)
{
	rotation = MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyObject3D::SetScale(float const & x, float const & y, float const & z, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			(*it)->SetScale(x, y, z, recursive);
		}
	}
	scale = MyVector3D(x, y, z);
}

void MyObject3D::SetScale(MyVector3D const & vector, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			(*it)->SetScale(vector, recursive);
		}
	}
	scale = vector;
}

void MyObject3D::SetScale(MyVector4D const & vector, bool recursive)
{
	if (recursive)
	{
		for (std::vector<MyObject3D *>::iterator it = children->begin(); it != children->end(); ++it)
		{
			(*it)->SetScale(vector, recursive);
		}
	}
	scale = MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ());
}

void MyObject3D::AddChild(MyObject3D * child)
{
	children->push_back(child);
}

void MyObject3D::RemoveChild(MyObject3D * child)
{
	std::vector<MyObject3D *>::iterator it = std::find(children->begin(), children->end(), child);
	if (it != children->end())
	{
		children->erase(it);
	}
}
