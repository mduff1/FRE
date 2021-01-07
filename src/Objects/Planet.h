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
		RigidBody::rigBodAttributes _attrib) : AttractingObj(_texture, _pos, _rot, _scale, _attrib)
	{
		pos = _pos;
		rotation = _rot;
		_attrib.object = this;
		scale = _scale;
		rigidBody = new RigidBody(_attrib);

		mesh = new Mesh("Sphere.obj");
		shader = new Shader("Sphere");
		texture = new Texture(_texture.c_str());
	}

	virtual void Update(double dt, int _timeStep) override;

	~Planet() {}


};