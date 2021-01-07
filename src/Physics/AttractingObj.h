#pragma once
#include "PhysObj.h"
#include "RigidBody.h"


class AttractingObj : public PhysObj
{
public:
	AttractingObj(
		std::string _texture,
		glm::dvec3 _pos,
		glm::dvec4 _rot,
		double _scale,
		RigidBody::rigBodAttributes _attrib);

	~AttractingObj() {};

	void CalculateInitialVelocity(AttractingObj* oObject, glm::dvec3 _forceVector, glm::dvec3 _dir);


	virtual void Update(double dt, int _timeStep) override;

	RigidBody* rigidBody;


};

