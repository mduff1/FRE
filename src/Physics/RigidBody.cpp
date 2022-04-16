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
		double initAngle   = rBAttributes.angle;
		double initAngAcc  = rBAttributes.angAcc;

		//linear kinematics
		glm::dvec3 initVel = rBAttributes.vel;
		glm::dvec3 initAcc = rBAttributes.acc;


		glm::dvec3 finPos = initPos;
		glm::dvec4 finRot = initRot;
		double finAngle   = initAngle;
		double finAngAcc  = initAngAcc;
		glm::dvec3 finVel = initVel;
		glm::dvec3 finAcc = initAcc;


		//angular kinematic calculations
		//finRot[0] += finAngAcc * timeStep;
		//finAngle += finRot[0] * timeStep;

		glm::mat4 temp = rBAttributes.object->GetModel();
		glm::mat4 rM   = glm::mat4(0.0);

		glm::dvec3 rotN = glm::normalize(glm::dvec3(finRot[1], finRot[2], finRot[3]));
	
		//quat stuff
		double qi = rotN[0] * sin(0.5 * finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		double qj = rotN[1] * sin(0.5 * finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		double qk = rotN[2] * sin(0.5 * finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		double qw = cos(0.5 * finRot[0] * timeStep / (rBAttributes.object->GetRadius()));
		double s  = 1 / (pow(qi, 2) + pow(qj, 2) + pow(qk, 2) + pow(qw, 2));
	
	

		rM[0][0] = 1 - 2 * s *(pow(qj, 2) + pow(qk, 2));
		rM[0][1] = 2 * s * (qi * qj - qk * qw);
		rM[0][2] = 2 * s * (qi * qk + qj * qw);
		rM[0][3] = 0;
		rM[1][0] = 2 * s * (qi * qj + qk * qw);
		rM[1][1] = 1 - 2 * s * (pow(qi, 2) + pow(qk, 2));
		rM[1][2] = 2 * s * (qj * qk - qi * qw);
		rM[1][3] = 0;
		rM[2][0] = 2 * s * (qi * qk - qj * qw);
		rM[2][1] = 2 * s * (qj * qk + qi * qw);
		rM[2][2] = 1 - 2 * s * (pow(qi, 2) + pow(qj, 2));
		rM[2][3] = 0;
		rM[3][3] = 1;
		
		
		temp = rM * temp;
		
		


	    //linear kinematic calculations
		finVel += rBAttributes.acc * timeStep;
		finPos += finVel * timeStep;


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
