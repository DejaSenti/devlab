#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <arm_controller/math/rotation.hpp>
#include <arm_controller/math/transform.hpp>
#include <arm_controller/math/vector3.hpp>

Vector3 operator+(const Vector3 &a, const Vector3 &b);

Vector3 operator*(const Rotation &rot, const Vector3 &v);

Rotation operator*(const Rotation &a, const Rotation &b);

Transform operator*(const Transform &t, const Transform &t_other);

Vector3 operator*(const Transform &t, const Vector3 &v);

Point3 operator*(const Transform &t, const Point3 &p);

#endif // OPERATORS_HPP