#include "stdafx.h"
#include "NodeCore.h"
#include "..\header\NodeCore.h"
#include "limits.h"

NodeCore::NodeCore()
{
	id = UINT_MAX;
}

NodeCore::NodeCore(IdType id) :
id(id)
{
}

NodeCore::~NodeCore()
{
}

IdType NodeCore::getId(void)
{
	return this->id;
}

void NodeCore::setPosition(CoordinateType * position)
{
	xPosition = *position++;
	yPosition = *position++;
	zPosition = *position++;
}

void NodeCore::getAcceleration(CoordinateType* acceleration){
	*acceleration++ = xAcceleration;
	*acceleration++ = yAcceleration;
	*acceleration++ = zAcceleration;
}