#pragma once


#define GLM_PRECISION_HIGHP_DOUBLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <vector>
#include <SDL/SDL.h>
#include "PhysObj.h"





class RigidBody
{
public:

	struct rigBodAttributes {
		//glm::dvec3 initVel;
		//glm::dvec3 initAcc;
		//glm::dvec4 initRotation;

		glm::dvec3 vel;
		glm::dvec3 acc;

		double angle = 0.0;
		double angAcc = 0.0;

		//physical attributes
		double mass;
		double density;

		//orbital characterisitics
		double oEccentricity;
		double oSemiMajorAxis;
		double oPeriod;

	


		PhysObj* object;

		bool simulatePhysics = true;

	};


	RigidBody(rigBodAttributes attributes);
	~RigidBody();

	void ApplyForce(glm::dvec3 forceVector);
	virtual void UpdatePhysics(double _dt, int _timeStep);


	//getters and setters

	//acceleration
	glm::dvec3 GetAcc();
	void SetAcc(glm::dvec3 _acc);

	//velocity
	glm::dvec3 GetVel();
	void SetVel(glm::dvec3 _Vel);

	//scale
	double GetScale();
	void SetScale(double _scale);

	//mass
	double GetMass();
	void SetMass(double _mass);

	//eccentricity
	double GetEcc();
	void SetEcc(double _ecc);




	double timeStep;

	std::vector<glm::vec3> stepsTaken;

protected:

	rigBodAttributes rBAttributes;
	
	 
	double x = 0;
	double y = 0;
	double z = 0;

};


