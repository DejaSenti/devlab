#include "test_utils.hpp"

#include <arm_controller/kinematics/rotational_joint.hpp>
#include <arm_controller/math/vector3.hpp>

bool TestRotationalJoint()
{
	bool ok = true;

	RotationalJoint joint(0.0f, -10.0f, 10.0f, 5.0f, Vector3{0.0f, 0.0f, 1.0f});
	joint.SetVelocity(0.0f);
	joint.UpdateState(0.0f);

	Transform transform = joint.GetRelativeTransform();
	ok &= ExpectClose(transform.GetPosition().x_, 0.0f, "Rotational joint position x");
	ok &= ExpectClose(transform.GetPosition().y_, 0.0f, "Rotational joint position y");
	ok &= ExpectClose(transform.GetPosition().z_, 0.0f, "Rotational joint position z");

	return ok;
}
