#include "stdafx.h"
#include "NodeCore.h"
#include "..\header\NodeCore.h"


NodeCore::NodeCore()
{
}

NodeCore::NodeCore(int id) : 
id(id)
{
}

NodeCore::~NodeCore()
{
}

int NodeCore::getId(void)
{
	return this->id;
}

void NodeCore::getPosition(CoordinateType* position){
	*position++ = xPosition;
	*position++ = yPosition;
	*position++ = zPosition;
}

void NodeCore::getVelocity(CoordinateType* velocity){
	*velocity++ = xVelocity;
	*velocity++ = yVelocity;
	*velocity++ = zVelocity;
}

void NodeCore::getAcceleration(CoordinateType* acceleration){
	*acceleration++ = xAcceleration;
	*acceleration++ = yAcceleration;
	*acceleration++ = zAcceleration;
}