#include "Level1Physics.h"


void Level1Physics::load()
{
	//////////////////////////////////////////////////////////////
	RigidBody::rigBodAttributes sunAttrib;
	sunAttrib.mass = solarMass;
	sunAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	sunAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	
	Planet* Sun(new Planet("Solar System/2k_sun.jpg", glm::dvec3(0.0, 0.0, 0.0), glm::dvec4(1.0, 0.0, 1.0, 0.0), 109.0, sunAttrib));
	vAObjects.push_back(Sun);
	
	//////////////////////////////////////////////////////////////
	RigidBody::rigBodAttributes mercuryAttrib;
	mercuryAttrib.mass = 0.0553 * earthMass;
	mercuryAttrib.vel = glm::vec3(0.0, 0.0, -7500.0);
	mercuryAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	
	Planet* Mercury(new Planet("Solar System/2k_mercury.jpg", glm::dvec3(0.955 * AU, 0.0, 0.0), glm::dvec4(0.5, 0.0, 1.0, 0.0), 50.0, mercuryAttrib));
	vAObjects.push_back(Mercury);
	//
	////Mercury->CalculateInitialVelocity(Sun, CalculateForceVector(Mercury->GetPos() - Sun->GetPos(), Mercury, Sun), glm::dvec3(0.0, 0.0, -1.0));
	////58.8 km/s 0.307 AU
	////39.0 km/s 0.461 AU
	//
	//////////////////////////////////////////////////////////////
	//RigidBody::rigBodAttributes venusAttrib;
	//venusAttrib.mass = 0.8 * earthMass;
	//venusAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	//venusAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	//
	//Planet* Venus(new Planet("Solar System/2k_venus_atmosphere.jpg", glm::dvec3(0.72 * AU, 0.0, 0.0), glm::dvec4(0.0, 0.0, 1.0, 0.0), 50.0, venusAttrib));
	//vAObjects.push_back(Venus);
	//Venus->CalculateInitialVelocity(Sun, CalculateForceVector(Venus->GetPos() - Sun->GetPos(), Venus, Sun), glm::dvec3(0.0, 0.0, -1.0));
	//
	//
	////////////////////////////////////////////////////////////////
	//RigidBody::rigBodAttributes earthAttrib;
	//earthAttrib.mass = earthMass;
	//earthAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	//earthAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	//
	//Planet* Earth(new Planet("Solar System/2k_earth_daymap.jpg", glm::dvec3(1.0 * AU, 0.0, 0.0), glm::dvec4(0.0, 0.0, 1.0, 0.0), 50.0, earthAttrib));
	//vAObjects.push_back(Earth);
	//Earth->CalculateInitialVelocity(Sun, CalculateForceVector(Earth->GetPos() - Sun->GetPos(), Earth, Sun), glm::dvec3(0.0, 0.0, -1.0));
	//
	//
	////////////////////////////////////////////////////////////////
	//RigidBody::rigBodAttributes marsAttrib;
	//marsAttrib.mass = 0.107 * earthMass;
	//marsAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	//marsAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	//
	//Planet* Mars(new Planet("Solar System/2k_mars.jpg", glm::dvec3(1.52 * AU, 0.0, 0.0), glm::dvec4(0.0, 0.0, 1.0, 0.0), 40.0, marsAttrib));
	//vAObjects.push_back(Mars);
	//Mars->CalculateInitialVelocity(Sun, CalculateForceVector(Mars->GetPos() - Sun->GetPos(), Mars, Sun), glm::dvec3(0.0, 0.0, -1.0));
	//
	////////////////////////////////////////////////////////////////
	//RigidBody::rigBodAttributes jupiterAttrib;
	//jupiterAttrib.mass = 318.0 * earthMass;
	//jupiterAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	//jupiterAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	//
	//Planet* Jupiter(new Planet("Solar System/2k_jupiter.jpg", glm::dvec3(5.03 * AU, 0.0, 0.0), glm::dvec4(0.0, 0.0, 1.0, 0.0), 40.0, jupiterAttrib));
	//vAObjects.push_back(Jupiter);
	//Jupiter->CalculateInitialVelocity(Sun, CalculateForceVector(Jupiter->GetPos() - Sun->GetPos(), Jupiter, Sun), glm::dvec3(0.0, 0.0, -1.0));
	//
	////////////////////////////////////////////////////////////////
	//RigidBody::rigBodAttributes saturnAttrib;
	//saturnAttrib.mass = 95.2 * earthMass;
	//saturnAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	//saturnAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	//
	//Planet* Saturn(new Planet("Solar System/2k_saturn.jpg", glm::dvec3(9.94 * AU, 0.0, 0.0), glm::dvec4(0.0, 0.0, 1.0, 0.0), 40.0, saturnAttrib));
	//vAObjects.push_back(Saturn);
	//Saturn->CalculateInitialVelocity(Sun, CalculateForceVector(Saturn->GetPos() - Sun->GetPos(), Saturn, Sun), glm::dvec3(0.0, 0.0, -1.0));
	//
	////////////////////////////////////////////////////////////////
	//RigidBody::rigBodAttributes unranusAttrib;
	//unranusAttrib.mass = 14.5 * earthMass;
	//unranusAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	//unranusAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	//
	//Planet* Uranus(new Planet("Solar System/2k_uranus.jpg", glm::dvec3(19.7 * AU, 0.0, 0.0), glm::dvec4(0.0, 0.0, 1.0, 0.0), 40.0, unranusAttrib));
	//vAObjects.push_back(Uranus);
	//Uranus->CalculateInitialVelocity(Sun, CalculateForceVector(Uranus->GetPos() - Sun->GetPos(), Uranus, Sun), glm::dvec3(0.0, 0.0, -1.0));
	//
	////////////////////////////////////////////////////////////////
	//RigidBody::rigBodAttributes neptuneAttrib;
	//neptuneAttrib.mass = 17.1 * earthMass;
	//neptuneAttrib.vel = glm::vec3(0.0, 0.0, 0.0);
	//neptuneAttrib.acc = glm::vec3(0.0, 0.0, 0.0);
	//
	//Planet* Neptune(new Planet("Solar System/2k_neptune.jpg", glm::dvec3(29.9 * AU, 0.0, 0.0), glm::dvec4(0.0, 0.0, 1.0, 0.0), 40.0, neptuneAttrib));
	//vAObjects.push_back(Neptune);
	//Neptune->CalculateInitialVelocity(Sun, CalculateForceVector(Neptune->GetPos() - Sun->GetPos(), Neptune, Sun), glm::dvec3(0.0, 0.0, -1.0));


	for (int i = 0; i < vAObjects.size(); i++)
	{
		vPObjects.push_back(vAObjects[i]);
	}
}