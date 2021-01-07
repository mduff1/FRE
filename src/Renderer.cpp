#include "Renderer.h"


Renderer::Renderer()
{
	Level1* level1(new Level1);
	scenes.push_back(level1);
	LoadScene(0);
	
}

Renderer::~Renderer()
{
	scenes.clear();
}

void Renderer::Render(double dt, std::vector<PhysObj*> _vPObjects)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//to allow skybox in scene without getting clipped
	glEnable(GL_DEPTH_CLAMP);

	curScene->Update(dt, _vPObjects);
	
}

void Renderer::UpdateCamRot(int mx, int my)
{
	SDL_GetWindowSize(SDL_GL_GetCurrentWindow(), &sWidth, &sHeight);
	if (firstMouse)
	{
		lastX = mx;
		lastY = my;
		firstMouse = false;
	}
	xoffset = mx - lastX;
	yoffset = lastY - my;

	lastX = mx;
	lastY = my;
	
	if (curScene && curScene->cam)
	{
		curScene->cam->ProcessCamRot(xoffset, yoffset);
	}
}

void Renderer::UpdateCamPos(const char* direction, double dt)
{
	if (curScene && curScene->cam)
	{
		if (direction == "left")
		{
			curScene->cam->ProcessCamPos(LEFT, dt);
		}
		else if (direction == "right")
		{
			curScene->cam->ProcessCamPos(RIGHT, dt);

		}
		else if (direction == "forward")
		{
			curScene->cam->ProcessCamPos(FORWARD, dt);

		}
		else if (direction == "backward")
		{
			curScene->cam->ProcessCamPos(BACKWARD, dt);

		}
	}
}
	

void Renderer::LoadScene(int ix)
{
	if (curScene) { curScene->unLoad(); }

	curScene = scenes[ix];
	curScene->load();

}