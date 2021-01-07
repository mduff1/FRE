#pragma once
#include <GL/glew.h>
#include <SDL/SDL.h>

#define GLM_PRECISION_HIGHP_DOUBLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <vector>
#include <memory>
#include "../Model/Shader.h"
#include "../Model/Mesh.h"
#include "../Model/Texture.h"
#include "../Camera/Camera.h"



class PhysObj
{
public:
	PhysObj();

	PhysObj(
		std::string _texture,
		glm::dvec3 _pos,
		glm::dvec4 _rotation,
		double _Scale);

	virtual ~PhysObj();

	virtual void Update(double dt, int _timeStep);


	virtual void Draw(Camera* cam);

	//getters and setters
	/////////////////////////

	//position
	glm::dvec3 GetPos();
	void SetPos(glm::dvec3 _pos);

	//rotation
	glm::dvec4 GetRot();
	void SetRot(glm::dvec4 _rot);

	//scale
	double GetScale();
	void SetScale(double _scale);

	float timeAlive = 0.0f;


protected:
	Shader* shader;
	Mesh* mesh;
	Texture* texture;

	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 view = glm::mat4(1.0);
	glm::mat4 projection = glm::mat4(1.0);

	// window resize event data
	int sWidth;
	int sHeight;

	//attributes
	glm::dvec3 pos;
	glm::vec4 rotation;
	double scale; //in the case of sphere is radius

};