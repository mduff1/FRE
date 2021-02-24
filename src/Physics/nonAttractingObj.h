#pragma once
#include "PhysObj.h"
#include "RigidBody.h"


class nonAttractingObj : public PhysObj
{
public:
	nonAttractingObj(
		std::string _texture,
		glm::dvec3 _pos,
		glm::dvec4 _rot,
		double _scale,
		RigidBody::rigBodAttributes _attrib)
	{
		mesh = new Mesh("Sphere.obj");
		shader = new Shader("Sphere");
		texture = new Texture(_texture.c_str());
	}

	~nonAttractingObj() {};

	virtual void Update(double _dt, int _timeStep) override;

	RigidBody* rigidBody;

};

