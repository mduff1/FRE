#pragma once
#include <GL/glew.h>
#include "AttractingObj.h"
#include "nonAttractingObj.h"
#include "../Objects/Planet.h"
#include <cMath>
#include <vector>
#include <iostream>
#include <Windows.h>

class PhysicsEnvironment
{
public:
	virtual void load() = 0;
	virtual void unLoad() {};

	virtual void Update(double dt, float runTime);

	//void AddObject(PhysObj* object);
	//void RemoveObject();


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//gravity calculations
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool CheckIfInRange(AttractingObj* object1, AttractingObj* object2);

	glm::dvec3 CalculateForceVector(glm::dvec3 _distance, AttractingObj* object1, AttractingObj* object2);

	glm::dvec3 CalculateForceDirection(AttractingObj* object1, AttractingObj* object2);

	glm::dvec3 DoGravityCalculation(AttractingObj* object1, AttractingObj* object2);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//oribital calculations
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void GetSemiMajorAxis(AttractingObj* object, AttractingObj* centerObject);



	void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	};

	//time step
	int timeStep = 2160000;

	
	std::vector<PhysObj*> vPObjects;
	std::vector<AttractingObj*> vAObjects;
	std::vector<nonAttractingObj*> vNAObjects;

protected:
	double earthMass = 5972200000000000000000000.0; //kg
	double solarMass = 1989000000000000000000000000000.0; //kg

	double solarRadius = 695500000.0; //m
	double earthRadius = 6378000.0; //m

	double AU = 149597870700.0; //m

	double gravityDetectionRadius = 100.0 * AU;
	double gravitationalConstant = 0.0000000000667430; //N * m^2 kg^-2

	double heliocentricGravitationalConstant = 132712440042000000000.0;

	
};





