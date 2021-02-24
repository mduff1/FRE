#pragma once
#include "PhysicsEnvironment.h"
#include "../Levels/Level1Physics.h"
#include <cMath>
#include <iostream>
#include <Windows.h>


class Simulation
{
public:

	Simulation();

	~Simulation();
	void LoadEnvironment(int i);

	virtual void Update(double dt);

	PhysicsEnvironment* curPE;

	bool isPaused = true;

	float runTime = 0.0f;

protected:

	std::vector<PhysicsEnvironment*> physicsEnvironments;


};

