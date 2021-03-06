// NodeCoreTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "GlobalHeader.h"
#include "../NodeCore/header/NodeCore.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace Node;

TEST(NodeCoreTest, EmptyContructor) {
	NodeCore n;	
	EXPECT_TRUE(n.getId(), UINT_MAX);
}

TEST(NodeCoreTest, SetConstructor) {
	IdType id = 10;
	NodeCore* n = new NodeCore(id);	
	EXPECT_EQ(n->getId(), id);	
	delete n;
}

TEST(NodeCoreTest, SetPosition) {
	IdType id = 10;
	CoordinateType sPos[3] = { 0.1, 1.2, 3.2 };
	CoordinateType gPos[3] = { 0.1, 1.2, 3.2 };

	NodeCore* n = new NodeCore(id);
	n->setPosition(sPos);
	n->getPosition(gPos);

	bool arraysEqual;
	for (int i = 0; i < 3; i++) {
		if (sPos[i] != gPos[i]) {
			arraysEqual = false;
		}
	}
	EXPECT_TRUE(arraysEqual) << "set position is not the same as get position \n";

	delete n;
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	
	int gtestResults = RUN_ALL_TESTS();

	return gtestResults;
}

