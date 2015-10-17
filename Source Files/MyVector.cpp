#include "MyVector.h"
#include "MyIncludes.h"

MyVector::~MyVector() { }

MyVector2D::MyVector2D(MyVector3D & vector) :
	MyPoint2D(vector.GetX(), vector.GetY())
{
}

MyVector2D::MyVector2D(MyVector4D & vector) :
	MyPoint2D(vector.GetX(), vector.GetY())
{
}

MyVector2D::MyVector2D(float x, float y) :
	MyPoint2D(x, y)
{
}

MyVector2D::~MyVector2D()
{
}

float MyVector2D::GetLength() const
{
	return sqrt(x_ * x_ + y_ * y_);
}

MyVector2D MyVector2D::GetNormalized()
{
	return (*this) / GetLength();
}

float MyVector2D::Dot(const MyVector2D & other) const
{
	return (x_ * other.x_ + y_ * other.y_);
}

void MyVector2D::Normalize()
{
	(*this) /= GetLength();
}

MyVector2D MyVector2D::operator-()
{
	return MyVector2D(-x_, -y_);
}

MyVector2D MyVector2D::operator+(const MyVector2D & other) const
{
	return MyVector2D(x_ + other.x_, y_ + other.y_);
}

MyVector2D MyVector2D::operator-(const MyVector2D & other) const
{
	return MyVector2D(x_ - other.x_, y_ - other.y_);
}

MyVector2D MyVector2D::operator*(const MyVector2D & other) const
{
	return MyVector2D(x_ * other.x_, y_ * other.y_);
}

MyVector2D MyVector2D::operator*(const float & multiplier) const
{
	return MyVector2D(x_ * multiplier, y_ * multiplier);
}

MyVector2D MyVector2D::operator/(const float & divisor) const
{
	assert(divisor != 0);
	return MyVector2D(x_ / divisor, y_ / divisor);
}

MyVector2D & MyVector2D::operator+=(const MyVector2D & other)
{
	x_ += other.x_;
	y_ += other.y_;

	return *this;
}


MyVector2D & MyVector2D::operator-=(const MyVector2D & other)
{
	x_ -= other.x_;
	y_ -= other.y_;

	return *this;
}

MyVector2D & MyVector2D::operator*=(const float & multiplier)
{
	x_ *= multiplier;
	y_ *= multiplier;

	return *this;
}

MyVector2D & MyVector2D::operator/=(const float & divisor)
{
	assert(divisor != 0);
	x_ /= divisor;
	y_ /= divisor;

	return *this;
}

MyVector2D operator*(const float &multiplier, MyVector2D &vector)
{
	return vector * multiplier;
}

std::ostream &operator<<(std::ostream &os, const MyVector2D &vector)
{
	os << "(" << vector.x_ << ", " << vector.y_ << ")";
	return os;
}

MyVector3D::MyVector3D(MyVector2D & vector, float z):
	MyPoint3D(vector.GetX(), vector.GetY(), z)
{
}

MyVector3D::MyVector3D(MyVector4D & vector) :
	MyPoint3D(vector.GetX(), vector.GetY(), vector.GetZ())
{
}

MyVector3D::MyVector3D(float x, float y, float z) :
	MyPoint3D(x, y, z)
{
}

MyVector3D::~MyVector3D()
{
}

