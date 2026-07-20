#ifndef PRISMATIC_JOINT_HPP
#define PRISMATIC_JOINT_HPP

#include <base_joint.hpp>
#include <transform.hpp>
#include <rotation.hpp>

class PrismaticJoint : public BaseJoint
{
public:
	Transform GetRelativeTransform() const
	{
		return Transform(axis_ * state_, Rotation{});
	}
};

#endif // PRISMATIC_JOINT_HPP