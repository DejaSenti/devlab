#include "test_utils.hpp"

#include <arm_controller/kinematics/operators.hpp>
#include <arm_controller/math/rotation.hpp>
#include <arm_controller/math/vector3.hpp>

bool TestRotation()
{
	bool ok = true;

	Rotation rotation;
	rotation.matrix_[0] = Vector3{1.0f, 0.0f, 0.0f};
	rotation.matrix_[1] = Vector3{0.0f, 1.0f, 0.0f};
	rotation.matrix_[2] = Vector3{0.0f, 0.0f, 1.0f};

	Vector3 transformed = rotation * Vector3{1.0f, 2.0f, 3.0f};
	ok &= ExpectClose(transformed.x_, 1.0f, "Rotation identity x");
	ok &= ExpectClose(transformed.y_, 2.0f, "Rotation identity y");
	ok &= ExpectClose(transformed.z_, 3.0f, "Rotation identity z");

	return ok;
}
