#pragma once
#ifndef VERTEX_H
#define VERTEX_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;

	Vertex(glm::vec3 pos, glm::vec2 texCoord = glm::vec2(0, 0), glm::vec3 normal = glm::vec3(0, 0, 0)) :
		pos(pos),
		texCoord(texCoord),
		normal(normal) {}
};

#endif