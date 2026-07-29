#ifndef PRISMATIC_JOINT_HPP
#define PRISMATIC_JOINT_HPP

#include <arm_controller/kinematics/base_joint.hpp>
#include <arm_controller/math/transform.hpp>
#include <arm_controller/math/rotation.hpp>

class PrismaticJoint : public BaseJoint
{
public:
	Transform GetRelativeTransform() const
	{
		return Transform(axis_ * state_, Rotation{});
	}
};

#endif // PRISMATIC_JOINT_HPP