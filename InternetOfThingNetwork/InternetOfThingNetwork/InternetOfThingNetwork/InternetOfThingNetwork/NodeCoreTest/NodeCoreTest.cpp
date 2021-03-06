// NodeCoreTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "GlobalHeader.h"
#include "..\nodeCore\header\NodeCore.h"

int main()
{
	NodeCore node0(0);
	NodeCore node1(1);
	NodeCore *pNode2 = new NodeCore();

	std::cout << "The id of node 0 is " << node0.getId()   << std::endl;
	std::cout << "The id of node 1 is " << node1.getId()   << std::endl;
	std::cout << "The id of node 2 is " << pNode2->getId() << std::endl;
	std::cout << std::endl;
	
	CoordinateType positionOfNode0[3] = {1.4 , 1.2, 5.1};
	node0.setPosition(positionOfNode0);
	std::cout << "The position of node 0 is [" << positionOfNode0[0] << "," << positionOfNode0[1] << "," << positionOfNode0[2] << "]" << std::endl;

	std::cout << std::endl;

	delete pNode2;
	
	std::cout << "Done!\n";
}

