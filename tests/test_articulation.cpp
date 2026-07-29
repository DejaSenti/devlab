#include "test_utils.hpp"

#include <arm_controller/kinematics/articulation.hpp>
#include <arm_controller/kinematics/prismatic_joint.hpp>
#include <arm_controller/kinematics/rotational_joint.hpp>
#include <memory>

bool TestArticulation()
{
	bool ok = true;

	Link proximal{Vector3{1.0f, 0.0f, 0.0f}};
	Link distal{Vector3{0.0f, 2.0f, 0.0f}};
	std::unique_ptr<BaseJoint> joint = std::make_unique<PrismaticJoint>(0.0f, -10.0f, 10.0f, 5.0f, Vector3{1.0f, 0.0f, 0.0f});

	Articulation articulation(proximal, distal, std::move(joint));
	articulation.SetJointVelocity(1.0f);
	articulation.Update(1.0f);

	Vector3 relative = articulation.GetRelativeTransform();
	ok &= ExpectClose(relative.x_, 1.0f, 1e-5f, "Articulation relative transform x");
	ok &= ExpectClose(relative.y_, 2.0f, 1e-5f, "Articulation relative transform y");
	ok &= ExpectClose(relative.z_, 0.0f, 1e-5f, "Articulation relative transform z");

	return ok;
}
