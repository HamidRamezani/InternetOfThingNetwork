#pragma once
#include "NodeCore.h"
#include "GlobalHeader.h"
#include "limits.h"

namespace Node {

	class NodeCore
	{
	public:
		NodeCore(IdType id = UINT_MAX);
		~NodeCore();

	public: // Only for logging purposes
		IdType getId(void);
		void setPosition(CoordinateType* position);
		void getPosition(CoordinateType* position) const;

	private:
		IdType id;

	protected:
		CoordinateType xPosition = 0.0; // default value 0.0
		CoordinateType yPosition = 0.0; // default value 0.0
		CoordinateType zPosition = 0.0; // default value 0.0
	};

}