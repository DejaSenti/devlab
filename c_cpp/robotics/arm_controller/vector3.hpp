#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>
#include <point3.hpp>

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

	operator Point3() const
	{
		return Point3{x_, y_, z_};
	}

	Vector3 operator*(float scalar) const
	{
		return Vector3{x_ * scalar, y_ * scalar, z_ * scalar};
	}
};

#endif // VECTOR3_HPP