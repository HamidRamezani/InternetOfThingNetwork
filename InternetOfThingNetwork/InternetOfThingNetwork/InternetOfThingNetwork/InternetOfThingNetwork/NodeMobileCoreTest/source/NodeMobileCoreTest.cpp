
#include "pch.h"
#include <iostream>
#include "GlobalHeader.h"
#include "../../NodeMobileCore/header/NodeMobileCore.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(NodeMobileCoreTest, Test001){
	EXPECT_EQ(true,true);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	NodeMobileCore  mNode0(0);

	CoordinateType position[] = { 1, 2, 3 };
	CoordinateType velocity[] = { 1, 1, 1 };
	TimeType stepTime = 1.0;

	mNode0.setPosition(position);
	mNode0.setVelocity(velocity);

	std::cout << "Node0 position is [" << position[0] << ", " << position[1] << ", " << position[2] << "]" << std::endl;
	std::cout << "Node0 velocity is [" << velocity[0] << ", " << velocity[1] << ", " << velocity[2] << "]" << std::endl;
	std::cout << "Node0 position kinematic steps: \n";
	for (int i = 0; i < 3; i++) {
		mNode0.stepKinematic(stepTime);
		mNode0.getPosition(position);
		std::cout << "	position is [" << position[0] << ", " << position[1] << ", " << position[2] << "]" << std::endl;
	}
	position[0] = 0;
	position[1] = 0;
	position[2] = 0;

	mNode0.setPosition(position);
	CoordinateType speed = 1;
	std::cout << "\n";
	std::cout << "Node0 position is [" << position[0] << ", " << position[1] << ", " << position[2] << "]" << std::endl;
	std::cout << "Node0 speed    is " << speed << "m/s" << std::endl;
	std::cout << "Node0 position randomwalk steps: \n";
	for (int i = 0; i < 3; i++) {
		mNode0.stepRandomWalk(stepTime, speed);
		mNode0.getPosition(position);
		std::cout << "	position is [" << position[0] << ", " << position[1] << ", " << position[2] << "]" << std::endl;
	}
	std::cout << "\n";
	std::cout << "\n";

	int gtestResults = RUN_ALL_TESTS();

	std::cout << "Done!\n";

	return gtestResults;
}

