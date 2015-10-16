#include "MyMatrix.h"

#include "MyIncludes.h"

MyMatrix::~MyMatrix()
{
}

MyMatrix4 MyMatrix4::NullMatrix()
{
	return MyMatrix4();
}

MyMatrix4 MyMatrix4::ZeroMatrix()
{
	return MyMatrix4(MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), MyVector4D(0.0f, 0.0f, 0.0f, 0.0f), MyVector4D(0.0f, 0.0f, 0.0f, 1.0f));
}

MyMatrix4 MyMatrix4::IdentityMatrix()
{
	return MyMatrix4(MyVector4D(1.0f, 0.0f, 0.0f, 0.0f), MyVector4D(0.0f, 1.0f, 0.0f, 0.0f), MyVector4D(0.0f, 0.0f, 1.0f, 0.0f), MyVector4D(0.0f, 0.0f, 0.0f, 1.0f));
}

MyMatrix4 MyMatrix4::RotationAboutXMatrix(float const & angle, bool isDegree)
{
	float a = (isDegree ? DegreeToRadian(angle) : angle);

	MyMatrix4 matrix = MyMatrix4::IdentityMatrix();
	matrix.entries[1][1] = matrix.entries[2][2] = cos(a);
	matrix.entries[1][2] = -(matrix.entries[2][1] = sin(a));

	return matrix;
}

MyMatrix4 MyMatrix4::RotationAboutYMatrix(float const & angle, bool isDegree)
{
	float a = (isDegree ? DegreeToRadian(angle) : angle);

	MyMatrix4 matrix = MyMatrix4::IdentityMatrix();
	matrix.entries[0][0] = matrix.entries[2][2] = cos(a);
	matrix.entries[0][2] = -(matrix.entries[2][0] = -sin(a));

	return matrix;
}

MyMatrix4 MyMatrix4::RotationAboutZMatrix(float const & angle, bool isDegree)
{
	float a = (isDegree ? DegreeToRadian(angle) : angle);

	MyMatrix4 matrix = MyMatrix4::IdentityMatrix();
	matrix.entries[0][0] = matrix.entries[1][1] = cos(a);
	matrix.entries[0][1] = -(matrix.entries[1][0] = sin(a));

	return matrix;
}

MyMatrix4 MyMatrix4::RollPitchYarRotationMatrix(float const & roll, float const & pitch, float const & yaw, bool isDegree)
{
	return (RotationAboutYMatrix(yaw, isDegree) * RotationAboutXMatrix(pitch, isDegree) * RotationAboutZMatrix(roll, isDegree));
}

MyMatrix4 MyMatrix4::RotationAboutVectorAxisMatrix(MyVector3D const & vector, float const & angle, bool isDegree)
{
	float a = (isDegree ? DegreeToRadian(angle) : angle);
	MyVector3D v = vector.GetNormalized();

	float x = v.GetX();
	float y = v.GetY();
	float z = v.GetZ();
	float c = cos(a);
	float s = sin(a);

	MyMatrix4 matrix = MyMatrix4(MyVector4D(c + (x * x * (1 - c)), (x * y * (1 - c)) - (z * s), (x * z * (1 - c)) + (y * s), 0.0f),
		MyVector4D((x * y * (1 - c)) + (z * s), c + (y * y * (1 - c)), (y * z * (1 - c)) - (x * s), 0.0f),
		MyVector4D((z * x * (1 - c)) - (y * s), (z * y * (1 - c)) + (x * s), c + (z * z * (1 - c)), 0.0f),
		MyVector4D());

	return matrix;
}

MyMatrix4 MyMatrix4::RotationAboutVectorAxisMatrix(MyVector4D const & vector, float const & angle, bool isDegree)
{
	return RotationAboutVectorAxisMatrix(MyVector3D(vector.GetX(), vector.GetY(), vector.GetZ()), angle, isDegree);
}

MyMatrix4 MyMatrix4::ScaleMatrix(float const & x, float const & y, float const & z)
{
	return MyMatrix4(MyVector4D(x, 0.0f, 0.0f, 0.0f), MyVector4D(0.0f, y, 0.0f, 0.0f), MyVector4D(0.0f, 0.0f, z, 0.0f), MyVector4D());
}

MyMatrix4 MyMatrix4::TranslationMatrix(float const & x, float const & y, float const & z)
{
	MyMatrix4 matrix = IdentityMatrix();
	matrix.entries[0][3] = x;
	matrix.entries[1][3] = y;
	matrix.entries[2][3] = z;
	return matrix;
}

MyMatrix4 MyMatrix4::TranslationMatrix(MyVector3D const & vector)
{
	MyVector3D v = vector;
	return TranslationMatrix(v.GetX(), v.GetY(), v.GetZ());
}

MyMatrix4 MyMatrix4::TranslationMatrix(MyVector4D const & vector)
{
	MyVector4D v = vector;
	return TranslationMatrix(v.GetX(), v.GetY(), v.GetZ());
}

