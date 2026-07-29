#include "test_utils.hpp"

#include <arm_controller/math/vector3.hpp>

bool TestVector3()
{
	bool ok = true;

	Vector3 vector{3.0f, 4.0f, 0.0f};
	Vector3 normalized = vector.Normalized();
	ok &= ExpectClose(normalized.x_, 0.6f, "Vector3 normalized x");
	ok &= ExpectClose(normalized.y_, 0.8f, "Vector3 normalized y");
	ok &= ExpectClose(normalized.z_, 0.0f, "Vector3 normalized z");

	Vector3 scaled = vector * 2.0f;
	ok &= ExpectClose(scaled.x_, 6.0f, "Vector3 scalar multiply x");
	ok &= ExpectClose(scaled.y_, 8.0f, "Vector3 scalar multiply y");
	ok &= ExpectClose(scaled.z_, 0.0f, "Vector3 scalar multiply z");

	Point3 point = static_cast<Point3>(vector);
	ok &= ExpectClose(point.x_, 3.0f, "Point3 conversion x");
	ok &= ExpectClose(point.y_, 4.0f, "Point3 conversion y");
	ok &= ExpectClose(point.z_, 0.0f, "Point3 conversion z");

	return ok;
}
