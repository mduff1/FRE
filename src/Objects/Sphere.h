#pragma once
#include <GL/glew.h>
#include "../Object/StaticObj.h"
#include <iostream>

class Sphere : public StaticObj
{
public:
	Sphere() : StaticObj()
	{

	}
	Sphere(
		std::string _texture, 
		glm::vec3 _initPos,
		glm::vec4 _initRotation,
		double _oScale) : StaticObj(_texture, _initPos, _initRotation, _oScale)
	{
		mesh = new Mesh("Sphere.obj");
		shader = new Shader("Sphere");
		texture = new Texture(_texture.c_str());

	}

	~Sphere() {}


};
