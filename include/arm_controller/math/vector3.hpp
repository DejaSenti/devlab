#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>

struct Point3;

struct Vector3
{
	float x_;
	float y_;
	float z_;

	Vector3 Normalized() const
	{
		float length = std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
		return Vector3{x_ / length, y_ / length, z_ / length};
	}

	operator Point3() const;

	Vector3 operator*(float scalar) const
	{
		return Vector3{x_ * scalar, y_ * scalar, z_ * scalar};
	}
};

struct Point3 : public Vector3
{
};

inline Vector3::operator Point3() const
{
	return Point3{x_, y_, z_};
}

#endif // VECTOR3_HPP