#include "Scene.h"

//normal objects
//void Scene::AddObject(StaticObj* object)
//{
//	vObjects.push_back(object);
//}
//
//void Scene::AddObject(PhysObj* object)
//{
//	vPObjects.push_back(object);
//}
//
//
//void Scene::RemoveObject()
//{
//	if (vObjects.empty() && vPObjects.empty()) return;
//
//	vObjects.erase(vObjects.end() - 1);
//	vPObjects.erase(vPObjects.end() - 1);
//}


void Scene::Update(double dt, std::vector<PhysObj*> _vPObjects)
{
	//static objects
	for (int i = 0; i < vObjects.size(); i++)
	{
		vObjects[i]->Update(dt, timeStep);
		vObjects[i]->Draw(cam);
	}

	//physics objects
	for (int i = 0; i < _vPObjects.size(); i++)
	{
		_vPObjects[i]->Draw(cam);
	}
	
	//skybox
	vSkyboxes[0]->Update(dt, timeStep);
	vSkyboxes[0]->Draw(cam);

	//console updates
	gotoxy(0, 27);

	std::cout << "Render Time : " << SDL_GetTicks() / 1000.0 << " s" << std::endl;

	//std::cout << std::endl;
	//std::cout << std::endl;
	//std::cout << "###########################################################################################" << std::endl;
	//
	//
	//std::cout << "Solar Total Velocity: " << length(vPObjects[0]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Mercury Total Velocity: " << length(vPObjects[1]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Venus Total Velocity: " << length(vPObjects[2]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Earth Total Velocity: " << length(vPObjects[3]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Mars Total Velocity: " << length(vPObjects[4]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Jupiter Total Velocity: " << length(vPObjects[5]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Saturn Total Velocity: " << length(vPObjects[6]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Uranus Total Velocity: " << length(vPObjects[7]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//std::cout << "Neptune Total Velocity: " << length(vPObjects[8]->rigidBody->GetVel()) / 1000.0 << " km/s " << std::endl;
	//
	//std::cout << std::endl;
	//
	////////////////////////////////////////////////////////////////////////
	//std::cout << std::endl;
	//
	//std::cout << "Distance Between Mercury and Sun: " << length((vPObjects[1]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Venus and Sun: " << length((vPObjects[2]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Earth and Sun: " << length((vPObjects[3]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Mars and Sun: " << length((vPObjects[4]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Jupiter and Sun: " << length((vPObjects[5]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Saturn and Sun: " << length((vPObjects[6]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Uranus and Sun: " << length((vPObjects[7]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//std::cout << "Distance Between Neptune and Sun: " << length((vPObjects[8]->GetPos() - vPObjects[0]->GetPos())) / AU << " Au" << std::endl;
	//
	////////////////////////////////////////////////////////////////////////
	//std::cout << std::endl;
	//
	//std::cout << "Distance from Origin: " << length(vCams[0]->Position) / (AU * (pow(10, -8))) << " Au" << std::endl;
	//std::cout << "Elapsed Time : " << dt << " s" << std::endl;
	//std::cout << "Simulation Speed : " << timeStep << " s/s" << std::endl;
	//
	////////////////////////////////////////////////////////////////////////
	//std::cout << std::endl;
	//
	//
	//
	//
	gotoxy(0, 27);


};

