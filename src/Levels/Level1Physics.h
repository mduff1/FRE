#pragma once
#include "GL/glew.h"
#include "../Physics/PhysicsEnvironment.h"

class Level1Physics : public PhysicsEnvironment
{
public:
	virtual void load() override;
};

