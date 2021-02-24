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
	gotoxy(0, 40);

	std::cout << "Render Time : " << SDL_GetTicks() / 1000.0 << " s" << std::endl;
	gotoxy(0, 40);

};

