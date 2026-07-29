#include "test_utils.hpp"

#include <arm_controller/kinematics/link.hpp>

bool TestLink()
{
	Link link{Vector3{1.0f, 2.0f, 3.0f}};
	bool ok = true;

	ok &= ExpectClose(link.relative_transform_.x_, 1.0f, 1e-5f, "Link position x");
	ok &= ExpectClose(link.relative_transform_.y_, 2.0f, 1e-5f, "Link position y");
	ok &= ExpectClose(link.relative_transform_.z_, 3.0f, 1e-5f, "Link position z");

	return ok;
}
