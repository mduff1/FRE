#include "PhysicsEnvironment.h"

//void PhysicsEnvironment::AddObject(PhysObj* object)
//{
//	vPObjects.push_back(object);
//}
//
//
//void PhysicsEnvironment::RemoveObject()
//{
//	if (vPObjects.empty()) return;
//
//	vPObjects.erase(vPObjects.end() - 1);
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//gravity calculations
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PhysicsEnvironment::CheckIfInRange(AttractingObj* object1, AttractingObj* object2)
{
	return glm::length(object2->GetPos() - object1->GetPos()) < gravityDetectionRadius;
}

glm::dvec3 PhysicsEnvironment::DoGravityCalculation(AttractingObj* object1, AttractingObj* object2)
{
	glm::dvec3 distance = object1->GetPos() - object2->GetPos();

	glm::dvec3 forceVector;

	if (glm::length(distance) > 0.3)
	{
		return CalculateForceVector(distance, object1, object2);
	}
	else
	{
		object1->rigidBody->SetVel(glm::dvec3(0.0));
		object2->rigidBody->SetVel(glm::dvec3(0.0));

		object1->rigidBody->SetAcc(glm::dvec3(0.0));
		object2->rigidBody->SetAcc(glm::dvec3(0.0));
		object1->SetPos(object2->GetPos());
	}
}

glm::dvec3 PhysicsEnvironment::CalculateForceVector(glm::dvec3 distance, AttractingObj* object1, AttractingObj* object2)
{
	return -(((gravitationalConstant * object1->rigidBody->GetMass() * object2->rigidBody->GetMass()) * (1 / pow(length(distance), 3))) * distance);
}

glm::dvec3 PhysicsEnvironment::CalculateForceDirection(AttractingObj* object1, AttractingObj* object2)
{
	return normalize(glm::dvec3(object2->GetPos() - object1->GetPos()));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void PhysicsEnvironment::Update(double dt, double t)
{

	//physics objects
	//adding forces to each object and updating data
	for (int i = 0; i < vAObjects.size(); i++)
	{

		glm::dvec3 totalForce = glm::dvec3(0.0);
		if (vAObjects.size() > 1)
		{
			for (int j = 0; j < vAObjects.size(); j++)
			{
				if (CheckIfInRange(vAObjects[i], vAObjects[j]))
				{
					if (i != j)
					{
						totalForce += DoGravityCalculation(vAObjects[i], vAObjects[j]);
					}
				}
			}
		}
		
		vAObjects[i]->rigidBody->ApplyForce(totalForce);
		vAObjects[i]->Update(dt, timeStep);

	}

	//updating non attracting objects
	for (int i = 0; i < vNAObjects.size(); i++)
	{
		vNAObjects[i]->Update(dt, timeStep);
	}



	//console updates
	gotoxy(0, 1);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "###########################################################################################" << std::endl;
	
	
	std::cout << "Solar Total Velocity: " << length(vAObjects[0]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	std::cout << "Mercury Total Velocity: " << length(vAObjects[1]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Venus Total Velocity: " << length(vAObjects[2]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Earth Total Velocity: " << length(vAObjects[3]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Mars Total Velocity: " << length(vAObjects[4]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Jupiter Total Velocity: " << length(vAObjects[5]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Saturn Total Velocity: " << length(vAObjects[6]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Uranus Total Velocity: " << length(vAObjects[7]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Neptune Total Velocity: " << length(vAObjects[8]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	
	std::cout << std::endl;
	
	//////////////////////////////////////////////////////////////////////
	std::cout << std::endl;
	
	std::cout << "Distance Between Mercury and Sun: " << length((vAObjects[1]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Venus and Sun: " << length((vAObjects[2]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Earth and Sun: " << length((vAObjects[3]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Mars and Sun: " << length((vAObjects[4]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Jupiter and Sun: " << length((vAObjects[5]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Saturn and Sun: " << length((vAObjects[6]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Uranus and Sun: " << length((vAObjects[7]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Neptune and Sun: " << length((vAObjects[8]->GetPos() - vAObjects[0]->GetPos())) / AU << " Au" << std::endl;
	
	//////////////////////////////////////////////////////////////////////
	std::cout << std::endl;
	
	std::cout << "Simulation Time : " << t << " s" << std::endl;
	//std::cout << "Elapsed Time : " << SDL_GetTicks() / 1000.0 << " s" << std::endl;

	std::cout << "Simulation Speed : " << timeStep << " s/s" << std::endl;
	
	//////////////////////////////////////////////////////////////////////
	std::cout << std::endl;
	
	
	
	
	gotoxy(0, 2);

}
