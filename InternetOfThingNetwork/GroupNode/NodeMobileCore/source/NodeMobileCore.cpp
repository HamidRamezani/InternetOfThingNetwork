#include "stdafx.h"
#include "NodeMobileCore.h"
#include "math.h"
#include <stdlib.h>

namespace Node {

	NodeMobileCore::NodeMobileCore()
		:NodeCore()
	{

	}

	NodeMobileCore::NodeMobileCore(IdType id)
		: NodeCore(id)
	{
	}

	NodeMobileCore::NodeMobileCore(IdType id, CoordinateType maxSpeed, CoordinateType maxAcceleration)
		: NodeCore(id), maxSpeed(maxSpeed), maxAcceleration(maxAcceleration)
	{

	}

	NodeMobileCore::~NodeMobileCore()
	{
	}

	void NodeMobileCore::setVelocity(CoordinateType * velocity)
	{
		xVelocity = *velocity++;
		yVelocity = *velocity++;
		zVelocity = *velocity++;
	}

	void NodeMobileCore::setAcceleration(CoordinateType * acceleration)
	{
		xAcceleration = *acceleration++;
		yAcceleration = *acceleration++;
		zAcceleration = *acceleration++;
	}

	void NodeMobileCore::getAcceleration(CoordinateType* acceleration) const {
		*acceleration++ = xAcceleration;
		*acceleration++ = yAcceleration;
		*acceleration++ = zAcceleration;
	}

	void NodeMobileCore::getVelocity(CoordinateType* velocity) const {
		*velocity++ = xVelocity;
		*velocity++ = yVelocity;
		*velocity++ = zVelocity;
	}

	void NodeMobileCore::controlMaxSpeed()
	{
		CoordinateType currentSpeed = this->getCurrentSpeed();
		if (currentSpeed > this->maxSpeed) {
			CoordinateType normalizationFactor = this->maxSpeed / currentSpeed;
			this->xVelocity /= normalizationFactor;
			this->yVelocity /= normalizationFactor;
			this->zVelocity /= normalizationFactor;
		}
	}

	void NodeMobileCore::controlMaxAccelaration(void)
	{
		CoordinateType currentAccelaration = this->getCurrentAccelaration();
		if (currentAccelaration > this->maxAcceleration) {
			CoordinateType normalizationFactor = this->maxAcceleration / currentAccelaration;
			this->xAcceleration /= normalizationFactor;
			this->yAcceleration /= normalizationFactor;
			this->zAcceleration /= normalizationFactor;
		}
	}

	void NodeMobileCore::stepKinematic(TimeType t)
	{
		// update positions
		this->xPosition += this->xVelocity * (CoordinateType)t;
		this->yPosition += this->yVelocity * (CoordinateType)t;
		this->zPosition += this->zVelocity * (CoordinateType)t;

		// update velocity 
		this->xVelocity += this->xAcceleration * (CoordinateType)t;
		this->yVelocity += this->yAcceleration * (CoordinateType)t;
		this->zVelocity += this->zAcceleration * (CoordinateType)t;

		// control maximum speed
		this->controlMaxSpeed();
	}

	/*
	randomWalkStep moves the node at random direction with distance t*speed
	*/
	void NodeMobileCore::stepRandomWalk(TimeType t, CoordinateType speed)
	{

		CoordinateType randX = (CoordinateType)rand() / (CoordinateType)RAND_MAX;
		CoordinateType randY = (CoordinateType)rand() / (CoordinateType)RAND_MAX;
		CoordinateType randZ = (CoordinateType)rand() / (CoordinateType)RAND_MAX;

		CoordinateType randNorm = sqrt(randX * randX + randY * randY + randZ * randZ);

		this->xPosition += randX / randNorm * (CoordinateType)t * speed;
		this->yPosition += randY / randNorm * (CoordinateType)t * speed;
		this->zPosition += randZ / randNorm * (CoordinateType)t * speed;

	}

	CoordinateType NodeMobileCore::getCurrentSpeed()
	{
		CoordinateType speed = sqrt(
			this->xVelocity*this->xVelocity +
			this->yVelocity*this->yVelocity +
			this->zVelocity*this->zVelocity);
		return speed;
	}

	CoordinateType NodeMobileCore::getCurrentAccelaration()
	{
		CoordinateType accelaration = sqrt(
			this->xAcceleration*this->xAcceleration +
			this->yAcceleration*this->yAcceleration +
			this->zAcceleration*this->zAcceleration);
		return accelaration;
	}

}//end of Node