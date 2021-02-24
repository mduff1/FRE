#pragma once
#include "../Physics/AttractingObj.h"
#include <iostream>

class Planet : public AttractingObj
{
public:
	Planet(
		std::string _texture,
		glm::dvec3 _pos,
		glm::dvec4 _rot,
		double _scale,
		double _radius,
		RigidBody::rigBodAttributes _attrib) : AttractingObj(_texture, _pos, _rot, _scale, _radius, _attrib)
	{
		pos = _pos;
		rotation = _rot;
		_attrib.object = this;
		scale = _scale;
		radius = _radius;
		rigidBody = new RigidBody(_attrib);

		mesh = new Mesh("Sphere.obj");
		shader = new Shader("Sphere");
		texture = new Texture(_texture.c_str());


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

	virtual void Update(double dt, int _timeStep) override;

	~Planet() {}


};