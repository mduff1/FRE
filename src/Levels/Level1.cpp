#include "Level1.h"
#include "../Objects/Cube.h"
#include "../Objects/Sphere.h"
#include "../Skyboxes/SpaceBox.h"
#include "../Objects/Planet.h"
#include "../Objects/Plane.h"


void Level1::load()
{
	cam = new Camera(glm::vec3(0.0, 0.0, 1500.0));

	if (cam)
	{
		vCams.push_back(cam);
	}

	//Cube* cube(new Cube("Carbon_03.bmp", glm::dvec3(0.0, 0.0, 0.0), glm::dvec4(1.0, 0.0, 1.0, 0.0), 100.0));
	//vObjects.push_back(cube);

	//skybox
	SpaceBox* SpaceBox(new SpaceBox(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), 1.0f));
	vSkyboxes.push_back(SpaceBox);

}
