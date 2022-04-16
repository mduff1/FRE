#include "Level1.h"
//#include "../Objects/Cube.h"
//#include "../Objects/Sphere.h"
#include "../Object/Skyboxes/Spacebox.h"
//#include "../Objects/Planet.h"
//#include "../Objects/Plane.h"


void Level1::load()
{
	cam = new Camera(glm::vec3(0.0, 0.0, 1500.0));

	if (cam)
	{
		vCams.push_back(cam);
	}

	//Cube* cube(new Cube("container.jpg", glm::dvec3(0.0, 0.0, 0.0), glm::dvec4(1.0, 0.0, 1.0, 0.0), 10000.0));
	//vObjects.push_back(cube);

	//skybox
	Spacebox* spacebox(new Spacebox(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), 1.0f));
	vSkyboxes.push_back(spacebox);
}
