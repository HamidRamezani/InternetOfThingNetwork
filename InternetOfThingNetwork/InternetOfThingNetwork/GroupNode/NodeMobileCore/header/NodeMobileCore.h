#pragma once
#include "../../nodeCore/header/NodeCore.h"
#include "GlobalHeader.h"

class NodeMobileCore :
	public NodeCore
{
public:
	  NodeMobileCore();
	  NodeMobileCore(IdType id);
	  NodeMobileCore(IdType id, CoordinateType maxSpeed, CoordinateType maxAccelaration);
	  ~NodeMobileCore();

	 void stepKinematic(TimeType t) ;
	 void stepRandomWalk(TimeType t, CoordinateType speed);
	 CoordinateType getCurrentSpeed();	 
	 CoordinateType getCurrentAccelaration();

	 void setVelocity(CoordinateType* velocity);
	 void getVelocity(CoordinateType* velocity);
	 void setAcceleration(CoordinateType* acceleration);
	 void getAcceleration(CoordinateType* acceleration);

private:
	void controlMaxSpeed(void);
	void controlMaxAccelaration(void);

private:
	CoordinateType maxSpeed        = (CoordinateType)NODE_MAX_POSSIBLE_SPEED_M_PER_SECOND;
	CoordinateType maxAccelaration = (CoordinateType)NODE_MAX_POSSIBLE_ACCELARATION_M_PER_SECOND_SECOND;
};

