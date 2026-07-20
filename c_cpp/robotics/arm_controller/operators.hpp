#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <rotation.hpp>
#include <transform.hpp>
#include <vector3.hpp>
#include <point3.hpp>

Vector3 operator+(const Vector3 &a, const Vector3 &b)
{
	return Vector3{a.x_ + b.x_, a.y_ + b.y_, a.z_ + b.z_};
}

Vector3 operator*(const Rotation &rot, const Vector3 &v)
{
	return Vector3{
		rot.matrix_[0].x_ * v.x_ + rot.matrix_[0].y_ * v.y_ + rot.matrix_[0].z_ * v.z_,
		rot.matrix_[1].x_ * v.x_ + rot.matrix_[1].y_ * v.y_ + rot.matrix_[1].z_ * v.z_,
		rot.matrix_[2].x_ * v.x_ + rot.matrix_[2].y_ * v.y_ + rot.matrix_[2].z_ * v.z_};
}

Rotation operator*(const Rotation &a, const Rotation &b)
{
	Rotation result;
	for (int i = 0; i < 3; ++i)
	{
		result.matrix_[i] = a * b.matrix_[i];
	}

	return result;
}

Transform operator*(const Transform &t, const Transform &t_other)
{
	return Transform(t.position_ + t.rotation_ * t_other.position_, t.rotation_ * t_other.rotation_);
}

Vector3 operator*(const Transform &t, const Vector3 &v)
{
	return t.position_ + t.rotation_ * v;
}

Point3 operator*(const Transform &t, const Point3 &p)
{
	return t.position_ + static_cast<Vector3>(p);
}

#endif // OPERATORS_HPP