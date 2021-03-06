
#include "pch.h"
#include <iostream>
#include "GlobalHeader.h"
#include "../../NodeMobileCore/header/NodeMobileCore.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace Node;

struct NodeMobileCoreTest : public ::testing::Test {
	NodeMobileCore n;
	IdType         id = 5;
	CoordinateType maxSpeed        = 10;
	CoordinateType maxAcceleration = 0;
	TimeType       stepTime        = 1.0;
	CoordinateType position[3] = { 0, 0, 0 };
	CoordinateType velocity[3] = { 1, 1, 1 };
	CoordinateType acceleration[3] = { 0,0,0 };

	NodeMobileCoreTest() {
		n = NodeMobileCore(id, maxSpeed, maxAcceleration);
		n.setPosition(position);
		n.setVelocity(velocity);
	}

	~NodeMobileCoreTest() {

	}
};

TEST_F(NodeMobileCoreTest, CheckStepKinematic){
	int nSteps = 10;

	CoordinateType gPos0[3];
	CoordinateType gVel0[3];
	CoordinateType gAcc0[3];	

	n.getPosition(gPos0);
	n.getVelocity(gVel0);
	n.getAcceleration(gAcc0);

	for (int i = 0; i < nSteps; i++) {
		n.stepKinematic(stepTime);
	}

	CoordinateType exPos[3];
	TimeType timeDuration = nSteps * stepTime;
	for (int i = 0; i < 3; i++) {
		exPos[i] = gPos0[i] + gVel0[i] * timeDuration + gAcc0[i] * timeDuration*timeDuration;		
	}

	CoordinateType finalPos[3];
	n.getPosition(finalPos);
	

	bool arraysEqual = true;
	for (int i = 0; i < 3; i++) {
		if (exPos[i] != finalPos[i]) {
			arraysEqual = false;
		}
	}
	EXPECT_TRUE(arraysEqual) << "Final position is not the same as the expected one \n";

}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	int gtestResults = RUN_ALL_TESTS();

	return gtestResults;
}