MyMatrix4 MyMatrix4::CameraMatrix(MyVector3D const & position, MyVector3D const & lookAt, MyVector3D const & upVector)
{
	MyVector3D n3 = (position - lookAt);
	n3.Normalize();

	MyVector3D u3 = upVector.GetNormalized().Cross(n3);
	u3.Normalize();

	MyVector3D v3 = n3.Cross(u3);

	MyVector4D u = MyVector4D(u3, 0.0f);
	MyVector4D v = MyVector4D(v3, 0.0f);
	MyVector4D n = MyVector4D(n3, 0.0f);
	
	MyVector4D pos = MyVector4D(position.GetX(), position.GetY(), position.GetZ());

	MyMatrix4 matrix = MyMatrix4(u, v, n, MyVector4D());
	matrix.entries[0][3] = (-u).Dot(pos);
	matrix.entries[1][3] = (-v).Dot(pos);
	matrix.entries[2][3] = (-n).Dot(pos);

	return matrix;
}

MyMatrix4 MyMatrix4::CameraMatrix(MyVector4D const & position, MyVector4D const & lookAt, MyVector4D const & upVector)
{
	MyVector4D n = (position - lookAt);
	n.SetW(0.0f);
	n.Normalize();

	MyVector4D up = MyVector4D(upVector.GetX(), upVector.GetY(), upVector.GetZ(), 0.0f);

	MyVector4D u = up.GetNormalized().Cross(n);
	u.SetW(0.0f);
	u.Normalize();

	MyVector4D v = n.Cross(u);
	v.SetW(0.0f);

	MyMatrix4 matrix = MyMatrix4(u, v, n, MyVector4D());
	matrix.entries[0][3] = (-u).Dot(position);
	matrix.entries[1][3] = (-v).Dot(position);
	matrix.entries[2][3] = (-n).Dot(position);

	return matrix;
}

MyMatrix4 MyMatrix4::FrustrumProjetionMatrix(float const & xMin, float const & yMin, float const & xMax, float const & yMax, float const & nearPlane, float const & farPlane)
{
	MyMatrix4 matrix = IdentityMatrix();

	/*
	m1.vm[0].x = 2 * nearPlane / (winMaxX - winMinX);		// check why it is not "-2"
	m1.vm[0].z = (winMaxX + winMinX) / (winMaxX - winMinX);
	m1.vm[1].y = 2 * nearPlane / (winMaxY - winMinY);		// check why it is not "-2"
	m1.vm[1].z = (winMaxY + winMinY) / (winMaxY - winMinY);
	m1.vm[2].z = (nearPlane + farPlane) / (nearPlane - farPlane);
	m1.vm[2].w = (2 * nearPlane * farPlane) / (nearPlane - farPlane);
	m1.vm[3].z = -1;
	m1.vm[3].w = 0;
	// ADD CODE
	*/

	return matrix;
}

MyMatrix4 MyMatrix4::SymmetricPerspectiveProjectionMatrix(float const & fieldOfView, float const & aspectRatio, float const & nearPlane, float const & farPlane)
{
	MyMatrix4 matrix = IdentityMatrix();
	float cot = 1.0f / tan(DegreeToRadian(fieldOfView / 2.0f));
	matrix.entries[0][0] = cot / aspectRatio;
	matrix.entries[1][1] = cot;
	matrix.entries[2][2] = (nearPlane + farPlane) / (nearPlane - farPlane);
	matrix.entries[2][3] = 2.0f * nearPlane * farPlane / (nearPlane - farPlane);
	matrix.entries[3][2] = -1;
	matrix.entries[3][3] = 0;
	return matrix;
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

MyMatrix4 MyMatrix4::GetTranspose() const
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
	MyMatrix4 matrix = *this;
	return matrix += other;
}

MyMatrix4 MyMatrix4::operator-(const MyMatrix4 & other) const
{
	MyMatrix4 matrix = *this;
	return matrix -= other;
}

MyMatrix4 MyMatrix4::operator*(const MyMatrix4 & other) const
{
	MyMatrix4 matrix = *this;
	return matrix *= other;
}

MyMatrix4 MyMatrix4::operator*(const float & multiplier) const
{
	MyMatrix4 matrix = *this;
	return matrix *= multiplier;
}

MyVector4D MyMatrix4::operator*(const MyVector4D & vector) const
{
	MyVector4D rows[4];

	for (int i = 0; i < 4; i++)
	{
		rows[i] = MyVector4D(entries[i][0], entries[i][1], entries[i][2], entries[i][3]);
	}

	return MyVector4D(rows[0].Dot(vector), rows[1].Dot(vector), rows[2].Dot(vector), rows[3].Dot(vector));
}

MyMatrix4 & MyMatrix4::operator+=(const MyMatrix4 & other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			entries[i][j] += other.entries[i][j];
		}
	}
	return *this;
}

MyMatrix4 & MyMatrix4::operator-=(const MyMatrix4 & other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			entries[i][j] -= other.entries[i][j];
		}
	}
	return *this;
}

MyMatrix4 & MyMatrix4::operator*=(const MyMatrix4 & other)
{
	MyMatrix4 matrix = other.GetTranspose();

	for (int i = 0; i < 4; i++)
	{
		MyVector4D vector1 = MyVector4D(entries[i][0], entries[i][1], entries[i][2], entries[i][3]);
		for (int j = 0; j < 4; j++)
		{
			MyVector4D vector2 = MyVector4D(matrix.entries[j][0], matrix.entries[j][1], matrix.entries[j][2], matrix.entries[j][3]);
			entries[i][j] = vector1.Dot(vector2);
		}
	}

	return *this;
}

MyMatrix4 & MyMatrix4::operator*=(const float & multiplier)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			entries[i][j] *= multiplier;
		}
	}
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
