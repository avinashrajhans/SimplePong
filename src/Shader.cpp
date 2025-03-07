#include <glad/glad.h>
#include "Shader.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    const int vertexShader{compileShader(vertexShaderPath, GL_VERTEX_SHADER)};
    const int fragmentShader{compileShader(fragmentShaderPath, GL_FRAGMENT_SHADER)};
    if (vertexShader && fragmentShader)
    {
        m_ID = glCreateProgram();
        glAttachShader(m_ID, vertexShader);
        glAttachShader(m_ID, fragmentShader);
        glLinkProgram(m_ID);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        int success{};
        char infoLog[512];

        glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << infoLog << std::endl;
        }
    }
    MatrixConfig();
}

const int Shader::compileShader(const char *shaderPath, const int shaderType)
{
    std::string intermediateString{};
    std::ifstream shaderCode{shaderPath};

    if (!shaderCode)
    {
        std::cerr << "ERROR::READING::" << ((shaderType == GL_VERTEX_SHADER) ? "VERTEX" : "PROBABLY::FRAGMENT") << "::SHADER::FILE\n";
        return 0;
    }

    std::stringstream shaderStream;
    shaderStream << shaderCode.rdbuf();
    shaderCode.close();
    intermediateString = shaderStream.str();
    const char *sourceOfShader{intermediateString.c_str()};
    unsigned int shaderID{glCreateShader(shaderType)};
    glShaderSource(shaderID, 1, &sourceOfShader, nullptr);
    glCompileShader(shaderID);

    int success{};
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::" << ((shaderType == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT::PROBABLY") << "::COMPILATION::FAILED" << infoLog << '\n';
    }
    return shaderID;
}

void Shader::useProgram()
{
    if (m_ID)
    {
        glUseProgram(m_ID);
    }

    else
    {
        std::cerr << "SHADER::PROGRAM::NOT::CREATED\n";
    }
}

Shader::~Shader()
{
    glDeleteProgram(m_ID);
}

void Shader::setMat4(const char *name, glm::mat4 &matrix)
{
    glUniformMatrix4fv((glGetUniformLocation(m_ID, name)), 1, GL_FALSE, glm::value_ptr(matrix));
}

// unsigned int Shader::getID()
// {
//     return m_ID;
// }

void Shader::MatrixConfig()
{
glUseProgram(m_ID);
glm::mat4 model{glm::mat4{1.0f}};
glm::mat4 projection{glm::mat4{1.0f}};
projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f);
setMat4("projection", projection);
setMat4("model", model);
}