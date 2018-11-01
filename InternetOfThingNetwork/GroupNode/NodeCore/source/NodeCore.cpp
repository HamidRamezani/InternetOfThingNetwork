#include "stdafx.h"
#include "NodeCore.h"

namespace Node {

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

	void NodeCore::getPosition(CoordinateType* position) const {
		*position++ = xPosition;
		*position++ = yPosition;
		*position++ = zPosition;
	}

}