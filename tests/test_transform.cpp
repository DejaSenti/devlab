#include "test_utils.hpp"

#include <arm_controller/math/rotation.hpp>
#include <arm_controller/math/transform.hpp>
#include <arm_controller/math/vector3.hpp>

bool TestTransform()
{
	bool ok = true;

	Rotation rotation;
	rotation.matrix_[0] = Vector3{1.0f, 0.0f, 0.0f};
	rotation.matrix_[1] = Vector3{0.0f, 1.0f, 0.0f};
	rotation.matrix_[2] = Vector3{0.0f, 0.0f, 1.0f};

	Transform transform(Vector3{1.0f, 2.0f, 3.0f}, rotation);
	ok &= ExpectClose(transform.GetPosition().x_, 1.0f, "Transform position x");
	ok &= ExpectClose(transform.GetPosition().y_, 2.0f, "Transform position y");
	ok &= ExpectClose(transform.GetPosition().z_, 3.0f, "Transform position z");

	Vector3 applied = transform * Vector3{4.0f, 5.0f, 6.0f};
	ok &= ExpectClose(applied.x_, 5.0f, "Transform vector application x");
	ok &= ExpectClose(applied.y_, 7.0f, "Transform vector application y");
	ok &= ExpectClose(applied.z_, 9.0f, "Transform vector application z");

	return ok;
}
