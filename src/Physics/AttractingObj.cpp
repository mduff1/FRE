#include "AttractingObj.h"



AttractingObj::AttractingObj(
	std::string _texture,
	glm::dvec3 _pos,
	glm::dvec4 _rot,
	double _scale,
	double _radius,
	RigidBody::rigBodAttributes _attrib)
{
	pos = _pos;
	rot = _rot;
	scale = _scale;
	radius = _radius;


	//position
	pos = model[3] = glm::dvec4(pos, 1.0f);

	//scaling
	model[0][0] *= scale;
	model[0][1] *= scale;
	model[0][2] *= scale;
	model[1][0] *= scale;
	model[1][1] *= scale;
	model[1][2] *= scale;
	model[2][0] *= scale;
	model[2][1] *= scale;
	model[2][2] *= scale;

	//temporary rotation application, to be put in a class later

	glm::mat4 rM = glm::mat4(0.0);

	double la = glm::length(glm::dvec3(rot[1], rot[2], rot[3]));

	glm::dvec3 cP = glm::cross(glm::dvec3(rot[1], rot[2], rot[3]), glm::dvec3(0.0, 1.0, 0.0));
	double cPA = glm::acos(glm::dot(glm::dvec3(0.0, 1.0, 0.0), glm::dvec3(rot[1], rot[2], rot[3])) / (1.0 * la));

	if (cP != glm::dvec3(0.0))
	{
		cP = glm::normalize(cP);
	}


	

	double qi = cP[0] * sin(cPA / 2);
	double qj = cP[1] * sin(cPA / 2);
	double qk = cP[2] * sin(cPA / 2);
	double qw = cos(cPA / 2);
	double s = 1 / (pow(qi, 2) + pow(qj, 2) + pow(qk, 2) + pow(qw, 2));


	rM[0][0] = 1 - 2 * s * (pow(qj, 2) + pow(qk, 2));
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

	model = rM * model;
}


//assuming e = 0;
void AttractingObj::CalculateInitialVelocity(AttractingObj* oObject, glm::dvec3 _forceVector, glm::dvec3 _dir)
{
	double distance = length(oObject->GetPos() - this->GetPos());
	rigidBody->SetVel(sqrt((1 / this->rigidBody->GetMass()) * length(_forceVector) * distance) * _dir);
}

//for elliptical orbits


void AttractingObj::Update(double _dt, int _timeStep)
{
	

}
