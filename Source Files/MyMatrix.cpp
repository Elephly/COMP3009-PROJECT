#include "MyMatrix.h"

MyMatrix::~MyMatrix()
{
}

MyMatrix4 MyMatrix4::NullMatrix()
{
	return MyMatrix4();
}

MyMatrix4 MyMatrix4::IdentityMatrix()
{
	return MyMatrix4(MyVector4D(1.0f, 0.0f, 0.0f, 0.0f), MyVector4D(0.0f, 1.0f, 0.0f, 0.0f), MyVector4D(0.0f, 0.0f, 1.0f, 0.0f), MyVector4D(0.0f, 0.0f, 0.0f, 1.0f));
}

MyMatrix4 MyMatrix4::RotateMatrix()
{
	return MyMatrix4();
}

MyMatrix4 MyMatrix4::ScaleMatrix()
{
	return MyMatrix4();
}

MyMatrix4 MyMatrix4::TranslationMatrix()
{
	return MyMatrix4();
}

MyMatrix4::MyMatrix4(MyVector4D vector1, MyVector4D vector2, MyVector4D vector3, MyVector4D vector4)
{
	entries[0][0] = vector1.GetX();
	entries[0][1] = vector1.GetY();
	entries[0][2] = vector1.GetZ();
	entries[0][3] = vector1.GetW();
	entries[1][0] = vector2.GetX();
	entries[1][1] = vector2.GetY();
	entries[1][2] = vector2.GetZ();
	entries[1][3] = vector2.GetW();
	entries[2][0] = vector3.GetX();
	entries[2][1] = vector3.GetY();
	entries[2][2] = vector3.GetZ();
	entries[2][3] = vector3.GetW();
	entries[3][0] = vector4.GetX();
	entries[3][1] = vector4.GetY();
	entries[3][2] = vector4.GetZ();
	entries[3][3] = vector4.GetW();
}

MyMatrix4::~MyMatrix4()
{
}

float * MyMatrix4::GetEntries()
{
	return (float *)entries;
}

MyMatrix4 MyMatrix4::GetTranspose()
{
	MyMatrix4 m = *this;
	return m.Transpose();
}

MyMatrix4 & MyMatrix4::SetNull()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			entries[i][j] = 0.0f;
		}
	}

	return *this;
}

MyMatrix4 & MyMatrix4::Transpose()
{
	MyMatrix4 m = *this;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			entries[i][j] = m.entries[j][i];
		}
	}

	return *this;
}

MyMatrix4 MyMatrix4::operator+(const MyMatrix4 & other) const
{
	return MyMatrix4();
}

MyMatrix4 MyMatrix4::operator-(const MyMatrix4 & other) const
{
	return MyMatrix4();
}

MyMatrix4 MyMatrix4::operator*(const MyMatrix4 & other) const
{
	return MyMatrix4();
}

MyMatrix4 MyMatrix4::operator*(const float & multiplier) const
{
	return MyMatrix4();
}

MyVector3D MyMatrix4::operator*(const MyVector3D & other) const
{
	return MyVector3D();
}

MyVector4D MyMatrix4::operator*(const MyVector4D & vector) const
{
	return MyVector4D();
}

MyMatrix4 & MyMatrix4::operator+=(const MyMatrix4 & other)
{
	// TODO: insert return statement here
	return *this;
}

MyMatrix4 & MyMatrix4::operator-=(const MyMatrix4 & other)
{
	// TODO: insert return statement here
	return *this;
}

MyMatrix4 & MyMatrix4::operator*=(const MyMatrix4 & other)
{
	// TODO: insert return statement here
	return *this;
}

MyMatrix4 & MyMatrix4::operator*=(const float & multiplier)
{
	// TODO: insert return statement here
	return *this;
}

MyMatrix4 operator*(const float & multiplier, MyMatrix4 & matrix)
{
	return matrix * multiplier;
}

std::ostream &operator<<(std::ostream &os, const MyMatrix4 &matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			os << matrix.entries[i][j] << "\t";
		}
		os << "\b" << std::endl;
	}
	return os;
}
