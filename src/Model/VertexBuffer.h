#pragma once
#include <GL/glew.h>
class VertexBuffer
{
public:
	VertexBuffer(GLsizeiptr size, const void* data);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;


	GLuint vbo;


	

};

