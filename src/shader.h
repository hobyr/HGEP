#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include <glad/gl.h>


class Shader
{
public:
    // the program ID
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
private:
    GLuint createShader(GLenum eShaderType, const char* shaderPath);
    GLuint createProgram(const std::vector<GLuint> &shaderList);
};

#endif /* ifndef _SHADER_H_ */
