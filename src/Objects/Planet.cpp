#include "Planet.h"


void Planet::Update(double dt, int _timeStep)
{
	if (rigidBody)
	{
		rigidBody->UpdatePhysics(dt, _timeStep);
		
	
		//translation
		model[3] = glm::dvec4(pos / pow(10, 8), 1.0);
	
	
		//rotation
		//model = glm::rotate(model, glm::radians(rotation[0]), glm::vec3(rotation[1], rotation[2], rotation[3]));
	}
		
}