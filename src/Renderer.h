#pragma once
#include "Scene.h"
#include "Levels/Level1.h"
#include "Camera/Camera.h"


class Renderer
{
public:
	Renderer();
	~Renderer();

	void Render(double dt, std::vector<PhysObj*> _vPObjects);
	void LoadScene(int ix);
	void UpdateCamRot(int mx, int my);
	void UpdateCamPos(const char* direction, double dt);
	

	int sWidth;
	int sHeight;

	
	int lastX = sWidth / 2;
	int lastY = sHeight / 2;
	int xoffset;
	int yoffset;
	bool firstMouse = true;

	Scene* curScene;

protected:
	std::vector<Scene*> scenes;
};

