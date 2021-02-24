#pragma once
#include <windows.h>
#include <GL/glew.h>
#include <SDL/SDL.h>
#include "Object/StaticObj.h"
#include "Renderer.h"
#include "Objects/Planet.h"
#include "Physics/Simulation.h"

#define GLM_PRECISION_HIGHP_DOUBLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_access.hpp>





class Engine
{
public:
	Engine();
	~Engine();

	int run();
	void update();

	//monitor coordinates
	int screenW;
	int screenH;

	void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	};

private:

	void SDLInit();
	void createGLWindow(const char* title, int xpos, int ypos, int width, int height);
	void handleEvents();
	void clear();

	bool isRunning;

	//physics
	bool simulationRun;


	int sHeight = 680;
	int sWidth = int((16.0 / 9.0) * sHeight);

	//time stuff
	double t = 0.0;
	double dt = 0.01;

	double currentFrame = SDL_GetTicks();
	double accumulator = 0.0;

	//input variables
	const Uint8* keyState;
	int cXpos;
	int cYpos;

	SDL_Window* window;
	SDL_Renderer* sdlRenderer;
	SDL_GLContext glContext;


	Renderer* renderer;

	Simulation* simulation;

};
