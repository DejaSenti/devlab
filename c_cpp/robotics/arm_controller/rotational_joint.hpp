#ifndef ROTATIONAL_JOINT_HPP
#define ROTATIONAL_JOINT_HPP

#include <base_joint.hpp>
#include <transform.hpp>
#include <rotation.hpp>

class RotationalJoint : public BaseJoint
{
public:
	// R =
	// | c + x²(1-c)     xy(1-c) - z s    xz(1-c) + y s |
	// | yx(1-c) + z s   c + y²(1-c)      yz(1-c) - x s |
	// | zx(1-c) - y s   zy(1-c) + x s    c + z²(1-c)   |
	Transform GetRelativeTransform() const
	{
		Rotation rot;
		float c = std::cos(state_);
		float s = std::sin(state_);
		float x = axis_.x_;
		float y = axis_.y_;
		float z = axis_.z_;

		rot.matrix_[0] = Vector3{c + x * x * (1 - c), x * y * (1 - c) - z * s, x * z * (1 - c) + y * s};
		rot.matrix_[1] = Vector3{y * x * (1 - c) + z * s, c + y * y * (1 - c), y * z * (1 - c) - x * s};
		rot.matrix_[2] = Vector3{z * x * (1 - c) - y * s, z * y * (1 - c) + x * s, c + z * z * (1 - c)};

		return Transform(Vector3{0.0f, 0.0f, 0.0f}, rot);
	}
};

#endif // ROTATIONAL_JOINT_HPP