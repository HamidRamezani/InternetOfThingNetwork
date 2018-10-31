#pragma once
#include "NodeCore.h"
#include "GlobalHeader.h"

class NodeCore
{
public:
	 NodeCore();
	 NodeCore(IdType id);
	~NodeCore();

public: // Only for logging purposes
	IdType getId(void);
	void setPosition(CoordinateType* position);
	void getPosition(CoordinateType* position);

private:
	IdType id;

protected:
	CoordinateType xPosition = 0.0; // default value 0.0
	CoordinateType yPosition = 0.0; // default value 0.0
	CoordinateType zPosition = 0.0; // default value 0.0

	CoordinateType xVelocity = 0.0; // default value 0.0
	CoordinateType yVelocity = 0.0; // default value 0.0
	CoordinateType zVelocity = 0.0; // default value 0.0

	CoordinateType xAcceleration = 0.0; // default value 0.0
	CoordinateType yAcceleration = 0.0; // default value 0.0
	CoordinateType zAcceleration = 0.0; // default value 0.0

};

