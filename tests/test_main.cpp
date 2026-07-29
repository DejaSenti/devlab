#include <iostream>

bool TestArticulation();
bool TestBaseJoint();
bool TestLink();
bool TestPrismaticJoint();
bool TestRotation();
bool TestRotationalJoint();
bool TestTransform();
bool TestVector3();

int main()
{
	bool ok = true;

	ok &= TestArticulation();
	ok &= TestBaseJoint();
	ok &= TestLink();
	ok &= TestPrismaticJoint();
	ok &= TestRotation();
	ok &= TestRotationalJoint();
	ok &= TestTransform();
	ok &= TestVector3();

	if (ok)
	{
		std::cout << "All robotics arm controller tests passed." << std::endl;
		return 0;
	}

	std::cerr << "One or more robotics arm controller tests failed." << std::endl;
	return 1;
}
