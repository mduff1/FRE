#pragma once
#include <GL/glew.h>
//#include "../Object/StaticObj.h"
#include "../Physics/Physobj.h"
#include "../Objects/Cube.h"
#include "../Objects/Sphere.h"
#include "../Object/Skyboxes/Skybox.h"
//#include "../Object/Skyboxes/Spacebox.h"
//#include "../Objects/Planet.h"
#include "../Physics/PhysicsEnvironment.h"
#include <cMath>
#include <iostream>
#include <Windows.h>


class Scene
{
public:
	virtual void load() = 0;
	virtual void unLoad() {};

	virtual void Update(double dt, std::vector<PhysObj*> _vPObjects);

	//void AddObject(StaticObj* object);
	//void AddObject(PhysObj* object);

	void RemoveObject();

	bool CheckIfInRange(PhysObj* object1, PhysObj* object2);

	glm::dvec3 CalculateForceVector(glm::dvec3 _distance, PhysObj* object1, PhysObj* object2);

	glm::dvec3 CalculateForceDirection(PhysObj* object1, PhysObj* object2);

	glm::dvec3 DoGravityCalculation(PhysObj* object1, PhysObj* object2);
	
	//time step
	int timeStep = 20840;

	Camera* cam;

	void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	};

protected:
	
	std::vector<Camera*> vCams;
	std::vector<StaticObj*> vObjects;
	std::vector<Skybox*> vSkyboxes;
	

};

