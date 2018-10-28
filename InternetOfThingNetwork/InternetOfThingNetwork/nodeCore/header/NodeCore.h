#pragma once

class NodeCore
{
public:
	 NodeCore();
	 NodeCore(int id);
	~NodeCore();

public: // Only for logging purposes
	int  getId(void);
	void getPosition(CoordinateType* position);
	void getVelocity(CoordinateType* velocity);
	void getAcceleration(CoordinateType* acceleration);

private:
	int id;

private:
	CoordinateType xPosition = 0.0;
	CoordinateType yPosition = 0.0;
	CoordinateType zPosition = 0.0;

	CoordinateType xVelocity = 0.0;
	CoordinateType yVelocity = 0.0;
	CoordinateType zVelocity = 0.0;

	CoordinateType xAcceleration = 0.0;
	CoordinateType yAcceleration = 0.0;
	CoordinateType zAcceleration = 0.0;

};

