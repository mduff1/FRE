#pragma once
#include "../Object/StaticObj.h"
#include <iostream>

class Cube : public StaticObj
{
public:
	Cube() : StaticObj()
	{

	}
	Cube(
		std::string _texture, 
		glm::vec3 _initPos,
		glm::vec4 _initRotation,
		double _oScale) : StaticObj(_texture, _initPos, _initRotation, _oScale)
	{
		mesh = new Mesh("Cube.obj");
		shader = new Shader("cube");
		texture = new Texture(_texture.c_str());

	}
	

	~Cube(){}


};