float MyVector3D::GetLength() const
{
	return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

MyVector3D MyVector3D::GetNormalized() const
{
	return (*this) / GetLength();
}

MyVector3D MyVector3D::Cross(const MyVector3D & other) const
{
	return MyVector3D((y_ * other.z_ - z_ * other.y_), -(x_ * other.z_ - z_ * other.x_), (x_ * other.y_ - y_ * other.x_));
}

float MyVector3D::Dot(const MyVector3D & other) const
{
	return (x_ * other.x_ + y_ * other.y_ + z_ * other.z_);
}

void MyVector3D::Normalize()
{
	(*this) /= GetLength();
}

MyVector3D MyVector3D::operator-()
{
	return MyVector3D(-x_, -y_, -z_);
}

MyVector3D MyVector3D::operator+(const MyVector3D & other) const
{
	return MyVector3D(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

MyVector3D MyVector3D::operator-(const MyVector3D & other) const
{
	return MyVector3D(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

MyVector3D MyVector3D::operator*(const MyVector3D & other) const
{
	return MyVector3D(x_ * other.x_, y_ * other.y_, z_ * other.z_);
}

MyVector3D MyVector3D::operator*(const float & multiplier) const
{
	return MyVector3D(x_ * multiplier, y_ * multiplier, z_ * multiplier);
}

MyVector3D MyVector3D::operator/(const float & divisor) const
{
	assert(divisor != 0);
	return MyVector3D(x_ / divisor, y_ / divisor, z_ / divisor);
}

MyVector3D & MyVector3D::operator+=(const MyVector3D & other)
{
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;

	return *this;
}


MyVector3D & MyVector3D::operator-=(const MyVector3D & other)
{
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;

	return *this;
}

MyVector3D & MyVector3D::operator*=(const float & multiplier)
{
	x_ *= multiplier;
	y_ *= multiplier;
	z_ *= multiplier;

	return *this;
}

MyVector3D & MyVector3D::operator/=(const float & divisor)
{
	assert(divisor != 0);
	x_ /= divisor;
	y_ /= divisor;
	z_ /= divisor;

	return *this;
}

MyVector3D operator*(const float &multiplier, MyVector3D &vector)
{
	return vector * multiplier;
}

std::ostream &operator<<(std::ostream &os, const MyVector3D &vector)
{
	os << "(" << vector.x_ << ", " << vector.y_ << ", " << vector.z_ << ")";
	return os;
}

MyVector4D::MyVector4D(MyVector2D & vector, float z, float w) :
	MyPoint4D(vector.GetX(), vector.GetY(), z, w)
{
}

MyVector4D::MyVector4D(MyVector3D & vector, float w) :
	MyPoint4D(vector.GetX(), vector.GetY(), vector.GetZ(), w)
{
}

MyVector4D::MyVector4D(float x, float y, float z, float w) :
	MyPoint4D(x, y, z, w)
{
}

MyVector4D::~MyVector4D()
{
}

float MyVector4D::GetLength() const
{
	return sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
}

MyVector4D MyVector4D::GetNormalized()
{
	return (*this) / GetLength();
}

MyVector4D MyVector4D::Cross(const MyVector4D & other) const
{
	return MyVector4D((y_ * other.z_ - z_ * other.y_), -(x_ * other.z_ - z_ * other.x_), (x_ * other.y_ - y_ * other.x_));
}

float MyVector4D::Dot(const MyVector4D & other) const
{
	return (x_ * other.x_ + y_ * other.y_ + z_ * other.z_ + w_ * other.w_);
}

float MyVector4D::Dot3(const MyVector4D & other) const
{
	return (x_ * other.x_ + y_ * other.y_ + z_ * other.z_);
}

void MyVector4D::Normalize()
{
	(*this) /= GetLength();
}

MyVector4D MyVector4D::operator-()
{
	return MyVector4D(-x_, -y_, -z_, -w_);
}

MyVector4D MyVector4D::operator+(const MyVector4D & other) const
{
	return MyVector4D(x_ + other.x_, y_ + other.y_, z_ + other.z_, w_ + other.w_);
}

MyVector4D MyVector4D::operator-(const MyVector4D & other) const
{
	return MyVector4D(x_ - other.x_, y_ - other.y_, z_ - other.z_, w_ - other.w_);
}

MyVector4D MyVector4D::operator*(const MyVector4D & other) const
{
	return MyVector4D(x_ * other.x_, y_ * other.y_, z_ * other.z_, w_ * other.w_);
}

MyVector4D MyVector4D::operator*(const float & multiplier) const
{
	return MyVector4D(x_ * multiplier, y_ * multiplier, z_ * multiplier, w_ * multiplier);
}

MyVector4D MyVector4D::operator/(const float & divisor) const
{
	assert(divisor != 0);
	return MyVector4D(x_ / divisor, y_ / divisor, z_ / divisor, w_ / divisor);
}

MyVector4D & MyVector4D::operator+=(const MyVector4D & other)
{
	x_ += other.x_;
	y_ += other.y_;
	z_ += other.z_;
	w_ += other.w_;

	return *this;
}


MyVector4D & MyVector4D::operator-=(const MyVector4D & other)
{
	x_ -= other.x_;
	y_ -= other.y_;
	z_ -= other.z_;
	w_ -= other.w_;

	return *this;
}

MyVector4D & MyVector4D::operator*=(const float & multiplier)
{
	x_ *= multiplier;
	y_ *= multiplier;
	z_ *= multiplier;
	w_ *= multiplier;

	return *this;
}

MyVector4D & MyVector4D::operator/=(const float & divisor)
{
	assert(divisor != 0);
	x_ /= divisor;
	y_ /= divisor;
	z_ /= divisor;
	w_ /= divisor;

	return *this;
}

MyVector4D operator*(const float &multiplier, MyVector4D &vector)
{
	return vector * multiplier;
}

std::ostream &operator<<(std::ostream &os, const MyVector4D &vector)
{
	os << "(" << vector.x_ << ", " << vector.y_ << ", " << vector.z_ << ", " << vector.w_ << ")";
	return os;
}