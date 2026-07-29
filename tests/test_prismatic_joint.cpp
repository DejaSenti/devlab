#include "test_utils.hpp"

#include <arm_controller/kinematics/prismatic_joint.hpp>
#include <arm_controller/math/vector3.hpp>

bool TestPrismaticJoint()
{
	bool ok = true;

	PrismaticJoint joint(0.0f, -10.0f, 10.0f, 5.0f, Vector3{1.0f, 0.0f, 0.0f});
	joint.SetVelocity(2.0f);
	joint.UpdateState(0.5f);

	Transform transform = joint.GetRelativeTransform();
	ok &= ExpectClose(transform.GetPosition().x_, 1.0f, "Prismatic joint position x");
	ok &= ExpectClose(transform.GetPosition().y_, 0.0f, "Prismatic joint position y");
	ok &= ExpectClose(transform.GetPosition().z_, 0.0f, "Prismatic joint position z");

	return ok;
}
