#include "Shader.h"
#include <fstream>
#include <sstream>


Shader::Shader(const char* name) {
    //Get the file paths
    const std::string vert = "Shaders/" + std::string(name) + ".vert";
    const std::string frag = "Shaders/" + std::string(name) + ".frag";

    //Load the shaders from disk
    vertID = loadShader(vert.c_str(), GL_VERTEX_SHADER);
    fragID = loadShader(frag.c_str(), GL_FRAGMENT_SHADER);

    //Create the program
    progID = glCreateProgram();
    glAttachShader(progID, vertID);
    glAttachShader(progID, fragID);

    //Bind variables
    for (size_t i = 0; i < attribs.size(); ++i) {
        glBindAttribLocation(progID, (GLuint)i, attribs[i].c_str());
    }

    //Link the program
    glLinkProgram(progID);

    //Check for linking errors
    GLint isLinked;
    glGetProgramiv(progID, GL_LINK_STATUS, &isLinked);
    if (!isLinked) {
        GLint logLength;
        glGetProgramiv(progID, GL_INFO_LOG_LENGTH, &logLength);

        std::vector<GLchar> log;
        log.resize(logLength);
        glGetProgramInfoLog(progID, logLength, &logLength, log.data());

        std::ofstream fout(std::string(vert) + ".link.log");
        fout.write(log.data(), logLength);

        progID = 0;
        return;
    }

   
}

Shader::~Shader()
{
    glDetachShader(progID, vertID);
    glDetachShader(progID, fragID);
    glDeleteProgram(progID);
    glDeleteShader(vertID);
    glDeleteShader(fragID);
}

void Shader::Use()
{
    glUseProgram(progID);
}

GLuint Shader::loadShader(const char* fname, GLenum type) {
    //Read shader source from disk
    std::ifstream fin(fname);
    std::stringstream buff;
    buff << fin.rdbuf();
    const std::string str = buff.str();
    const char* source = str.c_str();

    //Create and compile shader
    const GLuint id = glCreateShader(type);
    glShaderSource(id, 1, (const GLchar**)&source, 0);
    glCompileShader(id);

    //Check to make sure there were no errors
    GLint isCompiled = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
    if (!isCompiled) {
        GLint logLength;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);

        std::vector<GLchar> log;
        log.resize(logLength);
        glGetShaderInfoLog(id, logLength, &logLength, log.data());

        std::ofstream fout(std::string(fname) + ".log");
        fout.write(log.data(), logLength);
        return 0;
    }

    //Save variable bindings
    if (type == GL_VERTEX_SHADER) {
        size_t ix = 0;
        while (true) {
            ix = str.find("\nin ", ix);
            if (ix == std::string::npos) {
                break;
            }
            ix = str.find(";", ix);
            size_t start_ix = ix;
            while (str[--start_ix] != ' ');
            attribs.push_back(str.substr(start_ix + 1, ix - start_ix - 1));
        }
    }

    //Return the shader id
    return id;
}

void Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(progID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(progID, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(progID, name.c_str()), value);
}
void Shader::setVec2(const std::string& name, glm::vec2 vec) const
{
    glUniform2f(glGetUniformLocation(progID, name.c_str()), vec.x, vec.y);
}
void Shader::setVec3(const std::string& name, glm::vec3 vec) const
{
    glUniform3f(glGetUniformLocation(progID, name.c_str()), vec.x, vec.y, vec.z);
}
void Shader::setVec4(const std::string& name, glm::vec4 vec) const
{
    glUniform4f(glGetUniformLocation(progID, name.c_str()), vec.x, vec.y, vec.z, vec.w);
}