#include <iostream>

int main()
{
	std::cout << "Hello, Robotics Arm Controller!" << std::endl;
	return 0;
}

class BaseJoint
{
public:
	BaseJoint(float initial_state, float min_state, float max_state, float max_velocity, Vector3 axis)
		: state_(initial_state),
		  min_state_(min_state),
		  max_state_(max_state),
		  velocity_(0.0f),
		  max_velocity_(max_velocity),
		  axis_(axis) {}

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

private:
	Vector3 axis_;
	float state_; // rad or m
	float min_state_;
	float max_state_;

	float velocity_; // rad/s or m/s
	float max_velocity_;
};

class RotationalJoint : public BaseJoint
{
public:
	Transform GetRelativeTransform() const
	{
	}
};

class PrismaticJoint : public BaseJoint
{
public:
	Transform GetRelativeTransform() const
	{
	}
};

struct Vector3
{
	float x_;
	float y_;
	float z_;

	operator Point3() const
	{
		return Point3{x_, y_, z_};
	}
};

struct Point3 : public Vector3
{
};

struct Rotation
{
	// Vector of 3 rows
	std::array<Vector3, 3> matrix_;
};

Vector3 operator+(const Vector3 &a, const Vector3 &b)
{
	return Vector3{a.x_ + b.x_, a.y_ + b.y_, a.z_ + b.z_};
}

Vector3 operator*(const Rotation &rot, const Vector3 &v)
{
	return Vector3{
		rot.matrix_[0].x_ * v.x_ + rot.matrix_[0].y_ * v.y_ + rot.matrix_[0].z_ * v.z_,
		rot.matrix_[1].x_ * v.x_ + rot.matrix_[1].y_ * v.y_ + rot.matrix_[1].z_ * v.z_,
		rot.matrix_[2].x_ * v.x_ + rot.matrix_[2].y_ * v.y_ + rot.matrix_[2].z_ * v.z_};
}

Rotation operator*(const Rotation &a, const Rotation &b)
{
	Rotation result;
	for (int i = 0; i < 3; ++i)
	{
		result.matrix_[i] = a * b.matrix_[i];
	}

	return result;
}

class Transform
{
public:
	Transform(const Vector3 &pos, const Rotation &rot)
		: position_(pos), rotation_(rot) {}

	Vector3 GetPosition() const
	{
		return position_;
	}

	Rotation GetRotation() const
	{
		return rotation_;
	}

	static Transform Inverse(const Transform &t)
	{
	}

	friend Transform operator*(const Transform &t, const Transform &t_other);
	friend Vector3 operator*(const Transform &t, const Vector3 &v);
	friend Point3 operator*(const Transform &t, const Point3 &p);

private:
	Vector3 position_;
	Rotation rotation_; // 3x3 rotation matrix
};

Transform operator*(const Transform &t, const Transform &t_other)
{
	return Transform(t.position_ + t.rotation_ * t_other.position_, t.rotation_ * t_other.rotation_);
}

Vector3 operator*(const Transform &t, const Vector3 &v)
{
	return t.position_ + t.rotation_ * v;
}

Point3 operator*(const Transform &t, const Point3 &p)
{
	return t.position_ + static_cast<Vector3>(p);
}

struct Link
{
	Vector3 relative_transform_;
};

class Articulation
{
public:
	Articulation(Link link_proximal, Link link_distal, std::unique_ptr<BaseJoint> joint)
		: link_proximal_(link_proximal), link_distal_(link_distal), joint_(std::move(joint)) {}

	Vector3 GetRelativeTransform() const
	{
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