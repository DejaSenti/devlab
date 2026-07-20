#ifndef ARTICULATION_HPP
#define ARTICULATION_HPP

#include <memory>
#include <base_joint.hpp>
#include <link.hpp>
#include <vector3.hpp>
#include <transform.hpp>

class Articulation
{
public:
	Articulation(Link link_proximal, Link link_distal, std::unique_ptr<BaseJoint> joint)
		: link_proximal_(link_proximal), link_distal_(link_distal), joint_(std::move(joint)) {}

	Vector3 GetRelativeTransform() const
	{
		Transform joint_transform = joint_->GetRelativeTransform();
		Vector3 proximal_pos = link_proximal_.relative_transform_;
		Vector3 distal_pos = link_distal_.relative_transform_;

		return joint_transform * proximal_pos + distal_pos;
	}

	void SetJointVelocity(float vel)
	{
		joint_->SetVelocity(vel);
	}

	void Update(float dt)
	{
		joint_->UpdateState(dt);
	}

private:
	Link link_proximal_;
	Link link_distal_;
	std::unique_ptr<BaseJoint> joint_;
};

#endif // ARTICULATION_HPP