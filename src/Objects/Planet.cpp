#include "Planet.h"


void Planet::Update(double dt, int _timeStep)
{
	if (rigidBody)
	{
		rigidBody->UpdatePhysics(dt, _timeStep);
		
	
		//translation
		model[3] = glm::dvec4(pos / pow(10, 8), 1.0);
	
	}
		
}