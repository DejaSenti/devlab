#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <vector3.hpp>
#include <rotation.hpp>
#include <point3.hpp>

class Transform
{
public:
	Transform(const Vector3 &pos, const Rotation &rot)
		: position_(pos), rotation_(rot) {}

	Vector3 GetPosition() const
	{
		return position_;
	}

	Rotation GetRotation() const
	{
		return rotation_;
	}

	friend Transform operator*(const Transform &t, const Transform &t_other);
	friend Vector3 operator*(const Transform &t, const Vector3 &v);
	friend Point3 operator*(const Transform &t, const Point3 &p);

private:
	Vector3 position_;
	Rotation rotation_; // 3x3 rotation matrix
};

#endif // TRANSFORM_HPP