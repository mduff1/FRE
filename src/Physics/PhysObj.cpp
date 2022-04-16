#include "PhysObj.h"


#define SAFE_DELETE(p) {if(p){delete p;}}

PhysObj::PhysObj()
{

}

PhysObj::PhysObj(
	std::string _texture,
	glm::dvec3 _pos,
	glm::dvec4 _rot,
	double _scale,
	double _radius)
{
	pos = _pos;
	rot = _rot;
	scale = _scale;

	//position
	pos = model[3] = glm::dvec4(pos, 1.0f);

	//scaling
	model[0][0] *= scale;
	model[0][1] *= scale;
	model[0][2] *= scale;
	model[1][0] *= scale;
	model[1][1] *= scale;
	model[1][2] *= scale;
	model[2][0] *= scale;
	model[2][1] *= scale;
	model[2][2] *= scale;

	//temporary rotation application, to be put in a class later

	//glm::mat4 rM = glm::mat4(0.0);
	//
	//double l1 = glm::length(glm::dvec3(0.0, 1.0, 0.0));
	//double la = glm::length(glm::dvec3(rot[1], rot[2], rot[3]));
	//
	//glm::dvec3 cP = glm::cross(glm::dvec3(0.0, 1.0, 0.0), glm::dvec3(rot[1], rot[2], rot[3]));
	//double cPA = glm::acos(glm::dot(glm::dvec3(0.0, 1.0, 0.0), glm::dvec3(rot[1], rot[2], rot[3])) / (l1 * la));
	//
	//
	//double qi = cP[0] * sin(cPA / 2);
	//double qj = cP[1] * sin(cPA / 2);
	//double qk = cP[2] * sin(cPA / 2);
	//double qw = cos(cPA / 2);
	//double s = 1 / (pow(qi, 2) + pow(qj, 2) + pow(qk, 2) + pow(qw, 2));
	//
	//
	//rM[0][0] = 1 - 2 * s * (pow(qj, 2) + pow(qk, 2));
	//rM[0][1] = 2 * s * (qi * qj - qk * qw);
	//rM[0][2] = 2 * s * (qi * qk + qj * qw);
	//rM[0][3] = 0;
	//rM[1][0] = 2 * s * (qi * qj + qk * qw);
	//rM[1][1] = 1 - 2 * s * (pow(qi, 2) + pow(qk, 2));
	//rM[1][2] = 2 * s * (qj * qk - qi * qw);
	//rM[1][3] = 0;
	//rM[2][0] = 2 * s * (qi * qk - qj * qw);
	//rM[2][1] = 2 * s * (qj * qk + qi * qw);
	//rM[2][2] = 1 - 2 * s * (pow(qi, 2) + pow(qj, 2));
	//rM[2][3] = 0;
	//rM[3][3] = 1;
	//
	//model = rM * model;

}

PhysObj::~PhysObj() 
{
	//deleting pointers
	SAFE_DELETE(mesh);
	SAFE_DELETE(shader);
	SAFE_DELETE(texture);

};

void PhysObj::Update(double _dt, int _timeStep) 
{

}


void PhysObj::Draw(Camera* cam)
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
		projection = glm::perspective(glm::radians(cam->Zoom), (double)sWidth / (double)sHeight, 1.0, 149000000000.0);
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
glm::dvec3 PhysObj::GetPos()
{
	return pos;
}

void PhysObj::SetPos(glm::dvec3 _pos)
{
	pos = _pos;
}

//rotation
glm::dvec4 PhysObj::GetRot()
{

	return rot;
}

void PhysObj::SetRot(glm::dvec4 _rot)
{
	rot = _rot;
}

//scale
double PhysObj::GetScale()
{
	return scale;
}

void PhysObj::SetScale(double _scale)
{
	scale = _scale;
}


double PhysObj::GetRadius()
{
	return radius;
}


void PhysObj::SetRadius(double _radius)
{
	radius = _radius;
}




glm::mat4 PhysObj::GetModel()
{
	return model;
}

void PhysObj::SetModel(glm::mat4 _model)
{
	model = _model;
}



