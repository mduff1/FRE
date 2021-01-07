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

	virtual void Update(double dt, double t);

	PhysicsEnvironment* curPE;


protected:

	std::vector<PhysicsEnvironment*> physicsEnvironments;


};

