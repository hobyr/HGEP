#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    GLuint vShader(createShader(GL_VERTEX_SHADER, vertexPath));
    GLuint fShader(createShader(GL_FRAGMENT_SHADER, fragmentPath));

    std::vector<GLuint> shaderList({vShader, fShader});
    ID = createProgram(shaderList);

    std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
}

void Shader::use()
{
    glUseProgram(ID);
}

GLuint Shader::createShader(GLenum eShaderType, const char* shaderPath)
{
    GLuint shader(glCreateShader(eShaderType));
    std::ifstream shaderFile(shaderPath);
    std::stringstream shaderStream {};

    shaderStream << shaderFile.rdbuf();
    shaderFile.close();

    std::string strShaderCode {shaderStream.str()};
    const char* shaderCode {strShaderCode.c_str()};

    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength {};
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
        const char *strShaderType = NULL;
        switch(eShaderType)
        {
            case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
            case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
            case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
        }
        std::cerr << "Compile failure in " << strShaderType << ":"
                  << std::endl << strInfoLog << std::endl;
        delete [] strInfoLog;
    }

    return shader;
}

GLuint Shader::createProgram(const std::vector<GLuint> &shaderList)
{
    GLuint program = glCreateProgram();
    
    for (const GLuint shader : shaderList)
    {
        glAttachShader(program, shader);
    }
    glLinkProgram(program);

    GLint status {};
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength {};
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        std::cerr << "Linker failure: " << strInfoLog << std::endl;
        delete [] strInfoLog;
    }

    for (const GLuint shader : shaderList)
    {
        glDetachShader(program, shader);
    }

    return program;
}
