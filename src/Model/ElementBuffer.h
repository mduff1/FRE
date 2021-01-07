#pragma once
#include <GL/glew.h>

class ElementBuffer
{
public:
	ElementBuffer(GLsizeiptr size, const void* data);
	~ElementBuffer();

	void Bind() const;
	void Unbind() const;


	GLuint ebo;

	

};

