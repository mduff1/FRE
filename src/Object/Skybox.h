#pragma once
#include "../Object/StaticObj.h"
#include <iostream>

class Skybox : public StaticObj
{
public:
	Skybox() : StaticObj() {}
	Skybox(
		glm::vec3 _initPos,
		glm::vec4 _initRotation,
		double _oScale) : StaticObj() {}
	~Skybox() {}


};