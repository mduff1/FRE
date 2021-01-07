#pragma once
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

class Shader
{
public:
	Shader(const char* name);
	~Shader();

	void Use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec2(const std::string& name, glm::vec2 vec) const;
	void setVec3(const std::string& name, glm::vec3 vec) const;
	void setVec4(const std::string& name, glm::vec4 vec) const;
	GLuint progID;

private:

	

	GLuint loadShader(const char* fname, GLenum type);

	std::vector<std::string> attribs;

	GLuint vertID;
	GLuint fragID;

	int sWidth;
	int sHeight;
	
};

