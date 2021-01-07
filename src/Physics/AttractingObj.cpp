#include "AttractingObj.h"



AttractingObj::AttractingObj(
	std::string _texture,
	glm::dvec3 _pos,
	glm::dvec4 _rot,
	double _scale,
	RigidBody::rigBodAttributes _attrib)
{
	pos = _pos;
	rotation = _rot;
	scale = _scale;

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
}



void AttractingObj::CalculateInitialVelocity(AttractingObj* oObject, glm::dvec3 _forceVector, glm::dvec3 _dir)
{
	double distance = length(oObject->GetPos() - this->GetPos());
	rigidBody->SetVel(sqrt((1 / this->rigidBody->GetMass()) * length(_forceVector) * distance) * _dir);
}

void AttractingObj::Update(double dt, int _timeStep)
{
	

}
