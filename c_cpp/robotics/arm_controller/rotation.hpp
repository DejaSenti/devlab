#ifndef ROTATION_HPP
#define ROTATION_HPP

#include <array>
#include <vector3.hpp>

struct Rotation
{
	// Array of rows
	std::array<Vector3, 3> matrix_;
};

#endif // ROTATION_HPP