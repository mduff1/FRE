#pragma once
#include "Skybox.h"
#include <iostream>

class Spacebox : public Skybox
{
public:
	Spacebox(
		glm::vec3 _initPos,
		glm::vec4 _initRotation,
		double _oScale) : Skybox(_initPos, _initRotation, _oScale)
	{
		mesh = new Mesh("Skybox.obj");
		shader = new Shader("Skybox");

		std::vector<std::string> faces
		{
				"Skybox/MilkywaySkybox/MWpositiveX.jpg",
				"Skybox/MilkywaySkybox/MWnegativeX.jpg",
				"Skybox/MilkywaySkybox/MWpositiveY.jpg",
				"Skybox/MilkywaySkybox/MWnegativeY.jpg",
				"Skybox/MilkywaySkybox/MWpositiveZ.jpg",
				"Skybox/MilkywaySkybox/MWnegativeZ.jpg"
		};

		texture = new Texture(faces);

	}
	~Spacebox() {}


}; 
