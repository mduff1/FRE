#pragma once
#include <GL/glew.h>
#include <memory>
#include <vector>
#include <string>
#include <map>

#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "../Vertex.h"

class Mesh
{
public:
	Mesh(const std::string& fname);
	~Mesh();

	void Draw();

private:

	std::string m_fname;
	GLuint vao;
	VertexBuffer* vb;
	ElementBuffer* eb;
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

