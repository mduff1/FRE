#include "StaticObj.h"
#include <iostream>
#include <SDL/SDL.h>

#define SAFE_DELETE(p) {if(p){delete p;}}

StaticObj::StaticObj()
{
	
}


StaticObj::StaticObj(std::string _texture, glm::dvec3 _pos, glm::dvec4 _rotation, double _oScale)
{
	pos       = _pos;
	rotation  = _rotation;
	oScale    = _oScale;

	//position
	pos = model[3] = glm::dvec4(pos, 1.0f);

	//scaling
	model[0][0] *= oScale;
	model[0][1] *= oScale;
	model[0][2] *= oScale;
	model[1][0] *= oScale;
	model[1][1] *= oScale;
	model[1][2] *= oScale;
	model[2][0] *= oScale;
	model[2][1] *= oScale;
	model[2][2] *= oScale;
}



StaticObj::~StaticObj()
{
	//deleting pointers
	SAFE_DELETE(mesh);
	SAFE_DELETE(shader);
	SAFE_DELETE(texture);
}

void StaticObj::Update(double dt, int _timeStep)
{
	
}



void StaticObj::Draw(Camera* cam)
{
	//get new window size on rescale
	SDL_GetWindowSize(SDL_GL_GetCurrentWindow(), &sWidth, &sHeight);
	

	if (shader && mesh)
	{
		shader->Use();
		if (texture)
		{
			texture->Use();
		}
		projection = glm::perspective(glm::radians(cam->Zoom), (double)sWidth / (double)sHeight, 1.0, 149000.0);
		glUniformMatrix4fv(glGetUniformLocation(shader->progID, "projection"), 1, GL_FALSE, &projection[0][0]);

		view = cam->GetViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(shader->progID, "view"), 1, GL_FALSE, &view[0][0]);
		

		glUniformMatrix4fv(glGetUniformLocation(shader->progID, "model"), 1, GL_FALSE, &model[0][0]);
		mesh->Draw();
	}

}


//getters and setters
/////////////////////////

//position
glm::dvec3 StaticObj::GetPos()
{
	return pos;
}

void StaticObj::SetPos(glm::dvec3 _pos)
{
	pos = _pos;
}

//rotation
glm::dvec4 StaticObj::GetRot()
{

	return rotation;
}

void StaticObj::SetRot(glm::dvec4 _rot)
{
	rotation = _rot;
}

//scale
double StaticObj::GetScale()
{
	return oScale;
}

void StaticObj::SetScale(double _oScale)
{
	oScale = _oScale;
}






