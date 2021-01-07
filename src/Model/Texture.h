#pragma once
#include <GL/glew.h>
#include <iostream>
#include <vector>

class Texture
{
public:
	Texture(const char* fname);

	Texture(std::vector<std::string> faces);

	virtual ~Texture();

	void Use();
private:
	GLuint texID;
	GLuint cubeMapID;
};

