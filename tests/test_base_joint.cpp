#include "test_utils.hpp"

#include <arm_controller/kinematics/base_joint.hpp>
#include <arm_controller/kinematics/prismatic_joint.hpp>
#include <arm_controller/kinematics/rotational_joint.hpp>
#include <arm_controller/math/vector3.hpp>

class TestPrismaticJoint : public PrismaticJoint
{
public:
	using PrismaticJoint::PrismaticJoint;
};

class TestRotationalJoint : public RotationalJoint
{
public:
	using RotationalJoint::RotationalJoint;
};

bool TestBaseJoint()
{
	bool ok = true;

	PrismaticJoint prismatic;
	prismatic.SetVelocity(2.0f);
	prismatic.UpdateState(0.5f);
	ok &= ExpectClose(prismatic.GetState(), 1.0f, "Prismatic joint state update");

	RotationalJoint rotational;
	rotational.SetVelocity(1.0f);
	rotational.UpdateState(0.5f);
	ok &= ExpectClose(rotational.GetState(), 0.5f, "Rotational joint state update");

	return ok;
}
