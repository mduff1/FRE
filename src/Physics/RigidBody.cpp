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

void RigidBody::UpdatePhysics(double _dt, int _timeStep)
{
	if (rBAttributes.simulatePhysics == true)
	{
		timeStep = _timeStep * 0.01;
	

		//position
		glm::dvec3 initPos = rBAttributes.object->GetPos();

		//angular kinematics
		glm::dvec4 initRot = rBAttributes.object->GetRot();
		double initAngle = rBAttributes.angle;
		double initAngAcc = rBAttributes.angAcc;

		//linear kinematics
		glm::dvec3 initVel = rBAttributes.vel;
		glm::dvec3 initAcc = rBAttributes.acc;


		glm::dvec3 finPos = initPos;
		glm::dvec4 finRot = initRot;
		double finAngle = initAngle;
		double finAngAcc = initAngAcc;
		glm::dvec3 finVel = initVel;
		glm::dvec3 finAcc = initAcc;


		//angular kinematic calculations
		finRot[0] += finAngAcc * timeStep;
		finAngle += finRot[0] * timeStep;

		glm::mat4 temp = rBAttributes.object->GetModel();
		glm::mat4 rM;
		
		rM[0][0] = cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius())) + pow(finRot[1], 2) * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius())));
		rM[0][1] = finRot[1] * finRot[2] * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius()))) - finRot[3] * sin(finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		rM[0][2] = finRot[1] * finRot[3] * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius()))) + finRot[2] * sin(finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		rM[0][3] = 0;
		rM[1][0] = finRot[1] * finRot[2] * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius()))) + finRot[3] * sin(finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		rM[1][1] = cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius())) + pow(finRot[2], 2) * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius())));
		rM[1][2] = finRot[2] * finRot[3] * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius()))) - finRot[1] * sin(finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		rM[1][3] = 0;
		rM[2][0] = finRot[1] * finRot[3] * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius()))) - finRot[2] * sin(finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		rM[2][1] = finRot[2] * finRot[3] * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius()))) + finRot[1] * sin(finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		rM[2][2] = cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius())) + pow(finRot[3], 2) * (1 - cos(finRot[0] * timeStep / (rBAttributes.object->GetRadius())));
		rM[2][3] = 0;
		rM[3][3] = 1;
		
		temp = rM * temp;
		
		


	    //linear kinematic calculations
		finVel += rBAttributes.acc * timeStep;
		finPos += (finVel * timeStep);


		rBAttributes.object->SetPos(finPos);
		rBAttributes.object->SetRot(finRot);
		rBAttributes.vel = finVel;

		rBAttributes.object->SetModel(temp);
		rBAttributes.angle = finAngle;

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



//orbital stuff
double RigidBody::GetEcc()
{
	return rBAttributes.oEccentricity;
};

void RigidBody::SetEcc(double _ecc)
{
	rBAttributes.oEccentricity = _ecc;
}
