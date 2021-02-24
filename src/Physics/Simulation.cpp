#include "Simulation.h"


Simulation::Simulation()
{
	Level1Physics* Level1(new Level1Physics);
	physicsEnvironments.push_back(Level1);
	LoadEnvironment(0);

}

Simulation::~Simulation()
{
	physicsEnvironments.clear();
}


void Simulation::Update(double _dt)
{
	if (!isPaused)
	{
		curPE->Update(_dt, runTime);
		runTime += _dt;
	}
}

void Simulation::LoadEnvironment(int i)
{
	if (curPE) { curPE->unLoad(); }

	curPE = physicsEnvironments[i];
	curPE->load();
}
