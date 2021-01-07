#include "RigidBody.h"


RigidBody::RigidBody(rigBodAttributes attributes)
{
	rBAttributes = attributes;
}

RigidBody::~RigidBody() 
{

}

void RigidBody::ApplyForce(glm::dvec3 forceVector)
{
	rBAttributes.acc = forceVector / rBAttributes.mass;
}

void RigidBody::UpdatePhysics(double dt, int _timeStep)
{
	if (rBAttributes.simulatePhysics == true)
	{
		timeStep = _timeStep;
		y += dt;
		//z += dt;


		glm::dvec3 initPos = rBAttributes.object->GetPos();
		glm::dvec4 initRot = rBAttributes.object->GetRot();
		glm::dvec3 initVel = rBAttributes.vel;
		glm::dvec3 initAcc = rBAttributes.acc;


		glm::dvec3 finPos = initPos;
		glm::dvec4 finRot = initRot;
		glm::dvec3 finVel = initVel;
		glm::dvec3 finAcc = initAcc;


		//fintAcc = (length(finVel - initVel) / x) * glm::dvec3(0.0,1.0,0.0);
		//
		//
		//rBAttributes.acc = length(glm::dvec3(sqrt(pow(finrAcc[0], 2) + pow(fintAcc[0], 2)),
		//								sqrt(pow(finrAcc[1], 2) + pow(fintAcc[1], 2)),
		//								sqrt(pow(finrAcc[2], 2) + pow(fintAcc[2], 2))))
		//									* normalize(finrAcc + fintAcc);
		//finRot[0] *= simSpeed;



	   
		finVel += rBAttributes.acc * timeStep;
		finPos += (finVel * timeStep);


		//
		//
		//
		//
		//temp = finVel;
		//
		//
		rBAttributes.object->SetPos(finPos);
		rBAttributes.object->SetRot(finRot);
		rBAttributes.vel = finVel;

		stepsTaken.push_back(finPos);
	}
}

double RigidBody::GetMass()
{
	return rBAttributes.mass;
}

glm::dvec3 RigidBody::GetAcc()
{
	return rBAttributes.acc;
}

void RigidBody::SetAcc(glm::dvec3 _acc)
{
	rBAttributes.acc = _acc;
}

glm::dvec3 RigidBody::GetVel()
{
	return rBAttributes.vel;
}

void RigidBody::SetVel(glm::dvec3 _vel)
{
	rBAttributes.vel = _vel;
}