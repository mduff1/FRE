#pragma once
#include "../Object/StaticObj.h"
#include <iostream>

class Plane : public StaticObj
{
public:
	Plane(
		std::string _texture,
		glm::vec3 _pos,
		glm::vec4 _rotation,
		double _oScale) : StaticObj(_texture, _pos, _rotation, _oScale)
	{
		mesh = new Mesh("Plane.obj");
		shader = new Shader("Sphere");
		texture = new Texture(_texture.c_str());

		model = glm::rotate(model, glm::radians(rotation[0]), glm::vec3(rotation[1], rotation[2], rotation[3]));

	}

	virtual void Update(double dt, int _timeStep) override;


	~Plane() {}


};

