#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
    ~Shader();
    
    void useProgram();
    unsigned int getID();
    void setMat4(const char* name, glm::mat4& matrix);
private:
    unsigned int m_ID{};
    const int compileShader(const char *shaderPath, const int shaderType);
    void MatrixConfig();
};

#endif