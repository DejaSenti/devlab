#ifndef BASE_JOINT_HPP
#define BASE_JOINT_HPP

#include <arm_controller/math/vector3.hpp>
#include <arm_controller/math/transform.hpp>

class BaseJoint
{
private:
	static constexpr float DEFAULT_STATE = 1000.0f;
	static constexpr Vector3 DEFAULT_AXIS = Vector3{0.0f, 0.0f, 1.0f};

public:
	BaseJoint(float initial_state = 0.0f, float min_state = -DEFAULT_STATE, float max_state = DEFAULT_STATE,
			  float max_velocity = DEFAULT_STATE, Vector3 axis = DEFAULT_AXIS)
		: state_(initial_state),
		  min_state_(min_state),
		  max_state_(max_state),
		  velocity_(0.0f),
		  max_velocity_(max_velocity),
		  axis_(axis.Normalized()) {}

	virtual ~BaseJoint() = default;

	float GetState() const
	{
		return state_;
	}

	void SetVelocity(float vel)
	{
		if (vel > max_velocity_)
			velocity_ = max_velocity_;
		else if (vel < -max_velocity_)
			velocity_ = -max_velocity_;
		else
			velocity_ = vel;
	}

	void UpdateState(float dt)
	{
		state_ += velocity_ * dt;
		if (state_ > max_state_)
			state_ = max_state_;
		else if (state_ < min_state_)
			state_ = min_state_;
	}

	virtual Transform GetRelativeTransform() const = 0;

protected:
	Vector3 axis_;
	float state_; // rad or m
	float min_state_;
	float max_state_;

	float velocity_; // rad/s or m/s
	float max_velocity_;
};

#endif // BASE_JOINT_HPP