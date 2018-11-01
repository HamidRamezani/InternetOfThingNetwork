#pragma once
#include "../../nodeCore/header/NodeCore.h"
#include "GlobalHeader.h"

namespace Node {

	class NodeMobileCore :
		public NodeCore
	{
	public:
		NodeMobileCore();
		NodeMobileCore(IdType id);
		NodeMobileCore(IdType id, CoordinateType maxSpeed, CoordinateType maxAcceleration);
		~NodeMobileCore();

		void stepKinematic(TimeType t);
		void stepRandomWalk(TimeType t, CoordinateType speed);
		CoordinateType getCurrentSpeed();
		CoordinateType getCurrentAccelaration();

		void setVelocity(CoordinateType* velocity);
		void getVelocity(CoordinateType* velocity) const;
		void setAcceleration(CoordinateType* acceleration);
		void getAcceleration(CoordinateType* acceleration) const;

	private:
		void controlMaxSpeed(void);
		void controlMaxAccelaration(void);

	private:
		CoordinateType xVelocity = 0.0; // default value 0.0
		CoordinateType yVelocity = 0.0; // default value 0.0
		CoordinateType zVelocity = 0.0; // default value 0.0

		CoordinateType xAcceleration = 0.0; // default value 0.0
		CoordinateType yAcceleration = 0.0; // default value 0.0
		CoordinateType zAcceleration = 0.0; // default value 0.0

		CoordinateType maxSpeed = (CoordinateType)NODE_MAX_POSSIBLE_SPEED_M_PER_SECOND;
		CoordinateType maxAcceleration = (CoordinateType)NODE_MAX_POSSIBLE_ACCELARATION_M_PER_SECOND_SECOND;
	};

}// End of Node