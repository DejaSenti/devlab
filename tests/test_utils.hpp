#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <cmath>
#include <iostream>
#include <string>

#define EPSILON (1e-5f)

inline bool Expect(bool condition, const std::string &message)
{
	if (!condition)
	{
		std::cerr << "[FAIL] " << message << std::endl;
		return false;
	}
	return true;
}

inline bool ExpectClose(float actual, float expected, const std::string &message)
{
	if (std::fabs(actual - expected) > EPSILON)
	{
		std::cerr << "[FAIL] " << message << " expected " << expected << " but got " << actual << std::endl;
		return false;
	}
	return true;
}

#endif // TEST_UTILS_HPP
