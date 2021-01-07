#include "Engine.h"
#include <GL/wglew.h>
#include <iostream>
#include <thread>

#define SAFE_DELETE(p) {if(p){delete p;}}

Engine::Engine()
{
	SDLInit();
	createGLWindow("FRE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sWidth, sHeight);
	glewInit();
	glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);
	SDL_CaptureMouse(SDL_TRUE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_WarpMouseInWindow(SDL_GL_GetCurrentWindow(), sWidth / 2, sHeight / 2);
	simulation = new Simulation();
	renderer = new Renderer();
	keyState = SDL_GetKeyboardState(NULL);
}

Engine::~Engine()
{
	clear();
}

void Engine::SDLInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)	
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		screenW = desktop.right;
		screenH = desktop.bottom;

		HWND consoleWindow = GetConsoleWindow();
		//SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		MoveWindow(consoleWindow, 0, 0, screenW / 3, screenH, TRUE);

		std::cout << "SDL INITIALIZED" << std::endl;
		isRunning = true;
	}
	else 
	{
		isRunning = false;
	}
}

int Engine::run()
{
	while (isRunning)
	{
		double newFrame = SDL_GetTicks() / 1000.0;
		double frameTime = (newFrame - currentFrame);
		currentFrame = newFrame;
		accumulator += frameTime;

		SDL_GL_SwapWindow(window);
		handleEvents();
		while (accumulator >= dt)
		{
			simulation->Update(dt, t);
			renderer->Render(dt, simulation->curPE->vPObjects);
			accumulator -= dt;
			t += dt;
		}

	}
	return 0;
}

void Engine::update()
{

}

void Engine::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_WINDOWEVENT)
		{
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
				SDL_GetWindowSize(window, &sWidth, &sHeight);
				glViewport(0, 0, sWidth, sHeight);
				break;
			case SDL_WINDOWEVENT_CLOSE:
				isRunning = false;
				break;
			}
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			SDL_GetMouseState(&cXpos, &cYpos);
			renderer->UpdateCamRot(cXpos, cYpos);
		}
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				isRunning = false;
				break;

				//scene stuff
			case SDLK_1:
			{
				//RigidBody::rigBodAttributes planetAttrib;
				//planetAttrib.mass = 1.0f;
				//planetAttrib.vel = glm::vec3(1.0f, 0.0f, 0.0f);
				//planetAttrib.acc = glm::vec3(0.0f, 0.0f, 0.0f);
				//
				//x += 5;
				//Planet* planet(new Planet("Carbon_03.bmp", glm::vec3(x, 0.0f, 0.0f), glm::vec4(0.5f, 0.0f, 1.0f, 0.0f), 1.0f, planetAttrib));
				//renderer->curScene->AddObject(planet);
			}
				break;

			case SDLK_DELETE:
				//renderer->curScene->RemoveObject();
				break;
			}
		}
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
	}
	//camera movement
	if (keyState[SDL_SCANCODE_A])
	{
		renderer->UpdateCamPos("left", 10 * dt);
	}
	if (keyState[SDL_SCANCODE_D])
	{
		renderer->UpdateCamPos("right", 10 * dt);
	}
	if (keyState[SDL_SCANCODE_W])
	{
		renderer->UpdateCamPos("forward", 10 * dt);
	}
	if (keyState[SDL_SCANCODE_S])
	{
		renderer->UpdateCamPos("backward", 10 * dt);
	}
	


	

}

void Engine::createGLWindow(const char* title, int xpos, int ypos, int width, int height)
{
	window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	SDL_SetWindowPosition(window, screenW / 3, 40);
	sdlRenderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetWindowResizable(window, SDL_TRUE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glContext = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, glContext);

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
}

void Engine::clear()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(sdlRenderer);
	SAFE_DELETE(renderer);
	SDL_Quit();
}